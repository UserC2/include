#include "date.h"

#include <cassert>
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

	std::string formatYMD(std::string_view date)
	{
		assert(date.length() == 10
			&& "date::formatYMD() called with invalid date");
		std::string day{ date[0], date[1] };
		std::string month{ date[3], date[4] };
		std::string year{ date[6], date[7], date[8], date[9] };
		return { year + month + day };
	}

	bool isNewer(std::string_view dateA, std::string_view dateB)
	{
		return formatYMD(dateA) > formatYMD(dateB);
	}

	bool isOlder(std::string_view dateA, std::string_view dateB)
	{
		return !isNewer(dateA, dateB);
	}
}
