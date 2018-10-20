#include "../lcd/lcd.h"
#include "../lcd/portyLcd.h"
#include "../fonty/fonty.h"
#include "../input/input.h"

int Divider = 45;
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
  
  
  
  switch(StanGry)
  {
    case Menu:
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
      clearDisplay();
      Divider = 0;
    }
    break;
  }
  
  
  
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
        case 2:
          StanGry = Menu;
        break;
        }
        break;
    }
    Divider = 45;
  }
}