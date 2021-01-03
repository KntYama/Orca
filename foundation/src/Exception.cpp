#include "orca/Exception.h"

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
    Exception::Exception(
    const std::string& message,
    const char* fileName,
    const char* functionName,
    int line)
    :_what(format(message, fileName, functionName, line)),
    _message(message), _fileName(fileName),
    _functionName(functionName), _line(line)
    {
    }
    const char* Exception::what() const noexcept
    {
        return _what.c_str();
    }
}

