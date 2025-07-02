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
void data1(char *e)
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
}.
void main()
{
	char data;
	TRISC6=0;
	TRISC7=1;
	TXSTA=0X26;
	RCSTA=0XD0;
	SPBRG=129;
	TRISC0=0;
	TRISC1=0;
	TRISC2=0;
	TRISD=0X00;
	PORTD=0XFF;
	RC0=1;
	RC1=1;
	RC2=1;
	while(1)
	{
		while(!RCIF);
		RCIF=0;
		data=RCREG;
		if(data1='/0')
		{
			Send_char(data)
			CREN=0;
			CREN=1;
			}
			else{
				cmd(0x80);
				}
				}
}