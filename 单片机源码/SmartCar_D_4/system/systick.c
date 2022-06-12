#include "systick.h"
u32 delay_fac_ms;
u32 delay_fac_us;
void systick_init(void)
{
    SysTick_CLKSourceConfig(SysTick_CLKSource_HCLK_Div8); //系统时钟8分频
    delay_fac_us=SystemCoreClock/8000000;//
    delay_fac_ms=SystemCoreClock/8000; //
}

void delay_ms(uint32_t i)
{
    uint32_t temp;
    SysTick->LOAD=delay_fac_ms*i;      //设置重装载值 ，72MHZ时
    SysTick->CTRL=0X01;        //使能，减到零时无动作，采用外部时钟源
  	SysTick->VAL=0;            //计数器清零
    do
    {
        temp=SysTick->CTRL;       //
    }
    while((temp&0x01)&&(!(temp&(1<<16))));    //等待时间到达
    SysTick->CTRL=0;    //关闭计数器
    SysTick->VAL=0;     //清零计数器
}

void delay_us(uint32_t i)
{
    uint32_t temp;
    SysTick->LOAD=delay_fac_us*i;      //设置重装载值 ，72MHZ时
    SysTick->CTRL=0X01;        //使能，减到零时无动作，采用外部时钟源
  	SysTick->VAL=0;            //计数器清零
    do
    {
        temp=SysTick->CTRL;       //
    }
    while((temp&0x01)&&(!(temp&(1<<16))));    //等待时间到达
    SysTick->CTRL=0;    //关闭计数器
    SysTick->VAL=0;     //清零计数器
}
