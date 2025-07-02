#include<pic.h>
void delay(unsigned int x)
{
    while (x--);
}
int main()
{
    char s[10] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};
    int i, digit0 = 0, digit1 = 0, digit2 = 0, digit3 = 0, dp = -1;
    float user_input = 1.314;
    int int_part = (int)user_input;
    int dec_part = (int)((user_input - int_part) * 100 + 0.5);
    digit0 = dec_part % 10;      
    digit1 = dec_part / 10;      
    digit2 = int_part % 10;      
    digit3 = int_part / 10;      
    if (user_input >= 10) 
        dp = 2; 
    else
        dp = 1;
    TRISB = 0x00;
    TRISC = 0x00;
    PORTB = 0x00;
    PORTC = 0x00;
    while (1)
    { 
        RC0 = 0;
        PORTB = (dp == 3)?(s[digit3]|0x80) : s[digit3];  
        delay(5000);
        RC0 = 1;
        RC1 = 0;
        PORTB = (dp == 2)?(s[digit2] | 0x80) : s[digit2];  
        delay(5000);
        RC1 = 1;
        RC2 = 0;
        PORTB = (dp == 1)?(s[digit1] | 0x80) : s[digit1];  
        delay(5000);
        RC2 = 1;
        RC3 = 0;
        PORTB = (dp == 0) ? (s[digit0] | 0x80) : s[digit0];  
        delay(5000);
        RC3 = 1;
    }
}
