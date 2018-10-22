#include <msp430x14x.h>

void InitButtons()
{
  P4DIR &= 0xf0;
}

int ButtonDown(int number)
{
  switch(number)
  {
    case 1:
      return ~P4IN & BIT4;
    case 2:
      return ~P4IN & BIT5;
    case 3:
      return ~P4IN & BIT6;
    case 4:
      return ~P4IN & BIT7;
    default:
      return 0;
  }
}

int ButtonUp(int number)
{
  return !ButtonDown(number);
}

int AnyButtonDown()
{
  return ButtonDown(1) || ButtonDown(2) || ButtonDown(3) || ButtonDown(4);
}