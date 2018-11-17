#include<reg51.h>
#include"types.h"
#include "delay.h"
#include "i2c.h"
sbit led = P2^2;
main()
{
 u8 i=0x70,t;
 led=0;
 i2cDevWrite(0xa0,i,'B');
 delay_ms(100);
 t=i2cDevRead(0xa0,i);
 if(t=='B')
 led=1;
 while(1);
}