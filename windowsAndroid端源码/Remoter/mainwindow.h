#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QUdpSocket>
#include <QTcpServer>
#include <QTcpSocket>
#include <QHostInfo>
#include <QNetworkAddressEntry>
#include <QTableWidget>
#include <QTimer>
#include <QLabel>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void TCPinit();                        //初始化TCP连接
    //图片显示
    void showImage(QByteArray imageByteArray);
private slots:
    void dealUDPreceive();                //UDP接收处理函数
    void dealTCPreceive();                //TCP接收处理函数
    void dealTCPreceive1();                //TCP接收处理函数
    void on_connect_clicked();

    void on_front_clicked();

    void on_left_clicked();

    void on_right_clicked();

    void on_behind_clicked();

    void on_stop_clicked();

    void on_disconnect_clicked();

    void on_Rtranslate_clicked();

    void on_Ltranslate_clicked();

    void on_RturnRound_clicked();

    void on_LturnRound_clicked();
    void recv1();
    void recv2();
    void on_add_clicked();
    void on_decrease_clicked();
    void on_autodrive_clicked();



signals:
    void send1();
    void send2();

private:
    Ui::MainWindow *ui;
    QLabel *status;                       //连接状态
    QLabel *video;                        //显示视频
    QTimer *timer;                        //定时器 用来更新帧率
    QTcpSocket *tcpSocket;                //TCP通信套接字
    QTcpServer *tcpServer;                //TCP监听套接字
    QTcpSocket *tcpSocket1;                //TCP通信套接字1
    QTcpServer *tcpServer1;                //TCP监听套接字1
    QUdpSocket *udpSocket;                //udp套接字
    const static quint16 myPort = 55555;  //我方端口号
    const static quint16 myPort1 = 55556;  //我方端口号
    const static quint16 clientPort = 45454;   //对方端口号
    QHostAddress cliAddr;                 //对方IP地址
    quint64 OneImageSize = 0;             //一帧图片大小
    quint16 number=0;                     //帧率
    float speed;
};
#endif // MAINWINDOW_H
