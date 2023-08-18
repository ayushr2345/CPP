#pragma once

#include<string>
#include<map>

namespace basics
{
	class Basics
	{
	private:
		int choice{ 0 };
		enum BasicsMenu
		{
			HELLO_WORLD = 1,
			HELLO_NAME = 2,
			EXIT = 3
		};
		std::map<BasicsMenu, std::string> BasicsMenuMap =
		{
			{
				BasicsMenu(HELLO_WORLD),
				std::string("Hello World")
			},
			{
				BasicsMenu(HELLO_NAME),
				std::string("Hello Name")
			}
		};
	public:
		Basics() = default;
		int			GetChoice();
		int			SetChoice(int&);
		int			GetChoiceInputFromUser();
		std::string GetSelectedChoice(BasicsMenu&);
		void		PrintMenu();
		void		HelloWorld();
		void		HelloName(std::string const&);
	};
}