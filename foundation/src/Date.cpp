#include "orca/calendar/Date.h"

#include <boost/date_time/gregorian/greg_date.hpp>

#include "orca/Exception.h"
#include "orca/calendar/YearMonthDay.h"
#include "orca/calendar/Period.h"

namespace orca {
namespace calendar {
    class Date::Pimpl {
    public:
        Pimpl() noexcept;
        explicit Pimpl(const boost::gregorian::date& greg_date);
        Pimpl(const Year& year, const Month& month, const Day& day);
        Pimpl(const Pimpl& rhs);
        ~Pimpl() noexcept;

    public:
        Pimpl& operator=(const Pimpl& rhs);
        Pimpl& operator+=(int n);
        Pimpl& operator-=(int n);
        
        Year year() const;
        Month month() const;
        Day day() const;
        std::size_t serialNumber() const;

        Day endDayOfMonth() const;

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

    Date::Pimpl::Pimpl(const boost::gregorian::date& greg_date)
        :_greg_date(greg_date)
    {
    }

    Date::Pimpl::Pimpl(const Year& year, 
        const Month& month, const Day& day)
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
        if (this != &rhs) {
            _greg_date = rhs._greg_date;
        }
        return *this;
    }

    Date::Pimpl& Date::Pimpl::operator+=(int n)
    {
        _greg_date = boost::gregorian::date(serialNumber() + n);
        return *this;
    }

    Date::Pimpl& Date::Pimpl::operator-=(int n)
    {
        return operator+=(-n);
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
            ORCA_THROW_EXCEPTION("bad month.");
            break;
        }
    }

    Day Date::Pimpl::day() const
    {
        return Day(_greg_date.day());
    }

    std::size_t Date::Pimpl::serialNumber() const
    {
        return _greg_date.day_number();
    }

    Day Date::Pimpl::endDayOfMonth() const
    {
        return Day(_greg_date.end_of_month().day());
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
        :_pimpl(std::make_unique<Pimpl>(year, month, day))
    {
    }

    Date::Date(const Date& rhs)
        :_pimpl(std::make_unique<Pimpl>(*rhs._pimpl))
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

    Date& Date::operator+=(int n)
    {
        _pimpl = std::make_unique<Pimpl>(_pimpl->operator+=(n));
        return *this;
    }
    Date& Date::operator-=(int n)
    {
        _pimpl = std::make_unique<Pimpl>(_pimpl->operator-=(n));
        return *this;
    }

    void Date::operator++()
    {
        _pimpl->operator++();
    }

    void Date::operator--()
    {
        _pimpl->operator--();
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

    std::size_t Date::serialNumber() const
    {
        return _pimpl->serialNumber();
    }

    Day Date::endDayOfMonth(const Year& year, const Month& month)
    {
        Pimpl d(year, month, Day(1));
        return d.endDayOfMonth();
    }
    // orca::Date
    
    bool operator==(const Date& lhs, const Date& rhs)
    {
        return lhs.serialNumber() == rhs.serialNumber();
    }
    bool operator!=(const Date& lhs, const Date& rhs)
    {
        return !(lhs == rhs);
    }
    bool operator<(const Date& lhs, const Date& rhs)
    {
        return lhs.serialNumber() < rhs.serialNumber();
    }
    bool operator>(const Date& lhs, const Date& rhs)
    {
        return rhs < lhs;
    }
    bool operator<=(const Date& lhs, const Date& rhs)
    {
        return !(lhs > rhs);
    }
    bool operator>=(const Date& lhs, const Date& rhs)
    {
        return !(lhs < rhs);
    }
    Date operator+(const Date& d, int n)
    {
        return Date(d) += n;
    }
    Date operator-(const Date& d, int n)
    {
        return Date(d) -= n;
    }
    Date operator+(const Date& d, const Period& p)
    {
        switch (p.timeUnit())
        {
        case Period::Days:
            return Date(d) += p.numOfUnit();
        case Period::Weeks:
            return Date(d) += (7 * p.numOfUnit());
        case Period::Months: {
            std::size_t y = d.year().val();
            std::size_t m = d.month().val() + p.numOfUnit();
            while (m > 12) {                
                m -= 12;
                ++y;
            }
            Year year(y);
            Month month(m);
            Day day(d.day());            
            if (day > Date::endDayOfMonth(year, month)) {
                day = Date::endDayOfMonth(year, month);
            }
            return Date(year, month, day);
        }
        case Period::Years: {
            auto year = d.year() + p.timeUnit();
            auto month = d.month();
            auto day = d.day();
            if (day > Date::endDayOfMonth(year, month)) {
                day = Date::endDayOfMonth(year, month);
            }
            return Date(year, month, day);
        }
        default:
            break;
        }
        return Date();
    }
    Date operator-(const Date& date, const Period& p)
    {
        return Date();
    }    
}} // namespace orca::calendar