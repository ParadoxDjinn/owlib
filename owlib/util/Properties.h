/* 
 * File:   Properties.h
 * Author: dark
 *
 * Created on March 9, 2017, 7:54 AM
 */

#ifndef OWL_UTIL_PROPERTIES_H
#define OWL_UTIL_PROPERTIES_H

#include <string>
#include "PropertyValue.h"

namespace owl {
  namespace util {

    class Properties {

    public:

      virtual ~Properties() = default;

      PropertyValue get(const std::string& key) {
        return PropertyValue(key, this);
      }

      virtual bool containsValue(const std::string& key) const = 0;
      virtual void setValue(const std::string& key, const std::string& value) = 0;
      virtual std::string getValue(const std::string& key) const = 0;

    } ;
  }
}
#endif /* OWL_UTIL_PROPERTIES_H */

