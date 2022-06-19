#include "input.h"
#include <functional>
#include <iostream>
#include <limits> // yeah I forgot this...
#include <string>
#include <string_view>

// namespaces are typically lowercase... I changed this to match
namespace input
{
	/* Loops until user enters Y/y or N/n. Returns true if Y/y, false if N/n */
	bool chooseYOrN(std::string_view prompt)
	{
		while (true)
		{
			char input{ getInput<char>(prompt) };
			switch (input)
			{
			case 'y':
			case 'Y':
				return true;
			case 'n':
			case 'N':
				return false;
			default:
				invalidInput();
//				continue;
			}
		}
	}

	/* For use within input.cpp. I guess you could use it. */
	void ignoreLine()
	{
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}

	/* Prompt user that input was invalid. */
	void invalidInput()
	{
		std::cout << "Invalid input.\n";
	}

	/* Get full line of input as a string, no input validation.
	* Manually call invalidInput() if the user enters invalid input. */
	std::string getSInput(std::string_view prompt)
	{
		// std::getline doesn't like to work with template functions
		std::cout << prompt;
		std::string input{};
		std::getline(std::cin >> std::ws, input);
		return input;
	}
}