#pragma once

#include "Basics.h"
#include <iostream>
#include <string>

namespace basics
{
	int Basics::GetChoice()
	{
		return choice;
	}

	int Basics::GetChoiceInputFromUser()
	{
		std::cin >> choice;
		return choice;
	}

	void Basics::HelloWorld()
	{
		std::cout << "Hello World!" << std::endl;
	}

	void Basics::HelloName(std::string const& name)
	{
		std::cout << "Hello " << name << std::endl;
	}

	void Basics::PrintMenu()
	{
		std::cout << "1. Hello World!"          << std::endl
			      << "2. Hello <NAME>"          << std::endl
			      << "3. Back to previous menu" << std::endl
				  << "4. Exit"				    << std::endl
			      << "Please enter your choice: ";
	}

	void Basics::PrintSelectedChoice(const int& choice)
	{
		std::cout << std::endl << std::endl
				  << "You have chosen choice "
				  << BasicsMenuMap.at(choice)
				  << std::endl;
	}
}
