#ifndef __ACTION_H
#define __ACTION_H

#include "stm32f10x.h"
#include "motor.h"
#include "systick.h"

//该函数控制前进速度
void speed(uint16_t speeds); /* 可传参数值 0<=speeds<=100 */

//以下函数控制方向
void front(void); //前进
void back(void);  //后退
void Lturn(void); //左转
void Rturn(void); //右转
void Stop(void);

#endif
