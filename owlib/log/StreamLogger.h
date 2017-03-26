/* 
 * File:   StreamLogger.h
 * Author: dark
 *
 * Created on February 24, 2017, 7:35 AM
 */

#ifndef OWL_LOG_STREAMLOGGER_H
#define OWL_LOG_STREAMLOGGER_H

#include <ostream>
#include "Logger.h"

namespace owl  {
  namespace log {

    class StreamLogger : public Logger {

    public:
      StreamLogger(std::ostream& stream);
      StreamLogger(const StreamLogger& orig);
      virtual ~StreamLogger();

      Logger& log(const Entry& entry) override;

    private:
      std::ostream& target;

      std::string timeToStr(std::chrono::system_clock::time_point timePoint);

    } ;
  }
}

#endif /* STREAMLOGGER_H */

