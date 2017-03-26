/* 
 * File:   Config.cpp
 * Author: dark
 * 
 * Created on March 9, 2017, 8:16 AM
 */

#include "Config.h"

namespace owl
{
  namespace util
  {

    Config::Config() { }

    Config::Config(const std::map<std::string, std::string >& data)
    : data(data) { }

    Config::Config(const Config& orig) : data(orig.data) { }

    Config::~Config() { }

    bool Config::containsValue(const std::string& key) const
    {
      return data.find(key) != data.end();
    }

    void Config::setValue(const std::string& key, const std::string& value)
    {
      data[key] = value;
    }

    std::string Config::getValue(const std::string& key) const
    {
      return data.at(key);
    }

    std::ostream& operator <<(std::ostream& stream, const Config& config)
    {
      for (auto pair : config.data)
      {
        stream << pair.first << '=' << pair.second << std::endl;
      }
      return stream;
    }

    std::istream& operator >>(std::istream& stream, Config& config) throw (std::invalid_argument)
    {
      int i = 0;
      auto temp(config.data);
      while (!stream.eof())
      {
        std::string line;
        stream >> line;
        std::size_t find = line.find('=');
        if (find != line.npos )
        {
          config.data[line.substr(0, find)] = line.substr(find + 1);
        }
        else
        {
          config.data = temp;
          throw std::invalid_argument("There is no assignment in line: " + i);
        }
        i++;
      }
      return stream;
    }

  }
}
