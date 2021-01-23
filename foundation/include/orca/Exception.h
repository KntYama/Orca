#ifndef FOUNDATION_EXCEPTION_INCLUDED
#define FOUNDATION_EXCEPTION_INCLUDED

#include <exception>
#include <string>
#include <sstream>

#include "orca/FoundationExport.h"

namespace orca {

class FOUNDATION_API Exception : public std::exception {
public:
    Exception(
        const std::string& message,
        const char* fileName,
        const char* functionName,
        int line);

    Exception(const Exception& other);

    ~Exception() noexcept {}

    const char* what() const noexcept;

    const std::string& message() const noexcept { return _message; }
    const char* fileName() const noexcept { return _fileName; }
    const char* functionName() const noexcept { return _functionName; }
    int line() const noexcept { return _line; }
        
private:
    const char* _fileName;
    const char* _functionName;
    const int _line;
    const std::string _message; 
    const std::string _what;                
}; // class Exception
} // namespace orca

#define ORCA_THROW_EXCEPTION(message) \
{ \
    std::ostringstream oss; \
    oss << message; \
    throw orca::Exception(oss.str(), \
        __FILE__, __func__, __LINE__); \
}

#define ORCA_REQUIRE(condition, message) \
{ \
    if (!(condition)) { \
        std::ostringstream oss; \
        oss << message; \
        throw orca::Exception(oss.str(), \
            __FILE__, __func__, __LINE__); \
    } \
}

#define ORCA_CONFIRM(condition, message) \
{ \
    if (!(condition)) { \
        std::ostringstream oss; \
        oss << message; \
        throw orca::Exception(oss.str(), \
            __FILE__, __func__, __LINE__); \
    } \
}
// !define CALENDAR_REQUIRE

#endif // !FOUNDATION_EXCEPTION_INCLUDED
