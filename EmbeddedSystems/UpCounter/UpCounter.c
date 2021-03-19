#include <LPC17xx.h>
unsigned int i, j, c=0;

int main()
{
	SystemInit();
	SystemCoreClockUpdate();
	
	//LPC_PINCON->PINSEL0 &= 0xFF0000FF;
	
	LPC_GPIO0->FIODIR |= 0x00000FF0;
	
	while(1)
	{
		c++;
		LPC_GPIO0->FIOPIN = c<<4;
		for(i=0;i<100000; i++);
		if(c==0xff)
			c=0;
	}
}