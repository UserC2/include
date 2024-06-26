#ifndef C2_INCLUDE_DATE_H
#define C2_INCLUDE_DATE_H

#include <string>

namespace date
{
	/* Returns current date in DD/MM/YYYY format. */
	std::string currentDate();
	/* Returns input date formatted as YYYY/MM/DDDD. */
	std::string formatYMD(std::string_view date);
	/* Returns true if dateA happened before dateB. */
	bool isOlder(std::string_view dateA, std::string_view dateB);
	/* Returns true if dateA happened after dateB. */
	bool isNewer(std::string_view dateA, std::string_view dateB);
}

#endif
