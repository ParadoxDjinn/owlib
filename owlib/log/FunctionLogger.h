/* 
 * File:   FunctionLogger.h
 * Author: dark
 *
 * Created on February 24, 2017, 7:40 AM
 */

#ifndef OWL_LOG_FUNCTIONLOGGER_H
#define OWL_LOG_FUNCTIONLOGGER_H

#include <functional>
#include "Logger.h"

namespace owl {
  namespace log {

    class FunctionLogger : public Logger {

    public:
      FunctionLogger(std::function<void(const Entry& entry)>& target);
      FunctionLogger(const FunctionLogger& orig);
      virtual ~FunctionLogger();

      Logger& log(const Entry& entry) override;

    private:
      std::function<void(const Entry& entry)>& target;

    } ;
  }
}

#endif /* OWL_LOG_FUNCTIONLOGGER_H */

