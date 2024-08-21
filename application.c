#include<lpc21xx.h>
#include "header.h"
#include<stdio.h>
#include<stdlib.h>



int main()
{
	int v_out,temp;
	char buf[10];
	unsigned short int  result = 0;
	char flag = 1;
	uart0_init(9600);
	uart0_tx_string("loading...........\r\n");
	adc_init();
	
	while(1)
	{
		if(flag)
		{
		uart0_tx_string("waiting for connection....\n");
		delay_msec(200);
		flag = 0;
		}
		result = adc_read(1);//1o bit resolution;
		//srand(getpid());
		//result = rand() % 100;
		
		v_out = ( result * 3.3 )/1023;
    		
		temp = (v_out - 0.50)/0.01;
		uart0_tx_string("temperature : ");
		sprintf(buf,"%d",temp);
		uart0_tx_string(buf);

    if(temp > 30)
		{
			uart0_tx_string("alert temp is high\r\n");
			uart0_tx_string("\tI will make u cool now\r\n");
			
			IOCLR0 = 1 << 12;// This pin is connected to AC to TURN ON.		
		}
		else if(temp < 30)
		{
			uart0_tx_string("\t I will turn off the AC\r\n");
			IOSET0 = 1 << 12;
		}
		delay_msec(200);
		uart0_tx_string("\r\n");
	}
}




