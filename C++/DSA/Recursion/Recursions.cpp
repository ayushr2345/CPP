#include <iostream>
#include <functional>
#include "Recursions.h"
#include "../../utils.h"

namespace recursions
{
	Recursions::Recursions():
		m_choice            (0),
		m_name              (""),
		m_RecursionsMenuMap ({})
	{
		m_RecursionsMenuMap.insert({ m_RecursionsMenu(SHOWCASE_RECURSION), 
								     std::string("Showcase Recursion") });
		m_RecursionsMenuMap.insert({ m_RecursionsMenu(SHOWCASE_HEAD_RECURSION), 
								     std::string("Showcase Head Recursion") });
		m_RecursionsMenuMap.insert({ m_RecursionsMenu(SHOWCASE_TAIL_RECURSION), 
								     std::string("Showcase Tail Recursion") });
		m_RecursionsMenuMap.insert({ m_RecursionsMenu(SHOWCASE_TREE_RECURSION), 
								     std::string("Showcase Tree Recursion") });
		m_RecursionsMenuMap.insert({ m_RecursionsMenu(SHOWCASE_INDIRECT_RECURSION), 
								     std::string("Showcase Indirect Recursion") });
		m_RecursionsMenuMap.insert({ m_RecursionsMenu(SHOWCASE_NESTED_RECURSION), 
								     std::string("Showcase Nested Recursion") });
		m_RecursionsMenuMap.insert({ m_RecursionsMenu(SHOWCASE_STATIC_VARIABLE_IN_RECURSION), 
								     std::string("Showcase Static Variable In Recursion") });
		m_RecursionsMenuMap.insert({ m_RecursionsMenu(SHOWCASE_GLOBAL_VARIABLE_IN_RECURSION), 
								     std::string("Showcase Global Variable In Recursion") });
		m_RecursionsMenuMap.insert({ m_RecursionsMenu(SHOWCASE_SUM_OF_NATURAL_NUMBERS_USING_RECURSION), 
								     std::string("Showcase Sum of Natural Numbers Using Recursion") });
		m_RecursionsMenuMap.insert({ m_RecursionsMenu(SHOWCASE_POWER_USING_RECURSION), 
								     std::string("Showcase Power Using Recursion") });
		m_RecursionsMenuMap.insert({ m_RecursionsMenu(SHOWCASE_FACTORIAL_USING_RECURSION), 
								     std::string("Showcase Factorial Using Recursion") });
		m_RecursionsMenuMap.insert({ m_RecursionsMenu(SHOWCASE_TAYLOR_SERIES_USING_RECURSION), 
								     std::string("Showcase Taylor Series Using Recursion") });
		m_RecursionsMenuMap.insert({ m_RecursionsMenu(SHOWCASE_FIBONACCI_SERIES_USING_RECURSION), 
								     std::string("Showcase Fibonacci Series Using Recursion") });
		m_RecursionsMenuMap.insert({ m_RecursionsMenu(SHOWCASE_COMBINATION_USING_RECURSION), 
								     std::string("Showcase Combination Using Recursion") });
		m_RecursionsMenuMap.insert({ m_RecursionsMenu(BACK_TO_PREVIOUS_MENU), 
								 	 std::string("Back to Previous Menu") });
		m_RecursionsMenuMap.insert({ m_RecursionsMenu(EXIT_FROM_PROGRAM), 
							     	 std::string("Exit from program") });
	}

	const int Recursions::GetMinCase()
	{
		return m_RecursionsMenu::MIN_COUNT;
	}

	const int Recursions::GetMaxCase()
	{
		return m_RecursionsMenu::MAX_COUNT;
	}

	const int& Recursions::GetChoice()
	{
		return m_choice;
	}

	void Recursions::GetChoiceInputFromUser()
	{
		utils::InputNumberFromUser(m_choice, 1, static_cast<int>(m_RecursionsMenu::MAX_COUNT));
	}

	void Recursions::PrintMenu()
	{
		std::cout << std::endl;
		for (std::map<int, std::string>::iterator it = m_RecursionsMenuMap.begin();
			it != m_RecursionsMenuMap.end();
			it++)
		{
			std::cout << it->first << ". " << it->second << std::endl;
		}
		std::cout << "Please enter your choice: ";
	}

	void Recursions::PrintSelectedChoice()
	{
		std::cout << std::endl << std::endl
                  << "You have chosen choice "
                  << m_RecursionsMenuMap.at(m_choice)
                  << std::endl;
	}

	void Recursions::ShowCaseRecursion()
	{
		std::cout << "A function calling itself is known as a Recursive Function and the process is called Recursion."
				  << std::endl;
		std::cout << "<return-type> recursion(int n)" << std::endl
				  << "{" << std::endl
				  << "........" << std::endl
				  << "....if (<mandatory_termination_condition>)" << std::endl
				  << "....{" << std::endl
				  << "........recursion(n - 1)" << std::endl
				  << "....}" << std::endl
				  << "........" << std::endl
				  << "}" << std::endl;
	}

	void Recursions::ShowCaseHeadRecursion()
	{
		std::cout << "When the Recursive call inside a function is the first statement of the Recursive Function, it is called Head Recursion."
			  	  << std::endl;
		std::cout << "<return-type> headRecursion(int n)" << std::endl
			  	  << "{" << std::endl
			      << "....headRecursion(n - 1)" << std::endl
			      << "........" << std::endl
			      << "}" << std::endl;

		std::cout << "The example function is not a proper head recusion as we have pring statements during the calling phase for demonstration"
			      << " purposes. A real head recursion function will not have any statment present before the recursive call" << std::endl;

		std::function<void(int)> headRecursion = [&headRecursion](int n) {
			if (n > 0)
			{
				std::cout << "Calling Phase for n: " << n << std::endl;
				headRecursion(n - 1);
				std::cout << "Returning Phase for n: " << n << std::endl;
			}
		};

		headRecursion(5);
	}

	void Recursions::ShowCaseTailRecursion()
	{
		std::cout << "When the Recursive call inside a function is the last statement of the Recursive Function, it is called Tail Recursion."
                  << std::endl;
        std::cout << "<return-type> tailRecursion(int n)" << std::endl
                  << "{" << std::endl
                  << "........" << std::endl
                  << "....tailRecursion(n - 1)" << std::endl
                  << "}" << std::endl;

        std::cout << "The example function is not a proper tail recusion as we have pring statements during the calling phase for demonstration"
                  << " purposes. A real tail recursion function will not have any statment present after the recursive call" << std::endl;

        std::function<void(int)> tailRecursion = [&tailRecursion](int n) {
            if (n > 0)
            {
                    std::cout << "Calling Phase for n: " << n << std::endl;
                    tailRecursion(n - 1);
                    std::cout << "Returning Phase for n: " << n << std::endl;
            }
        };

        tailRecursion(5);
	}

	void Recursions::ShowCaseTreeRecursion()
	{
		std::cout << "When the Recursive call inside a function is the last statement of the Recursive Function, it is called Tail Recursion."
                  << std::endl;
        std::cout << "<return-type> treeRecursion(int n)" << std::endl
                  << "{" << std::endl
                  << "........" << std::endl
                  << "....treeRecursion(n - 1)" << std::endl
                  << "....treeRecursion(n - 1)" << std::endl
                  << "}" << std::endl;

        std::cout << "The example function is not a proper head recusion as we have pring statements during the calling phase for demonstration"
                  << " purposes. A real head recursion function will not have any statment present before the recursive call" << std::endl;

        std::function<void(int)> treeRecursion = [&treeRecursion](int n) {
            if (n > 0)
            {
                    std::cout << "Calling Phase 1 for n: " << n << std::endl;
                    treeRecursion(n - 1);
                    std::cout << "Returning Phase 1 for n: " << n << std::endl;
                    std::cout << "Calling Phase 2 for n: " << n << std::endl;
                    treeRecursion(n - 1);
                    std::cout << "Returning Phase 2 for n: " << n << std::endl;
            }
        };

        treeRecursion(3);
	}

	void 	   Recursions::ShowCaseIndicrectRecursion(){}

	void 	   Recursions::ShowCaseNestedRecursion(){}

	void 	   Recursions::ShowCaseStaticVariableInRecursion(){}

	void 	   Recursions::ShowCaseGlobalVariableInRecursion(){}

	void 	   Recursions::ShowCaseSumOfNaturalNumbersUsingRecursion(){}

	void 	   Recursions::ShowCasePowerUsingRecursion(){}

	void 	   Recursions::ShowCaseFactorialUsingRecursion(){}

	void 	   Recursions::ShowCaseTaylorSeriesUsingRecursion(){}

	void 	   Recursions::ShowCaseFibonacciSeriesUsingRecursion(){}

	void 	   Recursions::ShowCaseCombinationUsingRecursion(){}

	
} // namespace recursions
