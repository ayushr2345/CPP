#pragma once

#include <string>
#include <map>

namespace utils
{
	enum MainMenu
	{
		MIN_COUNT               = 0,
		BASICS	                = 1,
		POINTERS_AND_REFERENCES = 2,
		EXIT                    = 3,
		MAX_COUNT               = EXIT
	};

	// The extern keyword in C++ is used to declare a global variable 
	// or function which can be accessed from any part of the program 
	// or from other files included in the program's header.

	// Used so that this MainMenuArray is available to the main.cpp
	// and we can print the selected choice.
	static std::map<int, std::string> MainMenuMap =
	{
		{
			MainMenu(BASICS),
			std::string("BASICS")
		},
		{
			MainMenu(POINTERS_AND_REFERENCES),
			std::string("Pointers and References")
        },
		{
			MainMenu(EXIT),
			std::string("EXIT")
		}
	};

	void PrintWelcomeScreen();
	void PrintMainMenu();
	void PrintSelectedChoice(const int&);
	void IgnoreStdCinBufferTillEOL();
	void InputIntegerFromUser(int& choice, int range_start = INT_MIN, int range_stop = INT_MAX);
} //namespace utils
