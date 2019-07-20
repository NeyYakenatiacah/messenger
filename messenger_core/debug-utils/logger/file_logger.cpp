#include "file_logger.hpp"
#include <iostream>

namespace core
{

FileLogger::FileLogger()
{

}

FileLogger::~FileLogger()
{

}

void FileLogger::write(std::string_view msg)
{
    auto print = [&](std::string_view line){
        std::cout << line << std::endl;
    };

    print("~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    std::cout << __LINE__ << std::endl;
    std::cout << __FUNCTION__ << std::endl;
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    std::cout << __ELF__ << std::endl;
//    print(__MMX__);
    std::cout << msg << std::endl;
    print("~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
}

}
