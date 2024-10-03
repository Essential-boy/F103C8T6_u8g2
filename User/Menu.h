#ifndef _MENU_H
#define _MENU_H	

#define uchar unsigned char
extern u8g2_t u8g2;
typedef struct
{
	uchar current;
	uchar up;//向上翻索引号
	uchar down;//向下翻索引号
	uchar enter;//确认索引号
	void (*current_operation)();
} key_table;

extern key_table table[30];

extern void fun_0(); 

extern void fun_a1(); 
extern void fun_b1();  
extern void fun_c1();  
extern void fun_d1();  

extern void fun_a21(); 
extern void fun_a22();  
extern void fun_a23();  
extern void fun_a24();  

extern void fun_b21(); 
extern void fun_b22();  
extern void fun_b23();  
extern void fun_b24(); 

extern void fun_c21(); 
extern void fun_c22();  
extern void fun_c23();  
extern void fun_c24();  

extern void fun_a31(); 
extern void fun_a32();  
extern void fun_a33();  

extern void fun_b31(); 
extern void fun_b32();  
extern void fun_b33(); 

extern void fun_c31(); 
extern void fun_c32();  
extern void fun_c33(); 
  
#endif
