#include "orca/calendar/DateTime.h"
#include "orca/calendar/Period.h"
#include "orca/Exception.h"

#include <cmath>

namespace orca {
namespace calendar {


DateTime::DateTime() noexcept
    :_year(0),
    _month(1),
    _day(1),
    _hour(0),
    _minute(0),
    _second(0)
{
    computeJulianDay(_year, _month, _day, _hour, _minute, _second);
}
DateTime::DateTime(int year, int month, int day, int hour, int minute, int second)
    :_year(year),
    _month(month),
    _day(day),
    _hour(hour),
    _minute(minute),
    _second(second)
{
    computeJulianDay(_year, _month, _day, _hour, _minute, _second);
}
DateTime::DateTime(double julianDay)
    :_julianDay(julianDay)
{
    computeGregorianDate(_julianDay);
}
DateTime::DateTime(const DateTime& other)
    :_year(other._year),
    _month(other._month),
    _day(other._day),
    _hour(other._hour),
    _minute(other._minute),
    _second(other._second),
    _julianDay(other._julianDay)
{
}
DateTime::~DateTime() noexcept
{
}
DateTime& DateTime::operator=(const DateTime& other)
{
    if (this != &other) {
        _julianDay = other._julianDay;
        _year = other._year;
        _month = other._month;
        _day = other._day;
        _hour = other._hour;
        _minute = other._minute;
        _second = other._second;
    }
    return *this;
}
bool DateTime::isLeapYear(int year)
{
    //divisible by 4, not if divisible by 100, but true if divisible by 400
    return (!(year % 4)) && ((year % 100) || (!(year % 400)));
}
int DateTime::daysOfMonth(int year, int month)
{
    switch (month) {
    case 2:
        if (isLeapYear(year)) {
            return 29;
        }
        else {
            return 28;
        };
    case 4:
    case 6:
    case 9:
    case 11:
        return 30;
    default:
        return 31;
    };
}
DateTime& DateTime::operator+=(int n)
{
    _julianDay += n;
    computeGregorianDate(_julianDay);
    return *this;
}
DateTime& DateTime::operator-=(int n)
{
    return this->operator+=(-n);
}
DateTime& DateTime::operator++()
{
    return this->operator+=(1);
}
DateTime& DateTime::operator--()
{
    return this->operator+=(-1);
}
void DateTime::computeGregorianDate(double julianDay)
{
    double z = std::floor(julianDay - 1721118.5);
    double r = julianDay - 1721118.5 - z;
    double g = z - 0.25;
    double a = std::floor(g / 36524.25);
    double b = a - std::floor(a / 4);
    _year = int(std::floor((b + g) / 365.25));
    double c = b + z - std::floor(365.25 * _year);
    _month = int(std::floor((5 * c + 456) / 153));
    double dday = c - std::floor((153.0 * _month - 457) / 5) + r;
    _day = int(dday);
    if (_month > 12)
    {
        ++_year;
        _month -= 12;
    }
    r *= 24;
    _hour = int(std::floor(r));
    r -= std::floor(r);
    r *= 60;
    _minute = int(std::floor(r));
    r -= std::floor(r);
    r *= 60;
    _second = int(std::floor(r));

}
void DateTime::computeJulianDay(int year, int month, int day, int hour, int minute, int second)
{
    // lookup table for (153*month - 457)/5 - note that 3 <= month <= 14.
    static int lookup[] = { -91, -60, -30, 0, 31, 61, 92, 122, 153, 184, 214, 245, 275, 306, 337 };

    // day to double
    double dday = double(day) + double((hour * 60 + minute) * 60 + second) / 86400.0;
    if (month < 3)
    {
        month += 12;
        --year;
    }
    double dyear = double(year);

    _julianDay = double(dday + lookup[month] + 365 * year + std::floor(dyear / 4) - std::floor(dyear / 100) + std::floor(dyear / 400) + 1721118.5);
}

// implementation of global function

bool operator==(const DateTime& lhs, const DateTime& rhs)
{
    return lhs.julianDay() == rhs.julianDay();
}

bool operator!=(const DateTime& lhs, const DateTime& rhs)
{
    return !(lhs == rhs);
}

bool operator<(const DateTime& lhs, const DateTime& rhs)
{
    return lhs.julianDay() < rhs.julianDay();
}

bool operator>(const DateTime& lhs, const DateTime& rhs)
{
    return rhs < lhs;
}

bool operator<=(const DateTime& lhs, const DateTime& rhs)
{
    return !(lhs > rhs);
}

bool operator>=(const DateTime& lhs, const DateTime& rhs)
{
    return !(lhs < rhs);
}

DateTime operator+(const DateTime& lhs, int rhs)
{
    return DateTime(lhs).operator+=(rhs);
}

DateTime operator-(const DateTime& lhs, int rhs)
{
    return DateTime(lhs).operator-=(rhs);
}

DateTime operator+(const DateTime& lhs, const Period& rhs)
{
    switch (rhs.timeUnit())
    {
    case Period::Days:
        return DateTime(lhs) += rhs.numOfUnit();
    case Period::Weeks:
        return DateTime(lhs) += (7 * rhs.numOfUnit());
    case Period::Months: {
        auto y = lhs.year();
        auto m = lhs.month() + rhs.numOfUnit();
        while (m > 12) {
            m -= 12;
            ++y;
        }
        auto d = lhs.day();
        if (d > DateTime::daysOfMonth(y, m)) {
            d = DateTime::daysOfMonth(y, m);
        }
        return DateTime(y, m, d);
    }
    case Period::Years: {
        auto y = lhs.year() + rhs.timeUnit();
        auto m = lhs.month();
        auto d = lhs.day();
        if (d > DateTime::daysOfMonth(y, m)) {
            d = DateTime::daysOfMonth(y, m);
        }
        return DateTime(y, m, d);
    }
    default:
        ORCA_THROW_EXCEPTION("Period invalid status.");
        break;
    }
    return DateTime();
}

DateTime operator-(const DateTime& lhs, const Period& rhs)
{
    return lhs + (-rhs);
}

}} // namespace orca::calendar