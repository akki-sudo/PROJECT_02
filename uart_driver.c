#include<lpc21xx.h>
#include "header.h"
#define THRE ((U0LSR >> 5)&1)
#define RDR ((U0LSR >> 0)&1)

void uart0_init(unsigned int baud)
{ 
	unsigned int result =0;
	int a[] = {15,60,30,15,15};
	unsigned int pclk;
	pclk =a[VPBDIV]*1000000;
	result = pclk/(16 * baud);
	
	PINSEL0 |= 5;  //tx and rx enabled here tx --- 0 1(1,0) rx(3,2)--- 0 1;
	U0LCR = 0X83;//8 BIT WORD LENGTH AND BAUD UNLOCK;
	U0DLL = (result)& 0XFF;
	U0DLM = (result >> 8)& 0XFF;
	U0LCR = 0X03; // LOCK THE BAUD
}
  	
void uart0_tx(unsigned char data)
{
	U0THR = data;
	while(THRE == 0);// THRE becomes one means u0thr trans mit the data 
}

unsigned char uart0_rx(void)
{

	 while(RDR == 0);
	 return U0RBR;
}

void uart0_tx_string(char *str)
{
	while(*str)
	{
		U0THR =*str;
		while(THRE == 0);
		str++;
	}
}

void uart0_rx_string(unsigned char *ptr,int max_bytes)
{
	int i;
	for(i =0; i <= max_bytes ;i++)
	{
	 while(RDR == 0);
	 ptr[i] = U0RBR;
   if(ptr[i] == '\r')
   break;
  }
  ptr[i] = '\0';
}	
	
	
	
	
	
