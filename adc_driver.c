#include<lpc21xx.h>
#include "header.h"

void adc_init()
{
	PINSEL1 |= 0X15200000 ;// P0.27 P0.28 PO.29 PO.30(AIN0,1,2,3)
	ADCR = 0X00200400;//dis select channel
	                  // adc clock 3mhz
	                  // brust mode is off 
	                  // 10 bit resolution 
	                  //power down mode is cancelled 
                    //stop adc 
}

#define DONE ((ADCR >> 31) & 1)
unsigned short int adc_read(unsigned char ch_num)
{     
	    unsigned short int result  = 0;
	    ADCR |=(1 << ch_num);// select channel 
	    ADCR |=(1<<24);//START adc
	    while(DONE==0);
	    ADCR ^= (1<<24);
	    result = (ADDR >> 6) & 0x3FF;//extract the data
	    ADCR ^=(1 << ch_num);//diselect channel number
	    return result;
}
	
	     
	
	