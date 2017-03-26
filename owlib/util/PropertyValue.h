/* 
 * File:   PropertyValue.h
 * Author: dark
 *
 * Created on March 10, 2017, 6:15 PM
 */

#ifndef OWL_UTIL_PROPERTY_VALUE_H
#define OWL_UTIL_PROPERTY_VALUE_H

#include <string>
#include <functional>



namespace owl {
  namespace util {

    class Properties;

    class PropertyValue {

    public:
      PropertyValue();
      PropertyValue(const PropertyValue& orig);
      PropertyValue(std::string key, Properties* properties);
      virtual ~PropertyValue();

      template<class VALUE>
      PropertyValue& operator =(VALUE value) {
        return set<VALUE>(value);
      }

      template<class VALUE>
      operator VALUE () const {
        return get<VALUE>();
      }

      template<class VALUE>
      VALUE operator || (VALUE& value) const {
        return get<VALUE>(value);
      }

      template<class VALUE>
      bool is() const;

      template<class VALUE>
      PropertyValue& set(const VALUE& value);

      template<class VALUE>
      VALUE get() const;

      template<class VALUE>
      VALUE get(const VALUE& defaultValue) const {
        if (is<VALUE>())
          return get<VALUE>();
        else
          return defaultValue;
      }

      template<class VALUE>
      bool ifExsist(std::function<void(VALUE) > func) {
        if (this->is<VALUE>()) {
          func(this->get<VALUE>());
          return true;
        } else
          return false;
      }

      friend std::ostream& operator << (std::ostream& stream, const PropertyValue& value);
      friend std::istream& operator >> (std::istream& stream,       PropertyValue& value);

    private:
      std::string key;
      Properties* properties;

    } ;

  }
}
#endif /* PROPERTYVALUE_H */
