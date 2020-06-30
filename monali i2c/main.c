#include <reg51.h>
#include "i2c.h"
#include "delay.h"
#include "types.h"
#include "RTC.h"
#include "serial.h"
#include "stdlib.h"
#include "lcd.h"
#include "keypad.h"
sbit led = P2^2;

void main()
{
	u8 key1;
	u8 addr = 0x66;
	u8 data_c = 0;
	u8 byte_data = 45;
	u8 bcd_data  ;
	u8 name[10];
	u8 Date_1[3];
	u8 Time_1[3];
	 init_UART();
	 lcd_init();
	 lcd_cmd(0x01);
	 lcd_cmd(0x80);
	lcd_string(" WELCOM ");
	lcd_cmd(0xc0);
	lcd_string(" TO CLOCK ");
	delay_ms(100);
	RTC_Set_Time(18,04,55);
	RTC_Set_Date(26,06,20);
	send_string("Time = \0");
	set_alarm(18,05);
	
	
	while(1)
	{
		//led =0;
		Row_Init();
   key1=keyscan();
		lcd_cmd(0x01);
		lcd_cmd(0x80);
   lcd_display(key1);
	//	delay_ms(100);
	/*
		RTC_Read_Time(Time_1);
	RTC_Read_Date(Date_1);
	  send_string("Time = \0");
		Tx_int(Time_1[0]);
		Tx_CHAR(':');
		Tx_int(Time_1[1]);
		Tx_CHAR(':');
		Tx_int(Time_1[2]);
		Tx_CHAR(' ');
		send_string("Date = \0");
		Tx_int(Date_1[0]);
		Tx_CHAR('-');
		Tx_int(Date_1[1]);
		Tx_CHAR('-');
		Tx_int(Date_1[2]);
		Tx_CHAR('\r');
		Tx_CHAR('\n');
		lcd_cmd(0x01);
		lcd_cmd(0x80);
		lcd_string("Time=");
		lcd_int(Time_1[0]);
		lcd_display(':');
		lcd_int(Time_1[1]);
		lcd_display(':');
		lcd_int(Time_1[2]);
		
		lcd_cmd(0xc0);
		lcd_string("Date=");
		lcd_int(Date_1[0]);
		lcd_display('-');
		lcd_int(Date_1[1]);
		lcd_display('-');
		lcd_int(Date_1[2]+2000);
			delay_ms(100);
	if(check_alarm(Time_1[0],Time_1[1]))
	{
		led=1;
	  lcd_cmd(0x01);
		lcd_cmd(0x80);
	lcd_string("Alarm Time :");
	delay_ms(500);
	}
	else
		led=0;
			
		delay_ms(400);
		//led =1;
	//	delay_ms(400);
	*/
	}
}