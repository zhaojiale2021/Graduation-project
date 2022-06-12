#include "widget.h"
#include "ui_widget.h"

#include <QNetworkAddressEntry>
#include <QProcess>
#include <QString>
#include <QHostAddress>
#include <QBuffer>
#include <QPushButton>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    if(wiringPiSetup() == -1){ //when initialize wiring failed,print messageto screen
            printf("setup wiringPi failed !");
        }
    ui->setupUi(this);
    //new对象
    ult = new ultrasonic();
    XunJi = new xunji();
    setWindowTitle("实时视频遥控界面");
    // Serial init
    serial = new QSerialPort;
    serial->close();
    serial->setPortName("/dev/ttyAMA0");
    serial->open(QIODevice::ReadWrite);
    serial->setBaudRate(9600);
    serial->setDataBits(QSerialPort::Data8);
    serial->setParity(QSerialPort::NoParity);
    serial->setStopBits(QSerialPort::OneStop);
    serial->setFlowControl(QSerialPort::NoFlowControl);
    connect(serial,&QSerialPort::readyRead,this,&Widget::read);

    this->connect(XunJi,SIGNAL(sendLeft()),this,SLOT(recvCamLeft()));
    this->connect(XunJi,SIGNAL(sendRight()),this,SLOT(recvCamRight()));
    this->connect(XunJi,SIGNAL(sendFront()),this,SLOT(recvCamFront()));
    this->connect(XunJi,SIGNAL(sendStop()),this,SLOT(recvCamStop()));
    this->connect(this, SIGNAL(notifyxunjiStart()), XunJi, SLOT(xunjiStart()));

    // Camera init
    camerainit();
    //UDP绑定
    udpSocket = new QUdpSocket(this);               //分配空间，指定父对象
    udpSocket->bind(QHostAddress::AnyIPv4,myPort);   //UDP绑定绑定端口号
    connect(udpSocket,&QUdpSocket::readyRead,       //当UDP接收到信息时会触发readyRead
            this,&Widget::dealUDPreceive);          //UDP接收槽函数连接
    //开启定时器
    timeUDP = new QTimer(this);                        //分配空间，指定父对象
    timeUDP->start(1000);                              //开启定时器
    connect(timeUDP,&QTimer::timeout,this,
            [=]()
    {
        QByteArray reply = "hello";
        udpSocket->writeDatagram(reply.data(),reply.size(),
                                 QHostAddress("10.31.172.13"), clientPort);
    }
    );

    timeImage = new QTimer(this);
    timeImage->start(33);
    connect(timeImage,&QTimer::timeout,this,&Widget::showImage);
}

Widget::~Widget()
{
    tcpSocket->disconnectFromHost();
    tcpSocket->close();
    tcpSocket1->disconnectFromHost();
    tcpSocket1->close();
    serial->write("S");
    serial->close();
    delete ui;
}
/**************************************************************
 * 函数名：void Widget::read()
 * 函数功能：serial接收槽函数
 * 输入参数：void
 * 输出参数:void
 * 返回值:void
**************************************************************/
void Widget::read()
{
    QByteArray buf;
    buf = serial->readAll();
    qDebug() << buf;
    QString a = QString(buf);
}
/**************************************************************
 * 函数名：void Widget::dealUDPreceive()
 * 函数功能：UDP接收槽函数 接收对方设备"你好"实现握手 初始化TCP设置
 * 输入参数：void
 * 输出参数:void
 * 返回值:void
**************************************************************/
void Widget::dealUDPreceive()
{
    char buf[1024] = {0};           //接收数组
    quint16 port;                   //对方端口
    qint64 len = udpSocket->readDatagram(buf, sizeof(buf), &cliAddr, &port);
    if(len > 0)
    {
        QString str = QString("%1").arg(buf);
        if(str == "你好" && port == clientPort)//第一次握手成功 收到对方回应“你好”
        {
            timeUDP->stop();            //停止UDP
            TCPinit();
        }
    }
}
/**************************************************************
 * 函数名：void Widget::TCPinit()
 * 函数功能：TCP初始化函数 TCP设备连接槽函数 断开连接槽函数
 * 输入参数：void
 * 输出参数:void
 * 返回值:void
**************************************************************/
void Widget::TCPinit()
{
    tcpSocket = nullptr;
    tcpSocket1 = nullptr;
    tcpSocket = new QTcpSocket(this);
    tcpSocket1 = new QTcpSocket(this);
    tcpSocket->connectToHost(cliAddr, clientPort);
    tcpSocket1->connectToHost(cliAddr, clientPort1);
    connect(tcpSocket, &QTcpSocket::connected,
            [=]()
    {
        connect(tcpSocket, &QTcpSocket::readyRead,this,&Widget::TCPread);
        connect(timeImage,&QTimer::timeout,this,&Widget::TCPsend);
    });
    connect(tcpSocket1, &QTcpSocket::connected,
            [=]()
    {
        //connect(tcpSocket1, &QTcpSocket::readyRead,this,&Widget::TCPread1);
        //Start QThread
        ult->start();
        this->connect(ult,SIGNAL(SendUltra(const float)),this,SLOT(ReceiveUltra()));
    });

    connect(tcpSocket, &QTcpSocket::disconnected,
            [=]()
    {
        timeUDP->start(1000);
        disconnect(tcpSocket, &QTcpSocket::readyRead,this,&Widget::TCPread);
        disconnect(timeImage,&QTimer::timeout,this,&Widget::TCPsend);
        this->disconnect(ult,SIGNAL(SendUltra(const float)),this,SLOT(ReceiveUltra()));

    });
}
/**************************************************************
 * 函数名：void Widget::TCPsend()
 * 函数功能：首先获取图像信息 加入到数据流 并同过TCP发送
 * 输入参数：void
 * 输出参数:void
 * 返回值:void
**************************************************************/
void Widget::TCPsend()
{
    QByteArray ii = getImageData();
    if(ii.length()>0)
    {
        TCPdata.clear();
        TCPdata.reserve(ii.length() + sizeof(quint64));
        QDataStream out(&TCPdata,QIODevice::WriteOnly);
        out.setVersion(QDataStream::Qt_5_11);
        quint64 imageSize = 0;

        out << static_cast<quint64>(imageSize);
        out << ii;
        imageSize = static_cast<unsigned int>(TCPdata.size())-sizeof(quint64);

        out.device()->seek(0);
        out << static_cast<quint64>(imageSize);
        tcpSocket->write(TCPdata);
    }
}

void Widget::TCPread()
{
    QString data;
    data=tcpSocket->readAll();
    while(1){
        if(data=="front"){
            serial->write("F");
            break;
        }
        if(data=="behind"){
            serial->write("B");
            break;
        }
        if(data=="left"){
            serial->write("L");
            break;
        }
        if(data=="right"){
            serial->write("R");
            break;
        }
        if(data=="Rtranslate"){
            serial->write("T");
            break;
        }
        if(data=="Ltranslate"){
            serial->write("E");
            break;
        }
        if(data=="RturnRound"){
            serial->write("U");
            break;
        }
        if(data=="LturnRound"){
            serial->write("N");
            break;
        }
        if(data=="accelerated"){
            serial->write("A");
            break;
        }
        if(data=="decelerate"){
            serial->write("D");
            break;
        }
        if(data=="stop"){
            serial->write("S");
            break;
        }
        if(data=="autodrive"){
            onxunjiStart();
            break;
        }
    }
}

/**************************************************************
 * 函数名：void Widget::showImage()
 * 函数功能：获取图像在相应位置显示
 * 输入参数：void
 * 输出参数:void
 * 返回值:void
**************************************************************/
void Widget::showImage()
{
    //获取图像
    videoCap>>srcImage;

    if(srcImage.data )//将获取到的图像信息进行数据转换
    {
        cvtColor(srcImage, srcImage, CV_BGR2RGB);//Qt中支持的是RGB图像, OpenCV中支持的是BGR
        update();  //发送刷新消息,重绘
    }

    CameraStoredImage = QImage(static_cast<uchar*>(srcImage.data), srcImage.cols, srcImage.rows, QImage::Format_RGB888);
    int a = ui->video->width();
    int b = ui->video->height();                 //获取控件大小
    QImage image = CameraStoredImage.scaled(a,b);//自定义缩放
    ui->video->setPixmap(QPixmap::fromImage(image));
}
/**************************************************************
 * 函数名：void Widget::camerainit()
 * 函数功能：打开摄像头
 * 输入参数：void
 * 输出参数:void
 * 返回值:void
**************************************************************/
void Widget::camerainit()
{
    videoCap.open(0);//摄像头默认0
}
/**************************************************************
 * 函数名：QByteArray Widget::getImageData()
 * 函数功能：获取图像返回图片信息以备发送
 * 输入参数：void
 * 输出参数:QByteArray
 * 返回值:void
**************************************************************/
QByteArray Widget::getImageData()
{
    //获取图像
    videoCap>>srcImage;
    if(srcImage.data )//将获取到的图像信息进行数据转换
    {
        cvtColor(srcImage, srcImage, CV_BGR2RGB);//Qt中支持的是RGB图像, OpenCV中支持的是BGR
        update();  //发送刷新消息,重绘
    }
    CameraStoredImage = QImage(static_cast<uchar*>(srcImage.data), srcImage.cols, srcImage.rows, QImage::Format_RGB888);
    int a = ui->video->width();
    int b = ui->video->height();                 //获取控件大小
    QImage image = CameraStoredImage.scaled(a,b);//自定义缩放
   // ui->video->setPixmap(QPixmap::fromImage(image));
    QByteArray byte;
    QBuffer buf(&byte);
    CameraStoredImage.save(&buf,"JPG");
    QByteArray ssImage=qCompress(byte,1);
    return ssImage.toBase64();
}

void Widget::ReceiveUltra()
{
    QString distance;
    distance = QString::number(static_cast<double>(dis),'f',2);
    //qDebug()<<"障碍物距离："<<distance;
    ui->lcdNumber->display(distance);
    tcpSocket1->write(distance.toUtf8());
    float dist =  distance.toFloat();
    if(dist<20){
         serial->write("W");
    }
    if(dis>20){
      serial->write("C");
    }
}

void Widget::recvCamLeft()
{
    serial->write("l");
}

void Widget::recvCamRight()
{
    serial->write("r");
}

void Widget::recvCamFront()
{
    serial->write("F");
}

void Widget::recvCamStop()
{
    serial->write("S");
}

void Widget::onxunjiStart()
{
    this->hide();
    timeImage->stop();    //关闭定时器
    videoCap.release();//释放图像
    emit notifyxunjiStart();
}

