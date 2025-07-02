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
	delay(650);
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
		RC0=1;
		RC1=1;
		PORTD=d[i]+0x30;
		delay(650);
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
	TRISB=0x03;
	RB0=0;
	RB1=0;
	PORTC=0x03;
	PORTD=0xFF;
	cmd(0x38);
	cmd(0x0F);
	int i=0;
	while(1)
	{
 		if(RB0==1 &&  i<30){
		i++;
			}
		if(RB1==1 && i>=1){
		i--;
			}
		cmd(0x80);
		num(i);
		delay(65000);
		cmd(0x01);
	}
}