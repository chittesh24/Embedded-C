#include <pic.h>
void delay(unsigned int x){
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
void num(int x)
{
	int a[10],i=0;
	while(x>0){
		a[i]=x%10;
		x=x/10;
		i++;
	}
	i--;
	while(i>=0)
	{
		RC0=1;
		RC1=1;
		PORTD=a[i]+0x30;
		delay(65000);
		RC1=0;
		i--;
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
		for(int i=0;i<=100;i++){
		cmd(0x80);
		num(i);
		delay(65000);
		cmd(0x01);}
	}
}
