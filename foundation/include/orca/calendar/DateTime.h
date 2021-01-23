#ifndef FOUNDATION_DATETIME_INCLUDED
#define FOUNDATION_DATETIME_INCLUDED

#include "orca/FoundationExport.h"

namespace orca {
namespace calendar {

    class Period;

class FOUNDATION_API DateTime {
public:
    /// <summary>
    /// default constructor, initialize as Jan-01, 0000
    /// </summary>
    DateTime() noexcept;
        
    /// <summary>
    /// constructor by gregorian date parameter
    /// </summary>
    /// <param name="year">: Year as integer (0 ~ 9999)</param>
    /// <param name="month">: Month as integer (1 ~ 12)</param>
    /// <param name="day">: Day as integer (1 ~ 31)</param>
    /// <param name="hour">: (optional) Hour as integer (0 ~ 23)</param>
    /// <param name="minute">: (optional) Minute as integer (0 ~ 59)</param>
    /// <param name="second">: (optional) Second as integer (0 ~ 59)</param>
    DateTime(int year, int month, int day, int hour = 0, int minute = 0, int second = 0);

    /// <summary>
    /// constructor by julian day as double, to allow hour, minute, and second
    /// </summary>
    /// <param name="julianDay"></param>
    explicit DateTime(double julianDay);

    /// <summary>
    /// copy constructor.
    /// </summary>
    /// <param name="rhs"></param>
    DateTime(const DateTime& other);

    /// <summary>
    /// destructor
    /// </summary>
    ~DateTime() noexcept;

public:
    DateTime& operator=(const DateTime& other);

    double julianDay() const { return _julianDay; }
    int year() const { return _year; }
    int month() const { return _month; }
    int day() const { return _day; }
    int hour() const { return _hour; }
    int minute() const { return _minute; }
    int second() const { return _second; }

    /// <summary>
    /// Return whether the year is leap year or not
    /// </summary>
    /// <param name="year"></param>
    /// <returns></returns>
    static bool isLeapYear(int year);
    
    /// <summary>
    /// Return number of days in the given year/month
    /// </summary>
    /// <param name="year"></param>
    /// <param name="month"></param>
    /// <returns></returns>
    static int daysOfMonth(int year, int month);

    DateTime& operator+=(int n);
    DateTime& operator-=(int n);
    DateTime& operator++();
    DateTime& operator--();
       
private:
    void computeGregorianDate(double julianDay);
    void computeJulianDay(int year, int month, int day, int hour, int minute, int second);

private:
    int _year;
    int _month;
    int _day;
    int _hour;
    int _minute;
    int _second;
    double _julianDay;
}; // class DateTime

/// global functions

bool FOUNDATION_API operator==(const DateTime& lhs, const DateTime& rhs);
bool FOUNDATION_API operator!=(const DateTime& lhs, const DateTime& rhs);
bool FOUNDATION_API operator<(const DateTime& lhs, const DateTime& rhs);
bool FOUNDATION_API operator>(const DateTime& lhs, const DateTime& rhs);
bool FOUNDATION_API operator<=(const DateTime& lhs, const DateTime& rhs);
bool FOUNDATION_API operator>=(const DateTime& lhs, const DateTime& rhs);

DateTime FOUNDATION_API operator+(const DateTime& lhs, int rhs);
DateTime FOUNDATION_API operator-(const DateTime& lhs, int rhs);
DateTime FOUNDATION_API operator+(const DateTime& lhs, const Period& rhs);
DateTime FOUNDATION_API operator-(const DateTime& lhs, const Period& rhs);

}} // orca::calendar

#endif // !FOUNDATION_DATETIME_INCLUDED

