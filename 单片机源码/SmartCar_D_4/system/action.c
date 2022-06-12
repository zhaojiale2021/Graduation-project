#include "action.h"

void speed(uint16_t speeds)
{
	  TIM_SetCompare3(TIM3,speeds);
	  TIM_SetCompare4(TIM3,speeds);
}

void front(void)
{
	
	//�������ת
	GPIO_ResetBits(GPIOC, GPIO_Pin_10);//AIN1
	GPIO_SetBits(GPIOC, GPIO_Pin_11);//AIN2
	//�ұ�����ת
	GPIO_ResetBits(GPIOC, GPIO_Pin_3);//BIN1
	GPIO_SetBits(GPIOC, GPIO_Pin_12);//BIN2	

}
void back(void)
{
	
	//����ַ�ת
	GPIO_SetBits(GPIOC, GPIO_Pin_10);//AIN1
	GPIO_ResetBits(GPIOC, GPIO_Pin_11);//AIN2
	//�ұ��ַ�ת
	GPIO_SetBits(GPIOC, GPIO_Pin_3);//BIN1
	GPIO_ResetBits(GPIOC, GPIO_Pin_12);//BIN2	
}
void Lturn(void)
{
	
  //�����ֹͣ
	GPIO_ResetBits(GPIOC, GPIO_Pin_10);//AIN1
	GPIO_ResetBits(GPIOC, GPIO_Pin_11);//AIN2
	//�ұ�����ת
	GPIO_ResetBits(GPIOC, GPIO_Pin_3);//BIN1
	GPIO_SetBits(GPIOC, GPIO_Pin_12);//BIN2	
//	delay_ms(4000);
//	//ֹͣ

	

}
void Rturn(void)
{

	
		//�������ת
	GPIO_ResetBits(GPIOC, GPIO_Pin_10);//AIN1
	GPIO_SetBits(GPIOC, GPIO_Pin_11);//AIN2
	//�ұ���ֹͣ
	GPIO_ResetBits(GPIOC, GPIO_Pin_3);//BIN1
	GPIO_ResetBits(GPIOC, GPIO_Pin_12);//BIN2	
//	delay_ms(4000);
//	//ֹͣ
//	GPIO_ResetBits(GPIOC, GPIO_Pin_10);//AIN1
//	GPIO_ResetBits(GPIOC, GPIO_Pin_11);//AIN2
//	GPIO_ResetBits(GPIOC, GPIO_Pin_3);//AIN1
//	GPIO_ResetBits(GPIOC, GPIO_Pin_12);//AIN2
	
}
void Stop(void)
{
	GPIO_ResetBits(GPIOC, GPIO_Pin_10);//AIN1
	GPIO_ResetBits(GPIOC, GPIO_Pin_11);//AIN2
	GPIO_ResetBits(GPIOC, GPIO_Pin_3);//BIN1
	GPIO_ResetBits(GPIOC, GPIO_Pin_12);//BIN2
}
