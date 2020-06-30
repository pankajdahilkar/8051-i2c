 #include<reg51.h>
 #include "delay.h"
 #define keypd P1
 sbit c0=keypd^4;
 sbit c1=keypd^5;
 sbit c2=keypd^6;
 sbit c3=keypd^7;
 sbit r0=keypd^0;
 sbit r1=keypd^1;
 sbit r2=keypd^2;
 sbit r3=keypd^3;

char row_val,col_val; //
code char a[4][4]={{'0','1','2','3'},
									{'4','5','6','7'},
									{'8','9','A','B'},
									{'C','D','E','F'}};
 
 void Row_Init(void)
 {
 r0=r1=r2=r3=0;
 }

 char Colstatus(void)
 {
 return(c0&&c1&&c2&&c3);
 }

 char keyscan (void)
 {
 
 while(Colstatus());

 	 
 r0=0;
	 r1=r2=r3=1;
	 //delay_ms(10);
 if(!Colstatus())
 {
 row_val=0;
 goto colcheck;
 }

 r1=0;
 r0=r2=r3=1;
//  delay_ms(10);
 if(!Colstatus())
 {
 row_val=1;
 goto colcheck;
 }

 r2=0;
 r0=r1=r3=1;
 // delay_ms(10);
 if(!Colstatus())
 {
 row_val=2;
 goto colcheck;
 }

 	 r3=0;
 r0=r1=r2=1;
 // delay_ms(10);
 if(!Colstatus())
 {
 row_val=3;
 }

colcheck:
      if(c0==0)
	  col_val=0;
	  else if(c1==0)
	  col_val=1;
	  else if(c2==0)
	  col_val=2;
	  else
	  col_val=3;

	  while(!Colstatus());
	  return(a[row_val][col_val]);
	  }