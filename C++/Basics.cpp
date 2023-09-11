#pragma once

#include "Basics.h"
#include "utils.h"
#include <iostream>

namespace basics
{
	Basics::Basics():
		m_choice(0)
	{
		m_BasicsMenuMap.insert({ m_BasicsMenu(HELLO_WORLD), 
								 std::string("Hello World") });
		m_BasicsMenuMap.insert({ m_BasicsMenu(HELLO_NAME), 
							     std::string("Hello Name") });
		m_BasicsMenuMap.insert({ m_BasicsMenu(BACK_TO_PREVIOUS_MENU), 
								 std::string("Back to Main Menu") });
		m_BasicsMenuMap.insert({ m_BasicsMenu(EXIT_FROM_PROGRAM), 
							     std::string("Exit") });
	}

	const int Basics::GetMinCase()
	{
		return m_BasicsMenu::MIN_COUNT;
		return 1;
	}

	const int Basics::GetMaxCase()
	{
		return m_BasicsMenu::MAX_COUNT;
		return 0;
	}

	const int& Basics::GetChoice()
	{
		return m_choice;
	}

	void Basics::GetChoiceInputFromUser()
	{
		utils::InputIntegerChoiceFromUser(m_choice);
	}

	void Basics::PrintMenu()
	{
		std::cout << "1. Hello World!" << std::endl
			      << "2. Hello <NAME>" << std::endl
			      << "3. Back to previous menu" << std::endl
			      << "4. Exit" << std::endl
			      << "Please enter your choice: ";
	}

	void Basics::PrintSelectedChoice()
	{
		std::cout << std::endl << std::endl
				  << "You have chosen choice "
				  << m_BasicsMenuMap.at(m_choice)
				  << std::endl;
	}
	
	void Basics::HelloWorld()
	{
		std::cout << "Hello World!" << std::endl;
	}

	void Basics::GetNameInputFromUser()
	{
		utils::IgnoreStdCinBufferTillEOL();
		std::getline(std::cin, m_name);
	}

	void Basics::HelloName()
	{
		std::cout << "Hello " << m_name << std::endl;
	}

	
} // namespace basics
