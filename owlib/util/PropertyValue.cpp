/* 
 * File:   PropertyValue.cpp
 * Author: dark
 * 
 * Created on March 10, 2017, 6:15 PM
 */

#include <iosfwd>

#include "PropertyValue.h"
#include "Properties.h"

namespace owl
{

  namespace util
  {

    PropertyValue::PropertyValue() : properties(nullptr) { }

    PropertyValue::PropertyValue(const PropertyValue& orig)
    : key(orig.key), properties(orig.properties) { }

    PropertyValue::PropertyValue(std::string key, Properties* properties)
    : key(key), properties(properties) { }

    PropertyValue::~PropertyValue() { }

    template<>
    bool PropertyValue::is<std::string>() const
    {
      if (properties != nullptr)
        return properties->containsValue(key);
      else return false;
    }

    template<>
    PropertyValue& PropertyValue::set<std::string>(const std::string& value)
    {
      properties->setValue(key, value);
      return *this;
    }

    template<>
    std::string PropertyValue::get<std::string>() const
    {
      return properties->getValue(key);
    }

    template<>
    PropertyValue& PropertyValue::set<int>(const int& value)
    {
      return set<std::string>("" + value);
    }

    template<>
    int PropertyValue::get<int>() const
    {
      return std::stoi(get<std::string>());
    }

    template<>
    bool PropertyValue::is<int>() const
    {
      if (!is<std::string>())
      {
        return false;
      }
      try
      {
        get<int>();
        return true;
      }
      catch (...)
      {
        return false;
      }
    }

    template<>
    bool PropertyValue::is<bool>() const
    {
      if (is<std::string>())
      {
        std::string v = get<std::string>();
        if (v.compare("true") == 0 || v.compare("false") == 0)
          return true;
        else
          return is<int>();
      }
      else return false;
    }

    template<>
    PropertyValue& PropertyValue::set<bool>(const bool& value)
    {
      return set<std::string>(value ? "true" : "false");
    }

    template<>
    bool PropertyValue::get<bool>() const
    {
      if (get<std::string>().compare("true") == 0)
        return true;
      else
        return get<int>() == 0;
    }

    std::ostream& operator <<(std::ostream& stream, const PropertyValue& value)
    {
      return stream << value.get<std::string>();
    }

    std::istream& operator >>(std::istream& stream, PropertyValue& value)
    {
      std::string str;
      stream >> str;
      value.set<std::string>(str);
      return stream;
    }

  }
}
