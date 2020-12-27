#ifndef CALENDAR_DATE_INCLUDED
#define CALENDAR_DATE_INCLUDED

#include <cstddef>
#include <memory>

#include "orca/calendar/export.h"

namespace orca {
namespace calendar {

    class Year;
    class Month;
    class Day;

    class CALENDAR_API Date {
    public:
        Date() noexcept;
        Date(const Year& year, const Month& month, const Day& day);
        Date(const Date& rhs);
        ~Date() noexcept;

    public:
        Date& operator =(const Date& rhs);
        
        Year year() const;
        Month month() const;
        Day day() const;

        bool operator==(const Date& rhs) const;
        bool operator!=(const Date& rhs) const;
        bool operator <(const Date& rhs) const;
        bool operator >(const Date& rhs) const;
        bool operator<=(const Date& rhs) const;
        bool operator>=(const Date& rhs) const;

        void operator++();
        void operator--();

    private:
        class Pimpl;
        std::unique_ptr<Pimpl> _pimpl;
    };
}} // namespace orca::calendar

#endif // CALENDAR_DATE_INCLUDED
