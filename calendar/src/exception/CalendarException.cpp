#include "orca/calendar/exception/CalendarException.h"

namespace {
    std::string format(
        const std::string& message,
        const char* fileName,
        const char* functionName,
        int line)
    {
        std::ostringstream out;
        out << "[message]: ";
        out << message << ";";
        out << " [file]: ";
        out << fileName << ";";
        out << " [function]: ";
        out << functionName << ";";
        out << " [line]: ";
        out << std::to_string(line) << ";";
        return out.str();
    }
}

namespace orca {
namespace calendar {
namespace exception {    
    CalendarException::CalendarException(
        const std::string& message, 
        const char* fileName, 
        const char* functionName, 
        int line)
        :_out(format(message, fileName, functionName, line))
    {
    }
    CalendarException::~CalendarException() noexcept
    {
    }
    const char* CalendarException::what() const noexcept
    {
        return _out.c_str();
    }
}}}

