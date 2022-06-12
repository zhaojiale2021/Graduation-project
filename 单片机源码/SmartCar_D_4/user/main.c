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
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); //����NVIC�жϷ���2:2λ��ռ���ȼ���2λ��Ӧ���ȼ�
	uart_init(9600);	 //���ڳ�ʼ��Ϊ9600
	setBeep(OFF);
	
	while(1)
	{
		u16 speed = 50;
		switch(USART_ReceiveData(USART1))
		{
			case 'F':	
				front(speed); //ǰ��
				break;
			case 'B':		
			  back(speed);  //����
				setBeep(ONOFF); //��������ʾ
				break;	
			case 'l': 
			  left(speed); //��ת
				break;
			case 'r': 
			  right(speed); //��ת
				break;
			case 'L': 
			  Lturn(speed); //������ǰ��ƽ��
				break;
			case 'R':
			  Rturn(speed); //������ǰ��ƽ��
			  break;
			case 'T':
			  Rtranslate(speed); //��ƽ��
			  break;
			case 'E':
			  Ltranslate(speed); //��ƽ��
			  break;
			case 'U':
			  RturnRound(speed); //˳ʱ����ת
			  break; 
			case 'N':
			  LturnRound(speed); //��ʱ����ת
			  break;
			case 'A':
				speed+=10;//����
				front(speed); //ǰ��
        //printf("%d",speed);
				break;
			case 'D':
			  speed-=10;     //����
				front(speed); //ǰ��
			  //printf("%d",speed);
				break;
			case 'S': 
				Stop();//STOP
				break;
			case 'W': 
				//����������
	      setBeep(ON);
				Stop();//STOP
				break;
	    case 'C':
				//��������
	      setBeep(OFF);
				break;
			default: 
				break;	
   }
 }
}
