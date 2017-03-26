/* 
 * File:   Block.h
 * Author: dark
 *
 * Created on February 21, 2017, 7:58 AM
 */

#ifndef OWL_LEX_BLOCK_H
#define OWL_LEX_BLOCK_H

#include <string>

namespace owl {
  namespace lex {

    template<typename TOKEN>
    class Block {

    public:

      Block(TOKEN token, std::string str, std::size_t line, std::size_t index)
      : token(token), str(str), line(line), index(index) {
      }

      Block(const Block<TOKEN>& other)
      : token(other.token), str(other.str), line(other.line), index(other.index) {
      }

      virtual ~Block() {
      }

      const TOKEN token;
      const std::string str;
      const std::size_t index;
      const std::size_t line;

    } ;
  }
}
#endif /* OWL_LEX_BLOCK_H */
