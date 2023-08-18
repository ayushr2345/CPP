#pragma once

#include "Basics.h"
#include<iostream>
#include<string>

namespace basics
{
	int Basics::GetChoice()
	{
		return choice;
	}

	int Basics::SetChoice(int& choice)
	{
		this->choice = choice;
		return this->choice;
	}

	int Basics::GetChoiceInputFromUser()
	{
		std::cin >> choice;
		return choice;
	}

	std::string Basics::GetSelectedChoice(BasicsMenu& basicsMenu)
	{
		// TO-DO
		// return BasicsMenu.at(basicsMenu);
		return "ASD";
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
		std::cout << "1. Hello World!" << std::endl
			<< "2. Hello <NAME>" << std::endl
			<< "3. Exit" << std::endl
			<< "Please enter your choice: ";
	}
}