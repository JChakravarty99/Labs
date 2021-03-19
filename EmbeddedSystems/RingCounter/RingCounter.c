#include <LPC17xx.h>
unsigned int i, j, c=1;

int main()
{
	SystemInit();
	SystemCoreClockUpdate();
	
	//LPC_PINCON->PINSEL0 &= 0xFF0000FF;
	
	LPC_GPIO0->FIODIR |= 0x00000FF0;
	
	while(1)
	{
		LPC_GPIO0->FIOPIN = c<<4;
		c<<=1;
		for(i=0;i<30000; i++);
		if(c==0x800)
			c=1;
	}
}