#include "ultrasonic.h"
#define Trig 5 //gpio5
#define Echo 6 //gpio6
float dis;
ultrasonic::ultrasonic():QThread ()
{
    pinMode(Echo, INPUT);
    pinMode(Trig, OUTPUT);
}
void ultrasonic::run()
{
    while(1)
    {
        struct timeval tv1;
        struct timeval tv2;
        long start, stop;
        digitalWrite(Trig, LOW);
        delayMicroseconds(2);
        digitalWrite(Trig, HIGH);
        delayMicroseconds(10); //发出超声波脉冲 需要高于 10us
        digitalWrite(Trig, LOW);
        while(!(digitalRead(Echo) == 1));
        gettimeofday(&tv1, nullptr); //获取当前时间
        while(!(digitalRead(Echo) == 0));
        gettimeofday(&tv2, nullptr); //获取当前时间
        start = tv1.tv_sec * 1000000 + tv1.tv_usec; //微秒级
        stop = tv2.tv_sec * 1000000 + tv2.tv_usec;
        dis = static_cast<float>(stop - start) / 1000000 * 34000 / 2; //求出距离 目标距离
        QThread::msleep(500);
        emit SendUltra(dis);
    }
}

