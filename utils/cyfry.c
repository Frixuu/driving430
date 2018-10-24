#include <msp430x14x.h>
#include "../lcd/lcd.h"
#include "../lcd/portyLcd.h"
#include "cyfry.h"

char CyfraNaZnak(int cyfra)
{
  char cyfry[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
  return cyfra <= 10 ? cyfry[cyfra] : '?';
}

void WypiszKoniec(unsigned long long liczba)
{
  
  long tempLiczba = liczba >= 0 ? liczba : -liczba;
  char tekst[16];
  tekst[15] = '\0';
  int i, j;
  for(i = 14; i >= 0; i--)
  {
    if(tempLiczba != 0)
    {
      tekst[i] = CyfraNaZnak(tempLiczba % 10);
      tempLiczba /= 10;
    }
    else
    {
      if(liczba < 0) tekst[i] = '-';
      else if(liczba == 0) tekst[i] = '0';
      else i++;
      break;
    }
  }
  
  clearDisplay();
  SEND_CMD(DD_RAM_ADDR);
  char napis1[7] = {'K', 'o', 'n', 'i', 'e', 'c', '!'};
  for(j = 0; j < 6; j++) SEND_CHAR(napis1[j]);
  SEND_CMD(DD_RAM_ADDR2);
  while(tekst[i] != '\0')
  {
    SEND_CHAR(tekst[i]);
    i++;
  }
  SEND_CHAR('m');
}
