#ifndef FOUNDATION_PERIOD_INCLUDED
#define FOUNDATION_PERIOD_INCLUDED

#include <cstddef>
#include <memory>

#include "orca/FoundationExport.h"

namespace orca {
namespace calendar {

class Date;

class FOUNDATION_API Period {
    friend Period operator-(const Period&);
public:
    enum TimeUnit {
        None = 0,
        Days,
        Weeks,
        Months,
        Years,
    };
private:
    Period() noexcept : _numOfUnit(0), _timeUnit(TimeUnit::None) {}
    Period(int unit, TimeUnit timeUnit) 
        : _numOfUnit(unit), _timeUnit(timeUnit) {}

public:
    ~Period() noexcept {}
    static Period days(int unit) { return Period(unit, Days); }
    static Period weeks(int unit) { return Period(unit, Weeks); }
    static Period months(int unit) { return Period(unit, Months); }
    static Period years(int unit) { return Period(unit, Years); }

    int numOfUnit() const { return _numOfUnit; }
    TimeUnit timeUnit() const { return _timeUnit; }

private:
    int _numOfUnit;
    TimeUnit _timeUnit;
}; // class Period

}} // namespace orca::calendar
#endif // !FOUNDATION_PERIOD_INCLUDED
