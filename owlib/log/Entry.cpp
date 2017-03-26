/* 
 * File:   Entry.cpp
 * Author: dark
 * 
 * Created on February 23, 2017, 8:26 AM
 */

#include "Entry.h"

namespace owl
{
  namespace log
  {

    Entry::Entry(const std::string& module, const Level& level,
            const std::string& message)
    : time(std::chrono::system_clock::now()),
    module(module), level(level), message(message) { }

    Entry::Entry(const Entry& orig)
    : time(orig.time), module(orig.module),
    level(orig.level), message(orig.message) { }

    Entry::~Entry() { }

  }
}