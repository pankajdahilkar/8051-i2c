#ifndef __I2C_H_
#define __I2C_H_
#include "types.h"
#include <reg51.h>
sbit SDA =P2^1;
sbit SCL = P2^0;

void i2cStart(void);
void i2cStop(void);
void i2cRestart(void);
void i2cAck(void);
void i2cNoAck(void);
void i2cWrite(u8);
void i2cMasterAck(void);
u8 i2cRead(void);
void i2cDevWrite(u8,u8,u8);
u8 i2cDevRead(u8,u8);
void i2cPageWrite(u8,u8,u8 *,u8);
void i2cPageRead(u8,u8,u8 *,u8);
#endif
