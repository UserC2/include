#ifndef C2_INCLUDE_DATE_H
#define C2_INCLUDE_DATE_H

#include <chrono>
#include <ctime>
#include <iomanip>

namespace date
{
	/* Returns current date in DD/MM/YYYY format. */
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

#endif
