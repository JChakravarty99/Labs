#include <LPC17xx.h>
unsigned int i, j;
unsigned long LED = 0x00000010;

int main()
{
	SystemInit();
	SystemCoreClockUpdate();
	
	LPC_PINCON->PINSEL0 &= 0xFF0000FF;
	LPC_GPIO0->FIODIR = 0x00000FF0;
	LPC_PINCON->PINSEL2 &=0xFFFFEFFF;
	LPC_GPIO2->FIODIR = 0x0;	
	
	while(1)
	{
		if(LPC_GPIO2->FIOPIN & 1<<12)               //Pressed
		{
				LED = 0x00000010;
				for(i = 1; i<9; i++)
				{
					LPC_GPIO0->FIOSET = LED;
					for(j = 0; j<10000; j++);
					LED<<=1;
				}
				LED = 0X00000010;
		
				for(i = 1; i<9; i++)
				{
					LPC_GPIO0->FIOCLR = LED;
					for(j = 0; j<10000; j++);
					LED<<=1;
				}
		}	
		else
		{
				LPC_GPIO0->FIOPIN = 0;
				continue;
		}
	}
}