/* 
 * File:   Entry.h
 * Author: dark
 *
 * Created on February 23, 2017, 8:26 AM
 */

#ifndef OWL_LOG_ENTRY_H
#define OWL_LOG_ENTRY_H

#include <string>
#include <chrono>

#include "Level.h"

namespace owl {
  namespace log {

    class Entry {

    public:

      Entry(  const std::string& module,
              const Level& level,
              const std::string& message);

      Entry(const Entry& orig);

      virtual ~Entry();

      const std::chrono::system_clock::time_point time;
      const std::string module;
      const std::string message;
      const Level level;

    } ;
  }
}
#endif /* OWL_LOG_ENTRY_H */

