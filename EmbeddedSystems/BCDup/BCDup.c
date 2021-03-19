#include <LPC17xx.h>
#define First_seg 0<<23
#define Second_seg 1<<23
#define Third_seg 2<<23
#define Fourth_seg 3<<23
unsigned int i;
unsigned int dig1 = 0x00, dig2 = 0x00, dig3 =0x00, dig4 = 0x00;
unsigned int dig_count = 0x00, temp1 = 0x00, one_sec_fly =0x00;
unsigned int array_dec[10] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};
unsigned int temp2 = 0x00;

void delay(void);
void display(void);

int main(void)
{
	LPC_GPIO0->FIODIR = 0xFF<<4;
	LPC_GPIO1->FIODIR = 15<<23;
	
	while(1)
	{
		delay();
		dig_count++;
		if(dig_count == 5)
		{
			delay();
			dig_count = 1;
			one_sec_fly = 0xFF;
		}
		if(one_sec_fly == 0xFF)
		{
			one_sec_fly = 0x00;
			dig1++;
			if(dig1 == 0x0A)
			{
				dig1 = 0;
				dig2++;
				if(dig2 == 0x0A)
				{
					dig2 = 0;
					dig3++;
					if(dig3 == 0x0A)
					{
						dig3 = 0;
						dig4++;
						if(dig4 == 0x0A)
						{
							dig4 = 0;
						}
					}
				}
			}
		}
		display();
	}
}

void display(void)
{
	if(dig_count == 0x01)
	{
		temp1 = dig1;
		LPC_GPIO1->FIOPIN = First_seg;
	}
	else if(dig_count == 0x02)
	{
		temp1 = dig2;
		LPC_GPIO1->FIOPIN = Second_seg;
	}
	else if(dig_count == 0x03)
	{
		temp1 = dig3;
		LPC_GPIO1->FIOPIN = Third_seg;
	}
	else if(dig_count == 0x04)
	{
		temp1 = dig4;
		LPC_GPIO1->FIOPIN = Fourth_seg;
	}
	
	temp1 &= 0x0F;
	temp2 = array_dec[temp1];
	temp2 <<= 4;
	LPC_GPIO0->FIOPIN = temp2;
	for(i = 0; i<5000; i++);
	LPC_GPIO0->FIOCLR = 0x00000FF0;
}

void delay(void)
{
	for(i = 0; i<10000; i++);
}