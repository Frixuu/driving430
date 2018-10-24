#include "random.h"

unsigned int randomseed = 2137;

unsigned int NextRandom()
{
  randomseed *= MULTIPLIER;
  randomseed += INCREMENT;
  return randomseed;
}
