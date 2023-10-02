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
			MIN_COUNT                                 = 0,
			HELLO_WORLD                               = 1,
			HELLO_NAME                                = 2,
			PRINT_DATA_TYPES_SIZE_AND_RANGES          = 3,
			SHOW_CASE_IF_ELSE                         = 4,
			SHOW_CASE_NESTED_IF_ELSE                  = 5,
			SHOW_CASE_IF_ELSE_LADDER                  = 6,
			SHOW_CASE_COMPOUND_CONDITIONAL_STATEMENTS = 7,
			SHOW_CASE_SHORT_CIRCUITING                = 8,
			SHOW_CASE_TERNARY_OPERATOR                = 9,
			SHOW_CASE_SWITCH_STATEMENT                = 10,
			SHOW_CASE_WHILE_LOOP                      = 11,
			SHOW_CASE_DO_WHILE_LOOP                   = 12,
			SHOW_CASE_FOR_LOOP                        = 13,
			SHOW_CASE_ARRAYS                          = 14,
			SHOW_CASE_FOR_EACH_LOOP                   = 15,
			SHOW_CASE_2D_ARRAYS                       = 16,
			BACK_TO_PREVIOUS_MENU                     = 17,
			EXIT_FROM_PROGRAM                         = 18,
			MAX_COUNT                                 = EXIT_FROM_PROGRAM
		};
		int						   m_choice{ 0 };
		std::string				   m_name;
		std::map<int, std::string> m_BasicsMenuMap;

	public:
		Basics();
		const int& GetMinCase();
		const int& GetMaxCase();
		const int& GetChoice();
		void       GetChoiceInputFromUser();
		void	   PrintMenu();
		void       PrintSelectedChoice();
		void	   HelloWorld();
		void       GetNameInputFromUser();
		void	   HelloName();
		void	   PrintDataTypeSizeAndRanges();
		void       ShowCaseIfElse();
		void       ShowCaseNestedIfElse();
		void       ShowCaseIfElseLadder();
		void       ShowCaseCompoundConditionalStatements();
		void       ShowCaseShortCircuiting();
		void       ShowCaseTernaryOperator();
		void       ShowCaseSwitchStatement();
		void       ShowCaseWhileLoop();
		void       ShowCaseDoWhileLoop();
		void       ShowCaseForLoop();
		void       ShowCaseArrays();
		void       ShowCaseForEachLoop();
		void       ShowCase2DArrays();
	};
} // namespace basics
