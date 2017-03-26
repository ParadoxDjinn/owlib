/* 
 * File:   Logger.h
 * Author: dark
 *
 * Created on February 23, 2017, 8:23 AM
 */

#ifndef OWL_LOG_LOGGER_H
#define OWL_LOG_LOGGER_H

#include <string>
#include "Entry.h"

namespace owl {
  namespace log {

    class Logger {

    public:

      virtual ~Logger() = default;

      Logger& log(const std::string& module, const Level& level, const std::string& message);

      Logger& operator()(const std::string& module, const Level& level, const std::string& message);

      virtual Logger& log(const Entry& entry) = 0;

      Logger& operator<<(const Entry& entry);

    } ;
  }
}

#endif /* OWL_LOG_LOGGER_H */

