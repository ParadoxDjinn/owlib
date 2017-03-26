/* 
 * File:   Exception.cpp
 * Author: dark
 * 
 * Created on March 3, 2017, 7:11 AM
 */

#include "Exception.h"

namespace owl {
  namespace util {

    Exception::Exception(const std::string& message) : message(message) {
    }

    Exception::Exception(const Exception& orig) : message(orig.message) {
    }

    Exception::~Exception() {
    }

    const char* Exception::what() const noexcept {
      return message.c_str();
    }

  }
}