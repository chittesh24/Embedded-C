#include<pic.h>
void delay(unsigned int x)
{
	while(x--);
} 
int main()
{
	char a[10]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
	int i;
	TRISB=0x00;
	PORTB=0x00;
	while(1)
	{
		for(i=0;i<10;i++)
		{
			PORTB=a[i];
			delay(65000);
		}	
	}	
}