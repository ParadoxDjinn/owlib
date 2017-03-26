/* 
 * File:   LoggerPointer.cpp
 * Author: dark
 * 
 * Created on February 24, 2017, 1:04 PM
 */

#include "LoggerPointer.h"

namespace owl {
  namespace log {

    LoggerPointer::LoggerPointer()
    : loggerPtr(nullptr) {

    }

    LoggerPointer::LoggerPointer(Logger* logger)
    : loggerPtr(logger) {
    }

    LoggerPointer::LoggerPointer(const LoggerPointer& orig)
    : loggerPtr(orig.loggerPtr) {
    }

    LoggerPointer::~LoggerPointer() {
    }

    Logger* LoggerPointer::getLogger() {
      return loggerPtr;
    }

    void LoggerPointer::setLogger(Logger* logger) {
      loggerPtr = logger;
    }

    bool LoggerPointer::hasLogger() {
      return loggerPtr != nullptr;
    }

    Logger& LoggerPointer::log(const Entry& entry) {
      if (loggerPtr != nullptr) {
        loggerPtr->log(entry);
      }
    }

  }
}