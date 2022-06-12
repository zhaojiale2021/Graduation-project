#ifndef CAMERATHREAD_H
#define CAMERATHREAD_H
#include <QThread>
#include <QDebug>
#include <vector>
#include <QString>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;
class CameraThread : public QThread
{
    Q_OBJECT

public:
    void stop();
    explicit CameraThread(QObject *parent = nullptr);

    VideoCapture cv_cap;
    int camera_index;
    Mat cv_src;

protected:
    void run();

private:
    volatile bool stopped;

signals:
    void getImage(const Mat&);

public slots:

};

#endif // CAMERATHREAD_H
