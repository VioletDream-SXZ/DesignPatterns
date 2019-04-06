/******************************************************************************************************************
* Copyright (C): 本代码所有版权为ysq所有，任何个人或者组织不得以任何方式复制、转载以挪作他用，否则将构成对ysq的产权知识侵权。
* @file       : Observer.h
* @brief      : 
*               观察者模式的而相关实现。
*               Subject   : 一个目标类的接口。
*               Observer  : 一个观察者的接口。
*               Subscriber: 订阅者类，可以订阅报刊信息。
*               Publisher : 报刊类，可以发布报刊或者书籍。
* @autor      : Ysq
* @emil:      : 694622692@qq.com
* @version    : 1.0.0.0
* @date       : 2019/04/06     12:04     
******************************************************************************************************************/
#ifndef GY_OBSERVER_H
#define GY_OBSERVER_H

#include <vector>
#include <string>
#include <algorithm>

namespace GY
{

class Subject;

class Observer
{
 public:
  bool operator==(const Observer* o) const;
  Observer& operator=(const Observer* o);

  std::string getID() const;
  virtual void Update(Subject* subject) = 0;
 protected:
  Observer();
  virtual ~Observer();
  Observer(std::string id);
  Observer(const Observer& o);
  Observer(const Observer* o);

 private:
   std::string _id;
};

class Subject
{
 public:
  virtual ~Subject();

  virtual void Attach(Observer* o);
  virtual void Detach(Observer* o);

  virtual void Notify();
  virtual std::string getInformation() = 0;
  virtual void Clear() = 0;
 protected:
  Subject();

 private:
  std::vector<Observer*> _observers;
};

class Subscriber
  : public Observer
{
 public:
  Subscriber(std::string id);
  ~Subscriber();

  virtual void Update(Subject* subject);
};

class Publisher
  : public Subject
{
 public:
  Publisher(std::string name);
  ~Publisher();

  virtual std::string getInformation();
  virtual void Clear();

  void Publish(std::string information);

 private:
  std::string _name;
  std::vector<std::string> _informations;
};

class ObserverDemo
{
 public:
  static void main()
  {
    Publisher publisher("Machinery Industry Press");

    Subscriber s1("ysq");
    Subscriber s2("cjr");

    publisher.Attach(&s1);
    publisher.Attach(&s2);

    publisher.Publish("Design Patterns");
    publisher.Publish("Database System Concepts");
    publisher.Notify();
  }
};

}

#endif // GY_OBSERVER_H
