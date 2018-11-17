#ifndef __I2C_H_
#define __I2C_H_
void i2cStart(void);
void i2cRestart(void);
void i2cWrite(u8);
void i2cAck(void);
void i2cNoAck(void);
void i2cStop(void);
void i2cMasterAck(void);
u8 i2cRead(void);
void i2cDevWrite(u8,u8,u8);
u8 i2cDevRead(u8,u8);
void i2cDevPageWrite(u8,u8,u8 *,u8);
void i2cDevPageRead(u8,u8,u8 *,u8);
#endif
