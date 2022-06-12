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
#include<CameraThread.h>
#include<xunji.h>
#include<QLabel>

using namespace std;
using namespace cv;
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

    void TCPread();                        //TCP read函数


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
    quint16 number=0;                     //帧率
    QHostAddress cliAddr;                //对方IP地址
    QByteArray TCPdata;                  //TCP图像数据
    QSerialPort *serial;
    CameraThread *Cam;
    ultrasonic *ult;
    xunji *XunJi;

signals:
    QByteArray sendImage(QByteArray);
private slots:
    void TCPsend(QByteArray);              //TCP发送函数
    void  getImageData(Mat image);            //获取图像并返回图像信息
    void openCamera();
    void closeCamera();
    void displayImage(QLabel *label, QPixmap &pixmap);
    QImage MatImageToQimage(const cv::Mat &src);
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
