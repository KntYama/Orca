#include "orca/calendar/YearMonthDay.h"

#include "orca/Exception.h"

namespace orca {
namespace calendar {
    Year& Year::operator=(const Year& rhs)
    {
        if (this != &rhs) {
            _val = rhs._val;
        }
        return *this;
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
}} // namespace orca::calendar