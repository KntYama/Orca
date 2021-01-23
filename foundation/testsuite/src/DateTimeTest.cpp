#include "orca/calendar/DateTime.h"
#include <boost/date_time/gregorian/greg_date.hpp>
#include <gtest/gtest.h>

TEST(DateTimeTest, DefaultConstructorTest) {
    orca::calendar::DateTime dateTime;
    ASSERT_EQ(0, dateTime.year());
    ASSERT_EQ(1, dateTime.month());
    ASSERT_EQ(1, dateTime.day());
    ASSERT_EQ(0, dateTime.hour());
    ASSERT_EQ(0, dateTime.minute());
    ASSERT_EQ(0, dateTime.second());
}

TEST(DateTimeTest, GregorianConstructorTest) {
    int year = 2020;
    int month = 12;
    int day = 31;
    int hour = 1;
    int minute = 30;
    int second = 30;
    orca::calendar::DateTime dateTime(year, month, day, hour, minute, second);
    ASSERT_EQ(year, dateTime.year());
    ASSERT_EQ(month, dateTime.month());
    ASSERT_EQ(day, dateTime.day());
    ASSERT_EQ(hour, dateTime.hour());
    ASSERT_EQ(minute, dateTime.minute());
    ASSERT_EQ(second, dateTime.second());
}

TEST(DateTimeTest, JulianConstructorTest) {
    double julianDay = 2459225.25;
    orca::calendar::DateTime dateTime(julianDay);
    ASSERT_EQ(julianDay, dateTime.julianDay());
}

TEST(DateTimeTest, JulianToGregorianTest) {
    // testing conversion from julian to gregorian
    // using boost::gregorian::date as an expected

    boost::gregorian::date maxDate(boost::gregorian::max_date_time);
    boost::gregorian::date expected(boost::gregorian::min_date_time);
    
    while (expected < maxDate) {
        orca::calendar::DateTime actual(double(expected.julian_day()));
        ASSERT_EQ(expected.year(), actual.year());
        ASSERT_EQ(expected.month(), actual.month());
        ASSERT_EQ(expected.day(), actual.day());
        expected = boost::gregorian::date(expected.julian_day() + 1);
    }    
}

TEST(DateTimeTest, GregorianToJulianTest) {
    // testing conversion from gregorian to julian
    // using boost::gregorian::date as an expected

    boost::gregorian::date maxDate(boost::gregorian::max_date_time);
    boost::gregorian::date expected(boost::gregorian::min_date_time);

    while (expected < maxDate) {
        orca::calendar::DateTime actual(expected.year(), expected.month(), expected.day());
        ASSERT_EQ(double(expected.julian_day() - 0.5), actual.julianDay());
        expected = boost::gregorian::date(expected.julian_day() + 1);
    }    
}
TEST(DateTimeTest, SelfConsistencyTest) {
    // testing self consisntency in conversion
    // from julian to gregorian vs. from gregorian to julian
    
    for (int y = 0; y <= 9999; ++y)
    {
        for (int m = 1; m <= 12; ++m)
        {
            for (int d = 1; d < orca::calendar::DateTime::daysOfMonth(y, m); ++d)
            {
                orca::calendar::DateTime fromgregorian(y, m, d);
                orca::calendar::DateTime fromjulian(fromgregorian.julianDay());
                ASSERT_EQ(y, fromjulian.year());
                ASSERT_EQ(m, fromjulian.month());
                ASSERT_EQ(d, fromjulian.day());
            }
        }
    }    
}

TEST(DateTimeTest, ComparisonOperatorTest) {
    // testing comparison operator
    
    orca::calendar::DateTime d1(0, 1, 1);
    orca::calendar::DateTime d2(0, 1, 1);
    orca::calendar::DateTime d3(0, 1, 2);
    for (int y = 0; y <= 9999; ++y)
    {
        for (int m = 1; m <= 12; ++m)
        {
            for (int d = 1; d < orca::calendar::DateTime::daysOfMonth(y, m); ++d)
            {
                d1 = orca::calendar::DateTime(y, m, d);
                d2 = orca::calendar::DateTime(y, m, d);
                d3 = d1 + 1;
                ASSERT_TRUE(d1 == d2);
                ASSERT_TRUE(d1 != d3);
                ASSERT_TRUE(d1 < d3);
                ASSERT_TRUE(d3 > d1);
                ASSERT_TRUE(d1 <= d2);
                ASSERT_TRUE(d1 <= d3);
                ASSERT_TRUE(d2 >= d1);
                ASSERT_TRUE(d3 >= d1);
            }
        }
    }     
}

TEST(DateTimeTest, IncrementDecrementTest) {
    // testing comparison operator

    orca::calendar::DateTime min(0, 1, 1);
    orca::calendar::DateTime max(9999, 12, 31);
    orca::calendar::DateTime d1 = min;
    orca::calendar::DateTime d2 = max;
    while (d1 < max) {
        auto julianDay1 = d1.julianDay();
        auto julianDay2 = d2.julianDay();
        ++d1;
        --d2;
        EXPECT_EQ(julianDay1 + 1, d1.julianDay());
        EXPECT_EQ(julianDay2 - 1, d2.julianDay());
    }
}
TEST(DateTimeTest, ArithmeticTest) {
    // testing comparison operator

    orca::calendar::DateTime d1(0, 1, 1);
    orca::calendar::DateTime d2(0, 1, 2);
    orca::calendar::DateTime max(9999, 12, 31);
    while (d1 < max) {
        orca::calendar::DateTime d3 = d1 + 1;
        orca::calendar::DateTime d4 = d3 - 1;
        EXPECT_EQ(d2, d3);
        EXPECT_EQ(d1, d4);
        ++d1;
        ++d2;
    }    
}