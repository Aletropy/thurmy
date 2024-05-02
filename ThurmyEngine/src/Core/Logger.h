#pragma once

#include <string>

namespace Thurmy
{
    class Logger
    {
    public:
        static void Log(const char *file, int line, const char *format, ...);
    };
}

#ifdef THURMY_DEBUG

#define THURMY_LOG(...) Thurmy::Logger::Log(__FILE__, __LINE__, __VA_ARGS__)
#define THURMY_ASSERT(x, ...)                                 \
    if (x)                                                    \
    {                                                         \
        Thurmy::Logger::Log(__FILE__, __LINE__, __VA_ARGS__); \
        __debugbreak();                                       \
    }

#elif THURMY_RELEASE

#define THURMY_LOG
#define THURMY_ASSERT

#endif
