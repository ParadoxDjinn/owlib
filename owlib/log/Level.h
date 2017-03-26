/* 
 * File:   Level.h
 * Author: dark
 *
 * Created on February 23, 2017, 8:33 AM
 */

#ifndef OWL_LOG_LEVEL_H
#define OWL_LOG_LEVEL_H

#include <string>

namespace owl {
  namespace log {

    class Level {

    public:

      Level(std::string name, int weight);

      Level(const Level& orig);

      virtual ~Level();

      const  std::string name;
      const  int         weight;

      static std::size_t MAX_NAME_LENGHT;
    } ;

  }
}
#endif /* OWL_LOG_LEVEL_H */

