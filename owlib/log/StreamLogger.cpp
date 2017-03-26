/* 
 * File:   StreamLogger.cpp
 * Author: dark
 * 
 * Created on February 24, 2017, 7:35 AM
 */

#include "StreamLogger.h"

namespace owl
{
  namespace log
  {

    StreamLogger::StreamLogger(std::ostream& stream) : target(stream)
    {
      target << " --- Logger begin at " << timeToStr(std::chrono::system_clock::now()) << " --- " << std::endl;
    }

    StreamLogger::StreamLogger(const StreamLogger& orig) : target(orig.target) { }

    StreamLogger::~StreamLogger()
    {
      target << " --- Logger end at " << timeToStr(std::chrono::system_clock::now()) << " --- " << std::endl;
    }

    Logger& StreamLogger::log(const Entry& entry)
    {
      std::string timeStr(timeToStr(entry.time));
      std::string levelName(entry.level.name);

      while (levelName.length() < Level::MAX_NAME_LENGHT)
      {
        levelName += ' ';
      }

      std::string head = timeStr + " " + levelName + " " + entry.module + ": ";

      std::string::size_type nlPos = entry.message.find_first_of('\n');
      if (nlPos == std::string::npos)
      {
        target << head << entry.message << std::endl;
      }
      else
      {
        std::string message(entry.message);
        target << head << message.substr(0, nlPos) << std::endl;
        for (std::string::size_type i = 0; i < head.length(); i++)
        {
          head[i] = ' ';
        }
        do
        {
          message = message.substr(++nlPos);
          nlPos = message.find_first_of("\n");
          target << head << message.substr(0, nlPos) << std::endl;
        }
        while (nlPos != std::string::npos);
      }
      return *this;
    }

    std::string StreamLogger::timeToStr(std::chrono::system_clock::time_point timePoint)
    {
      std::time_t t = std::chrono::system_clock::to_time_t(timePoint);
      std::string timeStr(std::ctime(&t));
      timeStr.resize(timeStr.length() - 1);
      return timeStr;
    }

  }
}
