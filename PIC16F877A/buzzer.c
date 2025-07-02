#include<pic.h>
int main()
{
	int count=0;
	TRISB=0x00;
	PORTB=0x00;
	T1CON=0x31;
	TMR1L=0x00;
	TMR1H=0x00;
	while(count<9)
	{
            while(!TMR1IF);
            TMR1IF=0;
            count++;
			PORTB=0x04;
    }
    count=0;
    while(count<238)
	{
            while(!TMR1IF);
            TMR1IF=0;
            count++;
			PORTB=0x04;
    }
        count=0;
}