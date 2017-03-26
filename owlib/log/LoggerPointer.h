/* 
 * File:   LoggerPointer.h
 * Author: dark
 *
 * Created on February 24, 2017, 1:04 PM
 */

#ifndef OWL_LOG_LOGGERPOINTER_H
#define OWL_LOG_LOGGERPOINTER_H

#include "Logger.h"

namespace owl {
  namespace log {

    class LoggerPointer : public Logger {

    public:
      LoggerPointer();
      LoggerPointer(Logger* logger);
      LoggerPointer(const LoggerPointer& orig);
      virtual ~LoggerPointer();

      Logger& log(const Entry& entry) override;

      void setLogger(Logger* logger);

      Logger* getLogger();

      bool hasLogger();

    private:
      Logger* loggerPtr;

    } ;
  }
}
#endif /* OWL_LOG_LOGGERPOINTER_H */

