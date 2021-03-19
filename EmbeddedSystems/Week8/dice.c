#include<LPC17xx.h>
#include <stdlib.h> 
#include"lcd_disp.h"
unsigned char Msg[]="Press key";
int main()
{
	unsigned char num;
	lcd_init();
	temp1=0x80;
	lcd_com(800);
	lcd_puts(&Msg[0]);
	while(1)
	{
		if(!(LPC_GPIO2->FIOPIN & 1<<12))
		{
			temp1=0xC0;
			lcd_com(800);
			num = (rand() % 6) + 1;
			num+=0x30;
			lcd_puts(&num);
		}
	}
}