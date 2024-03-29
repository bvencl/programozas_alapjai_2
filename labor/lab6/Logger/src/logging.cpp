#include "logging.h"
#include <iostream>

using namespace logging;

Logger *Logger::instance = nullptr;

Logger::Logger(){
    
};

Logger::~Logger()
{
    std::cout << "torolve" << std::endl;
    delete (instance);
}

Logger &Logger::getInstance()
{
    if (instance == nullptr)
    {
        instance = new Logger();
    }
    return *instance;
}

void Logger::log(logtype current, char const *s)
{
    if (current >= logLevel)
    {
        std::cout << s << std::endl;
    }
}

void Logger::setDefaultLogLevel(logtype set)
{
    logLevel = set;
}

void Logger::printInstance() const {
    std::cout << "Instance address: " << this << std::endl;
}