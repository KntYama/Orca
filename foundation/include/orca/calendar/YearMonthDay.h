#ifndef FOUNDATION_YEARMONTHDAY_INCLUDED
#define FOUNDATION_YEARMONTHDAY_INCLUDED

#include <cstddef>

#include "orca/FoundationExport.h"

namespace orca {
namespace calendar {
    class FOUNDATION_API Year {
    public:
        Year() :_val(1900) {}
        explicit Year(std::size_t val);
        Year(const Year& rhs) :_val(rhs._val) {}

        ~Year() noexcept {}

    public:
        Year& operator=(const Year& rhs);
        Year& operator+=(int n);
        Year& operator-=(int n);

        void operator++();
        void operator--();

        std::size_t val() const { return _val; }

        bool operator==(const Year& rhs) const;
        bool operator!=(const Year& rhs) const;
        bool operator <(const Year& rhs) const;
        bool operator >(const Year& rhs) const;
        bool operator<=(const Year& rhs) const;
        bool operator>=(const Year& rhs) const;

    private:
        std::size_t _val;
    };

    class FOUNDATION_API Month {
    public:
        static Month Jan() { return Month(1); }
        static Month Feb() { return Month(2); }
        static Month Mar() { return Month(3); }
        static Month Apr() { return Month(4); }
        static Month May() { return Month(5); }
        static Month Jun() { return Month(6); }
        static Month Jul() { return Month(7); }
        static Month Aug() { return Month(8); }
        static Month Sep() { return Month(9); }
        static Month Oct() { return Month(10); }
        static Month Nov() { return Month(11); }
        static Month Dec() { return Month(12); }

        Month() :_val(1) {}
        explicit Month(std::size_t val);
        Month(const Month& rhs) :_val(rhs._val) {}

        ~Month() noexcept {}

    public:
        Month& operator =(const Month& rhs);
        
        std::size_t val() const { return _val; }

        bool operator==(const Month& rhs) const;
        bool operator!=(const Month& rhs) const;
        bool operator <(const Month& rhs) const;
        bool operator >(const Month& rhs) const;
        bool operator<=(const Month& rhs) const;
        bool operator>=(const Month& rhs) const;

    private:
        std::size_t _val;
    };

    class FOUNDATION_API Day {
    public:
        Day() :_val(1) {}
        explicit Day(std::size_t val);
        Day(const Day& rhs) :_val(rhs._val) {}

        ~Day() noexcept {}

    public:
        Day& operator =(const Day& rhs);

        std::size_t val() const { return _val; }

        bool operator==(const Day& rhs) const;
        bool operator!=(const Day& rhs) const;
        bool operator <(const Day& rhs) const;
        bool operator >(const Day& rhs) const;
        bool operator<=(const Day& rhs) const;
        bool operator>=(const Day& rhs) const;

    private:
        std::size_t _val;
    };

    // global functions

    Year operator+(const Year& y, int n); 
    Year operator-(const Year& y, int n); 
}} // namespace orca::calendar

#endif // !FOUNDATION_YEARMONTHDAY_INCLUDED
