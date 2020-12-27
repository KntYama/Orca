#include "orca/calendar/Date.h"

#include <boost/date_time/gregorian/greg_date.hpp>

#include "orca/calendar/YearMonthDay.h"

namespace orca {
namespace calendar {
    class Date::Pimpl {
    public:
        Pimpl() noexcept;
        Pimpl(const Year& year, const Month& month, const Day& day);
        Pimpl(const Pimpl& rhs);
        ~Pimpl() noexcept;

    public:
        Pimpl& operator =(const Pimpl& rhs);
        
        Year year() const;
        Month month() const;
        Day day() const;

        bool operator==(const Pimpl& rhs) const;
        bool operator!=(const Pimpl& rhs) const;
        bool operator <(const Pimpl& rhs) const;
        bool operator >(const Pimpl& rhs) const;
        bool operator<=(const Pimpl& rhs) const;
        bool operator>=(const Pimpl& rhs) const;

        void operator++();
        void operator--();

    private:
        boost::gregorian::date _greg_date;
    };

    // --- implementation of opt::Date::Pimpl class --- //

    Date::Pimpl::Pimpl() noexcept
        :_greg_date(boost::gregorian::date(
            Year().val(), Month().val(), Day().val()))
    {
    }

    Date::Pimpl::Pimpl(const Year& year, const Month& month, const Day& day)
        : _greg_date(boost::gregorian::date(
            year.val(), month.val(), day.val()))
    {
    }

    Date::Pimpl::Pimpl(const Pimpl& rhs)
        : _greg_date(rhs._greg_date)
    {
    }

    Date::Pimpl::~Pimpl()
    {
    }

    Date::Pimpl& Date::Pimpl::operator=(const Pimpl& rhs)
    {
        _greg_date = rhs._greg_date;
        return *this;
    }
 
    Year Date::Pimpl::year() const
    {
        return Year(_greg_date.year());
    }

    Month Date::Pimpl::month() const
    {
        switch (_greg_date.month())
        {
        case 1:
            return Month::Jan();
        case 2:
            return Month::Feb();
        case 3:
            return Month::Mar();
        case 4:
            return Month::Apr();
        case 5:
            return Month::May();
        case 6:
            return Month::Jun();
        case 7:
            return Month::Jul();
        case 8:
            return Month::Aug();
        case 9:
            return Month::Sep();
        case 10:
            return Month::Oct();
        case 11:
            return Month::Nov();
        case 12:
            return Month::Dec();
        default:
            throw std::exception("bad month.");
            break;
        }
    }

    Day Date::Pimpl::day() const
    {
        return Day(_greg_date.day());
    }

    bool Date::Pimpl::operator==(const Pimpl& rhs) const
    {
        return _greg_date == rhs._greg_date;
    }

    bool Date::Pimpl::operator!=(const Pimpl& rhs) const
    {
        return _greg_date != rhs._greg_date;
    }

    bool Date::Pimpl::operator<(const Pimpl& rhs) const
    {
        return _greg_date < rhs._greg_date;
    }

    bool Date::Pimpl::operator>(const Pimpl& rhs) const
    {
        return _greg_date > rhs._greg_date;
    }

    bool Date::Pimpl::operator<=(const Pimpl& rhs) const
    {
        return _greg_date <= rhs._greg_date;
    }

    bool Date::Pimpl::operator>=(const Pimpl& rhs) const
    {
        return _greg_date >= rhs._greg_date;
    }

    void Date::Pimpl::operator++()
    {
        _greg_date = boost::gregorian::date(_greg_date.day_number() + 1);
    }

    void Date::Pimpl::operator--()
    {
        _greg_date = boost::gregorian::date(_greg_date.day_number() - 1);
    }

    // --- implementation of opt::Date class --- //
    Date::Date() noexcept
        :_pimpl(std::make_unique<Pimpl>())
    {
    }

    Date::Date(const Year& year, const Month& month, const Day& day)
        : _pimpl(std::make_unique<Pimpl>(year, month, day))
    {
    }

    Date::Date(const Date& rhs)
        : _pimpl(std::make_unique<Pimpl>(*rhs._pimpl))
    {
    }

    Date::~Date() noexcept
    {
    }

    Date& Date::operator=(const Date& rhs)
    {
        if (this != &rhs) {
            _pimpl = std::make_unique<Pimpl>(*rhs._pimpl);
        }
        return *this;
    }

    Year Date::year() const
    {
        return _pimpl->year();
    }

    Month Date::month() const
    {
        return _pimpl->month();
    }

    Day Date::day() const
    {
        return _pimpl->day();
    }

    bool Date::operator==(const Date& rhs) const
    {
        return _pimpl->operator==(*rhs._pimpl);
    }

    bool Date::operator!=(const Date& rhs) const
    {
        return _pimpl->operator!=(*rhs._pimpl);
    }

    bool Date::operator<(const Date& rhs) const
    {
        return _pimpl->operator<(*rhs._pimpl);
    }

    bool Date::operator>(const Date& rhs) const
    {
        return _pimpl->operator>(*rhs._pimpl);
    }

    bool Date::operator<=(const Date& rhs) const
    {
        return _pimpl->operator<=(*rhs._pimpl);
    }

    bool Date::operator>=(const Date& rhs) const
    {
        return _pimpl->operator>=(*rhs._pimpl);
    }

    void Date::operator++()
    {
        _pimpl->operator++();
    }

    void Date::operator--()
    {
        _pimpl->operator--();
    }
}} // namespace orca::calendar