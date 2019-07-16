#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <string_view>

template<class LoggerImpl>
class Logger: public LoggerImpl
{
    void operator()(std::string_view msg)
    {

    }
};

#endif // LOGGER_HPP
