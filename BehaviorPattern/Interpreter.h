/******************************************************************************************************************
* Copyright (C): 本代码所有版权为ysq所有，任何个人或者组织不得以任何方式复制、转载以挪作他用，否则将构成对ysq的产权知识侵权。
* FileName     : Interpreter.h
* Author       : Ysq
* Date         : 2019/3/30     16:44     
******************************************************************************************************************/
#ifndef GY_INTERPRETER_H
#define GY_INTERPRETER_H

#include <map>

namespace GY
{

class Context;

class BooleanExp
{
 public:
  BooleanExp() = default;
  virtual ~BooleanExp() = default;

  virtual bool Evaluate(Context&) = 0;
  virtual BooleanExp* Replace(const char*, BooleanExp&) = 0;
  virtual BooleanExp* Copy() const = 0;
};

class VariableExp
  : public BooleanExp
{
 public:
  VariableExp(const char*);
  virtual ~VariableExp();

  virtual bool Evaluate(Context&);
  virtual BooleanExp* Replace(const char*, BooleanExp&);
  virtual BooleanExp* Copy() const;

  bool operator<(const VariableExp&) const;
 private:
  char* _variableName;
};

class AndExp
  : public BooleanExp
{
 public:
  AndExp(BooleanExp*, BooleanExp*);
  virtual ~AndExp();

  virtual bool Evaluate(Context&);
  virtual BooleanExp* Replace(const char*, BooleanExp&);
  virtual BooleanExp* Copy() const;

 private:
  BooleanExp* _operand1;
  BooleanExp* _operand2;
};

class OrExp
  : public BooleanExp
{
 public:
  OrExp(BooleanExp*, BooleanExp*);
  virtual ~OrExp();

  virtual bool Evaluate(Context&);
  virtual BooleanExp* Replace(const char*, BooleanExp&);
  virtual BooleanExp* Copy() const;

 private:
  BooleanExp* _operand1;
  BooleanExp* _operand2;
};

class NotExp
  : public BooleanExp
{
 public:
  NotExp(BooleanExp*);
  virtual ~NotExp();

  virtual bool Evaluate(Context&);
  virtual BooleanExp* Replace(const char*, BooleanExp&);
  virtual BooleanExp* Copy() const;

 private:
  BooleanExp* _operand;
};

class Constant
  : public BooleanExp
{
 public:
  Constant(bool);
  ~Constant() = default;

  virtual bool Evaluate(Context&);
  virtual BooleanExp* Replace(const char*, BooleanExp&);
  virtual BooleanExp* Copy() const;
 
 private:
  bool _value;
};

class Context
{
 public:
  bool LookUp(const char*) const;
  void Assign(VariableExp*, bool);

 private:
  std::map<VariableExp, bool> _variableMap;
};

class InterpreterDemo
{
 public:
  static void main()
  {
    VariableExp *X = new VariableExp("x");
    VariableExp *Y = new VariableExp("y");

    BooleanExp* expression = new OrExp(
          new AndExp(new Constant(true), X),
          new AndExp(Y, new NotExp(X))
      );

    Context context;
    context.Assign(X, false);
    context.Assign(Y, false);

    bool result = expression->Evaluate(context);
    if(result == true)
      printf("Now Expression Result is true.\n");
    else
      printf("Now Expression Result is false.\n");

    context.Assign(X, true);
    result = expression->Evaluate(context);
    if(result == true)
      printf("Now Expression Result is true.\n");
    else
      printf("Now Expression Result is false.\n");
  }
};

}

#endif // GY_INTERPRETER_H
