
/* 
 * File:   SyntaxException.cpp
 * Author: dark
 * 
 * Created on March 14, 2017, 8:16 AM
 */

#include "SyntaxException.h"

namespace owl
{
  namespace lex
  {

    SyntaxException::SyntaxException(
            const std::string& message,
            const std::size_t& line,
            const std::size_t& index)
    : message(message), line(line), index(index) { }

    SyntaxException::SyntaxException(const SyntaxException& orig)
    : message(orig.message), line(orig.line), index(orig.index) { }

    SyntaxException::~SyntaxException() { }

    const char* SyntaxException::what() const noexcept
    {
      std::stringstream ss;
      ss << message << " at line " << line << ", index " << index;
      return ss.str().c_str();
    }

  }
}
