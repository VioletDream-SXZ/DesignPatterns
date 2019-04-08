#include "Strategy.h"

namespace GY
{

void getRand(int* array, int size)
{
  for(int i=0; i<=size; ++i)
    array[i] = rand();
}

}
