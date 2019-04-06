#include "Observer.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

namespace GY
{

Observer::Observer()
{
  _id = "normal";
}

Observer::Observer(std::string id)
{
  _id.assign(id.data(), id.size());
}

Observer::Observer(const Observer& o)
{
  _id.assign(o._id.data(), o._id.size());
}

Observer::Observer(const Observer* o)
{
  _id.assign(o->_id.data(), o->_id.size());
}

Observer::~Observer()
{
}

bool Observer::operator==(const Observer* o) const
{
  return _id == o->_id;
}

Observer& Observer::operator=(const Observer* o)
{
  if(o->_id == this->_id)
  	return *this;

  this->_id.assign(o->_id.data(), o->_id.size());
}

std::string Observer::getID() const
{
  return _id;
}

Subject::Subject()
{
}

Subject::~Subject()
{
}

void Subject::Attach(Observer* o)
{
  _observers.push_back(o);
}

void Subject::Detach(Observer* o)
{
  std::vector<Observer*>::iterator it;

  it = find(_observers.begin(), _observers.end(), o);
  _observers.erase(it);
}

void Subject::Notify()
{
  for(int i=0; i<_observers.size(); ++i)
    _observers[i]->Update(this);

  Clear();
}

Subscriber::Subscriber(std::string id)
  : Observer(id)
{
}

Subscriber::~Subscriber()
{
}

void Subscriber::Update(Subject* subject)
{
  printf("Now user id is: %s.\n  %s: %s\n",
    getID().data(),
    "Periodical information update and the latest information is ",
    subject->getInformation().data());
}

Publisher::Publisher(std::string name)
{
  _name.assign(name.data(), name.size());
}

Publisher::~Publisher()
{
}

void Publisher::Clear()
{
  this->_informations.clear();
}

std::string Publisher::getInformation()
{
  std::string information = _name + " publish ";

  for(int i=0; i<_informations.size(); ++i)
    information = information + "(" + _informations[i] + ") ";

  return information;
}

void Publisher::Publish(std::string information)
{
  this->_informations.push_back(information);
}

}
