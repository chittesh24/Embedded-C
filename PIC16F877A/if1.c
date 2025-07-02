#include<pic.h>
void delay(unsigned int x)
{
	while(x--);
}
int main()
{
	TRISB=0x00;
	PORTB=0x00;
	while(1)
	{
		if(RB0==1||RB1==1)
		{
			RB4=1;
			delay(65000);
			RB5=1;
			delay(65000);
		}
		if(RB3==1||RB2==1)
		{
			RB6=1;
			delay(65000);
			RB7=1;
			delay(65000);
		}
	}
}