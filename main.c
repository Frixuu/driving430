#include <msp430x14x.h>
#include "lcd/lcd.h"
#include "lcd/portyLcd.h"
#include "gra/silnik.h"
#include "fonty/fonty.h"
#include "input/input.h"

int Initialized;

void main(void)
{
  Initialized = 0;
  unsigned int i;
  WDTCTL = WDTPW + WDTHOLD;                // wy31czenie uk3adu WDT
  P2DIR |= BIT1;                         // bit P2.1 jako wyjocie 
  BCSCTL1 |= XTS + DIVA1 + DIVA0;           // (ACLK = LFXT1 = HF XTAL)/8 
  do 
  {
    IFG1 &= ~OFIFG;                       // Czyszczenie flgi OSCFault
    for (i = 0xFF; i > 0; i--);           // odczekanie 
  }
  while ((IFG1 & OFIFG));               //  dopóki OSCFault jest ci1gle ustawiona                
 
  WDTCTL = WDTPW + WDTCNTCL + WDTTMSEL + WDTSSEL ;// czyszczenie WDT ustaienie w tryb interval ACLK
  IE1 |= WDTIE;                         // W31czenie przerwan od WDT 
  _EINT();                              // W31czenie przerwan
  InitPortsLcd();
  InitLCD();
  clearDisplay();
  LoadFonts();
  InitButtons();
  Initialized = 1;
  while(1){}
}


#pragma vector=WDT_VECTOR
__interrupt void watchdog_timer(void)
{
  if (Initialized) tick_gry();
}
