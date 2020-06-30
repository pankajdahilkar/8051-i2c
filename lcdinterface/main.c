#include <reg51.h>
#include "lcd.h"
void main()
{
	lcd_init();
	lcd_custom();
	lcd_string (" MONALI ");
	lcd_cmd(0xc0); //Force cursor to beginning of second line
	lcd_string (" KATHANE ");
	delay_ms(1000);
	lcd_cmd(0x01); //Clear Display (also clear DDRAM content)
	lcd_cmd(0x80); //Set DDRAM address or coursor position on display
	lcd_string (" BHARAT ELECTRONICS LIMITED ");
	lcd_cmd(0xc0); //Force cursor to beginning of second line
	lcd_string (" ON LCD 16*2 ");
	delay_ms(1000);
	while(1);
}