#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QHostAddress>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //setWindowTitle("遥控端");
    // 设置背景图片
    this->setObjectName("mainWindow");
    this->setStyleSheet("#mainWindow{border-image:url(:/background.jpg);}");
    //初始所有按钮为disable
    ui->connect->setEnabled(false);
    ui->disconnect->setEnabled(false);
    ui->front->setEnabled(false);
    ui->behind->setEnabled(false);
    ui->left->setEnabled(false);
    ui->right->setEnabled(false);
    ui->stop->setEnabled(false);
    ui->Ltranslate->setEnabled(false);
    ui->Rtranslate->setEnabled(false);
    ui->LturnRound->setEnabled(false);
    ui->RturnRound->setEnabled(false);
    ui->add->setEnabled(false);
    ui->decrease->setEnabled(false);
    ui->autodrive->setEnabled(false);
    //设置按钮图标
    QIcon iconF(":/front.png");
    QIcon iconB(":/behind.png");
    QIcon iconLt(":/left.png");
    QIcon iconRt(":/right.png");
    QIcon iconL(":/L.jpg");
    QIcon iconR(":/R.jpg");
    QIcon iconLC(":/L-C.jpg");
    QIcon iconRC(":/R-C.jpg");
    QIcon iconS(":/stop.jpg");

    ui->front->setIcon(iconF);
    ui->front->setIconSize(QSize(60,60));
    ui->behind->setIcon(iconB);
    ui->behind->setIconSize(QSize(60,60));
    ui->left->setIcon(iconL);
    ui->left->setIconSize(QSize(60,60));
    ui->right->setIcon(iconR);
    ui->right->setIconSize(QSize(60,60));
    ui->Ltranslate->setIcon(iconLt);
    ui->Ltranslate->setIconSize(QSize(60,60));
    ui->Rtranslate->setIcon(iconRt);
    ui->Rtranslate->setIconSize(QSize(60,60));
    ui->LturnRound->setIcon(iconLC);
    ui->LturnRound->setIconSize(QSize(60,60));
    ui->RturnRound->setIcon(iconRC);
    ui->RturnRound->setIconSize(QSize(60,60));
    ui->stop->setIcon(iconS);
    ui->stop->setIconSize(QSize(80,60));
    //设置速度初始值为50
    speed = 50;
    ui->lcdNumber_3->display(speed);
    //初始化状态栏
    status =new QLabel;
    status->setPixmap(QPixmap(":/disconnect.png").scaled(40,40));
    ui->statusbar->addWidget(new QLabel("TCP通信状态："));
    ui->statusbar->addWidget(status);
    //开启1S定时器 来清帧率
    timer = new QTimer(this);
    // timer->start(1000);
    connect(timer,&QTimer::timeout,this,[=](){
        number = 0;
        ui->FPS->setText(QString::number(number));
    });
    //UDP设置
    udpSocket = new QUdpSocket(this);                                     //分配空间，指定父对象
    udpSocket->bind(QHostAddress::Any,myPort);                         //UDP绑定我方端口号
    connect(udpSocket,&QUdpSocket::readyRead,this,&MainWindow::dealUDPreceive);    //当UDP接收到信息时会触发readyRead
    this->connect(this,SIGNAL(send1()),this,SLOT(recv1()));
    this->connect(this,SIGNAL(send2()),this,SLOT(recv2()));
}

MainWindow::~MainWindow()
{
    tcpSocket->disconnectFromHost();
    tcpSocket->close();
    delete ui;
}
/**************************************************************
 * 函数名：void MainWindow::dealUDPreceive()
 * 函数功能：UDP接收函数 检测是否连接至树莓派 连接则初始化TCP
 * 输入参数：void
 * 输出参数:void
 * 返回值:void
**************************************************************/
void MainWindow::dealUDPreceive()
{
    char buf[1024] = {0};           //接收数组
    quint16 port;                  //对方端口
    qint64 len = udpSocket->readDatagram(buf, sizeof(buf), &cliAddr, &port);
    if(len > 0)
    {
        QString str = QString("%1").arg(buf);
        if(str == "hello" && port == clientPort) //第一次握手成功 并回应对方“你好”
        {
            QByteArray reply = "你好";
            udpSocket->writeDatagram(reply.data(),reply.size(),
                                     QHostAddress(cliAddr), port);
            TCPinit();
        }
    }

}
/**************************************************************
 * 函数名：void MainWindow::TCPinit()
 * 函数功能：TCP初始化函数 TCP设备连接槽函数
 * 输入参数：void
 * 输出参数:void
 * 返回值:void
**************************************************************/
void MainWindow::TCPinit()
{
    tcpServer = nullptr;
    tcpSocket = nullptr;
    tcpServer = new QTcpServer(this);
    tcpServer->listen(QHostAddress::AnyIPv4, myPort);
    connect(tcpServer, &QTcpServer::newConnection,[=](){
        tcpSocket = tcpServer->nextPendingConnection();  //取出建立好连接的套接字
        ui->video->setText("已连接至树莓派");
        status->setPixmap(QPixmap(":/connect.png").scaled(40,40));
        ui->connect->setEnabled(true);
        ui->disconnect->setEnabled(false);
        ui->front->setEnabled(true);
        ui->behind->setEnabled(true);
        ui->left->setEnabled(true);
        ui->right->setEnabled(true);
        ui->stop->setEnabled(true);
        ui->Ltranslate->setEnabled(true);
        ui->Rtranslate->setEnabled(true);
        ui->LturnRound->setEnabled(true);
        ui->RturnRound->setEnabled(true);
        ui->add->setEnabled(true);
        ui->decrease->setEnabled(true);
        ui->autodrive->setEnabled(true);
    });
    connect(tcpSocket, &QTcpSocket::disconnected,
            [=]()
    {
        ui->connect->setEnabled(false);
        ui->disconnect->setEnabled(false);
        ui->front->setEnabled(false);
        ui->behind->setEnabled(false);
        ui->left->setEnabled(false);
        ui->right->setEnabled(false);
        ui->stop->setEnabled(false);
        ui->Ltranslate->setEnabled(false);
        ui->Rtranslate->setEnabled(false);
        ui->LturnRound->setEnabled(false);
        ui->RturnRound->setEnabled(false);
        ui->add->setEnabled(false);
        ui->decrease->setEnabled(false);
        ui->autodrive->setEnabled(false);
        ui->video->setText("TCP连接中断");
        status->setPixmap(QPixmap(":/disconnect.png").scaled(40,40));
    });

    tcpServer1 = nullptr;
    tcpSocket1 = nullptr;
    tcpServer1 = new QTcpServer(this);
    tcpServer1->listen(QHostAddress::AnyIPv4, myPort1);
    connect(tcpServer1, &QTcpServer::newConnection,[=](){
        tcpSocket1 = tcpServer1->nextPendingConnection();  //取出建立好连接的套接字
        connect(tcpSocket1, &QTcpSocket::readyRead,
                this,&MainWindow::dealTCPreceive1);
    });

    timer->start(1000);
}
/**************************************************************
 * 函数名：MainWindow::dealTCPreceive()
 * 函数功能：TCP接收函数 TCP设备连接槽函数
 * 输入参数：void
 * 输出参数:void
 * 返回值:void
**************************************************************/
void MainWindow::dealTCPreceive()
{
    QDataStream strameIn(tcpSocket);
    strameIn.setVersion(QDataStream::Qt_5_11);
    if(OneImageSize==0)
    {
        if (tcpSocket->bytesAvailable()<(int)(sizeof(quint64)))
        {
            return;
        }
        strameIn >> OneImageSize;
    }

    if(OneImageSize>50000||OneImageSize<1000)
    {
        OneImageSize=0;
        tcpSocket->readAll();        //清空TCP缓冲区
        return;
    }
    if (tcpSocket->bytesAvailable()<(qint64)OneImageSize)
    {
        return;
    }
    if (tcpSocket->bytesAvailable()>50000)
    {
        OneImageSize=0;
        tcpSocket->readAll();        //清空TCP缓冲区
        return;
    }
    QByteArray ImageMessage;
    ImageMessage.resize(OneImageSize);
    strameIn >> ImageMessage;
    showImage(ImageMessage);
    OneImageSize = 0;
}

void MainWindow::dealTCPreceive1()
{
    QString str;
    str=tcpSocket1->readAll();
    qDebug()<<"障碍物距离："<<str;
    ui->lcdNumber->display(str);
    float dis = str.toFloat();
    if(dis<20)
    {
        emit send1();
    }
    if(dis>20){
        emit send2();
    }

}
void MainWindow::recv1()
{
//    QString action ="Warning";
//    tcpSocket1->write(action.toUtf8());
    QColor red;
    red.setRed(255);
    ui->textBrowser->setTextColor(red);
    ui->textBrowser->setText("前方有障碍物");
}

void MainWindow::recv2()
{
//    QString action ="Common";
//    tcpSocket1->write(action.toUtf8());
    QColor green;
    green.setGreen(255);
    ui->textBrowser->setTextColor(green);
    ui->textBrowser->setText("前方道路通畅");
}
/**************************************************************
 * 函数名：MainWindow::showImage(QByteArray imageByteArray)
 * 函数功能：视频显示函数
 * 输入参数：QByteArray
 * 输出参数:void
 * 返回值:void
**************************************************************/
void MainWindow::showImage(QByteArray imageByteArray)
{
    QString ss = QString::fromLatin1(imageByteArray.data(),imageByteArray.size());
    QByteArray rc = QByteArray::fromBase64(ss.toLatin1());
    QByteArray rdc=qUncompress(rc);
    QImage image;
    image.loadFromData(rdc);
    int a = ui->video->width();
    int b = ui->video->height();
    QImage showimage=image.scaled(a,b);
    ui->video->setPixmap(QPixmap::fromImage(showimage));//原像
    ++number;
    ui->FPS->setText(QString::number(number));
    update();//更新页面image
}

void MainWindow::on_connect_clicked()
{
    connect(tcpSocket, &QTcpSocket::readyRead,
            this,&MainWindow::dealTCPreceive);
    ui->connect->setEnabled(false);
    ui->disconnect->setEnabled(true);
    //按钮状态随连接状态变化
    connect(tcpSocket,&QTcpSocket::connected,this,[=](){
        ui->disconnect->setEnabled(true);
        ui->front->setEnabled(true);
        ui->behind->setEnabled(true);
        ui->left->setEnabled(true);
        ui->right->setEnabled(true);
        ui->stop->setEnabled(true);
        ui->connect->setEnabled(true);
        ui->Ltranslate->setEnabled(true);
        ui->Rtranslate->setEnabled(true);
        ui->LturnRound->setEnabled(true);
        ui->RturnRound->setEnabled(true);
        ui->add->setEnabled(true);
        ui->decrease->setEnabled(true);
        ui->autodrive->setEnabled(true);
        status->setPixmap(QPixmap(":/connect.png").scaled(40,40));


    });
}

void MainWindow::on_disconnect_clicked()
{
    disconnect(tcpSocket, &QTcpSocket::readyRead,
               this,&MainWindow::dealTCPreceive);
    ui->video->setText("视频传输终止");
    ui->disconnect->setEnabled(false);
    ui->connect->setEnabled(true);

}

void MainWindow::on_front_clicked()
{
    QString action ="front";
    tcpSocket->write(action.toUtf8());
}

void MainWindow::on_left_clicked()
{
    QString action ="left";
    tcpSocket->write(action.toUtf8());
}

void MainWindow::on_right_clicked()
{
    QString action ="right";
    tcpSocket->write(action.toUtf8());
}

void MainWindow::on_behind_clicked()
{
    QString action ="behind";
    tcpSocket->write(action.toUtf8());
}

void MainWindow::on_stop_clicked()
{
    QString action ="stop";
    tcpSocket->write(action.toUtf8());
}

void MainWindow::on_Rtranslate_clicked()
{
    QString action ="Rtranslate";
    tcpSocket->write(action.toUtf8());
}

void MainWindow::on_Ltranslate_clicked()
{
    QString action ="Ltranslate";
    tcpSocket->write(action.toUtf8());
}

void MainWindow::on_RturnRound_clicked()
{
    QString action ="RturnRound";
    tcpSocket->write(action.toUtf8());
}

void MainWindow::on_LturnRound_clicked()
{
    QString action ="LturnRound";
    tcpSocket->write(action.toUtf8());
}

void MainWindow::on_add_clicked()
{

    speed+=10;
    if(speed == 100){
        ui->add->setDisabled(true);
        ui->decrease->setDisabled(false);
    }
    else {
        ui->add->setDisabled(false);
    }
    ui->lcdNumber_3->display(speed);
    QString action;
    action ="accelerated";
    tcpSocket->write(action.toUtf8());

}

void MainWindow::on_decrease_clicked()
{   speed-=10;
    if(speed == 0){
        ui->add->setDisabled(false);
        ui->decrease->setDisabled(true);
    }
    else {
        ui->add->setDisabled(false);
        ui->decrease->setDisabled(false);
    }

    ui->lcdNumber_3->display(speed);
    QString action;
    action ="decelerate";
    tcpSocket->write(action.toUtf8());
}

void MainWindow::on_autodrive_clicked()
{
    QString action;
    action ="autodrive";
    tcpSocket->write(action.toUtf8());
}

