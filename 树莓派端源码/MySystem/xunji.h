#ifndef XUNJI_H
#define XUNJI_H
#include <QObject>
#include<opencv2/opencv.hpp>
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include<opencv2/imgproc/types_c.h>
#include<QThread>
using namespace std;
using namespace cv;

class xunji:public QThread
{
    Q_OBJECT
public:
    xunji();
    int findcenter(Mat);
signals:
    void sendLeft();
    void sendRight();
    void sendFront();
    void sendStop();
protected:
    void run();
private:
};

#endif // XUNJI_H
