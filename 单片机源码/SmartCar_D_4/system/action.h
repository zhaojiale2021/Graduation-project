#ifndef __ACTION_H
#define __ACTION_H

#include "stm32f10x.h"
#include "motor.h"
#include "systick.h"

//�ú�������ǰ���ٶ�
void speed(uint16_t speeds); /* �ɴ�����ֵ 0<=speeds<=100 */

//���º������Ʒ���
void front(void); //ǰ��
void back(void);  //����
void Lturn(void); //��ת
void Rturn(void); //��ת
void Stop(void);

#endif
