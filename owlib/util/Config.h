/* 
 * File:   Config.h
 * Author: dark
 *
 * Created on March 9, 2017, 8:16 AM
 */

#ifndef OWL_UTIL_CONFIG_H
#define OWL_UTIL_CONFIG_H

#include <string>
#include <map>
#include <iostream>
#include <stdexcept>

#include "Properties.h"


namespace owl {
  namespace util {

    class Config : public Properties {

    public:
      Config();
      Config(const std::map < std::string, std::string >& data);
      Config(const Config& orig);
      virtual ~Config();

      friend std::ostream& operator << (std::ostream& stream, const Config& config);
      friend std::istream& operator >> (std::istream& stream,       Config& config) throw (std::invalid_argument);

      bool containsValue(const std::string& key) const override;
      void setValue(const std::string& key, const std::string& value) override;
      std::string getValue(const std::string& key) const override;

      std::map < std::string, std::string > data;

    } ;
  }
}
#endif /* OWL_UTIL_CONFIG_H */

