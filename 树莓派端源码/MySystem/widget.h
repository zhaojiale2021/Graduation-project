#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

#include <QUdpSocket>
#include <QTcpSocket>
#include <QHostInfo>
#include <QTimer>
#include <QTableWidget>
#include <QAbstractSocket>
#include<opencv2/opencv.hpp>
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include<opencv2/imgproc/types_c.h>
#include <QByteArray>
#include<QtSerialPort/QSerialPort>
#include<ultrasonic.h>
#include<xunji.h>
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();
    void read();                           // serial

    void TCPinit();                        //初始化TCP连接
    void TCPsend();                        //TCP发送函数
    void TCPread();                        //TCP read函数
    void showImage();                      //图像显示
    void camerainit();                     //打kai摄像头
    QByteArray  getImageData();            //获取图像并返回图像信息


private:
    Ui::Widget *ui;

    QTimer *timeUDP;                     //UDP组播定时器
    QTimer *timeImage;                   //TCP发送图片定时器
    QTcpSocket *tcpSocket;               //tcp通信套接字
    QTcpSocket *tcpSocket1;               //tcp通信套接字1
    QUdpSocket *udpSocket;               //udp套接字
    const static quint16 myPort = 45454;  //我方端口号
    const static quint16 clientPort = 55555;  //对方端口号
      const static quint16 clientPort1 = 55556;  //对方端口号1
    QHostAddress cliAddr;                //对方IP地址
    QByteArray TCPdata;                  //TCP图像数据

    QSerialPort *serial;
    QImage CameraStoredImage;         //获取合成后的图片
    cv::VideoCapture videoCap;
    cv::Mat srcImage;
    ultrasonic *ult;
    xunji *XunJi;

signals:
    void notifyxunjiStart();
private slots:
    void dealUDPreceive();                //UDP接收处理函数
    //按键槽函数
    void ReceiveUltra();
    void recvCamLeft();
    void recvCamRight();
    void recvCamFront();
    void recvCamStop();
    void onxunjiStart();
};



#endif // WIDGET_H
