/* 
 * File:   Logger.cpp
 * Author: dark
 * 
 * Created on February 23, 2017, 8:23 AM
 */

#include "Logger.h"

namespace owl
{
  namespace log
  {

    Logger& Logger::log(const std::string& module, const Level& level,
            const std::string& message)
    {
      Entry entry(module, level, message);
      return log(entry);
    }

    Logger& Logger::operator ()(const std::string& module, const Level& level, const std::string& message)
    {
      Entry entry(module, level, message);
      return log(entry);
    }

    Logger& Logger::operator<<(const Entry& entry)
    {
      return log(entry);
    }

  }
}