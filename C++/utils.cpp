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
				  << "2. Exit" << std::endl;
		std::cout << "Please enter your choice: ";
	}

	void PrintSelectedChoice(const int& choice)
	{
		std::cout << std::endl << std::endl
			      << "You have chosen choice "
			      << utils::MainMenuMap.at(choice)
			      << std::endl;
	}

	void utils::IgnoreStdCinBufferTillEOL()
	{
		// ignore the input stream till the EOL
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}

	void utils::InputIntegerChoiceFromUser(int& choice)
	{
		std::cin >> choice;
		while (std::cin.fail() || std::cin.peek() != '\n')
		{
			std::cin.clear();
			utils::IgnoreStdCinBufferTillEOL();
			std::cout << "Wrong input type! Please enter an integer value: ";
			std::cin >> choice;
		}
	}
} // namespace utils
