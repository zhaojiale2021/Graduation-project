#ifndef XUNJI_H
#define XUNJI_H
#include <QObject>
#include<opencv2/opencv.hpp>
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include<opencv2/imgproc/types_c.h>

using namespace std;
using namespace cv;

class xunji:public QObject
{
    Q_OBJECT
public:
    explicit xunji(QObject *parent = nullptr);
public slots:
    void xunjiStart();

signals:
    void sendLeft();
    void sendRight();
    void sendFront();
    void sendStop();
protected:

private:
};

#endif // XUNJI_H
