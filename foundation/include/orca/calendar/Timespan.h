#ifndef FOUNDATION_TIMESPAN_INCLUDED
#define FOUNDATION_TIMESPAN_INCLUDED

namespace orca {
namespace calendar {

class Timespan {
public:
    enum TimeUnit {
        Seconds = 1,
        Minutes = 60,
        Hours = 3600,
        Days = 86400
    };

    Timespan() noexcept;

    Timespan(int days, int hours, int minutes, int seconds);

    explicit Timespan(int days);

    ~Timespan() noexcept;

    int totalSeconds() const;

    int days() const;
    int hours() const;
    int minutes() const;
    int seconds() const;

private:
    int _span;
};
}}

#endif // !FOUNDATION_TIMESPAN_INCLUDED
