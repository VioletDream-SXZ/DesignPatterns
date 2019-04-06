#include "Mediator.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

namespace GY
{

ChatRoom::ChatRoom(std::string name)
{
  _name.assign(name.data(), name.size());
}

void ChatRoom::sendMessage(Colleague* c, std::string message)
{
  printf("In ChatRoom[%s], User[%s]: %s.\n",
      _name.data(), c->getName().data(), message.data());
}

ChatUser::ChatUser(std::string name)
{
  _name.assign(name.data(), name.size());
}

ChatUser::ChatUser(const char* name)
{
  _name.assign(name, strlen(name));
}

std::string ChatUser::getName() const
{
  return _name;
}

}
