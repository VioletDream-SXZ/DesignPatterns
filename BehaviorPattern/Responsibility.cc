#include "Responsibility.h"

namespace GY
{

const char AbstractLogger::GY_LOG_TYPE_INFO[]  = "gy::info";
const char AbstractLogger::GY_LOG_TYPE_DEBUG[] = "gy::debug";
const char AbstractLogger::GY_LOG_TYPE_ERROR[] = "gy::error";
const char AbstractLogger::GY_LOG_TYPE_WARNING[] = "gy::warning";
const char AbstractLogger::GY_LOG_TYPE_UNKNOWN[] = "gy::unknown";

AbstractLogger::AbstractLogger(LOGGER_TYPE type)
{
  nextLogger = NULL;
  level      = type;
}

const char* AbstractLogger::getLevel() const
{
  switch(level)
  {
    case GY_LOG_INFO:
      return GY_LOG_TYPE_INFO;
    case GY_LOG_DEBUG:
      return GY_LOG_TYPE_DEBUG;
    case GY_LOG_ERROR:
      return GY_LOG_TYPE_ERROR;
    case GY_LOG_WARNING:
      return GY_LOG_TYPE_WARNING;
    default:
      return GY_LOG_TYPE_UNKNOWN;
  }

  return GY_LOG_TYPE_UNKNOWN;
}

void AbstractLogger::setNextLogger(AbstractLogger* logger)
{
  nextLogger = logger;
}

void AbstractLogger::logger(LOGGER_TYPE type, const char* message)
{
  if(level == type)
  {
    print(message);
    return;
  }

  if(nextLogger != NULL)
  	nextLogger->logger(type, message);
}

InfoLogger::InfoLogger(LOGGER_TYPE type)
  : AbstractLogger(type)
{
}

void InfoLogger::print(const char* message)
{
  printf("%s: %s.\n", getLevel(), message);
}

DebugLogger::DebugLogger(LOGGER_TYPE type)
  : AbstractLogger(type)
{
}

void DebugLogger::print(const char* message)
{
  printf("%s: %s.\n", getLevel(), message);
}

}
