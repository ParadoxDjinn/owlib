/* 
 * File:   Level.cpp
 * Author: dark
 * 
 * Created on February 23, 2017, 8:33 AM
 */

#include "Level.h"

namespace owl
{
  namespace log
  {

    std::size_t Level::MAX_NAME_LENGHT = 0;

    Level::Level(std::string name, int weight)
    : name(name), weight(weight)
    {
      if (MAX_NAME_LENGHT < name.length())
      {
        MAX_NAME_LENGHT = name.length();
      }
    }

    Level::Level(const Level& orig)
    : name(orig.name), weight(orig.weight) { }

    Level::~Level() { }

  }
}