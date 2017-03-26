/* 
 * File:   Exception.h
 * Author: dark
 *
 * Created on March 3, 2017, 7:11 AM
 */

#ifndef OWL_UTIL_EXCEPTION_H
#define OWL_UTIL_EXCEPTION_H

#include <exception>
#include <string>

namespace owl {
  namespace util {

    class Exception : std::exception {

    public:
      Exception(const std::string& message);
      Exception(const Exception& orig);
      virtual ~Exception();

      const std::string message;
      const char* what() const noexcept override;

    } ;
  }
}
#endif /* OWL_UTIL_EXCEPTION_H */

