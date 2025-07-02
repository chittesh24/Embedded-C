#include<stdio.h>
char arr[10]="arun";2403
int main()
{
	TRISC6=0;
	TRISC7=1;
	TXSTA=0x26;
	RCSTA=0x00;
	short int i=0;
	SPBRG=129;
	while(1)
	{
		while(!TXIF);
		TXIF=0;
		for(i=0;i<5;i++)
		{
			TXREG=a[i];
			delay(65000);
		}
	}
}