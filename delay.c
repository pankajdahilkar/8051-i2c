#include"types.h"
#include"delay.h"

void delay_ms(u16 d)
{
u16 a;
for(;d>0;d--)
for(a=125;a>0;a--);
}
// Delay Period = [18 + (d-1)*8]
void delay_us(u8 d)
{
for(;d>0;d--);
}