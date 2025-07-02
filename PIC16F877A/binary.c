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
		for(int i=0x00;i<=0xff;i++)
		{
			PORTB=i;
			delay(65000);
		}
	}
}
