#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <string_view>

#include <messenger_core_export.h>

namespace core
{

template<class LoggerImpl>
class MESSENGER_CORE_EXPORT Logger: public LoggerImpl
{
private:

public:
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
}

#endif // LOGGER_HPP
