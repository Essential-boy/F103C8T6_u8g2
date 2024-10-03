/*
��������˵�� 
OLED��SCL SDA �ֱ�ΪPB6 PB7
UART��TX RX���ŷֱ�Ϊ PA9 PA10 ������115200
��u8g2�����0.96''OLED�����

*/

#include "Sys.h"

u8g2_t u8g2;
uint8_t count = 0;

void (*current_operation_index)();
uchar func_index = 0; //��ʼ��ʾ��ӭ����
uchar last_index = 127; //last��ʼΪ��Чֵ

int main(void)
{
	Sys_Init();
	u8g2_SetFontMode(&u8g2, 1);
	u8g2_ClearBuffer(&u8g2);
	/*�ֿ�ѡ��*/
	u8g2_SetFont(&u8g2,u8g2_font_unifont_t_symbols);
//	u8g2_SetFont(&u8g2,u8g2_font_ncenB14_tf);
//	u8g2_SetFont(&u8g2, u8g2_font_inb24_mf); 
//	u8g2_SetFont(&u8g2, u8g2_font_inb30_mn);
//	u8g2_SetFont(&u8g2, u8g2_font_4x6_tr);
///	u8g2_SetFont(&u8g2,u8g2_font_helvR08_tr);	
//	u8g2_SetFont(&u8g2,u8g2_font_wqy12_t_gb2312); //??????�д�

//	u8g2_DrawLine(&u8g2, 0,0, 127, 63);//���ߣ�ǰ��λΪ���ĺ������꣬����λΪ�յ�ĺ�������
//	u8g2_DrawLine(&u8g2, 127,0 , 0,63);
//	u8g2_DrawBox(&u8g2, 0, 0, 10,10);//��ʵ�ķ���
//	u8g2_DrawCircle(&u8g2, 18, 5, 5,U8G2_DRAW_ALL);//������Բ
//	u8g2_DrawDisc(&u8g2,30, 35, 10, U8G2_DRAW_ALL);//��ʵ��Բ
//	u8g2_DrawEllipse(&u8g2,50, 45, 15, 10, U8G2_DRAW_ALL);//������Բ
//	u8g2_DrawFilledEllipse(&u8g2,80, 45, 15, 10, U8G2_DRAW_ALL);//ʵ����Բ
//	u8g2_DrawFrame(&u8g2,3,7,25,15);//���ĳ�����

//	u8g2_DrawStr(&u8g2,1,30,"Hello World!");
//	u8g2_DrawButtonUTF8(&u8g2,72, 20, U8G2_BTN_BW1, 0, 2, 2, "Btn" ); 
//	u8g2_DrawGlyph(&u8g2,30, 20, 0x2603);
//	u8g2_DrawUTF8(&u8g2,30, 20, "WOC");
//  u8g2_DrawStr(&u8g2, 1,54,"github.com/olikraus/u8g2");
//	Draw_u8g2(&u8g2);
//	u8g2_SendBuffer(&u8g2);
//	Delay_ms(1000);
	while (1)
	{
//		OLED_ShowImage(0,0,64, 64, kunkun[count++/10]);
//		OLED_ShowImage(64,0,64, 64, kunkun[count++/10]);
//		count %= 130;
//		OLED_Update();
		if((KEY1==0)||(KEY2==0)||(KEY3==0))
		{
			delay_ms(10);//����
			if(KEY1==0)
			{
				func_index = table[func_index].up;    //���Ϸ�
				while(!KEY1);//���ּ��
			}
			if(KEY2==0)
			{
				func_index = table[func_index].down;    //���·�
				while(!KEY2);
			}
			if(KEY3==0)
			{
				func_index = table[func_index].enter;    //ȷ��
				while(!KEY3);
			}
		}
		if (func_index != last_index)
		{
			current_operation_index = table[func_index].current_operation;
			u8g2_ClearBuffer(&u8g2); 
			(*current_operation_index)();//ִ�е�ǰ��������
			u8g2_SendBuffer(&u8g2);
			last_index = func_index;
		}
	}
}
