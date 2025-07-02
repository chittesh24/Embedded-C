#include<pic.h>
int main()
{
	TRISB=0x00;
	PORTB=0x00;
	T1CON=0x31;
	TMR1L=0x00;
	TMR1H=0x00;
	int count=0;
	while(1)
	{
		while(!TMR1IF);
		TMR1IF=0;
		count++;
		if(count==47)
		{
			PORTB=~PORTB;
			count=0;
		}
	}
}