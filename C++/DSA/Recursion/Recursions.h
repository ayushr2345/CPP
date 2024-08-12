#pragma once

#include <map>
#include <string>

namespace recursions
{
	class Recursions
	{
	private:
		enum m_RecursionsMenu
		{
			MIN_COUNT                                 		= 0,
			SHOWCASE_RECURSION								= 1,
			SHOWCASE_HEAD_RECURSION					  		= 2,
			SHOWCASE_TAIL_RECURSION					  		= 3,
			SHOWCASE_TREE_RECURSION					  		= 4,
			SHOWCASE_INDIRECT_RECURSION				  		= 5,
			SHOWCASE_NESTED_RECURSION				  		= 6,
			SHOWCASE_STATIC_VARIABLE_IN_RECURSION	  		= 7,
			SHOWCASE_GLOBAL_VARIABLE_IN_RECURSION	  		= 8,
			SHOWCASE_SUM_OF_NATURAL_NUMBERS_USING_RECURSION	= 9,
			SHOWCASE_POWER_USING_RECURSION		            = 10,
			SHOWCASE_FACTORIAL_USING_RECURSION			    = 11,
			SHOWCASE_TAYLOR_SERIES_USING_RECURSION		    = 12,
			SHOWCASE_FIBONACCI_SERIES_USING_RECURSION	    = 13,
			SHOWCASE_COMBINATION_USING_RECURSION		    = 14,
			BACK_TO_PREVIOUS_MENU							= 15,
			EXIT_FROM_PROGRAM                         		= 16,
			MAX_COUNT                                 		= EXIT_FROM_PROGRAM
		};
		int						   						    m_choice{ 0 };
		std::string				   						    m_name;
		std::map<int, std::string> 							m_RecursionsMenuMap;

	public:
		Recursions();
		const int  GetMinCase();
		const int  GetMaxCase();
		const int& GetChoice();
		void       GetChoiceInputFromUser();
		void	   PrintMenu();
		void       PrintSelectedChoice();
		void 	   ShowCaseRecursion();
		void 	   ShowCaseHeadRecursion();
		void 	   ShowCaseTailRecursion();
		void 	   ShowCaseTreeRecursion();
		void 	   ShowCaseIndicrectRecursion();
		void 	   ShowCaseNestedRecursion();
		void 	   ShowCaseStaticVariableInRecursion();
		void 	   ShowCaseGlobalVariableInRecursion();
		void 	   ShowCaseSumOfNaturalNumbersUsingRecursion();
		void 	   ShowCasePowerUsingRecursion();
		void 	   ShowCaseFactorialUsingRecursion();
		void 	   ShowCaseTaylorSeriesUsingRecursion();
		void 	   ShowCaseFibonacciSeriesUsingRecursion();
		void 	   ShowCaseCombinationUsingRecursion();
	};
} // namespace recursions
