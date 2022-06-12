#include "motor.h"
void Motor1_Init(void)
{  
	GPIO_InitTypeDef GPIO_InitStructure;
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	TIM_OCInitTypeDef  TIM_OCInitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);  //使能GPIO外设和AFIO复用功能模块时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);	 //使能PC端口时钟
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);	//使能定时器1时钟
	
	//设置AIN21 AIN22 BIN21 BIN22的GPIO
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //通用推挽输出
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO口速度为50MHz
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3 | GPIO_Pin_10 | GPIO_Pin_11 | GPIO_Pin_12 |GPIO_Pin_13;			
  GPIO_Init(GPIOC, &GPIO_InitStructure);					 //根据设定参数初始化GPIOC
	//设置该引脚为复用输出功能,输出TIM3 CH3 CH4的PWM脉冲波形	GPIOB.0  GPIOB.1
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1; //TIM3_CH1  CH4
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;  //复用推挽输出
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);//初始化GPIO
 
   //初始化TIM3
	TIM_TimeBaseStructure.TIM_Period = 99; //设置在下一个更新事件装入活动的自动重装载寄存器周期的值
	TIM_TimeBaseStructure.TIM_Prescaler =7199; //设置用来作为TIMx时钟频率除数的预分频值 
	TIM_TimeBaseStructure.TIM_ClockDivision = 0; //设置时钟分割:TDTS = Tck_tim
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIM向上计数模式
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure); //根据TIM_TimeBaseInitStruct中指定的参数初始化TIMx的时间基数单位
	TIM_ARRPreloadConfig(TIM3,ENABLE);
	
	//初始化TIM1 Channel2 PWM模式	 
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; //选择定时器模式:TIM脉冲宽度调制模式2
 	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //比较输出使能
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; //输出极性:TIM输出比较极性高
	TIM_OC3Init(TIM3, &TIM_OCInitStructure);  //根据T指定的参数初始化外设TIM3 OC3
	TIM_OC3PreloadConfig(TIM3, TIM_OCPreload_Enable);
	TIM_OC4Init(TIM3, &TIM_OCInitStructure);  //根据T指定的参数初始化外设TIM3 OC4
	TIM_OC4PreloadConfig(TIM3, TIM_OCPreload_Enable);

	TIM_Cmd(TIM3, ENABLE);  //使能TIM3
	TIM_CtrlPWMOutputs(TIM3,ENABLE);
	
}

void Motor2_Init(void)
{  
	GPIO_InitTypeDef GPIO_InitStructure;
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	TIM_OCInitTypeDef  TIM_OCInitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);  //使能GPIO外设和AFIO复用功能模块时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);	 //使能PC端口时钟
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);	//使能定时器1时钟
	
	//设置AIN21 AIN22 BIN21 BIN22的GPIO
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //通用推挽输出
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO口速度为50MHz
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4 | GPIO_Pin_7 | GPIO_Pin_8 | GPIO_Pin_9;			
    GPIO_Init(GPIOC, &GPIO_InitStructure);					 //根据设定参数初始化GPIOC
	//设置该引脚为复用输出功能,输出TIM3 CH3 CH4的PWM脉冲波形	GPIOB.0  GPIOB.1
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7; //TIM4_CH1  CH2
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;  //复用推挽输出
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);//初始化GPIO
 
   //初始化TIM4
	TIM_TimeBaseStructure.TIM_Period = 99; //设置在下一个更新事件装入活动的自动重装载寄存器周期的值arr
	TIM_TimeBaseStructure.TIM_Prescaler =7199; //设置用来作为TIMx时钟频率除数的预分频值
	TIM_TimeBaseStructure.TIM_ClockDivision = 0; //设置时钟分割:TDTS = Tck_tim
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIM向上计数模式
	TIM_TimeBaseInit(TIM4, &TIM_TimeBaseStructure); //根据TIM_TimeBaseInitStruct中指定的参数初始化TIMx的时间基数单位
	TIM_ARRPreloadConfig(TIM4,ENABLE);
	
	//初始化TIM1 Channel2 PWM模式	 
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; //选择定时器模式:TIM脉冲宽度调制模式2
 	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //比较输出使能
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; //输出极性:TIM输出比较极性高
	TIM_OC1Init(TIM4, &TIM_OCInitStructure);  //根据T指定的参数初始化外设TIM4 OC1
	TIM_OC1PreloadConfig(TIM4, TIM_OCPreload_Enable);
	TIM_OC2Init(TIM4, &TIM_OCInitStructure);  //根据T指定的参数初始化外设TIM4 OC2
	TIM_OC2PreloadConfig(TIM4, TIM_OCPreload_Enable);

	TIM_Cmd(TIM4, ENABLE);  //使能TIM4 
	TIM_CtrlPWMOutputs(TIM4,ENABLE);
	
}

//设置占空比 //speed ccr/arr 
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
  GPIO_ResetBits(GPIOC,GPIO_Pin_10);  //右后电机正转
	
	GPIO_SetBits(GPIOC,GPIO_Pin_12);    
  GPIO_ResetBits(GPIOC,GPIO_Pin_3);  //右前电机正转
	
	GPIO_SetBits(GPIOC,GPIO_Pin_7);    
  GPIO_ResetBits(GPIOC,GPIO_Pin_4); //左后电机正转
	
	GPIO_SetBits(GPIOC,GPIO_Pin_9);   
  GPIO_ResetBits(GPIOC,GPIO_Pin_8); //左前电机正转
}

void left(u16 speeds)
{
	setSpeed(speeds);
	GPIO_SetBits(GPIOC,GPIO_Pin_11);    
  GPIO_ResetBits(GPIOC,GPIO_Pin_10);  //右后电机正转
	
	GPIO_SetBits(GPIOC,GPIO_Pin_12);    
  GPIO_ResetBits(GPIOC,GPIO_Pin_3);  //右前电机正转
	
	GPIO_ResetBits(GPIOC,GPIO_Pin_4);    
  GPIO_ResetBits(GPIOC,GPIO_Pin_7); //左后电机停止
	
	GPIO_ResetBits(GPIOC,GPIO_Pin_8);   
  GPIO_ResetBits(GPIOC,GPIO_Pin_9); //左前电机停止
}
void right(u16 speeds)
{
	setSpeed(speeds);

	GPIO_SetBits(GPIOC,GPIO_Pin_7);    
  GPIO_ResetBits(GPIOC,GPIO_Pin_4); //左后电机正转
	
	GPIO_SetBits(GPIOC,GPIO_Pin_9);   
  GPIO_ResetBits(GPIOC,GPIO_Pin_8); //左前电机正转
	
	  GPIO_ResetBits(GPIOC,GPIO_Pin_10);    
  GPIO_ResetBits(GPIOC,GPIO_Pin_11);  //右后停止
	
	GPIO_ResetBits(GPIOC,GPIO_Pin_3);    
  GPIO_ResetBits(GPIOC,GPIO_Pin_12);  //右前停止
}
void back(u16 speeds)
{
	setSpeed(speeds);
	GPIO_SetBits(GPIOC,GPIO_Pin_10);    
  GPIO_ResetBits(GPIOC,GPIO_Pin_11);  //右后电机反转
	
	GPIO_SetBits(GPIOC,GPIO_Pin_3);    
  GPIO_ResetBits(GPIOC,GPIO_Pin_12);  //右前电机反转
	
	GPIO_SetBits(GPIOC,GPIO_Pin_4);    
  GPIO_ResetBits(GPIOC,GPIO_Pin_7); //左后电机反转
	
	GPIO_SetBits(GPIOC,GPIO_Pin_8);   
  GPIO_ResetBits(GPIOC,GPIO_Pin_9); //左前电机反转
}
void Lturn(u16 speeds)
{
	setSpeed(speeds);
	GPIO_SetBits(GPIOC,GPIO_Pin_12);    
  GPIO_ResetBits(GPIOC,GPIO_Pin_3);  //右前电机正转
	
	GPIO_ResetBits(GPIOC,GPIO_Pin_10);    
  GPIO_ResetBits(GPIOC,GPIO_Pin_11);  //右后停止
	
	GPIO_ResetBits(GPIOC,GPIO_Pin_8);   
  GPIO_ResetBits(GPIOC,GPIO_Pin_9); //左前电机停止
	
	GPIO_SetBits(GPIOC,GPIO_Pin_7);    
  GPIO_ResetBits(GPIOC,GPIO_Pin_4); //左后电机正转
}
void Rturn(u16 speeds)
{
	setSpeed(speeds);
	GPIO_SetBits(GPIOC,GPIO_Pin_11);    
  GPIO_ResetBits(GPIOC,GPIO_Pin_10); //右后电机正转
	
	GPIO_ResetBits(GPIOC,GPIO_Pin_3);    
  GPIO_ResetBits(GPIOC,GPIO_Pin_12);  //右前停止
	
	GPIO_SetBits(GPIOC,GPIO_Pin_9);   
  GPIO_ResetBits(GPIOC,GPIO_Pin_8); //左前电机正转
	
	GPIO_ResetBits(GPIOC,GPIO_Pin_4);    
  GPIO_ResetBits(GPIOC,GPIO_Pin_7); //左后电机停止

}
void LturnRound(u16 speeds)
{
	setSpeed(speeds);
	GPIO_SetBits(GPIOC,GPIO_Pin_11);    
  GPIO_ResetBits(GPIOC,GPIO_Pin_10);  //右后电机正转
	
	GPIO_SetBits(GPIOC,GPIO_Pin_12);    
  GPIO_ResetBits(GPIOC,GPIO_Pin_3);  //右前电机正转
	
	GPIO_SetBits(GPIOC,GPIO_Pin_4);    
  GPIO_ResetBits(GPIOC,GPIO_Pin_7); //左后电机反转  
	
	GPIO_SetBits(GPIOC,GPIO_Pin_8);   
  GPIO_ResetBits(GPIOC,GPIO_Pin_9); //左前电机反转
	
}
void RturnRound(u16 speeds)
{
	setSpeed(speeds);
	GPIO_SetBits(GPIOC,GPIO_Pin_10);    
  GPIO_ResetBits(GPIOC,GPIO_Pin_11);  //右后电机反转
	
	GPIO_SetBits(GPIOC,GPIO_Pin_3);    
  GPIO_ResetBits(GPIOC,GPIO_Pin_12);  //右前电机反转
	
	GPIO_SetBits(GPIOC,GPIO_Pin_7);    
  GPIO_ResetBits(GPIOC,GPIO_Pin_4); //左后电机正转
	
	GPIO_SetBits(GPIOC,GPIO_Pin_9);   
  GPIO_ResetBits(GPIOC,GPIO_Pin_8); //左前电机正转
	
}
void Ltranslate(u16 speeds)
{
	setSpeed(speeds);
	GPIO_SetBits(GPIOC,GPIO_Pin_8);   
  GPIO_ResetBits(GPIOC,GPIO_Pin_9); //左前电机反转
	
  GPIO_SetBits(GPIOC,GPIO_Pin_7);    
  GPIO_ResetBits(GPIOC,GPIO_Pin_4); //左后电机正转
	
	GPIO_SetBits(GPIOC,GPIO_Pin_12);    
  GPIO_ResetBits(GPIOC,GPIO_Pin_3);  //右前电机正转
	
	GPIO_SetBits(GPIOC,GPIO_Pin_10);    
  GPIO_ResetBits(GPIOC,GPIO_Pin_11);  //右后电机反转
}
void Rtranslate(u16 speeds)
{
	setSpeed(speeds);
	GPIO_SetBits(GPIOC,GPIO_Pin_11);    
  GPIO_ResetBits(GPIOC,GPIO_Pin_10);  //右后电机正转
	
	GPIO_SetBits(GPIOC,GPIO_Pin_3);    
  GPIO_ResetBits(GPIOC,GPIO_Pin_12);  //右前电机反转
	
	GPIO_SetBits(GPIOC,GPIO_Pin_9);   
  GPIO_ResetBits(GPIOC,GPIO_Pin_8); //左前电机正转
	
	GPIO_SetBits(GPIOC,GPIO_Pin_4);    
  GPIO_ResetBits(GPIOC,GPIO_Pin_7); //左后电机反转  
}
void Stop(void)
{
  GPIO_ResetBits(GPIOC,GPIO_Pin_10);    
  GPIO_ResetBits(GPIOC,GPIO_Pin_11);  //右后停止
	
	GPIO_ResetBits(GPIOC,GPIO_Pin_3);    
  GPIO_ResetBits(GPIOC,GPIO_Pin_12);  //右前停止
	
	GPIO_ResetBits(GPIOC,GPIO_Pin_4);    
  GPIO_ResetBits(GPIOC,GPIO_Pin_7); //左后电机停止
	
	GPIO_ResetBits(GPIOC,GPIO_Pin_8);   
  GPIO_ResetBits(GPIOC,GPIO_Pin_9); //左前电机停止
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
