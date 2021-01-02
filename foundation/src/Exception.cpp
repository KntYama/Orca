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
        :_message(message), _fileName(fileName), 
        _functionName(functionName), _line(line)
    {
    }
    Exception::~Exception() noexcept
    {
    }
    const char* Exception::what() const noexcept
    {
        return format(_message, _fileName, 
            _functionName, _line).c_str();
    }
    const std::string& Exception::message() const noexcept
    {
        return _message;
    }
    const char* Exception::fileName() const noexcept
    {
        return _fileName;
    }
    const char* Exception::functionName() const noexcept
    {
        return _functionName;
    }
    int Exception::line() const noexcept
    {
        return _line;
    }
}

