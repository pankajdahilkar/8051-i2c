#include "delay.h"
#include "types.h"

void delay_ms(u16 d_ms)
{
	u8 j;
	for(;d_ms>0;d_ms--)
	for(j=125;j>0;j--);
}

void delay_us(u8 d_us)
{
	for(;d_us>0;d_us--);
}