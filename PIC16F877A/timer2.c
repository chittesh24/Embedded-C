#include<pic.h>
int main()
{
	TRISB=0x00;
	PORTB=0x00;
	T2CON=0x7F;
	TMR2=0x00;
	PR2=100;
	int count=0;
	while(1)
	{
		while(!TMR2IF);
		TMR2IF=0;
		count++;
		if(count==977)
		{
			PORTB=~PORTB;
			count=0;
		}
	}
}