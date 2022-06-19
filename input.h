#ifndef AYDAN_INPUT_H
#define AYDAN_INPUT_H
#include <functional>
#include <iostream>
#include <string_view>

// compile input.cpp with your project!
// namespaces are typically lowercase... I changed this to match
namespace input
{
	/* Loops until user enters Y/y or N/n. Returns true if Y/y, false if N/n */
	bool chooseYOrN(std::string_view prompt);

	/* For use within input.cpp. I guess you could use it. */
	void ignoreLine();

	/* Prompt user that input was invalid. */
	void invalidInput();

	/* Get full line of input as a string, no input validation.
	* Manually call invalidInput() if the user enters invalid input. */
	std::string getSInput(std::string_view prompt);

	/* Checks if std::cin fails, if it does, prompts user to enter again.
	* Make sure to specify type it should return in < > between name and () */
	template <typename T>
	T getInput(std::string_view prompt)
	{
		while (true)
		{
			std::cout << prompt;
			T input{}; // this is annoying
			std::cin >> input;

			// Input validation
			if (std::cin.fail())
			{
				std::cin.clear();
				ignoreLine();
				invalidInput();
			}
			else
			{
				ignoreLine();
				return input;
			}
		}
	}
}
#endif