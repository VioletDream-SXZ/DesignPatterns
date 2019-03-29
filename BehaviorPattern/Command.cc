#include "Command.h"
#include <stdio.h>

namespace GY
{

Command::Command()
{
  // TODO
}

Command::~Command()
{
  // TODO
}

DefaultMenuItem::DefaultMenuItem()
{
  MenuCommand* command = new MenuCommand();
  _command = command;
}

DefaultMenuItem::DefaultMenuItem(Command* command)
{
  // TODO INIT
  _command = command;
}

DefaultMenuItem::~DefaultMenuItem()
{
  // TODO DELETE 
  delete _command;
}

void DefaultMenuItem::click()
{
  _command->Execute();
}

void MenuCommand::Execute()
{
  printf("Now MenuCommand Execute.\n");
}

MenuItem1::MenuItem1()
{
  // TODO INIT
}

MenuItem1::~MenuItem1()
{
  // TODO
}

void MenuItem1::Execute()
{
  printf("Now MenuItem1 Execute.\n");
}

MenuItem2::MenuItem2()
{
  // TODO
}

MenuItem2::~MenuItem2()
{
  // TODO
}

void MenuItem2::Execute()
{
  printf("Now MenuItem2 Execute.\n");
}

CommandMenu::CommandMenu()
{
  // TODO
}

CommandMenu::~CommandMenu()
{
  // TODO
  for (int i = 0; i < _items.size(); ++i)
  {
  	delete _items[i];
  	_items[i] = NULL;
  }
}

void CommandMenu::addMenuItem(DefaultMenuItem* menuItem)
{
  _items.push_back(menuItem);
}

void CommandMenu::execute()
{
  if(_curPos >= _items.size())
  	return;

  (_items[_curPos])->click();
}

void CommandMenu::setCurrentPos(int pos)
{
  _curPos = pos;
}

}
