#ifndef ULTRASONIC_H
#define ULTRASONIC_H
#include <QThread>
#include "wiringPi.h"
#include <unistd.h>
#include <string.h>
#include <QDebug>
#include <fcntl.h>
#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <sys/time.h>
extern float dis;
class ultrasonic:public QThread
{
 Q_OBJECT
public:
    ultrasonic();
signals:
 void SendUltra(const float dis);
protected:
 void run();
};

#endif // ULTRASONIC_H
