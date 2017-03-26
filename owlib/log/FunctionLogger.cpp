/* 
 * File:   FunctionLogger.cpp
 * Author: dark
 * 
 * Created on February 24, 2017, 7:40 AM
 */

#include "FunctionLogger.h"

namespace owl {
  namespace log {

    FunctionLogger::FunctionLogger(std::function<void(const Entry& entry)>& target) : target(target) {
    }

    FunctionLogger::FunctionLogger(const FunctionLogger& orig) : target(orig.target) {
    }

    FunctionLogger::~FunctionLogger() {
    }

    Logger& FunctionLogger::log(const Entry& entry) {
      target(entry);
      return *this;
    }

  }
}
