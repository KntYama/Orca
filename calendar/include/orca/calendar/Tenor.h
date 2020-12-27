#ifndef CALENDAR_TENOR_INCLUDED
#define CALENDAR_TENOR_INCLUDED

#include <cstddef>

#include "orca/calendar/export.h"

namespace orca {
namespace calendar {
    
    class CALENDAR_API Tenor {
    public:
        Tenor() noexcept;
        Tenor(std::size_t years, std::size_t months, 
            std::size_t weeks, std::size_t days);
        
        Tenor(const Tenor& rhs);
        
        ~Tenor() noexcept;

    public:

        std::size_t years() const { return _years; }
        std::size_t months() const { return _months; }
        std::size_t weeks() const { return _weeks; }
        std::size_t days() const { return _days; }

    private:
        std::size_t _years;
        std::size_t _months;
        std::size_t _weeks;
        std::size_t _days;
    };
}} // namespace orca::calendar

#endif // !CALENDAR_TENOR_INCLUDED
