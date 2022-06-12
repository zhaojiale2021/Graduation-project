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
    qRegisterMetaType<Mat>("Mat");
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
    //开启1S定时器 来清帧率
     timeImage = new QTimer(this);
     // timer->start(1000);
     connect(timeImage,&QTimer::timeout,this,[=](){
         number = 0;
         ui->FPS->setText(QString::number(number));
     });
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
                                 QHostAddress("10.36.98.152"), clientPort);
    }
    );

//    timeImage = new QTimer(this);
    timeImage->start(1000);
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(openCamera()));
    connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(closeCamera()));
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
        connect(this,SIGNAL(sendImage(QByteArray)),this,SLOT(TCPsend(QByteArray)));
        //connect(timeImage,&QTimer::timeout,this,&Widget::TCPsend);
    });
    connect(tcpSocket1, &QTcpSocket::connected,
            [=]()
    {
        //Start QThread
        ult->start();
        this->connect(ult,SIGNAL(SendUltra(const float)),this,SLOT(ReceiveUltra()));
    });

    connect(tcpSocket, &QTcpSocket::disconnected,
            [=]()
    {
        timeUDP->start(1000);
        disconnect(tcpSocket, &QTcpSocket::readyRead,this,&Widget::TCPread);
        disconnect(this,SIGNAL(sendImage(QByteArray)),this,SLOT(TCPsend(QByteArray)));
    });
}
/**************************************************************
 * 函数名：void Widget::TCPsend()
 * 函数功能：首先获取图像信息 加入到数据流 并同过TCP发送
 * 输入参数：void
 * 输出参数:void
 * 返回值:void
**************************************************************/
void Widget::TCPsend(QByteArray ii)
{   qDebug()<<"Main:"<<QThread::currentThreadId();
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
void Widget::openCamera()
{
    Cam = new CameraThread();
    connect(Cam, SIGNAL(getImage(Mat)), this, SLOT(getImageData(Mat)));
    Cam->start();
}

void Widget::closeCamera()
{
    if (Cam->isRunning())
    {
        Cam->stop();
        Cam->destroyed();
    }
    ui->video->close();
}

void Widget::getImageData(Mat image)
{
    QImage qt_image = MatImageToQimage(image);
    QPixmap qt_pixmap = QPixmap::fromImage(qt_image);
    ui->video->setPixmap(qt_pixmap);
    displayImage(ui->video, qt_pixmap);
    ui->video->show();
    ++number;
    ui->FPS->setText(QString::number(number));
    QByteArray byte;
    QBuffer buf(&byte);
    qt_image.save(&buf,"JPG");
    QByteArray ssImage=qCompress(byte,1);
    QByteArray ii=ssImage.toBase64();
     //Send Tcpdata
    emit sendImage(ii);

}

void Widget::displayImage(QLabel *label, QPixmap &pixmap)
{
    //对齐方式，水平与垂直
    label->setAlignment(Qt::AlignLeft);

    //图像自适应窗口大小
    QSize imageSize = pixmap.size();
    QSize labelSize = label->size();

    double widthRatio = 1.0*imageSize.width() / labelSize.width();
    double heightRatio = 1.0*imageSize.height() / labelSize.height();

    if (widthRatio > heightRatio)
    {
        pixmap = pixmap.scaledToWidth(labelSize.width());
    }
    else
    {
        pixmap = pixmap.scaledToHeight(labelSize.height());
    }
    //这个设置是整个图片跟着窗口改变，铺满
    label->setScaledContents(true);

    //label->resize(QSize(pixmap.width(),pixmap.height()));
    label->setPixmap(pixmap);

}
//Mat转成QImage
QImage Widget::MatImageToQimage(const Mat &src)
{
    //CV_8UC1 8位无符号的单通道---灰度图片
    if (src.type() == CV_8UC1)
    {
        //使用给定的大小和格式构造图像
        //QImage(int width, int height, Format format)
        QImage qImage(src.cols, src.rows, QImage::Format_Indexed8);
        //扩展颜色表的颜色数目
        qImage.setColorCount(256);
        //在给定的索引设置颜色
        for (int i = 0; i < 256; i++)
        {
            //得到一个黑白图
            qImage.setColor(i, qRgb(i, i, i));
        }
        //复制输入图像,data数据段的首地址
        uchar *pSrc = src.data;
        //
        for (int row = 0; row < src.rows; row++)
        {
            //遍历像素指针
            uchar *pDest = qImage.scanLine(row);
            //从源src所指的内存地址的起始位置开始拷贝n个
            //字节到目标dest所指的内存地址的起始位置中
            memcmp(pDest, pSrc, src.cols);
            //图像层像素地址
            pSrc += src.step;
        }
        return qImage;
    }
    //为3通道的彩色图片
    else if (src.type() == CV_8UC3)
    {
        //得到图像的的首地址
        const uchar *pSrc = (const uchar*)src.data;
        //以src构造图片
        QImage qImage(pSrc, src.cols, src.rows, src.step, QImage::Format_RGB888);
        //在不改变实际图像数据的条件下，交换红蓝通道
        return qImage.rgbSwapped();
    }
    //四通道图片，带Alpha通道的RGB彩色图像
    else if (src.type() == CV_8UC4)
    {
        const uchar *pSrc = (const uchar*)src.data;
        QImage qImage(pSrc, src.cols, src.rows, src.step, QImage::Format_ARGB32);
        //返回图像的子区域作为一个新图像
        return qImage.copy();
    }
    else
    {
        return QImage();
    }
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
    //    XunJi->quit();
    //    videoCap.open(0);
    //    timeImage->start(33);    //定时器
    //    connect(timeImage,&QTimer::timeout,this,&Widget::showImage);
    //    this->show();

}

void Widget::onxunjiStart()
{
    this->hide();
  //  disconnect(timeImage,&QTimer::timeout,this,&Widget::TCPsend);
  //  timeImage->stop();    //关闭定时器
    delay(1000);
    XunJi->start();
    this->connect(XunJi,SIGNAL(sendLeft()),this,SLOT(recvCamLeft()));
    this->connect(XunJi,SIGNAL(sendRight()),this,SLOT(recvCamRight()));
    this->connect(XunJi,SIGNAL(sendFront()),this,SLOT(recvCamFront()));
    this->connect(XunJi,SIGNAL(sendStop()),this,SLOT(recvCamStop()));
}

