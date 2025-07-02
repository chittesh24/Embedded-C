#include<pic.h>
void delay(unsigned int x)
{
	while(x--);
}
int main()
{
	int count=0;
	TRISB=0x00;
	TRISC2=0;
	PR2=1024;
	PORTB=0x00;
	TMR2=0x00;
	T2CON=0xFF;
	CCP1CON=0X0F;
	RC2=0;
	CCPR1L=0;
	int j,i;
	while(1) 
	{
		for(i=0;i<1024;i++)
		{
			CCPR1L=i;
			delay(65000);
		}
		
	}
}
