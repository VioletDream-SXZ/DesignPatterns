#include "Responsibility.h"
#include <map>
#include <string>
#include <iostream>
#include <string.h>
#include <stdio.h>

typedef void (*function)(void);
typedef std::map<std::string, function>::iterator MapIterator;
std::map<std::string, function> callocBack;

void TestResponsibility()
{
  GY::ChainPatternDemo::main();
}

void registerFunction()
{
  callocBack["Responsibility"] = TestResponsibility;
}

void runCallocBack(std::string op)
{
  if(callocBack.find(op) == callocBack.end())
  {
    printf("Unknown Op With(%s).\n", op.data());
    return;
  }

  MapIterator it = callocBack.find(op);
  (it->second)();
}

int main(int argc, char** argv)
{
  if(argc <= 1)
  {
    printf("Param error.Now Need One Param To Define Function.\n");
    printf("    Responsibility: Responsibility Pattern!.\n");
    return 0;
  }

  registerFunction();

  std::string str;
  str.assign(argv[1], strlen(argv[1]));
  runCallocBack(str);
}
