#include "C2Utility.h"

#include <algorithm> // std::cout
#include <exception>
#include <fstream>
#include <iostream> // std::cerr
//#include <regex> // isAVowel()
#include <string>
#include <string_view>
//#ifdef __unix__
//#include <unistd.h>
//#include <term.h>
//#endif
//#ifdef _WIN32
//#include <windows.h>
//#endif

namespace utility
{
	std::string makeLower(std::string_view input)
	{
		std::string output{ input };
		for (char& c : output)
		{
			c = static_cast<char>(tolower(c));
		}
		return output;
	}

	void error(std::string_view prompt)
	{
		std::cerr << "Error occured: " << '\n' << prompt << '\n';
	}

	int getLines(std::fstream& file)
	{
		auto result{ std::count(std::istreambuf_iterator<char>(file),
			std::istreambuf_iterator<char>(), '\n') };
		/* Move file cursor to start of file so that any subsequent uses of the
		* file doesn't just return EOF... */
		file.seekg(0, std::ios::beg);
		return static_cast<int>(result);
	}

	std::string getPrefix(std::string_view string)
	{
		return isAVowel(string[0]) ? "An " : "A ";
	}

	bool isAVowel(char c)
	{
		/*const std::string str{ c };
		const std::regex vowel{ "[aeiouAEIOU]" };
		return std::regex_match(str, vowel);*/
		return (0x208222 >> (c & 0x1f)) & 1;
		/* geza on StackOverflow :
		https://stackoverflow.com/questions/47846406/ */
	}

// https://cplusplus.com/articles/4z18T05o/#HeaderFiles
//#ifdef __unix__
//	void clearScreen()
//	{
//		if (!cur_term)
//		{
//			int result;
//			setupterm(NULL, STDOUT_FILENO, &result);
//			if (result <= 0) return;
//		}
//
//		putp(tigetstr("clear"));
//	}
//#endif
//#ifdef _WIN32
//	void clearScreen()
//	{
//		HANDLE                     hStdOut;
//		CONSOLE_SCREEN_BUFFER_INFO csbi;
//		DWORD                      count;
//		DWORD                      cellCount;
//		COORD                      homeCoords = { 0, 0 };
//
//		hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
//		if (hStdOut == INVALID_HANDLE_VALUE) return;
//
//		/* Get the number of cells in the current buffer */
//		if (!GetConsoleScreenBufferInfo(hStdOut, &csbi)) return;
//		cellCount = csbi.dwSize.X * csbi.dwSize.Y;
//
//		/* Fill the entire buffer with spaces */
//		if (!FillConsoleOutputCharacter(
//			hStdOut,
//			(TCHAR)' ',
//			cellCount,
//			homeCoords,
//			&count
//		)) return;
//
//		/* Fill the entire buffer with the current colors and attributes */
//		if (!FillConsoleOutputAttribute(
//			hStdOut,
//			csbi.wAttributes,
//			cellCount,
//			homeCoords,
//			&count
//		)) return;
//
//		/* Move the cursor home */
//		SetConsoleCursorPosition(hStdOut, homeCoords);
//	}
//#endif
}
