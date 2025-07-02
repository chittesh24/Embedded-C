#include<pic.h>
int main()
{
	TRISB0=1;
	TRISB1=0;
	RB1=0;
	while(1)
	{
		while(RB0==1)
		{
			RB1=1;
		}
		RB0=0;
	}
}