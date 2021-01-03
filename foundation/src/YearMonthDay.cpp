#include "orca/calendar/YearMonthDay.h"

#include "orca/Exception.h"

namespace orca {
namespace calendar {
    Year::Year(std::size_t val)
        :Year()
    {
        ORCA_REQUIRE(val >= 1900,
            "year value must be equal or larger than 1900");
        _val = val;
    }
    Year& Year::operator=(const Year& rhs)
    {
        if (this != &rhs) {
            _val = rhs._val;
        }
        return *this;
    }
    Year& Year::operator+=(int n)
    {
        while (n > 0) {
            this->operator++();
            --n;
        }
        while (n < 0)
        {
            this->operator--();
            ++n;
        }
        ORCA_CONFIRM(_val >= 1900,
            "year value must be equal or larger than 1900");
        return *this;
    }
    Year& Year::operator-=(int n)
    {
        return operator+=(-n);
    }
    void Year::operator++()
    {
        ++_val;
    }
    void Year::operator--()
    {
        --_val;
    }
    bool Year::operator==(const Year& rhs) const
    {
        return _val == rhs._val;
    }
    bool Year::operator!=(const Year& rhs) const
    {
        return !operator==(rhs);
    }
    bool Year::operator<(const Year& rhs) const
    {
        return _val < rhs._val;
    }
    bool Year::operator>(const Year& rhs) const
    {
        return !(operator<(rhs) || operator==(rhs));
    }
    bool Year::operator<=(const Year& rhs) const
    {
        return !operator>(rhs);
    }
    bool Year::operator>=(const Year& rhs) const
    {
        return !operator<(rhs);
    }
    Month::Month(std::size_t val)
        :Month()
    {
        ORCA_REQUIRE(val > 0 && val <= 12,
            "month value must be within [1, 12].");
        _val = val;
    }
    Month& Month::operator=(const Month& rhs)
    {
        if (this != &rhs) {
            _val = rhs._val;
        }
        return *this;
    }
    bool Month::operator==(const Month& rhs) const
    {
        return _val == rhs._val;
    }
    bool Month::operator!=(const Month& rhs) const
    {
        return !operator==(rhs);
    }
    bool Month::operator<(const Month& rhs) const
    {
        return _val < rhs._val;
    }
    bool Month::operator>(const Month& rhs) const
    {
        return !(operator<(rhs) || operator==(rhs));
    }
    bool Month::operator<=(const Month& rhs) const
    {
        return !operator>(rhs);
    }
    bool Month::operator>=(const Month& rhs) const
    {
        return !operator<(rhs);
    }
    Day::Day(std::size_t val)
        :Day()
    {
        ORCA_REQUIRE(val > 0 && val <= 31,
            "day value must be within [1, 31].");
        _val = val;
    }
    Day& Day::operator=(const Day& rhs)
    {
        if (this != &rhs) {
            _val = rhs._val;
        }
        return *this;
    }
    bool Day::operator==(const Day& rhs) const
    {
        return _val == rhs._val;
    }
    bool Day::operator!=(const Day& rhs) const
    {
        return !operator==(rhs);
    }
    bool Day::operator<(const Day& rhs) const
    {
        return _val < rhs._val;
    }
    bool Day::operator>(const Day& rhs) const
    {
        return !(operator<(rhs) || operator==(rhs));
    }
    bool Day::operator<=(const Day& rhs) const
    {
        return !operator>(rhs);
    }
    bool Day::operator>=(const Day& rhs) const
    {
        return !operator<(rhs);
    }

    // implementation of global functions

    Year operator+(const Year& y, int n) 
    { 
        return Year(y) += n; 
    }
    Year operator-(const Year& y, int n) 
    { 
        return Year(y) -= n; 
    }
}} // namespace orca::calendar