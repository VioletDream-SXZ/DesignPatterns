/******************************************************************************************************************
* Copyright (C): 本代码所有版权为ysq所有，任何个人或者组织不得以任何方式复制、转载以挪作他用，否则将构成对ysq的产权知识侵权。
* FileName     : Responsibility.h
* Author       : Ysq
* Date         : 2019/3/28     18:33     
******************************************************************************************************************/
#ifndef GY_RESPONSIBILITY_H
#define GY_RESPONSIBILITY_H

#include <stdio.h>

namespace GY
{

class AbstractLogger
{
 public:
  enum LOGGER_TYPE
  {
  	GY_LOG_UNKNOWN = 0,
    GY_LOG_INFO    = 1,
    GY_LOG_DEBUG   = 2,
    GY_LOG_ERROR   = 3,
    GY_LOG_WARNING = 4,
  };

  AbstractLogger(LOGGER_TYPE type);
  const char* getLevel() const;

  void setNextLogger(AbstractLogger* logger);
  void logger(LOGGER_TYPE type, const char* message);

  virtual void print(const char* message) = 0;

 private:
  AbstractLogger* nextLogger;
  int level;

  static const char GY_LOG_TYPE_INFO[];
  static const char GY_LOG_TYPE_DEBUG[];
  static const char GY_LOG_TYPE_ERROR[];
  static const char GY_LOG_TYPE_WARNING[];
  static const char GY_LOG_TYPE_UNKNOWN[];
};

class InfoLogger
  : public AbstractLogger
{
 public:
  InfoLogger(LOGGER_TYPE type);

  void print(const char* message);
};

class DebugLogger
  : public AbstractLogger
{
 public:
  DebugLogger(LOGGER_TYPE type);

  void print(const char* message);
};

class ChainPatternDemo
{
 public:
  static AbstractLogger* getChainOfLoggers(){
    AbstractLogger* infoLogger  = new InfoLogger(AbstractLogger::GY_LOG_INFO);
    AbstractLogger* debugLogger = new DebugLogger(AbstractLogger::GY_LOG_DEBUG);

    infoLogger->setNextLogger(debugLogger);

    return infoLogger;
  }

  static void main(){
    AbstractLogger* abstractLogger = getChainOfLoggers();

    abstractLogger->logger(AbstractLogger::GY_LOG_INFO, "123");
    abstractLogger->logger(AbstractLogger::GY_LOG_DEBUG, "234");
    abstractLogger->logger(AbstractLogger::GY_LOG_UNKNOWN, "234");
  }
};

}

#endif // GY_RESPONSIBILITY_H
