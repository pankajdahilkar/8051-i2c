#ifndef __RTC_H_
#define __RTC_H_
#include "types.h"

u8 bcd_to_byte (u8 bcd);
u8 byte_to_bcd (u8 byte);
void RTC_Set_Time(u8 hrs,u8 min,u8 sec);
void RTC_Set_Date(u8 date,u8 month,u8 year);
void RTC_Read_Date(u8 *);
void RTC_Read_Time(u8 *);
void set_alarm(u8 hr , u8 min);
u8 check_alarm(u8 rtc_hr,u8 rtc_min);

#endif
