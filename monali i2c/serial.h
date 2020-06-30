#ifndef __SERIAL_H_
#define __SERIAL_H_

void init_UART();
void Tx_CHAR(char ch);
char Rx_char();
void send_string(char *ptr);
void Tx_int(int val);
#endif