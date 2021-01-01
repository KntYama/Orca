#ifndef CALENDAR_CALENDAREXCEPTION_INCLUDED
#define CALENDAR_CALENDAREXCEPTION_INCLUDED

#include <exception>
#include <string>
#include <sstream>

namespace orca {
namespace calendar {
namespace exception {
    class CalendarException : public std::exception {
    public:
        CalendarException(
            const std::string& message,
            const char* fileName,
            const char* functionName,
            int line);

        ~CalendarException() noexcept;

        const char* what() const noexcept;

    private:
        std::string _out;        
    };
}}}

#define CALENDAR_REQUIRE(condition,message) \
if (!(condition)) { \
    std::ostringstream msgStream; \
    msgStream << message; \
    throw orca::calendar::exception::CalendarException( \
        msgStream.str(), __FILE__, __func__, __LINE__); \
} else 
// !define CALENDAR_REQUIRE

#endif // !CALENDAR_CALENDAREXCEPTION_INCLUDED
