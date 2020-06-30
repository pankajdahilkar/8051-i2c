#ifndef __LCD_H_
#define __LCD_H_


#define LCD P0
sbit rs = P3^2;
sbit en = P3^3;
void delay_ms(int ms);
void lcd_init(void);
void lcd_cmd(char ch);
void lcd_display(char ch);
void lcd_string (char *ptr);
void lcd_custom(void);
void lcd_int(int num);

#endif