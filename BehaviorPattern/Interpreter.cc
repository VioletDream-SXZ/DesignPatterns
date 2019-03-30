#include "Interpreter.h"
#include "../Tool/memoryTool.h"
#include <string.h>

namespace GY
{

VariableExp::VariableExp(const char* name)
{
  _variableName = strdup(name);
}

VariableExp::~VariableExp()
{
  free(_variableName);
}

bool VariableExp::Evaluate(Context& Context)
{
  Context.LookUp(_variableName);
}

BooleanExp* VariableExp::Replace(const char* name, BooleanExp& other)
{
  if(strcmp(_variableName, name) == 0)
    return other.Copy();
  else
    return new VariableExp(_variableName);
}

BooleanExp* VariableExp::Copy() const
{
  return new VariableExp(_variableName);
}

bool VariableExp::operator<(const VariableExp& exp) const
{
  return strcmp(_variableName, exp._variableName) < 0;
}

AndExp::AndExp(BooleanExp* exp1, BooleanExp* exp2)
{
  _operand1 = exp1;
  _operand2 = exp2;
}

AndExp::~AndExp()
{
  delete _operand1;
  delete _operand2;
}

bool AndExp::Evaluate(Context& Context)
{
  return _operand1->Evaluate(Context) &&
         _operand2->Evaluate(Context);
}

BooleanExp* AndExp::Replace(const char* name, BooleanExp& exp)
{
  return new AndExp(
        _operand1->Replace(name, exp),
        _operand2->Replace(name, exp)
    );
}

BooleanExp* AndExp::Copy() const
{
  return new AndExp(
        _operand1->Copy(), 
        _operand2->Copy()
    );
}

OrExp::OrExp(BooleanExp* exp1, BooleanExp* exp2)
{
  _operand1 = exp1;
  _operand2 = exp2;
}

OrExp::~OrExp()
{
  delete _operand1;
  delete _operand2;
}

bool OrExp::Evaluate(Context& Context)
{
  return _operand1->Evaluate(Context) ||
         _operand2->Evaluate(Context);
}

BooleanExp* OrExp::Replace(const char* name, BooleanExp& exp)
{
  return new OrExp(
        _operand1->Replace(name, exp),
        _operand2->Replace(name, exp)
    );
}

BooleanExp* OrExp::Copy() const
{
  return new OrExp(
        _operand1->Copy(),
        _operand2->Copy()
    );
}

NotExp::NotExp(BooleanExp* exp)
{
  _operand = exp;
}

NotExp::~NotExp()
{
  delete _operand;
}

bool NotExp::Evaluate(Context& Context)
{
  return !(_operand->Evaluate(Context));
}

BooleanExp* NotExp::Replace(const char* name, BooleanExp& exp)
{
  return new NotExp(
        _operand->Replace(name, exp)
    );
}

BooleanExp* NotExp::Copy() const
{
  return new NotExp(
        _operand->Copy()
    );
}

Constant::Constant(bool value)
{
  _value = value;
}

bool Constant::Evaluate(Context&)
{
  return _value;
}

BooleanExp* Constant::Replace(const char* name, BooleanExp& exp)
{
  return new Constant(_value);
}

BooleanExp* Constant::Copy() const
{
  return new Constant(_value);
}

bool Context::LookUp(const char* name) const
{
  VariableExp exp(name);
  if(_variableMap.find(exp) != _variableMap.end())
  	return _variableMap.find(exp)->second;

  // TODO
  return false;
}

void Context::Assign(VariableExp* exp, bool value)
{
  _variableMap[*exp] = value;
}

}
