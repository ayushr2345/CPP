#pragma once

#include <iostream>
#include <iomanip>
#include "utils.h"

namespace utils 
{
	void PrintWelcomeScreen()
	{
		std::cout << std::setw(100) << "#################### WELCOME ####################" << std::endl;
		std::cout << "Welcome to the World of Learning C++, we have programs of all sorts starting"
			" from Hello World to DSAs implemented using Classes or C style programs. Choose one"
			" from the menu below : " << std::endl;
	}

	void PrintMainMenu()
	{
		std::cout << "1. Basics" << std::endl
		          << "2. Pointers and References" << std::endl
		          << "3. Exit" << std::endl;
		std::cout << "Please enter your choice: ";
	}

	void PrintSelectedChoice(const int& choice)
	{
		std::cout << std::endl << std::endl
			      << "You have chosen choice "
			      << MainMenuMap.at(choice)
			      << std::endl;
	}

	void IgnoreStdCinBufferTillEOL()
	{
		// ignore the input stream till the EOL
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}

	void utils::InputIntegerFromUser(int& choice, int range_start, int range_stop)
	{
		std::cin >> choice;
		while (std::cin.fail() || std::cin.peek() != '\n' || choice < range_start || choice > range_stop)
		{
			std::cin.clear();
			IgnoreStdCinBufferTillEOL();
			std::cout << "Wrong input type! Please enter an integer value within range: "
				      << range_start << " to " << range_stop << ": ";
			std::cin >> choice;
		}
	}
} // namespace utils
