#include<pic.h>
void delay (unsigned int x)
{
	while(x--);
}
void main()
{
	TRISB=0x00;
	PORTB=0X00;
	while(1)
	{
		PORTB=0XFF;
		delay(65000);
		PORTB=0X00;
		delay(65000);
	}
}