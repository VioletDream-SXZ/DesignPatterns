#include "BehaviorPattern/Responsibility.h"
#include "BehaviorPattern/Command.h"
#include "BehaviorPattern/Interpreter.h"
#include "BehaviorPattern/Observer.h"
#include "BehaviorPattern/Mediator.h"
#include "BehaviorPattern/Iterator.h"
#include "BehaviorPattern/Strategy.h"

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

void TestCommand()
{
  GY::CommandDemo::main();
}

void TestInterpreter()
{
  GY::InterpreterDemo::main();
}

void TestIterator()
{
  GY::IteratorDemo::main();
}

void TestObserver()
{
  GY::ObserverDemo::main();
}

void TestMediator()
{
  GY::MediatorDemo::main();
}

void TestStrategy()
{
  GY::StrategyDemo::main();
}

void registerFunction()
{
  callocBack["Responsibility"] = TestResponsibility;
  callocBack["Command"]        = TestCommand;
  callocBack["Interpreter"]    = TestInterpreter;
  callocBack["Iterator"]       = TestIterator;
  callocBack["Observer"]       = TestObserver;
  callocBack["Mediator"]       = TestMediator;
  callocBack["Strategy"]       = TestStrategy;
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
    printf("    Command       : Command Pattern!.\n");
    printf("    Interpreter   : Interpreter Pattern.\n");
    printf("    Iterator      : Iterator Pattern.\n");
    printf("    Mediator      : Mediator Pattern.\n");
    printf("    Observer      : Observer Pattern.\n");
    printf("    Strategy      : Strategy Pattern.\n");
    return 0;
  }

  registerFunction();

  std::string str;
  str.assign(argv[1], strlen(argv[1]));
  runCallocBack(str);
}
