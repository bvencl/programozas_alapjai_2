#pragma once

enum logtype
{

    DEBUG = 1,
    INFO = 2,
    WARN = 3,
    ERROR = 4,

};
namespace logging
{
    class Logger
    {
    private:
        logtype logLevel;
        static Logger *instance;
        Logger();
        ~Logger();

    public:
        void log(logtype, char const *);

        static Logger &getInstance();

        void setDefaultLogLevel(logtype);

        void printInstance() const;

    };

}