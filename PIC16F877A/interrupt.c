#include<pic.h>
void interrrupt isr()
{
	if(TMR0TF==1)
	{
		TMR0TF=0;
		count++;
		if(count==76)
		{
			sec++;
			count=0;
		}
	}
}
int main()
{
	char count=0;
	short int sec=0;
	TRISC0=1;
	TRISC1=0;
	TRISB=0x00;
	TMR0=0x00;
	OPTION=0x07;
	TMRIE=1;
	GIE=1;
	while(1)
	{
		if(RC0==1)
		{
			RC1=~RC1;
		}
		if(sec==5)
		{
			PORTB=~PORTB;
			sec=0;
		}
	}
}