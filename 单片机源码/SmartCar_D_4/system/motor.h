#ifndef __MOTOR_H
#define __MOTOR_H

#include "stm32f10x.h"
#include "systick.h"
void Motor1_Init(void);
void Motor2_Init(void);
void setSpeed(u16);
void front(u16);
void back(u16);
void left(u16);
void right(u16);
void Lturn(u16);
void Rturn(u16);
void LturnRound(u16);
void RturnRound(u16);
void Ltranslate(u16);
void Rtranslate(u16);
void Stop(void);
void setBeep(int);
#endif	/* __MOTOR_H */
