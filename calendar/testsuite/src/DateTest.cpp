#include <gtest/gtest.h>

#include <vector>

#include "orca/calendar/YearMonthDay.h"
#include "orca/calendar/Date.h"

TEST(DateTest, ConstructorTest) {
    orca::calendar::Year year(2020);
    orca::calendar::Day day(1); 

    std::vector<orca::calendar::Date> dates;
    dates.emplace_back(year, orca::calendar::Month::Jan(), day);
    dates.emplace_back(year, orca::calendar::Month::Feb(), day);
    dates.emplace_back(year, orca::calendar::Month::Mar(), day);
    dates.emplace_back(year, orca::calendar::Month::Apr(), day);
    dates.emplace_back(year, orca::calendar::Month::May(), day);
    dates.emplace_back(year, orca::calendar::Month::Jun(), day);
    dates.emplace_back(year, orca::calendar::Month::Jul(), day);
    dates.emplace_back(year, orca::calendar::Month::Aug(), day);
    dates.emplace_back(year, orca::calendar::Month::Sep(), day);
    dates.emplace_back(year, orca::calendar::Month::Oct(), day);
    dates.emplace_back(year, orca::calendar::Month::Nov(), day);
    dates.emplace_back(year, orca::calendar::Month::Dec(), day);    

    for (std::size_t i = 0; i < dates.size(); ++i)
    {
        EXPECT_EQ(2020, dates[i].year().val());
        EXPECT_EQ(i + 1, dates[i].month().val());
        EXPECT_EQ(1, dates[i].day().val());
    }
}

TEST(DateTest, CopyConstructorTest) {
    orca::calendar::Year year(2020);
    orca::calendar::Day day(1);
    orca::calendar::Month month = orca::calendar::Month::Dec();

    orca::calendar::Date date1(year, month, day);
    orca::calendar::Date date2 = date1;

    EXPECT_EQ(date1, date2);
}

TEST(DateTest, SubstitutionTest) {
    orca::calendar::Year year(2020);
    orca::calendar::Month month = orca::calendar::Month::Dec();
    orca::calendar::Day day(1);

    orca::calendar::Date date1(year, month, day);
    orca::calendar::Date date2;
    date2 = date1;

    EXPECT_EQ(date1, date2);
}

TEST(DateTest, IncrementDecrementTest) {
    orca::calendar::Year year(2020);
    orca::calendar::Month month = orca::calendar::Month::Dec();
    orca::calendar::Day day(31);

    orca::calendar::Date date(year, month, day);
    
    ++date;
    EXPECT_EQ(2021, date.year().val());
    EXPECT_EQ(1, date.month().val());
    EXPECT_EQ(1, date.day().val());

    --date;
    EXPECT_EQ(2020, date.year().val());
    EXPECT_EQ(12, date.month().val());
    EXPECT_EQ(31, date.day().val());
}