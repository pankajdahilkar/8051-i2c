#include <reg51.h>
#include "i2c.h"
#include "delay.h"
#include "types.h"
#include "RTC.h"

void init_UART()
{
	SCON = 0x50;
	TMOD = 0x20;
	TH1  = 0XFD;
	TR1  = 1;
	
}

void Tx_CHAR(char ch)
{
	SBUF = ch;
	while(TI==0);
	TI=0;
}

char Rx_char()
{
	char ci;
	
	while(RI==0);
	ci=SBUF;
	RI=0;
	return ci;
}

void send_string(char *ptr)
{
	while(*ptr!='\0')
	{
		Tx_CHAR(*ptr);
		ptr++;
	}	
		
}

void Tx_int(int val)
{
char Tx_data[3];
	Tx_data[0] = (val/10) + 48;
	Tx_data[1] = (val%10) + 48;
	Tx_data[2] = '\0';
	send_string(Tx_data);
}