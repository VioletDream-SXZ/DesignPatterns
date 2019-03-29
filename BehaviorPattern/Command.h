/******************************************************************************************************************
* Copyright (C): 本代码所有版权为ysq所有，任何个人或者组织不得以任何方式复制、转载以挪作他用，否则将构成对ysq的产权知识侵权。
* FileName     : Command.h
* Author       : Ysq
* Date         : 2019/3/29     00:27     
******************************************************************************************************************/
#ifndef GY_COMMAND_H
#define GY_COMMAND_H

#include <vector>

namespace GY
{

class Command
{
 public:
  ~Command();

  virtual void Execute() = 0;
 protected:
  Command();	
};

class DefaultMenuItem
{
 public:
  DefaultMenuItem();
  DefaultMenuItem(Command* command);
  ~DefaultMenuItem();

  void click();
 private:
  Command* _command;
};

class MenuCommand
  : public Command
{
 public:
  MenuCommand() = default;
  ~MenuCommand() = default;

  virtual void Execute();
};

class MenuItem1
  : public Command
{
 public:
  MenuItem1();
  ~MenuItem1();

  virtual void Execute();	
};

class MenuItem2
  : public Command
{
 public:
  MenuItem2();
  ~MenuItem2();

  virtual void Execute();
};

class CommandMenu
{
 public:
  CommandMenu();
  ~CommandMenu();

  void addMenuItem(DefaultMenuItem* menuItem);
  void execute();
  void setCurrentPos(int pos);

 private:
  std::vector<DefaultMenuItem*> _items;
  int                           _curPos;
};

class CommandDemo
{
 public:
  static void main()
  {
    CommandMenu* menu = new CommandMenu();
    menu->addMenuItem(new DefaultMenuItem());
    menu->addMenuItem(new DefaultMenuItem(new MenuItem1()));
    menu->addMenuItem(new DefaultMenuItem(new MenuItem2()));

    for (int i = 0; i < 3; ++i)
    {
      menu->setCurrentPos(i);
      menu->execute();
    }

    delete menu;
  }
};

}

#endif // GY_COMMAND_H
