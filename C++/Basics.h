#pragma once

#include <string>
#include <map>

namespace basics
{
	class Basics
	{
	private:
		int choice{ 0 };
		enum BasicsMenu
		{
			HELLO_WORLD		      = 1,
			HELLO_NAME			  =	2,
			BACK_TO_PREVIOUS_MENU = 3,
			EXIT_FROM_PROGRAM     = 4
		};
		std::map<int, std::string> BasicsMenuMap =
		{
			{
				BasicsMenu(HELLO_WORLD),
				std::string("Hello World")
			},
			{
				BasicsMenu(HELLO_NAME),
				std::string("Hello Name")
			},
			{
				BasicsMenu(BACK_TO_PREVIOUS_MENU),
				std::string("Back to Main Menu")
			},
			{
				BasicsMenu(EXIT_FROM_PROGRAM),
				std::string("Exit")
			}	
		};
	public:
		Basics() = default;
		int			GetChoice();
		int			GetChoiceInputFromUser();
		void		PrintMenu();
		void        PrintSelectedChoice(const int&);
		void		HelloWorld();
		void		HelloName(std::string const&);
	};
}