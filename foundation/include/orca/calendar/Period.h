#ifndef FOUNDATION_PERIOD_INCLUDED
#define FOUNDATION_PERIOD_INCLUDED

#include <cstddef>
#include <memory>

#include "orca/FoundationExport.h"

namespace orca {
namespace calendar {
    class Date;

    class FOUNDATION_API Period {
    public:
        enum TimeUnit {
            None = 0,
            Days,
            Weeks,
            Months,
            Years
        };
    private:
        Period() : _numOfUnit(0), _timeUnit(TimeUnit::None) {}
        Period(std::size_t unit, TimeUnit timeUnit) 
            : _numOfUnit(unit), _timeUnit(timeUnit) {}

    public:
        ~Period() noexcept {}
        static Period days(std::size_t unit) { return Period(unit, Days); }
        static Period weeks(std::size_t unit) { return Period(unit, Weeks); }
        static Period months(std::size_t unit) { return Period(unit, Months); }
        static Period years(std::size_t unit) { return Period(unit, Years); }

        std::size_t numOfUnit() const { return _numOfUnit; }
        TimeUnit timeUnit() const { return _timeUnit; }

    private:
        std::size_t _numOfUnit;
        TimeUnit _timeUnit;
    };
}}
#endif // !FOUNDATION_PERIOD_INCLUDED
