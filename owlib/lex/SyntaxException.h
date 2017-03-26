/* 
 * File:   SyntaxException.h
 * Author: dark
 *
 * Created on March 14, 2017, 8:16 AM
 */

#ifndef OWL_LEX_SYNTAXEXCEPTION_H
#define OWL_LEX_SYNTAXEXCEPTION_H

#include <string>
#include <exception>
#include <sstream>

namespace owl {
  namespace lex {

    class SyntaxException : public std::exception {

    public:
      SyntaxException(const std::string& message,
              const std::size_t& index,
              const std::size_t& line);
      SyntaxException(const SyntaxException& orig);
      virtual ~SyntaxException();

      const char* what() const noexcept override;

      const std::string message;
      const std::size_t index;
      const std::size_t line;

    } ;

  }
}
#endif /* OWL_LEX_SYNTAXEXCEPTION_H */
