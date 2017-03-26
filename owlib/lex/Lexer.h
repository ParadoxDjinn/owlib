/* 
 * File:   Lexer.h
 * Author: dark
 *
 * Created on February 20, 2017, 9:05 AM
 */

#ifndef OWL_LEX_LEXER_H
#define OWL_LEX_LEXER_H

#include <istream>
#include <string>
#include <unordered_map>
#include <vector>

#include "Block.h"

namespace owl {
  namespace lex {

    template<typename TOKEN>
    class Lexer {

    public:

      Lexer() {
      }

      Lexer(const Lexer& other)
      : tokens(other.tokens), line(other.line), index(other.index) {
      }

      virtual ~Lexer() {
      }

      void add(std::string key, TOKEN token) {
        tokens.insert(std::make_pair(
                std::string(key.rbegin(), key.rend()), token));
      }

      void remove(std::string key) {
        tokens.erase(key);
      }

      bool contains(std::string key) {
        return tokens.find(key) != tokens.end();
      }

      std::vector<Block<TOKEN>> lexAll(std::istream& stream) {
        std::vector<Block < TOKEN>> result;
        while (true) {
          Block<TOKEN> block = lex(stream);
          result.push_back(block);
          if (block.token == noneToken()) {
            return result;
          }
        }
      }

      Block<TOKEN> lex(std::istream& stream) {
        std::string str = "";
        char c;
        std::size_t indexTemp = index;
        std::size_t lineTemp = line;
        while (stream.get(c)) {
          str = c + str;

          if (c == '\n') {
            index = 0;
            line++;
            indexTemp++;
          } else {
            indexTemp = ++index;
          }

          auto find = tokens.begin();

          while (find != tokens.end()) {
            std::string key = find->first;

            auto length = key.length();
            if (!key.empty() && str.compare(0, length, key) == 0) {
              str = str.substr(length, str.length() - length);
              return Block<TOKEN>(find->second,
                      std::string(str.rbegin(), str.rend()),
                      lineTemp, indexTemp);
            }
            find++;
          }
          lineTemp = line;
          indexTemp = index;
        }
        return Block<TOKEN>(noneToken(), std::string(str.rbegin(), str.rend()),
                line, index);
      }

      TOKEN noneToken() {
        return tokens.at("");
      }

      std::size_t getIndex() {
        return index;
      }

      std::size_t getLine() {
        return line;
      }

      void reset() {
        index = 0;
        line = 1;
      }

    private:
      std::unordered_map<std::string, TOKEN> tokens;
      std::size_t index = 0;
      std::size_t line = 1;

    } ;
  }
}
#endif /* OWL_LEX_LEXER_H */
