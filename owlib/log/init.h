/* 
 * File:   init.h
 * Author: dark
 *
 * Created on February 24, 2017, 1:04 PM
 */

#ifndef OWL_LOG_INIT_H
#define OWL_LOG_INIT_H

#include <limits>

#include "LoggerPointer.h"
#include "StreamLogger.h"

namespace owl {
  namespace log {

    static const Level off     ("OFF", std::numeric_limits<unsigned int>::max());
    static const Level severe  ("SEVERE", 1000);
    static const Level warning ("WARNING", 900);
    static const Level info    ("INFO",    800);
    static const Level config  ("CONFIG",  700);
    static const Level fine    ("FINE",    500);
    static const Level finer   ("FINER",   400);
    static const Level finest  ("FINEST",  300);
    static const Level all     ("ALL", std::numeric_limits<unsigned int>::min());

    static LoggerPointer out;

  }
}

#endif /* INIT_H */

