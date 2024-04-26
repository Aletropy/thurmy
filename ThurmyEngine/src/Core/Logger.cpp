#include "Logger.h"
#include <cstdio>
#include <cstdarg>

namespace Thurmy
{
	void Logger::Log(const char* file, int line, const char* format, ...)
	{
        va_list args;
        va_start(args, format);

        std::printf("[%s:%d] ", file, line);
        std::vprintf(format, args);
        std::printf("\n");

        va_end(args);
	}
}