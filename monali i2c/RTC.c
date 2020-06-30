#include <reg51.h>
#include "RTC.h"
#include "types.h"
#include "i2c.h"
#define RTC_ADDR 0xD0

u8 hr_alarm, min_alarm;

u8 bcd_to_byte(u8 bcd)
{
	u8 a,b;
	a = (bcd>>4);
	a  = a * 10;
	b = (bcd & 0x0F);
	return (a+b);
}

u8 byte_to_bcd(u8 byte)
{
	u8 a,b;
	a = byte/10;
	b = byte%10;
	a = ((a << 4) +b);
  return a; 
}


void RTC_Set_Time(u8 hrs,u8 min,u8 sec)
{
	u8 hr,m,s;
	
	hr = byte_to_bcd(hrs);
	m = byte_to_bcd(min);
	s = byte_to_bcd(sec);
	
	i2cDevWrite(RTC_ADDR,0x00,s);
	i2cDevWrite(RTC_ADDR,0x01,m);
	i2cDevWrite(RTC_ADDR,0x02,hr);
}

void RTC_Set_Date(u8 date,u8 month,u8 year)
{
	u8 dt,mnth,yr;
	dt = byte_to_bcd(date);
	mnth = byte_to_bcd(month);
	yr = byte_to_bcd (year);
	
	i2cDevWrite(RTC_ADDR,0x04,dt);
	i2cDevWrite(RTC_ADDR,0x05,mnth);
	i2cDevWrite(RTC_ADDR,0x06,yr);
}

void RTC_Read_Time(u8 *Time)
{
	u8 hr,min,sec;
	
	hr = i2cDevRead(RTC_ADDR,0x02);
	min = i2cDevRead(RTC_ADDR,0x01);
	sec = i2cDevRead(RTC_ADDR,0x00);
	
	Time[0] = bcd_to_byte(hr);
	Time[1] = bcd_to_byte(min);
	Time[2] = bcd_to_byte(sec);
}


void RTC_Read_Date(u8 *Date)
{
	u8 dt,mnth,yr;
	dt = i2cDevRead(RTC_ADDR,0x04);
	mnth = i2cDevRead(RTC_ADDR,0x05);
	yr = i2cDevRead(RTC_ADDR,0x06);	
	Date[0] = bcd_to_byte(dt);
	Date[1] = bcd_to_byte(mnth);
	Date[2] = bcd_to_byte(yr);
}

void set_alarm(u8 hr , u8 min)
{
hr_alarm = hr;
min_alarm = min;	
}

u8 check_alarm(u8 rtc_hr,u8 rtc_min)
{
	if((rtc_hr==hr_alarm)&&(rtc_min==min_alarm))
	{
		return 1;
	}
	  return 0;
}