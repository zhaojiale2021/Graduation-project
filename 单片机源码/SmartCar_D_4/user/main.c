#include "uart.h"
#include "motor.h"
#include "systick.h"
#include "stm32f10x.h"
#include "sys.h"
#define ON 1
#define OFF 0
#define ONOFF 2
int main(void)
{
  systick_init();
	Motor1_Init();
  Motor2_Init(); 
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); //设置NVIC中断分组2:2位抢占优先级，2位响应优先级
	uart_init(9600);	 //串口初始化为9600
	setBeep(OFF);
	
	while(1)
	{
		u16 speed = 50;
		switch(USART_ReceiveData(USART1))
		{
			case 'F':	
				front(speed); //前进
				break;
			case 'B':		
			  back(speed);  //后退
				setBeep(ONOFF); //蜂鸣器提示
				break;	
			case 'l': 
			  left(speed); //左转
				break;
			case 'r': 
			  right(speed); //右转
				break;
			case 'L': 
			  Lturn(speed); //麦轮左前方平移
				break;
			case 'R':
			  Rturn(speed); //麦轮右前方平移
			  break;
			case 'T':
			  Rtranslate(speed); //右平移
			  break;
			case 'E':
			  Ltranslate(speed); //左平移
			  break;
			case 'U':
			  RturnRound(speed); //顺时针旋转
			  break; 
			case 'N':
			  LturnRound(speed); //逆时针旋转
			  break;
			case 'A':
				speed+=10;//加速
				front(speed); //前进
        //printf("%d",speed);
				break;
			case 'D':
			  speed-=10;     //减速
				front(speed); //前进
			  //printf("%d",speed);
				break;
			case 'S': 
				Stop();//STOP
				break;
			case 'W': 
				//蜂鸣器报警
	      setBeep(ON);
				Stop();//STOP
				break;
	    case 'C':
				//蜂鸣器灭
	      setBeep(OFF);
				break;
			default: 
				break;	
   }
 }
}
