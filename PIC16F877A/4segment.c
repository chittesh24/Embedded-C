#include<pic.h>
void delay(unsigned int x)
{
	while(x--);
} 
int main()
{
	char s[10]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
	int i,a=0,b=0,c=0,d=0,e,f;
	TRISB=0x00;
	TRISC=0x00;
	PORTB=0x00;
	PORTC=0x00;
	while(1)
	{ 
		for(int i=0;i<10000;i++)
{//6348
			a=i%10;//8
			b=i/10;//634
            c=b%10;//4
            d=b/10;//63
			e=d%10;//3
			f=d/10;//6
			RC0=0;
			PORTB=s[f];
			delay(5000);
			RC0=1;
			RC1=0;
			PORTB=s[e];
			delay(5000);
			RC1=1;
			RC2=0;
			PORTB=s[c];
			delay(5000);
			RC2=1;
			RC3=0;
			PORTB=s[a];
			delay(5000);	
            RC3=1;
		}
	}	
}