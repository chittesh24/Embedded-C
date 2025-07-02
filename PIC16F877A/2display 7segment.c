#include<pic.h>
void delay(unsigned int x)
{
	while(x--);
} 
int main()
{
	char s[10]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
	int i=28,a=0,b=0;
	TRISB=0x00;
	TRISC=0x00;
	PORTB=0x00;
	PORTC=0x00;
	while(1)
	{
		for(int i=0;i<=100;i++){
			a=i%10;
			b=i/10;
			RC0=0;
			PORTB=s[b];
			delay(6500);
			RC0=1;
			RC1=0;
			PORTB=s[a];
			delay(6500);
			RC1=1;	
		}
	}	
}