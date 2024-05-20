#pragma once

#include <map>
#include <string>
#include <iostream>

#ifndef _WIN32
	#include <cstring>
#endif

// include files for linux
#ifndef _WIN32
	#include <limits>
#endif	


namespace utils
{
	enum MainMenu
	{
		MIN_COUNT               = 0,
		BASICS	                = 1,
		POINTERS_AND_REFERENCES = 2,
		C_STYLE_STRINGS			= 3,
		CPP_STRINGS			    = 4,
		FUNCTIONS				= 5,
		CLASSES_AND_OBJECTS     = 6,
		IOSTREAMS				= 7,
		EXIT                    = 8,
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
			MainMenu(FUNCTIONS),
			std::string("Functions")
		},
		{
			MainMenu(CLASSES_AND_OBJECTS),
			std::string("Classes and Objects")
		},
		{
			MainMenu(IOSTREAMS),
			std::string("I/O Streams")
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

	// templates should not have definition in a separate source file 
	// as it would give compilation and linking errors
	template<typename T>
	void InputNumberFromUser(T& choice, T range_start = std::numeric_limits<T>::min(), T range_stop = std::numeric_limits<T>::max())
	{
		std::cin >> choice;
		while (std::cin.fail() || std::cin.peek() != '\n' || choice < range_start || choice > range_stop)
		{
			ClearCinFlag();
			IgnoreStdCinBufferTillEOL();
			std::cout << "Wrong input type! Please enter a value within range: "
				      << range_start << " to " << range_stop << ": ";
			std::cin >> choice;
		}
	}
} //namespace utils
