#pragma once

#include <string>
#include <map>

namespace basics
{
	class Basics
	{
	private:
		enum m_BasicsMenu
		{
			MIN_COUNT                        = 0,
			HELLO_WORLD                      = 1,
			HELLO_NAME                       = 2,
			PRINT_DATA_TYPES_SIZE_AND_RANGES = 3,
			BACK_TO_PREVIOUS_MENU            = 4,
			EXIT_FROM_PROGRAM                = 5,
			MAX_COUNT                        = EXIT_FROM_PROGRAM
		};
		int						   m_choice{ 0 };
		std::string				   m_name;
		std::map<int, std::string> m_BasicsMenuMap;
	public:
		Basics();
		const int  GetMinCase();
		const int  GetMaxCase();
		const int& GetChoice();
		void       GetChoiceInputFromUser();
		void	   PrintMenu();
		void       PrintSelectedChoice();
		void	   HelloWorld();
		void       GetNameInputFromUser();
		void	   HelloName();
		void	   PrintDataTypeSizeAndRanges();
	};
} // namespace basics
