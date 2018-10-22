#include "../lcd/lcd.h"
#include "../lcd/portyLcd.h"

void LoadFonts()
{
  SEND_CMD(DD_RAM_ADDR);
  SEND_CMD(CG_RAM_ADDR);
  // 0 - BARIERKA_GORA
  SEND_CHAR((char)31);
  SEND_CHAR((char)0);
  SEND_CHAR((char)0);
  SEND_CHAR((char)0);
  SEND_CHAR((char)0);
  SEND_CHAR((char)0);
  SEND_CHAR((char)0);
  SEND_CHAR((char)0);
  // 1 - BARIERKA_DOL
  SEND_CHAR((char)0);
  SEND_CHAR((char)0);
  SEND_CHAR((char)0);
  SEND_CHAR((char)0);
  SEND_CHAR((char)0);
  SEND_CHAR((char)0);
  SEND_CHAR((char)0);
  SEND_CHAR((char)31);
  // 2 - GRACZ_BEZ_BARIERKI
  SEND_CHAR((char)0);
  SEND_CHAR((char)0);
  SEND_CHAR((char)9);
  SEND_CHAR((char)31);
  SEND_CHAR((char)31);
  SEND_CHAR((char)9);
  SEND_CHAR((char)0);
  SEND_CHAR((char)0);
  // 3 - GRACZ_BARIERKA_GORA
  SEND_CHAR((char)31);
  SEND_CHAR((char)0);
  SEND_CHAR((char)9);
  SEND_CHAR((char)31);
  SEND_CHAR((char)31);
  SEND_CHAR((char)9);
  SEND_CHAR((char)0);
  SEND_CHAR((char)0);
  // 4 - GRACZ_BARIERKA_DOL
  SEND_CHAR((char)0);
  SEND_CHAR((char)0);
  SEND_CHAR((char)9);
  SEND_CHAR((char)31);
  SEND_CHAR((char)31);
  SEND_CHAR((char)9);
  SEND_CHAR((char)0);
  SEND_CHAR((char)31);
  //5 - WROG_BEZ_BARIERKI
  SEND_CHAR((char)0);
  SEND_CHAR((char)0);
  SEND_CHAR((char)18);
  SEND_CHAR((char)31);
  SEND_CHAR((char)31);
  SEND_CHAR((char)18);
  SEND_CHAR((char)0);
  SEND_CHAR((char)0);
  //6 - WROG_BARIERKA_GORA
  SEND_CHAR((char)31);
  SEND_CHAR((char)0);
  SEND_CHAR((char)18);
  SEND_CHAR((char)31);
  SEND_CHAR((char)31);
  SEND_CHAR((char)18);
  SEND_CHAR((char)0);
  SEND_CHAR((char)0);
  //7 - WROG_BARIERKA_DOL
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