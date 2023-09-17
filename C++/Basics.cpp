#pragma once

#include "Basics.h"
#include "utils.h"
#include <iostream>
#include <iomanip>
#include <limits>	

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
		// As there are 22 types in the table, counter is set to 23 and counterDec is a lambda which will decrement the counter
		// counterDec is called in each row of the table. As all the counterDec are called in same cout statement, they will get executed
		// in reverse order hence we use this approach. 
		// NOTE: This is illegal in C++ and can give undefined behaviour
		int counter { 23 };
		auto counterDec = [&counter] () -> int
			{
				counter -= 1;
				return counter; 
			};


		std::cout << std::left <<
			" ---------------------------------------------------------------------------------------------------------\n"                              <<
			"| " << std::setw(9) << "[S. NO.]"   << "| " << std::setw(19) << "[DATA TYPE]"        << "| " << std::setw(7) << "[SIZE]"                   << "| " << std::setw(17) << "[SIZE (in bits)]"             << "| " << std::setw(21) << "[RANGE (Min)]"                                << "| " << std::setw(21) << "[RANGE (Max)]"                                << "|\n" <<
			" ---------------------------------------------------------------------------------------------------------\n"                <<																		  
			"| " << std::setw(9) << counterDec() << "| " << std::setw(19) << "BOOL"               << "| " << std::setw(7) << sizeof(bool)               << "| " << std::setw(17) << 8 * sizeof(bool)               << "| " << std::setw(21) << std::numeric_limits<bool>::min()               << "| " << std::setw(21) << std::numeric_limits<bool>::max()               << "|\n" <<
			"| " << std::setw(9) << counterDec() << "| " << std::setw(19) << "CHAR"               << "| " << std::setw(7) << sizeof(char)               << "| " << std::setw(17) << 8 * sizeof(char)               << "| " << std::setw(21) << (int)std::numeric_limits<char>::min()          << "| " << std::setw(21) << (int)std::numeric_limits<char>::max()          << "|\n" <<
			"| " << std::setw(9) << counterDec() << "| " << std::setw(19) << "SIGNED CHAR"        << "| " << std::setw(7) << sizeof(signed char)        << "| " << std::setw(17) << 8 * sizeof(signed char)        << "| " << std::setw(21) << (int)std::numeric_limits<signed char>::min()   << "| " << std::setw(21) << (int)std::numeric_limits<signed char>::max()   << "|\n" <<
			"| " << std::setw(9) << counterDec() << "| " << std::setw(19) << "UNSIGNED CHAR"      << "| " << std::setw(7) << sizeof(unsigned char)      << "| " << std::setw(17) << 8 * sizeof(unsigned char)      << "| " << std::setw(21) << (int)std::numeric_limits<unsigned char>::min() << "| " << std::setw(21) << (int)std::numeric_limits<unsigned char>::max() << "|\n" <<
			"| " << std::setw(9) << counterDec() << "| " << std::setw(19) << "WCHAR_T"            << "| " << std::setw(7) << sizeof(wchar_t)            << "| " << std::setw(17) << 8 * sizeof(wchar_t)            << "| " << std::setw(21) << (int)std::numeric_limits<wchar_t>::min()       << "| " << std::setw(21) << (int)std::numeric_limits<wchar_t>::max()       << "|\n" <<
			"| " << std::setw(9) << counterDec() << "| " << std::setw(19) << "CHAR16_T"           << "| " << std::setw(7) << sizeof(char16_t)           << "| " << std::setw(17) << 8 * sizeof(char16_t)           << "| " << std::setw(21) << (int)std::numeric_limits<char16_t>::min()      << "| " << std::setw(21) << (int)std::numeric_limits<char16_t>::max()      << "|\n" <<
			"| " << std::setw(9) << counterDec() << "| " << std::setw(19) << "CHAR32_T"           << "| " << std::setw(7) << sizeof(char32_t)           << "| " << std::setw(17) << 8 * sizeof(char32_t)           << "| " << std::setw(21) << (int)std::numeric_limits<char32_t>::min()      << "| " << std::setw(21) << (int)std::numeric_limits<char32_t>::max()      << "|\n" <<
			"| " << std::setw(9) << counterDec() << "| " << std::setw(19) << "SHORT"              << "| " << std::setw(7) << sizeof(short)              << "| " << std::setw(17) << 8 * sizeof(short)              << "| " << std::setw(21) << std::numeric_limits<short>::min()              << "| " << std::setw(21) << std::numeric_limits<short>::max()              << "|\n" <<
			"| " << std::setw(9) << counterDec() << "| " << std::setw(19) << "SIGNED SHORT"       << "| " << std::setw(7) << sizeof(signed short)       << "| " << std::setw(17) << 8 * sizeof(signed short)       << "| " << std::setw(21) << std::numeric_limits<signed short>::min()       << "| " << std::setw(21) << std::numeric_limits<signed short>::max()       << "|\n" <<
			"| " << std::setw(9) << counterDec() << "| " << std::setw(19) << "UNSIGNED SHORT"     << "| " << std::setw(7) << sizeof(unsigned short)     << "| " << std::setw(17) << 8 * sizeof(unsigned short)     << "| " << std::setw(21) << std::numeric_limits<unsigned short>::min()     << "| " << std::setw(21) << std::numeric_limits<unsigned short>::max()     << "|\n" <<
			"| " << std::setw(9) << counterDec() << "| " << std::setw(19) << "INT"                << "| " << std::setw(7) << sizeof(int)                << "| " << std::setw(17) << 8 * sizeof(int)                << "| " << std::setw(21) << std::numeric_limits<int>::min()                << "| " << std::setw(21) << std::numeric_limits<int>::max()                << "|\n" <<
			"| " << std::setw(9) << counterDec() << "| " << std::setw(19) << "SIGNED INT"         << "| " << std::setw(7) << sizeof(signed int)         << "| " << std::setw(17) << 8 * sizeof(signed int)         << "| " << std::setw(21) << std::numeric_limits<signed int>::min()         << "| " << std::setw(21) << std::numeric_limits<signed int>::max()         << "|\n" <<
			"| " << std::setw(9) << counterDec() << "| " << std::setw(19) << "UNSIGNED INT"       << "| " << std::setw(7) << sizeof(unsigned int)       << "| " << std::setw(17) << 8 * sizeof(unsigned int)       << "| " << std::setw(21) << std::numeric_limits<unsigned int>::min()       << "| " << std::setw(21) << std::numeric_limits<unsigned int>::max()       << "|\n" <<
			"| " << std::setw(9) << counterDec() << "| " << std::setw(19) << "LONG"               << "| " << std::setw(7) << sizeof(long)               << "| " << std::setw(17) << 8 * sizeof(long)               << "| " << std::setw(21) << std::numeric_limits<long>::min()               << "| " << std::setw(21) << std::numeric_limits<long>::max()               << "|\n" <<
			"| " << std::setw(9) << counterDec() << "| " << std::setw(19) << "SIGNED LONG"        << "| " << std::setw(7) << sizeof(signed long)        << "| " << std::setw(17) << 8 * sizeof(signed long)        << "| " << std::setw(21) << std::numeric_limits<signed long>::min()        << "| " << std::setw(21) << std::numeric_limits<signed long>::max()        << "|\n" <<
			"| " << std::setw(9) << counterDec() << "| " << std::setw(19) << "UNSIGNED LONG"      << "| " << std::setw(7) << sizeof(unsigned long)      << "| " << std::setw(17) << 8 * sizeof(unsigned long)      << "| " << std::setw(21) << std::numeric_limits<unsigned long>::min()      << "| " << std::setw(21) << std::numeric_limits<unsigned long>::max()      << "|\n" <<
			"| " << std::setw(9) << counterDec() << "| " << std::setw(19) << "LONG LONG"          << "| " << std::setw(7) << sizeof(long long)          << "| " << std::setw(17) << 8 * sizeof(long long)          << "| " << std::setw(21) << std::numeric_limits<long long>::min()          << "| " << std::setw(21) << std::numeric_limits<long long>::max()          << "|\n" <<
			"| " << std::setw(9) << counterDec() << "| " << std::setw(19) << "SIGNED LONG LONG"   << "| " << std::setw(7) << sizeof(signed long long)   << "| " << std::setw(17) << 8 * sizeof(signed long long)   << "| " << std::setw(21) << std::numeric_limits<signed long long>::min()   << "| " << std::setw(21) << std::numeric_limits<signed long long>::max()   << "|\n" <<
			"| " << std::setw(9) << counterDec() << "| " << std::setw(19) << "UNSIGNED LONG LONG" << "| " << std::setw(7) << sizeof(unsigned long long) << "| " << std::setw(17) << 8 * sizeof(unsigned long long) << "| " << std::setw(21) << std::numeric_limits<unsigned long long>::min() << "| " << std::setw(21) << std::numeric_limits<unsigned long long>::max() << "|\n" <<
			"| " << std::setw(9) << counterDec() << "| " << std::setw(19) << "FLOAT"              << "| " << std::setw(7) << sizeof(float)              << "| " << std::setw(17) << 8 * sizeof(float)              << "| " << std::setw(21) << std::numeric_limits<float>::min()              << "| " << std::setw(21) << std::numeric_limits<float>::max()              << "|\n" <<
			"| " << std::setw(9) << counterDec() << "| " << std::setw(19) << "DOUBLE"             << "| " << std::setw(7) << sizeof(double)	            << "| " << std::setw(17) << 8 * sizeof(double)	           << "| " << std::setw(21) << std::numeric_limits<double>::min()             << "| " << std::setw(21) << std::numeric_limits<double>::max()             << "|\n" <<
			"| " << std::setw(9) << counterDec() << "| " << std::setw(19) << "LONG DOUBLE"        << "| " << std::setw(7) << sizeof(long double)        << "| " << std::setw(17) << 8 * sizeof(long double)        << "| " << std::setw(21) << std::numeric_limits<long double>::min()        << "| " << std::setw(21) << std::numeric_limits<long double>::max()        << "|\n" <<
			" ---------------------------------------------------------------------------------------------------------\n";

	}
} // namespace basics
