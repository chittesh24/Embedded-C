#include<pic.h>
int main()
{
	TRISB=0x00;
	PORTB=0x00;
	TRISC2=0;
	RC2=1;
	CCP1CON=0x02;
	T1CON=0x31;
	TMR1L=0x00;
	TMR1H=0x00;
	CCPR1H=0x80;
	CCPR1L=0x00;
	while(1)
	{
		while(!CCP1IF);
		CCP1IF=0;
		PORTB=~PORTB;
	}
}