#pragma once

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
		std::cout << std::endl;
		for (std::map<int, std::string>::iterator it = MainMenuMap.begin();
			it != MainMenuMap.end();
			it++)
		{
			std::cout << it->first << ". " << it->second << std::endl;
		}
		std::cout << "Please enter your choice: ";
	}

	void PrintSelectedChoice(const int& choice)
	{
		std::cout << std::endl << std::endl
			      << "You have chosen choice "
			      << MainMenuMap.at(choice)
			      << std::endl;
	}

	void ClearCinFlag()
	{
		// clear cin error flag so that further operations can be performed correctly
		std::cin.clear();
	}

	void IgnoreStdCinBufferTillEOL()
	{
		// ignore the input stream till the EOL
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}

	bool CheckAndClearCharactersInStream(const char str[], const int len)
	{
		if (std::cin.gcount() == (static_cast<long long>(len) - 1) && strlen(str) == (static_cast<unsigned long long>(len) - 1))
		{
			// there are characters in the stream before '\n'
			ClearCinFlag();
			IgnoreStdCinBufferTillEOL();
			return true;
		}
		return false;
	}
} // namespace utils
