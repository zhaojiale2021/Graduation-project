#include "CameraThread.h"

CameraThread::CameraThread(QObject *parent) :
    QThread(parent)
{
    stopped = false;
}

void CameraThread::run()
{
    qDebug() << "Current thread:" << QThread::currentThreadId();
    if (!cv_cap.isOpened())
    {
        cv_cap.open(0);
    }

    while (!stopped)
    {
        cv_cap >> cv_src;

        if(!cv_src.data)
        {
            continue;
        }
        emit getImage(cv_src);
        cv_src.release();
    }
    cv_cap.release();
}

void CameraThread::stop()
{
    stopped = true;
}
