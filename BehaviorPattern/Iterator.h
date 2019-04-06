/******************************************************************************************************************
* Copyright (C): 本代码所有版权为ysq所有，任何个人或者组织不得以任何方式复制、转载以挪作他用，否则将构成对ysq的产权知识侵权。
* @file       : Iterator.h
* @brief      : 
*               迭代器模式的而相关实现。
*               ListNode    : 链表的子节点。
*               AbstractList: 抽象链表接口。
*               List        : 链表具体类
*               Iterator    : 迭代器接口。
*               ListIterator: 链表迭代器具体实现。
*               IteratorPtr : 链表迭代器智能指针。
* @autor      : Ysq
* @emil:      : 694622692@qq.com
* @version    : 1.0.0.0
* @date       : 2019/04/06     22:57  
******************************************************************************************************************/
#ifndef GY_ITERATOR_H
#define GY_ITERATOR_H

#include <stdio.h>
#include <stdlib.h>

namespace GY
{

//  define
template<typename> class Iterator;

template<typename _Ty>
struct ListNode
{
  struct ListNode<_Ty>* _front;
  struct ListNode<_Ty>* _rear;

  _Ty _data;
};

template<typename _Ty>
class AbstractList
{
  public:
  virtual ~AbstractList() = default;
   
   virtual void Append(_Ty val) = 0;
   virtual bool Remove(_Ty val) = 0;

   virtual Iterator<_Ty>* begin() = 0;

  protected:
   AbstractList() = default;
};

template<typename _Ty>
class List
 : public AbstractList<_Ty>
{
 public:
  List();
  List(int size);
  virtual ~List();

  virtual void Append(_Ty val);
  virtual bool Remove(_Ty val);

  virtual Iterator<_Ty>* begin();

 private:
  struct ListNode<_Ty>* getHead() const;

  struct ListNode<_Ty>* _head;
  struct ListNode<_Ty>* _end;
  struct ListNode<_Ty>* _current;

  int _size;
};

template<typename _Ty>
class Iterator
{
 public:
  virtual ~Iterator() = default;
  virtual Iterator<_Ty>* Next() = 0;
  virtual bool isDone() = 0;
  virtual _Ty CurrentItem() = 0;

 protected:
  Iterator() = default;
};

template<typename _Ty>
class ListIterator
  : public Iterator<_Ty>
{
 public:
  ListIterator(struct ListNode<_Ty>* current);
  virtual ~ListIterator() = default;
  virtual Iterator<_Ty>* Next();
  virtual bool isDone();
  virtual _Ty CurrentItem();

 private:
  struct ListNode<_Ty>* _current;
};

template<typename _Ty>
class IteratorPtr
{
 public:
  IteratorPtr(Iterator<_Ty>* ptr);
  ~IteratorPtr();

  Iterator<_Ty>& operator*();
  Iterator<_Ty>* operator->();

 private:
  IteratorPtr(const IteratorPtr<_Ty>&);
  IteratorPtr& operator=(const IteratorPtr&);

 private:
  Iterator<_Ty>* _iterator;
};

class IteratorDemo
{
 public:
  static void main()
  {
    AbstractList<int>* list = new List<int>();
    list->Append(1);
    list->Append(2);
    list->Append(3);
    list->Remove(2);

    Iterator<int>* it = list->begin();
    IteratorPtr<int> ptr(it);

    ptr->Next();            // 该项目头结点为空，需要指向下一个。
    while(ptr->isDone())
    {
      printf("%d ", ptr->CurrentItem());
      ptr->Next();
    }
  }
};

//  achieve
template<typename _Ty>
List<_Ty>::List()
{
  _head = new struct ListNode<_Ty>();
  _end  = _head;
  _current = _head;

  _head->_rear  = NULL;
  _head->_front = NULL;

  _size = 0;
}

template<typename _Ty>
List<_Ty>::List(int size)
{
  if(size <= 0)
    size = 1;

  _head = new struct ListNode<_Ty>();
  _current = _head;
  _size    = size;

  struct ListNode<_Ty>* ptr = _head;
  struct ListNode<_Ty>* cur = NULL;
  for(int i=0; i<_size; ++i)
  {
    cur = new struct ListNode<_Ty>();
    cur->_front = ptr;
    cur->_rear  = NULL;

    ptr->_rear  = cur;
    ptr = cur;
  }

  _end = ptr;
}

template<typename _Ty>
List<_Ty>::~List()
{
  struct ListNode<_Ty>* ptr = NULL;
  struct ListNode<_Ty>* cur = NULL;

  ptr = _head;
  cur = _head;
  while(cur != NULL)
  {
    cur = cur->_rear;

    delete ptr;
    ptr = cur;
  }
}

template<typename _Ty>
void List<_Ty>::Append(_Ty val)
{
  struct ListNode<_Ty>* ptr = NULL;

  ptr = new struct ListNode<_Ty>();
  ptr->_data = val;
  ptr->_rear = NULL;

  _end->_rear = ptr;
  ptr->_front = _end;

  _end = ptr;
}

template<typename _Ty>
bool List<_Ty>::Remove(_Ty val)
{
  struct ListNode<_Ty>* ptr = NULL;
  struct ListNode<_Ty>* cur = NULL;

  ptr = _head;
  cur = _head;
  while(cur != NULL)
  {
    if( cur->_data == val )
      break;

    cur = cur->_rear;
  }

  if(cur == NULL)
    return false;

  ptr = cur;

  if(ptr->_front == NULL)
  {
    _head = _head->_rear;
    _head->_front = NULL;

    ptr->_rear = NULL;
    delete ptr;
  }
  else
  {
    ptr->_front->_rear = ptr->_rear;
    ptr->_rear->_front = ptr->_front;

    ptr->_rear  = NULL;
    ptr->_front = NULL;
    delete ptr;
  }
}

template<typename _Ty>
struct ListNode<_Ty>* List<_Ty>::getHead() const
{
  return _head;
}

template<typename _Ty> Iterator<_Ty>* List<_Ty>::begin()
{
  Iterator<_Ty>* res = new ListIterator<_Ty>(_head);

  return res;
}

template<typename _Ty>
ListIterator<_Ty>::ListIterator(struct ListNode<_Ty>* current)
{
  _current = current;
}

template<typename _Ty> Iterator<_Ty>* ListIterator<_Ty>::Next()
{
  _current = _current->_rear;
  return this;
}

template<typename _Ty> bool ListIterator<_Ty>::isDone()
{
  return _current != NULL;
}

template<typename _Ty> _Ty ListIterator<_Ty>::CurrentItem()
{
  return _current->_data;
}

template<typename _Ty> 
IteratorPtr<_Ty>::IteratorPtr(Iterator<_Ty>* iterator)
{
  _iterator = iterator;
}

template<typename _Ty>
IteratorPtr<_Ty>::~IteratorPtr()
{
  delete _iterator;
}

template<typename _Ty>
Iterator<_Ty>* IteratorPtr<_Ty>::operator->()
{
  return _iterator;
}

template<typename _Ty>
Iterator<_Ty>& IteratorPtr<_Ty>::operator*()
{
  return *_iterator;
}

}

#endif // GY_ITERATOR_H
