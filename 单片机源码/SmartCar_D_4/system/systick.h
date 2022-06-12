#ifndef __SYSTICK_H
#define __SYSTICK_H	 
#include "stm32f10x.h"                  // Device header
#include "stm32f10x_rcc.h"              // Keil::Device:StdPeriph Drivers:RCC
void systick_init(void);
void delay_ms(uint32_t i);
void delay_us(uint32_t i);
#endif
