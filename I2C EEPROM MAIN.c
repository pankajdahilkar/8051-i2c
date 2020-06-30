#include<reg51.h>
#include "types.h"
#include "delay.h"
#include "i2c.h"
sbit led = P2^2;
main()
{
 u8 i=0x68;
 u8 t;
 u8 name[7];
 led=0;
 i2cDevWrite(0xa0,i,'C');
 delay_ms(100);
	
	i2cDevPageWrite(0xa0,0x00,"pankaj dahilkar",15);
 t=i2cDevRead(0xa0,i);
	delay_ms(100);
	i2cDevPageRead(0xa0,0x00,name,7);
 if(t=='C')
 led=1;
 while(1);
}