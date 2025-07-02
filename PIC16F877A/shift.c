#include<pic.h>
void delay(unsigned int x)
{
	while(x--);
}
void main()
{
	int k=0x01;
	TRISB=0x00;
	PORTB=0x00;
	while(1)
	{
		for(k=0x80;k>=0x01;k=k>>1)
		{
			PORTB=k;
			delay(65000);
		}
	}
}