#ifndef C2_INCLUDE_C2UTILITY_H
#define C2_INCLUDE_C2UTILITY_H

/* File is named C2Utility.h to avoid accidentally including utility.h. */

#include <fstream>
#include <string>
#include <string_view>

/* Functions that can be useful in many places. */
namespace utility
{
	/* Return the lowercase version of a string. 
	* Doesn't remove special characters. */
	std::string makeLower(std::string_view input);

	/* Display an error to the user. Doesn't stop program execution.
	* If the program cannot continue, you should throw std::runtime_error. */
	void error(std::string_view prompt);

	/* Thanks to Abhay on StackOverflow
	* Returns the amount of lines in a file. */
	int getLines(std::fstream& file);

	/* Returns the prefix ('a' or 'an') to a string. */
	std::string getPrefix(std::string_view string);

	/* Returns true if the input character is a vowel (excluding Y). */
	bool isAVowel(char c);

	/* Clears the screen. */
	//void clearScreen();
}

#endif
