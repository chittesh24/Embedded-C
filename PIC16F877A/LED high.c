#include<pic.h>
void delay(unsigned int x)
{
	while(x--);
}
void cmd(char a)
{
	RC0=0;
	RC1=1;
	PORTD=a;
	delay(65000);
	RC1=0;
}
void num(int c)
{
	int d[10],i=0;
	while(c>0)
	{
		d[i]=c%10;
		c=c/10;
		i++;
	}
	i--;
	while(i>=0)
	{
		RC0=1;
		RC1=1;
		PORTD=d[i]+0x30;
		delay(65000);
		RC1=0;
		i--;
	}
}
int main()
{
	int a,b,c;
	TRISA=0x04;
	TRISC=0x00;
	TRISD=0x00;
	PORTC=0x03;
	PORTD=0xFF;
	ADCON0=0xD5;
	ADCON1=0x82;
	cmd(0x38);
	cmd(0x0F);
	
	while(1)
	{
		cmd(0x80);
		ADGO=1;
		while(!ADIF);
		ADIF=0;
		a=ADRESL;
		b=ADRESH;
		b=b<<8;
		c=a+b;
		if(c>=471 && c<=758){
		RC2=1;
		RC3=0;RC4=0;
		}
		else if(c>758 && c<=1024){
		RC2=0;
		RC3=1;RC4=0;
		}
	else if(c>0 && c<471){
		RC2=0;
		RC3=0;RC4=1;
		}		num(c);
		delay(65000);
		cmd(0x01);
	}
}
