#ifndef FOUNDATION_DATE_INCLUDED
#define FOUNDATION_DATE_INCLUDED

#include <cstddef>
#include <memory>

#include "orca/FoundationExport.h"

namespace orca {
namespace calendar {

    class Year;
    class Month;
    class Day;
    class Period;

    class FOUNDATION_API Date {
    public:
        Date() noexcept;
        Date(const Year& year, const Month& month, const Day& day);
        Date(const Date& rhs);
        ~Date() noexcept;        

    public:
        Date& operator=(const Date& rhs);
        Date& operator+=(int n);
        Date& operator-=(int n);

        void operator++();
        void operator--();

        Year year() const;
        Month month() const;
        Day day() const;
        std::size_t serialNumber() const;

        static Day endDayOfMonth(const Year& year, const Month& month);

    private:
        class Pimpl;
        std::unique_ptr<Pimpl> _pimpl;
    };

    bool FOUNDATION_API operator==(const Date& lhs, const Date& rhs);
    bool FOUNDATION_API operator!=(const Date& lhs, const Date& rhs); 
    bool FOUNDATION_API operator<(const Date& lhs, const Date& rhs);
    bool FOUNDATION_API operator>(const Date& lhs, const Date& rhs); 
    bool FOUNDATION_API operator<=(const Date& lhs, const Date& rhs); 
    bool FOUNDATION_API operator>=(const Date& lhs, const Date& rhs); 

    Date FOUNDATION_API operator+(const Date& d, int n);
    Date FOUNDATION_API operator-(const Date& d, int n);
    Date FOUNDATION_API operator+(const Date& d, const Period& p);
    Date FOUNDATION_API operator-(const Date& d, const Period& p);
}} // namespace orca::calendar

#endif // !FOUNDATION_DATE_INCLUDED
