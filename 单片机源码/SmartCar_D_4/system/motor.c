#include "motor.h"
void Motor1_Init(void)
{  
	GPIO_InitTypeDef GPIO_InitStructure;
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	TIM_OCInitTypeDef  TIM_OCInitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);  //ʹ��GPIO�����AFIO���ù���ģ��ʱ��
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);	 //ʹ��PC�˿�ʱ��
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);	//ʹ�ܶ�ʱ��1ʱ��
	
	//����AIN21 AIN22 BIN21 BIN22��GPIO
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //ͨ���������
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO���ٶ�Ϊ50MHz
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3 | GPIO_Pin_10 | GPIO_Pin_11 | GPIO_Pin_12 |GPIO_Pin_13;			
  GPIO_Init(GPIOC, &GPIO_InitStructure);					 //�����趨������ʼ��GPIOC
	//���ø�����Ϊ�����������,���TIM3 CH3 CH4��PWM���岨��	GPIOB.0  GPIOB.1
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1; //TIM3_CH1  CH4
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;  //�����������
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);//��ʼ��GPIO
 
   //��ʼ��TIM3
	TIM_TimeBaseStructure.TIM_Period = 99; //��������һ�������¼�װ�����Զ���װ�ؼĴ������ڵ�ֵ
	TIM_TimeBaseStructure.TIM_Prescaler =7199; //����������ΪTIMxʱ��Ƶ�ʳ�����Ԥ��Ƶֵ 
	TIM_TimeBaseStructure.TIM_ClockDivision = 0; //����ʱ�ӷָ�:TDTS = Tck_tim
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIM���ϼ���ģʽ
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure); //����TIM_TimeBaseInitStruct��ָ���Ĳ�����ʼ��TIMx��ʱ�������λ
	TIM_ARRPreloadConfig(TIM3,ENABLE);
	
	//��ʼ��TIM1 Channel2 PWMģʽ	 
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; //ѡ��ʱ��ģʽ:TIM�����ȵ���ģʽ2
 	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //�Ƚ����ʹ��
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; //�������:TIM����Ƚϼ��Ը�
	TIM_OC3Init(TIM3, &TIM_OCInitStructure);  //����Tָ���Ĳ�����ʼ������TIM3 OC3
	TIM_OC3PreloadConfig(TIM3, TIM_OCPreload_Enable);
	TIM_OC4Init(TIM3, &TIM_OCInitStructure);  //����Tָ���Ĳ�����ʼ������TIM3 OC4
	TIM_OC4PreloadConfig(TIM3, TIM_OCPreload_Enable);

	TIM_Cmd(TIM3, ENABLE);  //ʹ��TIM3
	TIM_CtrlPWMOutputs(TIM3,ENABLE);
	
}

void Motor2_Init(void)
{  
	GPIO_InitTypeDef GPIO_InitStructure;
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	TIM_OCInitTypeDef  TIM_OCInitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);  //ʹ��GPIO�����AFIO���ù���ģ��ʱ��
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);	 //ʹ��PC�˿�ʱ��
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);	//ʹ�ܶ�ʱ��1ʱ��
	
	//����AIN21 AIN22 BIN21 BIN22��GPIO
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //ͨ���������
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO���ٶ�Ϊ50MHz
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4 | GPIO_Pin_7 | GPIO_Pin_8 | GPIO_Pin_9;			
    GPIO_Init(GPIOC, &GPIO_InitStructure);					 //�����趨������ʼ��GPIOC
	//���ø�����Ϊ�����������,���TIM3 CH3 CH4��PWM���岨��	GPIOB.0  GPIOB.1
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7; //TIM4_CH1  CH2
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;  //�����������
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);//��ʼ��GPIO
 
   //��ʼ��TIM4
	TIM_TimeBaseStructure.TIM_Period = 99; //��������һ�������¼�װ�����Զ���װ�ؼĴ������ڵ�ֵarr
	TIM_TimeBaseStructure.TIM_Prescaler =7199; //����������ΪTIMxʱ��Ƶ�ʳ�����Ԥ��Ƶֵ
	TIM_TimeBaseStructure.TIM_ClockDivision = 0; //����ʱ�ӷָ�:TDTS = Tck_tim
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIM���ϼ���ģʽ
	TIM_TimeBaseInit(TIM4, &TIM_TimeBaseStructure); //����TIM_TimeBaseInitStruct��ָ���Ĳ�����ʼ��TIMx��ʱ�������λ
	TIM_ARRPreloadConfig(TIM4,ENABLE);
	
	//��ʼ��TIM1 Channel2 PWMģʽ	 
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; //ѡ��ʱ��ģʽ:TIM�����ȵ���ģʽ2
 	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //�Ƚ����ʹ��
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; //�������:TIM����Ƚϼ��Ը�
	TIM_OC1Init(TIM4, &TIM_OCInitStructure);  //����Tָ���Ĳ�����ʼ������TIM4 OC1
	TIM_OC1PreloadConfig(TIM4, TIM_OCPreload_Enable);
	TIM_OC2Init(TIM4, &TIM_OCInitStructure);  //����Tָ���Ĳ�����ʼ������TIM4 OC2
	TIM_OC2PreloadConfig(TIM4, TIM_OCPreload_Enable);

	TIM_Cmd(TIM4, ENABLE);  //ʹ��TIM4 
	TIM_CtrlPWMOutputs(TIM4,ENABLE);
	
}

//����ռ�ձ� //speed ccr/arr 
void setSpeed(u16 speeds)
{
	TIM_SetCompare3(TIM3,speeds);
	TIM_SetCompare4(TIM3,speeds);
	TIM_SetCompare1(TIM4,speeds);
	TIM_SetCompare2(TIM4,speeds);
}

void front(u16 speeds)
{
	setSpeed(speeds);
	GPIO_SetBits(GPIOC,GPIO_Pin_11);    
  GPIO_ResetBits(GPIOC,GPIO_Pin_10);  //�Һ�����ת
	
	GPIO_SetBits(GPIOC,GPIO_Pin_12);    
  GPIO_ResetBits(GPIOC,GPIO_Pin_3);  //��ǰ�����ת
	
	GPIO_SetBits(GPIOC,GPIO_Pin_7);    
  GPIO_ResetBits(GPIOC,GPIO_Pin_4); //�������ת
	
	GPIO_SetBits(GPIOC,GPIO_Pin_9);   
  GPIO_ResetBits(GPIOC,GPIO_Pin_8); //��ǰ�����ת
}

void left(u16 speeds)
{
	setSpeed(speeds);
	GPIO_SetBits(GPIOC,GPIO_Pin_11);    
  GPIO_ResetBits(GPIOC,GPIO_Pin_10);  //�Һ�����ת
	
	GPIO_SetBits(GPIOC,GPIO_Pin_12);    
  GPIO_ResetBits(GPIOC,GPIO_Pin_3);  //��ǰ�����ת
	
	GPIO_ResetBits(GPIOC,GPIO_Pin_4);    
  GPIO_ResetBits(GPIOC,GPIO_Pin_7); //�����ֹͣ
	
	GPIO_ResetBits(GPIOC,GPIO_Pin_8);   
  GPIO_ResetBits(GPIOC,GPIO_Pin_9); //��ǰ���ֹͣ
}
void right(u16 speeds)
{
	setSpeed(speeds);

	GPIO_SetBits(GPIOC,GPIO_Pin_7);    
  GPIO_ResetBits(GPIOC,GPIO_Pin_4); //�������ת
	
	GPIO_SetBits(GPIOC,GPIO_Pin_9);   
  GPIO_ResetBits(GPIOC,GPIO_Pin_8); //��ǰ�����ת
	
	  GPIO_ResetBits(GPIOC,GPIO_Pin_10);    
  GPIO_ResetBits(GPIOC,GPIO_Pin_11);  //�Һ�ֹͣ
	
	GPIO_ResetBits(GPIOC,GPIO_Pin_3);    
  GPIO_ResetBits(GPIOC,GPIO_Pin_12);  //��ǰֹͣ
}
void back(u16 speeds)
{
	setSpeed(speeds);
	GPIO_SetBits(GPIOC,GPIO_Pin_10);    
  GPIO_ResetBits(GPIOC,GPIO_Pin_11);  //�Һ�����ת
	
	GPIO_SetBits(GPIOC,GPIO_Pin_3);    
  GPIO_ResetBits(GPIOC,GPIO_Pin_12);  //��ǰ�����ת
	
	GPIO_SetBits(GPIOC,GPIO_Pin_4);    
  GPIO_ResetBits(GPIOC,GPIO_Pin_7); //�������ת
	
	GPIO_SetBits(GPIOC,GPIO_Pin_8);   
  GPIO_ResetBits(GPIOC,GPIO_Pin_9); //��ǰ�����ת
}
void Lturn(u16 speeds)
{
	setSpeed(speeds);
	GPIO_SetBits(GPIOC,GPIO_Pin_12);    
  GPIO_ResetBits(GPIOC,GPIO_Pin_3);  //��ǰ�����ת
	
	GPIO_ResetBits(GPIOC,GPIO_Pin_10);    
  GPIO_ResetBits(GPIOC,GPIO_Pin_11);  //�Һ�ֹͣ
	
	GPIO_ResetBits(GPIOC,GPIO_Pin_8);   
  GPIO_ResetBits(GPIOC,GPIO_Pin_9); //��ǰ���ֹͣ
	
	GPIO_SetBits(GPIOC,GPIO_Pin_7);    
  GPIO_ResetBits(GPIOC,GPIO_Pin_4); //�������ת
}
void Rturn(u16 speeds)
{
	setSpeed(speeds);
	GPIO_SetBits(GPIOC,GPIO_Pin_11);    
  GPIO_ResetBits(GPIOC,GPIO_Pin_10); //�Һ�����ת
	
	GPIO_ResetBits(GPIOC,GPIO_Pin_3);    
  GPIO_ResetBits(GPIOC,GPIO_Pin_12);  //��ǰֹͣ
	
	GPIO_SetBits(GPIOC,GPIO_Pin_9);   
  GPIO_ResetBits(GPIOC,GPIO_Pin_8); //��ǰ�����ת
	
	GPIO_ResetBits(GPIOC,GPIO_Pin_4);    
  GPIO_ResetBits(GPIOC,GPIO_Pin_7); //�����ֹͣ

}
void LturnRound(u16 speeds)
{
	setSpeed(speeds);
	GPIO_SetBits(GPIOC,GPIO_Pin_11);    
  GPIO_ResetBits(GPIOC,GPIO_Pin_10);  //�Һ�����ת
	
	GPIO_SetBits(GPIOC,GPIO_Pin_12);    
  GPIO_ResetBits(GPIOC,GPIO_Pin_3);  //��ǰ�����ת
	
	GPIO_SetBits(GPIOC,GPIO_Pin_4);    
  GPIO_ResetBits(GPIOC,GPIO_Pin_7); //�������ת  
	
	GPIO_SetBits(GPIOC,GPIO_Pin_8);   
  GPIO_ResetBits(GPIOC,GPIO_Pin_9); //��ǰ�����ת
	
}
void RturnRound(u16 speeds)
{
	setSpeed(speeds);
	GPIO_SetBits(GPIOC,GPIO_Pin_10);    
  GPIO_ResetBits(GPIOC,GPIO_Pin_11);  //�Һ�����ת
	
	GPIO_SetBits(GPIOC,GPIO_Pin_3);    
  GPIO_ResetBits(GPIOC,GPIO_Pin_12);  //��ǰ�����ת
	
	GPIO_SetBits(GPIOC,GPIO_Pin_7);    
  GPIO_ResetBits(GPIOC,GPIO_Pin_4); //�������ת
	
	GPIO_SetBits(GPIOC,GPIO_Pin_9);   
  GPIO_ResetBits(GPIOC,GPIO_Pin_8); //��ǰ�����ת
	
}
void Ltranslate(u16 speeds)
{
	setSpeed(speeds);
	GPIO_SetBits(GPIOC,GPIO_Pin_8);   
  GPIO_ResetBits(GPIOC,GPIO_Pin_9); //��ǰ�����ת
	
  GPIO_SetBits(GPIOC,GPIO_Pin_7);    
  GPIO_ResetBits(GPIOC,GPIO_Pin_4); //�������ת
	
	GPIO_SetBits(GPIOC,GPIO_Pin_12);    
  GPIO_ResetBits(GPIOC,GPIO_Pin_3);  //��ǰ�����ת
	
	GPIO_SetBits(GPIOC,GPIO_Pin_10);    
  GPIO_ResetBits(GPIOC,GPIO_Pin_11);  //�Һ�����ת
}
void Rtranslate(u16 speeds)
{
	setSpeed(speeds);
	GPIO_SetBits(GPIOC,GPIO_Pin_11);    
  GPIO_ResetBits(GPIOC,GPIO_Pin_10);  //�Һ�����ת
	
	GPIO_SetBits(GPIOC,GPIO_Pin_3);    
  GPIO_ResetBits(GPIOC,GPIO_Pin_12);  //��ǰ�����ת
	
	GPIO_SetBits(GPIOC,GPIO_Pin_9);   
  GPIO_ResetBits(GPIOC,GPIO_Pin_8); //��ǰ�����ת
	
	GPIO_SetBits(GPIOC,GPIO_Pin_4);    
  GPIO_ResetBits(GPIOC,GPIO_Pin_7); //�������ת  
}
void Stop(void)
{
  GPIO_ResetBits(GPIOC,GPIO_Pin_10);    
  GPIO_ResetBits(GPIOC,GPIO_Pin_11);  //�Һ�ֹͣ
	
	GPIO_ResetBits(GPIOC,GPIO_Pin_3);    
  GPIO_ResetBits(GPIOC,GPIO_Pin_12);  //��ǰֹͣ
	
	GPIO_ResetBits(GPIOC,GPIO_Pin_4);    
  GPIO_ResetBits(GPIOC,GPIO_Pin_7); //�����ֹͣ
	
	GPIO_ResetBits(GPIOC,GPIO_Pin_8);   
  GPIO_ResetBits(GPIOC,GPIO_Pin_9); //��ǰ���ֹͣ
}
void setBeep(int ONOFF)
{
	if(ONOFF==0){ 
	GPIO_ResetBits(GPIOC,GPIO_Pin_13);
	}
	else if(ONOFF==1){
	GPIO_SetBits(GPIOC,GPIO_Pin_13);
	}
	else if(ONOFF==2){
		setBeep(1);
		delay_ms(500);
		setBeep(0);
		delay_ms(500);
	}
}
