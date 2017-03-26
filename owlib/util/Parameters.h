/* 
 * File:   Parameters.h
 * Author: dark
 *
 * Created on February 21, 2017, 6:46 PM
 */

#ifndef OWL_UTIL_PARAMETERS_H
#define OWL_UTIL_PARAMETERS_H

#include <vector>
#include <unordered_map>
#include <string>

#include "Properties.h"

namespace owl {
  namespace util {

    class Parameters : public Properties {

    public:
      Parameters(int argc, char** argv);
      Parameters(const std::vector < std::string >& args);
      Parameters(const Parameters& orig);
      virtual ~Parameters();

      void add(std::string arg);

      bool containsValue(const std::string& key) const override;
      void setValue(const std::string& key, const std::string& value) override;
      std::string getValue(const std::string& key) const override;

      const std::unordered_map < std::string, std::string >& getNamed() const;
      const std::vector < std::string >& getUnnamed() const;
      const std::vector < std::string >& getRaw() const;

    private:
      std::vector < std::string > raw;
      std::vector < std::string > unnamed;
      std::unordered_map< std::string, std::string > named;

    } ;
  }
}

#endif /* OWL_UTIL_PARAMETERS_H */

