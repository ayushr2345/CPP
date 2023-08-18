#pragma once

#include<iostream>
#include<string>
#include<map>

namespace utils
{
	enum MainMenu
	{
		BASICS = 1,
		EXIT = -1
	};

	// The extern keyword in C++ is used to declare a global variable 
	// or function which can be accessed from any part of the program 
	// or from other files included in the program's header.

	// Used so that this MainMenuArray is available to the main.cpp
	// and we can print the selected choice.
	static std::map<MainMenu, std::string> MainMenuMap =
	{
		{
			MainMenu(BASICS),
			std::string("BASICS")
		}
	};

	void PrintWelcomeScreen();
	void PrintMainMenu();
}