#include "orca/calendar/Tenor.h"

#include <type_traits>

namespace orca {
namespace calendar {
    Tenor::Tenor() noexcept
        :_years(0), _months(0), _weeks(0), _days(0)
    {
    }
    Tenor::Tenor(std::size_t years, std::size_t months, 
        std::size_t weeks, std::size_t days)
        :_years(years), _months(months), 
        _weeks(weeks), _days(days)
    {
    }
    Tenor::Tenor(const Tenor& rhs)
        :_years(rhs._years), _months(rhs._months), 
        _weeks(rhs._weeks), _days(rhs._days)
    {
    }
    Tenor::~Tenor() noexcept
    {
    }
}} // namespace orca::calendar