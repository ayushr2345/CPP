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
		m_BasicsMenuMap.insert({ m_BasicsMenu(PRINT_DATA_TYPES_SIZE_AND_RANGES),
								 std::string("Print data types with their sizes and ranges") });
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
				  << "3. Print data types with their sizes and ranges" << std::endl
			      << "4. Back to previous menu" << std::endl
			      << "5. Exit" << std::endl
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

	void Basics::PrintDataTypeSizeAndRanges()
	{
		// TODO: Convert this into a table [datatype, size, range, used for] 
		// with borders
		bool b;
		char c;
		wchar_t w;
		char16_t ch16;
		char32_t ch32;
		short s;
		int i;
		long l;
		long long ll;
		float f;
		double d;
		long double ld;

		std::cout << "BOOL: ";
		std::cout << sizeof(b) << std::endl;

		std::cout << "CHAR: ";
		std::cout << sizeof(c) << std::endl;
		std::cout << "Range: " << CHAR_MIN << ":" << CHAR_MAX << std::endl << std::endl;

		std::cout << "WCHAR: ";
		std::cout << sizeof(w) << std::endl;
		std::cout << "Range: " << WCHAR_MIN << ":" << WCHAR_MAX << std::endl << std::endl;

		std::cout << "CHAR16_T: ";
		std::cout << sizeof(ch16) << std::endl;
		std::cout << "Range: " << SCHAR_MIN << ":" << SCHAR_MAX << std::endl << std::endl;

		std::cout << "CHAR32_T: ";
		std::cout << sizeof(ch32) << std::endl;
		std::cout << "Range: " << 0 << ":" << UCHAR_MAX << std::endl << std::endl;

		std::cout << "SHORT: ";
		std::cout << sizeof(s) << std::endl;
		std::cout << "Range: " << SHRT_MIN << ":" << SHRT_MAX << std::endl << std::endl;

		std::cout << "INT: ";
		std::cout << sizeof(i) << std::endl;
		std::cout << "Range: " << INT_MIN << ":" << INT_MAX << std::endl << std::endl;

		std::cout << "LONG INT: ";
		std::cout << sizeof(l) << std::endl;
		std::cout << "Range: " << LONG_MIN << ":" << LONG_MAX << std::endl << std::endl;

		std::cout << "LONG LONG: ";
		std::cout << sizeof(ll) << std::endl;
		//std::cout << "Range: " << LONG_LONG_MIN << ":" << LONG_LONG_MAX << std::endl << std::endl;

		std::cout << "FLOAT: ";
		std::cout << sizeof(f) << std::endl;

		std::cout << "DOUBLE: ";
		std::cout << sizeof(d) << std::endl;

		std::cout << "LONG DOUBLE: ";
		std::cout << sizeof(ld) << std::endl;
	}
} // namespace basics
