#include "Sys.h"

uint8_t u8g2_gpio_and_delay_stm32(U8X8_UNUSED u8x8_t *u8x8, U8X8_UNUSED uint8_t msg, U8X8_UNUSED uint8_t arg_int, U8X8_UNUSED void *arg_ptr)
{
	switch(msg)
		{

		case U8X8_MSG_DELAY_MILLI:
				Delay_ms(arg_int);
		break;
		
		case U8X8_MSG_DELAY_10MICRO:
				Delay_us(10);
		break;

		case U8X8_MSG_DELAY_100NANO:
			__NOP();
		break;
		
		case U8X8_MSG_GPIO_I2C_CLOCK:
				if (arg_int) 
					I2C_OLED_SCL_HIGH();
				else 
					I2C_OLED_SCL_LOW();
		break;
		
		case U8X8_MSG_GPIO_I2C_DATA:
				if (arg_int) 
					I2C_OLED_SDA_HIGH();
				else 
					I2C_OLED_SDA_LOW();
		break;
		
		case U8X8_MSG_GPIO_MENU_SELECT:
        u8x8_SetGPIOResult(u8x8, /* get menu select pin state */ 0);
        break;
		
		case U8X8_MSG_GPIO_MENU_NEXT:
        u8x8_SetGPIOResult(u8x8, /* get menu next pin state */ 0);
        break;
		
		case U8X8_MSG_GPIO_MENU_PREV:
        u8x8_SetGPIOResult(u8x8, /* get menu prev pin state */ 0);
        break;
		
		case U8X8_MSG_GPIO_MENU_HOME:
        u8x8_SetGPIOResult(u8x8, /* get menu home pin state */ 0);
        break;
		
		default:
        u8x8_SetGPIOResult(u8x8, 1); // default return value
        break;
	}
	return 1; 
}

void Draw_u8g2(u8g2_t *u8g2)
{
	u8g2_ClearBuffer(u8g2); 
	u8g2_SetFontMode(u8g2, 1); 
	u8g2_SetFontDirection(u8g2, 0); 
	u8g2_SetFont(u8g2, u8g2_font_inb24_mf);
	u8g2_DrawStr(u8g2, 0, 20, "U");

	u8g2_SetFontDirection(u8g2, 1);
	u8g2_SetFont(u8g2, u8g2_font_inb30_mn);
	u8g2_DrawStr(u8g2, 21,8,"8");

	u8g2_SetFontDirection(u8g2, 0);
	u8g2_SetFont(u8g2, u8g2_font_inb24_mf);
	u8g2_DrawStr(u8g2, 51,30,"g");
	u8g2_DrawStr(u8g2, 67,30,"\xb2");

	u8g2_DrawHLine(u8g2, 2, 35, 47);
	u8g2_DrawHLine(u8g2, 3, 36, 47);
	u8g2_DrawVLine(u8g2, 45, 32, 12);
	u8g2_DrawVLine(u8g2, 46, 33, 12);

	u8g2_SetFont(u8g2, u8g2_font_4x6_tr);
	u8g2_DrawStr(u8g2, 1,54,"github.com/olikraus/u8g2");

	u8g2_SendBuffer(u8g2);
	Delay_ms(1000);
}

void u8g2_init()
{
	u8g2_Setup_ssd1306_i2c_128x64_noname_f(&u8g2, U8G2_R0, u8x8_byte_sw_i2c, u8g2_gpio_and_delay_stm32);
	u8g2_InitDisplay(&u8g2); // 根据所选的芯片进行初始化工作，初始化完成后，显示器处于关闭状态
	u8g2_SetPowerSave(&u8g2, 0); // 开启显示
}

void Sys_Init()
{
	u8g2_init();
	OLED_Init();
	Key_Init();
	LED_Init();
	USART1_Init(115200);
}

