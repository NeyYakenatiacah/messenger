#ifndef FILE_LOGGER_H
#define FILE_LOGGER_H

#include <string_view>

namespace core
{
class FileLogger
{
public:

    void write(std::string_view msg);

protected:
    FileLogger();
    ~FileLogger();
};
}
#endif // FILE_LOGGER_H
