#include "systick.h"
u32 delay_fac_ms;
u32 delay_fac_us;
void systick_init(void)
{
    SysTick_CLKSourceConfig(SysTick_CLKSource_HCLK_Div8); //ϵͳʱ��8��Ƶ
    delay_fac_us=SystemCoreClock/8000000;//
    delay_fac_ms=SystemCoreClock/8000; //
}

void delay_ms(uint32_t i)
{
    uint32_t temp;
    SysTick->LOAD=delay_fac_ms*i;      //������װ��ֵ ��72MHZʱ
    SysTick->CTRL=0X01;        //ʹ�ܣ�������ʱ�޶����������ⲿʱ��Դ
  	SysTick->VAL=0;            //����������
    do
    {
        temp=SysTick->CTRL;       //
    }
    while((temp&0x01)&&(!(temp&(1<<16))));    //�ȴ�ʱ�䵽��
    SysTick->CTRL=0;    //�رռ�����
    SysTick->VAL=0;     //���������
}

void delay_us(uint32_t i)
{
    uint32_t temp;
    SysTick->LOAD=delay_fac_us*i;      //������װ��ֵ ��72MHZʱ
    SysTick->CTRL=0X01;        //ʹ�ܣ�������ʱ�޶����������ⲿʱ��Դ
  	SysTick->VAL=0;            //����������
    do
    {
        temp=SysTick->CTRL;       //
    }
    while((temp&0x01)&&(!(temp&(1<<16))));    //�ȴ�ʱ�䵽��
    SysTick->CTRL=0;    //�رռ�����
    SysTick->VAL=0;     //���������
}
