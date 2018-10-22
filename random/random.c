#include "random.h"

int randomseed = 1;

int NextRandom()
{
  randomseed *= MULTIPLIER;
  randomseed += INCREMENT;
  return randomseed;
}
