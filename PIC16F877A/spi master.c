#include <pic.h>


#define UP RB0
#define Down RB1
#define Send RB2
void SPI_Master_Init();
void SPI_Write(unsigned int t);
void delay(unsigned int x);

void main(void)
{
  //--[ Peripherals & IO Configurations ]--
  SPI_Master_Init(); // Initialize The SPI in Master Mode @ Fosc/64 SCK
   int Data = 0; // The Data Byte
  TRISB = 0x07; // RB0, RB1 & RB2 Are Input Pins (Push Buttons)
  TRISD = 0x00; // Output Port (4-Pins)
  PORTD = 0x00; // Initially OFF
  //---------------------------
  while(1)
  {
    if (UP) // Increment The Data Value
    {
      Data++;
     delay(250);
    }
    if (Down) // Decrement The Data Value
    {
      Data--;
      delay(250);
    }
    if (Send) // Send The Current Data Value Via SPI
    {
      SPI_Write(Data);
     delay(250);
    }
    PORTD = Data; // Display The Current Data Value @ PORTD
  }
  return;
}
void SPI_Master_Init()
{
  // Set Spi Mode To Master + Set SCK Rate To Fosc/64
  SSPM0 = 0;
  SSPM1 = 0;
  SSPM2 = 0;
  SSPM3 = 0;
  // Enable The Synchronous Serial Port
  SSPEN = 1;
  // Configure The Clock Polarity & Phase (SPI Mode Num. 1)
  CKP = 0;
  CKE = 0;
  // Configure The Sampling Time (Let's make it at middle)
  SMP = 0;
  // Configure The IO Pins For SPI Master Mode
  TRISC5 = 0; // SDO -> Output
  TRISC4 = 1; // SDI -> Input
  TRISC3 = 0; // SCK -> Output
  // If Interrupts Are Needed, Un-comment The Line Below
  // SSPIE = 1; PEIE = 1; GIE = 1;
}
 
void SPI_Write(unsigned int Data)
{
  SSPBUF = Data; // Transfer The Data To The Buffer Register
  // while(!SSPSTATbits.BF); // Un-comment it if you're Not Using Interrupts!
  // The Above While Loop Protects Against Writing To The Buffer
  // Before The Previous Transmission Ends
}

void delay(unsigned int x)
{
while(x--);
}
