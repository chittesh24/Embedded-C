#include<pic.h>
void delay(unsigned int x)
{
while(x--);
}
int sec=0;
char count=0;
void interrupt isr()
{
	if(TMR0IF==1)
	{
		TMR0IF=0;
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
				TRISB=0X00;
                PORTB=0X00;
				TRISC0=1;
				TRISC1=0;
				TMR0=0X00;
				OPTION=0X07;
				TMR0IE=1;
				GIE=1;
				while(1)
				{
					if(RC0==1)
					{
						RC1=~RC1;
                        delay(1000);
						if(sec==5)
						{
							PORTB=~PORTB;
							sec=0;
							}}
else
{sec=0;
	PORTB=0;
}				}
}