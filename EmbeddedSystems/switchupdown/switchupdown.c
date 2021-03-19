#include <LPC17xx.h>

unsigned int i,j,c=0;
unsigned long LED = 0x00000010;

int main(void){
	LPC_PINCON->PINSEL0 &= 0xFF0000FF;
	LPC_GPIO0->FIODIR = 0x00000FF0;
	LPC_PINCON->PINSEL2 &=0xFFFFEFFF;
	LPC_GPIO2->FIODIR = 0x0;
	
	while(1)
	{
		LPC_GPIO0->FIOPIN=c<<4;
		if(LPC_GPIO2->FIOPIN & 1<<12)
		{
			c--;
		}
		else
		{
			c++;
		}
		
		if(c==-1)
		{
			c=0xFF;
		}
		if(c==0x100)
			c=0x00;
		for(j=0;j<100000;j++);
	}
	}