#include "date.h"

#include <chrono>
#include <ctime>
#include <iomanip>
#include <string>

namespace date
{
    std::string currentDate()
    {
        static constexpr int formatLength{ 11 };
        std::time_t utc{ std::chrono::system_clock::to_time_t(
            std::chrono::system_clock::now()) };
        std::tm* local{ std::localtime(&utc) };
        char buffer[formatLength];
            strftime(buffer, formatLength, "%d/%m/%Y", local);
        return buffer;
    }
}
