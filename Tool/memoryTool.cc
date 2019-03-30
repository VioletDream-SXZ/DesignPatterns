#include "memoryTool.h"
#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

namespace GY
{

char* strdup(const char* name)
{
  char* _name = NULL;
  _name = (char*)malloc(sizeof(name));
  strcpy(_name, name);

  return _name;
}

}
