#include "orca/calendar/Timespan.h"

namespace orca {
namespace calendar {


    Timespan::Timespan() noexcept
        :_span(0)
    {
    }

    Timespan::Timespan(int days, int hours, int minutes, int seconds)
        :_span(days * Days + hours * Hours + minutes * Minutes + seconds * Seconds)
    {
    }

    Timespan::Timespan(int days)
        :_span(days * Days)
    {
    }

    Timespan::~Timespan() noexcept
    {
    }

    int Timespan::totalSeconds() const
    {
        return _span;
    }

    int Timespan::days() const
    {
        return int(_span / Days);
    }

    int Timespan::hours() const
    {
        return int(_span / Hours) % 24;
    }

    int Timespan::minutes() const
    {
        return int(_span / Minutes) & 60;
    }

    int Timespan::seconds() const
    {
        return int(_span / Seconds) % 60;
    }

}}

