/******************************************************************************************************************
* Copyright (C): 本代码所有版权为ysq所有，任何个人或者组织不得以任何方式复制、转载以挪作他用，否则将构成对ysq的产权知识侵权。
* @file       : Strategy.h
* @brief      : 
*               策略模式的而相关实现。
*               Strategy  : 一个策略类的接口。
*               QuitSort  : 快排策略的具体类。
*               BubbleSort: 冒泡排序策略的具体类。
*               Sort      : 具有策略模式的排序具体类。
* @autor      : Ysq
* @emil:      : 694622692@qq.com
* @version    : 1.0.0.0
* @date       : 2019/04/08     19:33     
******************************************************************************************************************/

#ifndef GY_STRATEGY_H
#define GY_STRATEGY_H

#include <stdio.h>
#include <stdlib.h>

#include <iostream>

namespace GY
{

template<typename _Ty>
void swap(_Ty& a, _Ty& b)
{
  _Ty temp = a;
  a = b;
  b = temp;
}

template<typename _Ty>
void display(_Ty* array, int size)
{
  for(int i=0; i<=size; ++i)
    std::cout << array[i] << " ";
  std::cout << std::endl;
}

void getRand(int* array, int size);

//  define
template<typename _Ty>
class Strategy
{
 public:
  virtual ~Strategy() = default;
  virtual void Sort(_Ty* array, int size) = 0;

 protected:
  Strategy() = default;
};

template<typename _Ty>
class QuitSort
 : public Strategy<_Ty>
{
 public:
  QuitSort() = default;
  ~QuitSort() = default;

  virtual void Sort(_Ty* array, int size);

 private:
  void Sort(_Ty* array, int beginPos, int endPos);
};

template<typename _Ty>
class BubbleSort
 : public Strategy<_Ty>
{
 public:
  BubbleSort() = default;
  ~BubbleSort() = default;

  virtual void Sort(_Ty* array, int size);

 private:
  void Sort(_Ty* array, int beginPos, int endPos);
};

template<typename _Ty>
class Sort
{
 public:
  Sort(Strategy<_Ty>* strategy);
  ~Sort() = default;

  void sort(_Ty *array, int size);

 private:
  Strategy<_Ty>* _stategy;
};

class StrategyDemo
{
 public:
  static void main()
  {
    int* array = NULL;
    array = new int[10];

    Strategy<int>* quitSort   = new QuitSort<int>();
    Strategy<int>* bubbleSort = new BubbleSort<int>();
    Sort<int>*     quitContext = new Sort<int>(quitSort);
    Sort<int>*     bubbleContext = new Sort<int>(bubbleSort);

    getRand(array, 9);
    display<int>(array, 9);
    quitContext->sort(array, 9);
    display<int>(array, 9);

    getRand(array, 9);
    display<int>(array, 9);
    bubbleContext->sort(array, 9);
    display<int>(array, 9);
  }
};

//  achieve
template<typename _Ty>
void QuitSort<_Ty>::Sort(_Ty* array, int size)
{
  Sort(array, 0, size);
}

template<typename _Ty>
void QuitSort<_Ty>::Sort(_Ty* array, int beginPos, int endPos)
{
  if(beginPos >= endPos)
    return;

  int start = beginPos, end = endPos;
  while(start < end)
  {
    while(start < end && array[start] <= array[end])
      start ++;
    swap<_Ty>(array[start], array[end]);

    while(start < end && array[start] <= array[end])
      end --;
    swap<_Ty>(array[start], array[end]);
  }

  Sort(array, beginPos, start-1);
  Sort(array, start+1, endPos);
}

template<typename _Ty>
void BubbleSort<_Ty>::Sort(_Ty* array, int size)
{
  Sort(array, 0, size);
}

template<typename _Ty>
void BubbleSort<_Ty>::Sort(_Ty* array, int beginPos, int endPos)
{
  for(int i=endPos; i>=beginPos; --i)
  {
    for(int j=beginPos; j<i; ++j)
      if(array[j] > array[j+1])
        swap<_Ty>(array[j], array[j+1]);
  }

  return;
}

template<typename _Ty>
Sort<_Ty>::Sort(Strategy<_Ty>* strategy)
 : _stategy(strategy)
{
}

template<typename _Ty>
void Sort<_Ty>::sort(_Ty* array, int size)
{
  _stategy->Sort(array, size);
}

}

#endif // GY_STRATEGY_H
