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
void data (char b)
{
	RC0=1;
	RC1=1;
	PORTD=b;
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
void str(char *e)
{
	RC0=1;
	while(*e!='\0')
	{
		RC1=1;
		PORTD=*e;
		delay(65000);
		RC1=0;
		e++;
	}
}
int main()
{
	TRISC=0x00;
	TRISD=0x00;
	PORTC=0x03;
	PORTD=0xFF;
	cmd(0x38);
	cmd(0x0F);
	while(1)
	{
		cmd(0x80);
		data('A');
		delay(65000);
		cmd(0x14);
		num(123);
		delay(65000);
		cmd(0xC0);
		str("Welcome To CVEA");
		delay(65000);
		cmd(0x01);
	}
}