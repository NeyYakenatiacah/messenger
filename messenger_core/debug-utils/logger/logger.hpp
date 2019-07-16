#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <string_view>

template<class LoggerImpl>
class Logger: public LoggerImpl
{
    Logger()
        : LoggerImpl()
    {

    }

    virtual ~Logger()
    {

    }

    void operator()(std::string_view msg)
    {
        LoggerImpl::write(msg);
    }
};

#endif // LOGGER_HPP
