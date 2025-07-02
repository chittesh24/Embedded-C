#include <pic.h>
 
void SPI_Slave_Init();
int SPI_Read();
 
unsigned int Data; // Global Received Data Variable (Not Recommended)
              // Just For Demonstration Purposes Only!
 
void main(void)
{
  SPI_Slave_Init();
  TRISB = 0x00;
  while(1)
  {
    // Dumping Received Data To PORTB To Validate Communication Success!
    PORTB = Data;
  }
  return;
}
 
void SPI_Slave_Init()
{
  // Set Spi Mode To Slave + SS Enabled
  SSPM0 = 0;
  SSPM1 = 0;
  SSPM2 = 1;
  SSPM3 = 0;
  // Enable The Synchronous Serial Port
  SSPEN = 1;
  // Configure The Clock Polarity & Phase (SPI Mode Num. 1)
  CKP = 0;
  CKE = 0;
  // Clear The SMP Bit
  SMP = 0;
  // Configure The IO Pins For SPI Master Mode
  TRISC5 = 0; // SDO -> Output
  TRISC4 = 1; // SDI -> Input
  TRISC3 = 1; // SCK -> Intput
  
  TRISA5 = 1; // SS -> Input
  // Enable Interrupts. Comment Them To Disable interrupts(NOT Recommended)
  SSPIE = 1;
  PEIE = 1;
  GIE = 1; 
}
 
int SPI_Read() // Not Recommended Method To Read SPI Data
{
  unsigned int Data;
  if(BF) // Check If Any New Data Is Received
  {
    Data = SSPBUF; // Read The Buffer
    BF = 0; // Clear The Buffer-Filled Indicator Bit
    SSPIF = 0; // Clear The Interrupt Flag Bit
    SSPOV = 0; // Clear The Overflow Indicator Bit
    return Data;
  }
}
 
void interrupt ISR()
{
  if(SSPIF)
  {
    Data = SSPBUF; // Read The Buffer
    SSPIF = 0; // Clear The Interrupt Flag
  }
}