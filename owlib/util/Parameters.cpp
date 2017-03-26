/* 
 * File:   Parameters.cpp
 * Author: dark
 * 
 * Created on February 21, 2017, 6:46 PM
 */

#include "Parameters.h"

namespace owl
{

  namespace util
  {

    Parameters::Parameters(int argc, char** argv)
    {
      for (int i = 0; i < argc; i++)
      {
        add(std::string(argv[i]));
      }
    }

    Parameters::Parameters(const std::vector<std::string>& args)
    {
      for (std::vector<std::string>::const_iterator it = args.begin();
              it != args.end(); it++)
      {
        add(*it);
      }
    }

    Parameters::Parameters(const Parameters& orig)
    : raw(orig.raw), unnamed(orig.unnamed), named(orig.named) { }

    Parameters::~Parameters() { }

    void Parameters::add(std::string arg)
    {
      raw.push_back(arg);
      if (arg.compare(0, 2, "--") == 0)
      {
        arg = arg.substr(2);
        std::size_t index = arg.find('=');
        if (index != std::string::npos)
        {
          named[arg.substr(0, index)] = arg.substr(index + 1);
        }
        else
        {
          unnamed.push_back(arg);
        }
      }
      else if (arg.compare(0, 1, "-") == 0)
      {
        unnamed.push_back(arg.substr(1));
      }
    }

    bool Parameters::containsValue(const std::string& key) const
    {
      if (named.find(key) != named.end())
      {
        return true;
      }
      for (std::string str : unnamed)
      {
        if (str == key)
        {
          return true;
        }
      }
      for (std::string str : raw)
      {
        if (str == key)
        {
          return true;
        }
      }
      return false;
    }

    std::string Parameters::getValue(const std::string& key) const
    {
      return named.at(key);
    }

    void Parameters::setValue(const std::string& key, const std::string& value)
    {
      add("--" + key + '=' + value);
    }

    const std::unordered_map<std::string, std::string>& Parameters::getNamed() const
    {
      return named;
    }

    const std::vector<std::string>& Parameters::getUnnamed() const
    {
      return unnamed;
    }

    const std::vector<std::string>& Parameters::getRaw() const
    {
      return raw;
    }

  }
}
