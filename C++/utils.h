#pragma once

#include <map>
#include <string>

namespace utils
{
	enum MainMenu
	{
		MIN_COUNT               = 0,
		BASICS	                = 1,
		POINTERS_AND_REFERENCES = 2,
		C_STYLE_STRINGS			= 3,
		CPP_STRINGS			    = 4,
		EXIT                    = 5,
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
			std::string("Basics")
		},
		{
			MainMenu(POINTERS_AND_REFERENCES),
			std::string("Pointers and References")
        },
		{
			MainMenu(C_STYLE_STRINGS),
			std::string("C Style Strings")
		},
		{
			MainMenu(CPP_STRINGS),
			std::string("CPP Style Strings")
		},
		{
			MainMenu(EXIT),
			std::string("Exit from program")
		}
	};

	void PrintWelcomeScreen();
	void PrintMainMenu();
	void PrintSelectedChoice(const int&);
	void ClearCinFlag();
	void IgnoreStdCinBufferTillEOL();
	bool CheckAndClearCharactersInStream(const char[], const int);
	void InputIntegerFromUser(int& choice, int range_start = INT_MIN, int range_stop = INT_MAX);
} //namespace utils
