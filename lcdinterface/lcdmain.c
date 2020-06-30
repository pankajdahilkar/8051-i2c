#include <reg51.h>
#include "lcd.h"

unsigned char custom_char[]= {0x00,0x04,0x0E,0x04,0x15,0x0E,0x04,0x00, 
	                      0x00,0x04,0x0E,0x0E,0x0E,0x1F,0x04,0x00, 
	                      0x00,0x0A,0x15,0x11,0x11,0x0A,0x04,0x00,
												0x0E,0x11,0x11,0x1F,0x1B,0x1B,0x1B,0x1F,
	                      0x0E,0x11,0x10,0x1F,0x1B,0x1B,0x1B,0x1F,
												0x00,0x0E,0x15,0x1B,0x0E,0x0E,0x00,0x00,
	                      };


void delay_ms(int ms)
{
	int i,j;
	for(i=0;i<=ms;i++)
	for(j=0;j<=1275;j++);
}

void lcd_init(void)
{
	lcd_cmd(0x38); // initialize lcd to 16*2 with 5*7 pixel
	lcd_cmd(0x0c); //Display on Cursor off
	lcd_cmd(0x01); //Clear Display (also clear DDRAM content)
	lcd_cmd(0x80); //Set DDRAM address or coursor position on display
}

void lcd_cmd(char ch)
{
	LCD = ch;
	rs=0;
	en=1;
	delay_ms(1);
	en=0;
}

void lcd_display(char ch)
{
	LCD = ch;
	rs=1;
	en=1;
	delay_ms(1);
	en=0;
}

void lcd_string (char *ptr)
{
	while(*ptr)
	{
		lcd_display(*ptr++);
	}
}

void lcd_custom(void)
{
	int i;
	lcd_cmd(0x40);
	for(i=0;i<48;i++)
	lcd_display(custom_char[i]);
	lcd_cmd(0x80);
}

