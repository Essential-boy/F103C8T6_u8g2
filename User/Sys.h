#ifndef _SYS_H__
#define _SYS_H__

#include "stm32f10x.h"                  // Device header
#include "SysTick.h"
#include "system.h"
#include "Delay.h"

#include "u8g2.h"
#include "OLED.h"
#include "usart.h"
#include "LED.h"
#include "Key.h"
#include "Menu.h"

uint8_t u8g2_gpio_and_delay_stm32(U8X8_UNUSED u8x8_t *u8x8, U8X8_UNUSED uint8_t msg, U8X8_UNUSED uint8_t arg_int, U8X8_UNUSED void *arg_ptr);
void Sys_Init(void);//º¯Êý³õÊ¼»¯

#endif
