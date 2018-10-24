#include "../lcd/lcd.h"
#include "../lcd/portyLcd.h"
#include "../fonty/fonty.h"
#include "../input/input.h"
#include "../random/random.h"
#include "../utils/cyfry.h"

int MaxDivider = 45;
int Divider = 45;

unsigned long long Dystans;

int liniaGracza = 1;
int ForceUpdate = 0;

int spawnFlag = 0;
int Zycia;

int droga[2][15];
enum Stan
{
  Menu = 0,
  Autorzy = 1,
  OpisGry = 2,
  Rekord = 3,
  Gra = 4,
  KoniecGry = 5
};
enum Stan StanGry = Menu;

int AnimacjaMenu = 1;
int AnimacjaOpis = 0;

void tick_gry()
{
  Divider--;
  if(Divider < 0) Divider = 0;
  
  int xi, xj;
  
  switch(StanGry)
  {
    case Menu:
     if(ButtonDown(1))
     {
       StanGry = Gra;
       Divider = 0;
       MaxDivider = 7;
       for(xi = 0; xi < 2; xi++)
       {
         for(xj = 0; xj < 15; xj++)
         {
           droga[xi][xj] = 0;
         }
       }
       
       Dystans = 0;
       Zycia = 3;
     }
     if(ButtonDown(2))
     {
       StanGry = Autorzy;
       clearDisplay();
       Divider = 0;
     }
     if(ButtonDown(3))
     {
       StanGry = OpisGry;
       clearDisplay();
       AnimacjaOpis = 0;
       Divider = 0;
     }
     break;
  case Autorzy:
  case KoniecGry:
    if(AnyButtonDown())
    {
      StanGry = Menu;
      Divider = 0;
    }
    break;
  case OpisGry:
    if(AnyButtonDown())
    {
      AnimacjaOpis++;
      Divider = 0;
      if(AnimacjaOpis == 2)
      {
        StanGry = Menu;
      }
      clearDisplay();
      
    }
    break;
  case Gra:
    if(ButtonDown(4))
    {
      liniaGracza = 1;
      ForceUpdate = Divider;
      Divider = 0;
    }
    if(ButtonDown(3))
    {
      liniaGracza = 2;
      ForceUpdate = Divider;
      Divider = 0;
    }
    break;
  }
  
  int x, y;

  
  if(Divider == 0)
  {
    switch(StanGry)
    {
      case Menu:
        clearDisplay();
        WyslijNapis("MistrzKierownicy", 1, 0);
        switch(AnimacjaMenu)
        {
          case 1:
          WyslijNapis("1. Graj", 2, 0);
          break;
          case 2:
          WyslijNapis("2. Autorzy", 2, 0);
          break;
          case 3:
          WyslijNapis("3. Opis gry", 2, 0);
          break;
          case 4:
          WyslijNapis("4. Rekord", 2, 0);
          break;
        }
        AnimacjaMenu++;
        if (AnimacjaMenu == 5) AnimacjaMenu = 1;
        break;
      case Autorzy:
        WyslijNapis("Walenciej Patryk", 1, 0);
        WyslijNapis("Zielinski Lukasz", 2, 0);
        break;
      case OpisGry:
        switch(AnimacjaOpis)
        {
          case 0:
            WyslijNapis("Skrecaj, aby omi", 1, 0);
            WyslijNapis("jac przeszkody.", 2, 0);
          break;
          case 1:
            WyslijNapis("Nigdy nie wiesz,", 1, 0);
            WyslijNapis("skad nadjada!", 2, 0);
          break;
        }
        break;
      case Gra:
        Dystans++;
        
        
        if(ForceUpdate == 0)
        {
          
          for(y = 0; y < 2; y++)
          {
            for(x = 14; x > 0; x--)
            {
              droga[y][x] = droga[y][x-1];
            }
          }
          
          droga[0][0] = 0;
          droga[1][0] = 0;
          
          if(spawnFlag == 0)
          {
            if(NextRandom() % 3)
            { 
              spawnFlag = 2;
              if(NextRandom() % 5 > 2) droga[0][0] = 1;
              else droga[1][0] = 1;
            }
          }
          else
          {
            spawnFlag--;
          }
          
          if(liniaGracza == 1 && droga[0][14] == 1)
            Zycia--;
          if(liniaGracza == 2 && droga[1][14] == 1)
            Zycia--;
          
          
          
          
        }
        
        SEND_CMD(DD_RAM_ADDR);
        for(x = 0; x < 15; x++)
        {
          if(x == 14 && liniaGracza == 1)
          {
            SEND_CHAR((Dystans + (15 - x)) % 4 < 2 ? GRACZ_BARIERKA_GORA : GRACZ_BEZ_BARIERKI);
          }
          else
          {
            if(droga[0][x] == 1)
            {
              SEND_CHAR((Dystans + (15 - x)) % 4 < 2 ? WROG_BARIERKA_GORA : WROG_BEZ_BARIERKI);
            }
            else SEND_CHAR((Dystans + (15 - x)) % 4 < 2 ? BARIERKA_GORA : ' ');
          }
        }
        SEND_CHAR('Z');
        SEND_CMD(DD_RAM_ADDR2);
        for(x = 0; x < 15; x++)
        {
          if(x == 14 && liniaGracza == 2)
          {
            SEND_CHAR((Dystans + (15 - x)) % 4 < 2 ? GRACZ_BARIERKA_DOL : GRACZ_BEZ_BARIERKI);
          }
          else
          {
            if(droga[1][x] == 1)
            {
              SEND_CHAR((Dystans + (15 - x)) % 4 < 2 ? WROG_BARIERKA_DOL : WROG_BEZ_BARIERKI);
            }
            else SEND_CHAR((Dystans + (15 - x)) % 4 < 2 ? BARIERKA_DOL : ' ');
          }
        }
        SEND_CHAR(CyfraNaZnak(Zycia));
        
        
        if(Zycia == 0)
        {
          StanGry = KoniecGry;
          MaxDivider = 45;
          clearDisplay();
        }
        
        
        break;
      case KoniecGry:
        WypiszKoniec(Dystans);
        break;
    }
    Divider = MaxDivider;
    if(ForceUpdate != 0)
    {
      Divider = ForceUpdate;
      ForceUpdate = 0;
    }
  }
}