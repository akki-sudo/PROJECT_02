#include<lpc21xx.h>

void delay_sec(unsigned int sec)
{
	//int a[] = {15,60,30,15,15};
	//unsigned int pclk = a[VPBDIV]*1000000;
	
	T0PC = 0;//starting point value of timer
	T0PR = 15000000 -1;//ending point value of timer
	T0TC = 0;//monitoring the condition 
	
	T0TCR = 1;//start the timer 
	while( T0TC  < sec);
	T0TCR = 0;//stop the timer 
}
void delay_msec(unsigned int ms)
{
	//int a[] = {15,60,30,15,15};
	//unsigned int pclk = a[VPBDIV]*1000000;
	
	T0PC = 0;//starting point value of timer
	T0PR = 15000 -1;//ending point value of timer
	T0TC = 0;//monitoring the condition 
	
	T0TCR = 1;//start the timer 
	while( T0TC  < ms);
	T0TCR = 0;//stop the timer 
}
