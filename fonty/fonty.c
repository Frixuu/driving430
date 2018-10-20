#include "../lcd/lcd.h"
#include "../lcd/portyLcd.h"

void ZaladujFonty()
{
  SEND_CMD(DD_RAM_ADDR);
  SEND_CMD(CG_RAM_ADDR);
  // 0 - barierka z gory
  SEND_CHAR((char)31);
  SEND_CHAR((char)0);
  SEND_CHAR((char)0);
  SEND_CHAR((char)0);
  SEND_CHAR((char)0);
  SEND_CHAR((char)0);
  SEND_CHAR((char)0);
  SEND_CHAR((char)0);
  // 1 - barierka dol
  SEND_CHAR((char)0);
  SEND_CHAR((char)0);
  SEND_CHAR((char)0);
  SEND_CHAR((char)0);
  SEND_CHAR((char)0);
  SEND_CHAR((char)0);
  SEND_CHAR((char)0);
  SEND_CHAR((char)31);
  // 2 - gb
  SEND_CHAR((char)0);
  SEND_CHAR((char)0);
  SEND_CHAR((char)9);
  SEND_CHAR((char)31);
  SEND_CHAR((char)31);
  SEND_CHAR((char)9);
  SEND_CHAR((char)0);
  SEND_CHAR((char)0);
  // 3 - gbg
  SEND_CHAR((char)31);
  SEND_CHAR((char)0);
  SEND_CHAR((char)9);
  SEND_CHAR((char)31);
  SEND_CHAR((char)31);
  SEND_CHAR((char)9);
  SEND_CHAR((char)0);
  SEND_CHAR((char)0);
  // 4 - gbd
  SEND_CHAR((char)0);
  SEND_CHAR((char)0);
  SEND_CHAR((char)9);
  SEND_CHAR((char)31);
  SEND_CHAR((char)31);
  SEND_CHAR((char)9);
  SEND_CHAR((char)0);
  SEND_CHAR((char)31);
  //5 - œ
  SEND_CHAR((char)0);
  SEND_CHAR((char)0);
  SEND_CHAR((char)18);
  SEND_CHAR((char)31);
  SEND_CHAR((char)31);
  SEND_CHAR((char)18);
  SEND_CHAR((char)0);
  SEND_CHAR((char)0);
  //6 - ¹
  SEND_CHAR((char)31);
  SEND_CHAR((char)0);
  SEND_CHAR((char)18);
  SEND_CHAR((char)31);
  SEND_CHAR((char)31);
  SEND_CHAR((char)18);
  SEND_CHAR((char)0);
  SEND_CHAR((char)0);
  //7 - Ÿ
  SEND_CHAR((char)0);
  SEND_CHAR((char)0);
  SEND_CHAR((char)18);
  SEND_CHAR((char)31);
  SEND_CHAR((char)31);
  SEND_CHAR((char)18);
  SEND_CHAR((char)0);
  SEND_CHAR((char)31);
  SEND_CMD(DD_RAM_ADDR);
}