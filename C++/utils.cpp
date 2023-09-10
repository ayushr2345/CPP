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
} // namespace utils
