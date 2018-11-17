#include<reg51.h>
#include "types.h"
#include "defines.h"
#include "delay.h"
#include "i2c.h"
void i2cStart(void)
{
SDA =1;
SCL=1;
SDA=0;
}

void i2cWrite(u8 d)
{
u8 i;
for(i=0;i<8;i++)
{
SCL =0;
SDA = d&(0x80>>i)?1:0;
SCL=1;
}
}

void i2cAck(void)
{
SCL=0;
SDA=1;
SCL=1;
while(SDA);
}
void i2cStop(void)
{
SCL=0;
SDA=0;
SCL=1;
SDA=1;
}
void i2cRestart(void)
{
SCL=0;
SDA=1;
SCL=1;
SDA=0;
}

void i2cNoAck(void)
{
SCL=0;
SDA=1;
SCL=1;
}

void i2cMasterAck(void)
{
SCL=0;
SDA=0;
SCL=1;
SCL=0;
SDA=1;
}

u8 i2cRead(void )
{
 u8 i;
 u8 buff=0;
 for(i=0;i<8;i++)
 {
 SCL=0;
 SCL=1;
 if(SDA) buff |=0x80>>i;
 }
 return buff;
}

void i2cDevWrite(u8 slaveAddr,u8 buffAddr,u8 dat)
{
i2cStart();
i2cWrite(slaveAddr);
i2cAck();
i2cWrite(buffAddr);
i2cAck();
i2cWrite(dat);
i2cAck();
i2cStop();
delay_ms(10);
}

u8 i2cDevRead(u8 slaveAddr,u8 buffAddr)
{
	u8 buff;
	i2cStart();
	i2cWrite(slaveAddr);
	i2cAck();
	i2cWrite(buffAddr);
	i2cAck();
	i2cRestart();
	i2cWrite(slaveAddr|1);
	i2cAck();
	buff=i2cRead();
	i2cNoAck();
	i2cStop();
	return buff;
	
}

void i2cDevPageWrite(u8 slaveAddr,u8 buffStartAddr,u8 *str,u8 size)
{
	u8 i;
	i2cStart();
	i2cWrite(slaveAddr);
	i2cAck();
	i2cWrite(buffStartAddr);
	i2cAck();
	for(i=0;i<size;i++)
	{
		i2cWrite(*str++);
		i2cAck();
	}
	i2cStop();
	delay_ms(10);
}

void i2cDevPageRead(u8 slaveAddr,u8 buffStartAddr,u8 *str,u8 size)
{
	u8 i;
	i2cStart();
	i2cWrite(slaveAddr);
	i2cAck();
	i2cWrite(buffStartAddr);
	i2cAck();
	i2cRestart();
	i2cWrite(slaveAddr|1);
	i2cAck();
	for(i=0;i<size-1;i++)
	{
		str[i]=i2cRead();
		i2cMasterAck();
	}
	str[i++] =i2cRead();
	str[i]='\0';
	i2cNoAck();
	i2cStop();
}



































