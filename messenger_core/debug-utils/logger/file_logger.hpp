#ifndef FILE_LOGGER_H
#define FILE_LOGGER_H

#include <string_view>

class FileLogger
{
public:
    FileLogger();

    void write(std::string_view msg);
};

#endif // FILE_LOGGER_H
