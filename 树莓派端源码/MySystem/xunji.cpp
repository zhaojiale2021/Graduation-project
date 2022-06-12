#include "xunji.h"
#include <QDebug>


xunji::xunji():QThread ()
{

}

int xunji::findcenter(Mat src)
{
    int array[640];
    int counter=0;
    int center;
    //迭代器访问像素点
    uchar* data = src.ptr<uchar>(410);
    for(int ncol = 0; ncol < src.cols; ncol++)
    {
        if(data[ncol]==255){//二值化后，像素点是0或者255
            array[counter]=ncol;
            counter+=1;
            //qDebug() << counter;
        }
        if(counter==0)
            counter=1;
    }
    center= (array[0]+array[counter-1])/2;
    qDebug() << center;
    return center;
}

void xunji::run()
{
    // 打开摄像头，图像尺寸640*480（长*高），opencv存储值为480*640（行*列）
    VideoCapture videoCap;
    videoCap.open(0);
    if (!videoCap.isOpened()) {
        printf("could not open camera...\n");
        return;
    }
    while(1){
        qDebug()<<"XUNJI:"<<QThread::currentThreadId();
        Mat frame,image,gray,blur,thresh1,mask;
        videoCap.read(frame);
        frame.copyTo(image);
        imshow("image",image);
        cvtColor(image,gray,COLOR_BGR2GRAY);
        //高斯滤波
        GaussianBlur(gray,blur,Size(15,15),0,0);
        //二值化
        threshold(blur,thresh1,0,255,THRESH_OTSU);
        // threshold(blur,thresh1,0,255,THRESH_BINARY);
        //腐蚀
        erode(thresh1,mask,2);
        //膨胀
        dilate(mask,mask,2);
        imshow("mask image",mask);
        // 找到白色像素的中心点位置
        int center=xunji::findcenter(mask);
        if(center>600||center<40){
            emit sendStop();
            qDebug()<<"未发现车道"<<endl;
            qDebug()<<"停止"<<endl;
           // videoCap.release();
            //destroyAllWindows();
            //return;
        }
        // 计算出center与标准中心点的偏移量
        int dis= center-320;
        if(dis>15){
            emit sendRight();
            qDebug()<<"中点在右方"<<endl;
            qDebug()<<"向右运动"<<endl;
        }
        if(dis>-15&&dis<15){
            emit sendFront();
            qDebug()<<"在车道上"<<endl;
            qDebug()<<"向前运动"<<endl;
        }
        if(dis<-15){
            emit sendLeft();
            qDebug()<<"中点在左方"<<endl;
            qDebug()<<"向左运动"<<endl;
        }
        QThread::msleep(500);
        char k = static_cast<char>(waitKey(10));
        if( k == 27 ){
            emit sendStop();
            qDebug()<<"停止并退出"<<endl;
            destroyAllWindows();
            break;
        }
    }
    return;
}
