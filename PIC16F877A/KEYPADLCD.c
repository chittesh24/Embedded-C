#include<pic.h>
void delay(unsigned int x)
{
	while(x--);
}
void cmd(char a)
{
	RB0=0;
	RB1=1;
	PORTD=a;
	delay(650000);
	RB1=0;
}
void data (char b)
{
	RB0=1;
	RB1=1;
	PORTD=b;
	delay(650000);
	RB1=0;
}
void num(int c)
{
	int d[10],i=0;
	if(c>0){
	while(c>0)
	{
		d[i]=c%10;
		c=c/10;
		i++;
	}
	i--;
	}
else{
	d[i]=0;
}
	while(i>=0)
	{
		RB0=1;
		RB1=1;
		PORTD=d[i]+0x30;
		delay(650000);
		RB1=0;
		i--;
	}
}
int main()
{
	TRISB=0x00;
	TRISD=0x00;
	TRISC=0xF0;
	PORTB=0x03;
	PORTD=0xFF;
	RC0=1;
	RC1=1;
	RC2=1;
	cmd(0x38);
	cmd(0x0F);
	cmd(0x80);
	while(1)
	{


	RC0=0;RC1=1;RC2=1;RC3=1;

 	if( RC4==0)
			{
while(RC4==0);
			num(1);
		
			}
	if( RC5==0)
			{
while(RC5==0);
			num(2);
		
			}
	if( RC6==0)
			{while(RC6==0);
			num(3);
		
			}
	RC0=1;RC1=0;RC2=1;RC3=1;

 	if( RC4==0)
			{
while(RC4==0);
			num(4);
		
			}
	if( RC5==0)
			{
while(RC5==0);
			num(5);
		
			}
	if( RC6==0)
			{while(RC6==0);
			num(6);
		
			}
	RC0=1;RC1=1;RC2=0;RC3=1;

 	if( RC4==0)
			{
while(RC4==0);
			num(7);
		
			}
	if( RC5==0)
			{
while(RC5==0);
			num(8);
		
			}
	if( RC6==0)
			{while(RC6==0);
			num(9);
		
			}
	RC0=1;RC1=1;RC2=1;RC3=0;

 	if( RC4==0)
			{
while(RC4==0);
			data('*');
		
			}
	if( RC5==0)
			{
while(RC5==0);
			num(0);
		
			}
	if( RC6==0)
			{while(RC6==0);
			data('#');
		
			}
	
	
	}
}