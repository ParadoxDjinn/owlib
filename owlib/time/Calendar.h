/* 
 * File:   Calendar.h
 * Author: dark
 *
 * Created on March 21, 2017, 6:53 PM
 */

#ifndef OWL_TIME_CALENDAR_H
#define OWL_TIME_CALENDAR_H

#include <chrono>
#include <string>
#include <sstream>
#include <iomanip>

namespace owl {
  namespace time {

    template<typename CLOCK = std::chrono::system_clock>
    class Calendar {

    public:
      typedef typename CLOCK::time_point time_point;

      Calendar() : timePoint(CLOCK::now()) {
      };

      Calendar(time_point timePoint) : timePoint(timePoint) {
      };

      Calendar(const Calendar& orig) : timePoint(orig.timePoint) {
      };

      virtual ~Calendar() = default;

      void setPoint(time_point timePoint) {
        this->timePoint = timePoint;
      }

      time_point getPoint() {
        return this->timePoint;
      }

      void setTime(std::time_t time) {
        timePoint = CLOCK::from_time_t(time);
      }

      std::time_t getTime() {
        return CLOCK::to_time_t(timePoint);
      }

      void setTM(std::tm tm) {
        setTime(std::mktime(&tm));
      }

      std::tm getTM() {
        std::time_t time = getTime();
        return *std::localtime(&time);
      }

      void setSec(int sec) {
        std::tm tm = getTM();
        tm.tm_sec = sec;
        setTM(tm);
      }

      int getSec() {
        return getTM().tm_sec;
      }

      void setMin(int min) {
        std::tm tm = getTM();
        tm.tm_min = min;
        setTM(tm);
      }

      int getMin() {
        return getTM().tm_min;
      }

      void setHour(int hour) {
        std::tm tm = getTM();
        tm.tm_hour = hour;
        setTM(tm);
      }

      int getHour() {
        return getTM().tm_hour;
      }

      void setDay(int day) {
        std::tm tm = getTM();
        tm.tm_mday = day;
        setTM(tm);
      }

      int getDay() {
        return getTM().tm_mday;
      }

      void setMonth(int month) {
        std::tm tm = getTM();
        tm.tm_mon = (month - 1);
        setTM(tm);
      }

      int getMonth() {
        return (getTM().tm_mon + 1);
      }

      void setYear(int year) {
        std::tm tm = getTM();
        tm.tm_year = (year - 1900);
        setTM(tm);
      }

      int getYear() {
        return (getTM().tm_year + 1900);
      }

      std::string toString() {
        return toString(timePoint);
      }

      template<typename CLOCK2 = std::chrono::system_clock>
      static std::string toString(typename CLOCK2::time_point tp) {
        std::time_t t = CLOCK2::to_time_t(tp);
        std::string timeStr(std::ctime(&t));
        timeStr.resize(timeStr.length() - 1);
        return timeStr;
      }

      template<typename CLOCK2 = std::chrono::system_clock>
      static  typename CLOCK2::time_point fromString(std::string str, std::string format = "%b %d %Y %H:%M:%S") {
        std::tm tm = {};
        std::stringstream ss(str);
        ss >> std::get_time(&tm, format.c_str());
        return CLOCK2::from_time_t(std::mktime(&tm));
      }

      template<typename CLOCK2 = std::chrono::system_clock>
      static std::string toString(typename CLOCK2::duration d) {
        std::string result;
        auto h = std::chrono::duration_cast<std::chrono::hours>(d);
        result += std::to_string(h.count()) + "h ";
        d -= h;
        auto m = std::chrono::duration_cast<std::chrono::minutes>(d);
        result += std::to_string(m.count()) + "m ";
        d -= m;
        auto s = std::chrono::duration_cast<std::chrono::seconds>(d);
        result += std::to_string(s.count()) + "s ";
        return result;
      }

    private:
      time_point timePoint;

    } ;

    using Cal = Calendar<>;
  }
}

#endif /* OWL_TIME_CALENDAR_H */
