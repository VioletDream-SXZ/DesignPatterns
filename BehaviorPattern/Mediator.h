/******************************************************************************************************************
* Copyright (C): 本代码所有版权为ysq所有，任何个人或者组织不得以任何方式复制、转载以挪作他用，否则将构成对ysq的产权知识侵权。
* @file       : Mediator.h
* @brief      : 
*               中介者模式的而相关实现。
*               Mediator  : 一个中介者的接口。
*               Colleague : 一个同事类的接口。
*               ChatRoom  : 聊天室类，可以将信息分发显示出来。
*               ChatUser  : 使用者类，可以发送信息。
* @autor      : Ysq
* @emil:      : 694622692@qq.com
* @version    : 1.0.0.0
* @date       : 2019/04/06     16:59     
******************************************************************************************************************/

#ifndef GY_MEDIATOR_H
#define GY_MEDIATOR_H

#include <string>

namespace GY
{

class Colleague;

class Mediator
{
 public:
  virtual ~Mediator() = default;

  virtual void sendMessage(Colleague* c, std::string message) = 0;
 protected:
  Mediator() = default;
};

class Colleague
{
 public:
  virtual ~Colleague() = default;

  virtual std::string getName() const = 0;
 protected:
  Colleague() = default;
};

class ChatRoom
 : public Mediator
{
 public:
  ChatRoom(std::string name);
  virtual void sendMessage(Colleague* c, std::string message);

 private:
  std::string _name;
};

class ChatUser
 : public Colleague
{
 public:
  ChatUser(std::string name);
  ChatUser(const char* name);
  virtual std::string getName() const;

 private:
  std::string _name;
};

class MediatorDemo
{
 public:
  static void main()
  {
    Mediator*  mediator = new ChatRoom("Line 7");
    Colleague* user1    = new ChatUser("ysq");
    Colleague* user2    = new ChatUser("cjr");

    mediator->sendMessage(user1, "How are you!");
    mediator->sendMessage(user2, "I am fine!");
  }
};

}

#endif // GY_MEDIATOR_H
