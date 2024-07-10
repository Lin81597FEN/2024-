#ifndef LED_H
#define LED_H

#include "stm32f4xx_rcc.h"
#include "stm32f4xx_gpio.h"


void Led_Config(void);
void LED0(uint16_t x);
void LED1(uint16_t x);
#endif

