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
		std::cout << "If the Recursive function has more than 1 recursice calls, it is knows as Tree Recursion."
                  << std::endl;
        std::cout << "<return-type> treeRecursion(int n)" << std::endl
                  << "{" << std::endl
                  << "........" << std::endl
                  << "....treeRecursion(n - 1)" << std::endl
                  << "....treeRecursion(n - 1)" << std::endl
                  << "}" << std::endl;

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

	void Recursions::ShowCaseIndicrectRecursion()
    {
        std::cout << "If a function A calls function B and that itself calls function A, it is known as Indirect Recursion."
                  << std::endl;
        std::cout << "<return-type> indirectRecursionA(int n)" << std::endl
                  << "{" << std::endl
                  << "........" << std::endl
                  << "....indirectRecursionB(n - 1)" << std::endl
                  << "}" << std::endl;

        std::cout << "<return-type> indirectRecursionB(int n)" << std::endl
                  << "{" << std::endl
                  << "........" << std::endl
                  << "....indirectRecursionA(n - 1)" << std::endl
                  << "}" << std::endl;

        std::function<void(int)> indirectRecursionB;

        std::function<void(int)> indirectRecursionA = [&indirectRecursionB](int n) {
            if (n > 0)
            {
                std::cout << "Calling Phase inside A for n: " << n << std::endl;
                indirectRecursionB(n - 1);
                std::cout << "Returning Phase inside A for n: " << n << std::endl;
            }
        };

        indirectRecursionB = [&indirectRecursionA](int n) {
            if (n > 1)
            {
                std::cout << "Calling Phase inside B for n: " << n << std::endl;
                indirectRecursionA(n - 1);
                std::cout << "Returning Phase inside B for n: " << n << std::endl;
            }
        };

        indirectRecursionA(3);
    }

	void Recursions::ShowCaseNestedRecursion()
    {
        std::cout << "If a recursive call passes another recursive call as its parameter, it is called Nested Recursion."
                  << std::endl;
        std::cout << "<return-type> nestedRecursion(int n)" << std::endl
                  << "{" << std::endl
                  << "........" << std::endl
                  << "....nestedRecursion(nestedRecursion(n - 1))" << std::endl
                  << "}" << std::endl;

        std::function<int (int)> nestedRecursion = [&nestedRecursion](int n) {
            if (n > 100)
            {
                return n - 10;
            }
            else
            {
                return nestedRecursion(nestedRecursion(n + 11));
            }
        };

        std::cout << "The output for this nested recursion is: " << nestedRecursion(95) << std::endl;
    }

	void Recursions::ShowCaseStaticVariableInRecursion()
    {
        std::cout << "Static variable lies in the code section and memory doesn't get deleted till the program ends so any update to it is permanent."
                  << std::endl;

        std::function<int (int)> staticVariableInRecursion = [&staticVariableInRecursion](int n) {
            static int x = 0;
            if (n > 0)
            {
                x++;
                return staticVariableInRecursion(n - 1) + x;
            }
            return 0;
        };

        std::cout << "The output for static variable in recursion is: " << staticVariableInRecursion(5) << std::endl;
    }

	void Recursions::ShowCaseGlobalVariableInRecursion()
    {
        std::cout << "Global variable lies in the code section and memory doesn't get deleted till the program ends so any update to it is permanent but"
                  << " its scope lies throughout the program"
                  << std::endl;

        int x = 10;

        std::function<int (int)> globalVariableInRecursion = [&globalVariableInRecursion, &x](int n) {
            if (n > 0)
            {
                x++;
                return globalVariableInRecursion(n - 1) + x;
            }
            return 0;
        };

        std::cout << "The output for global variable in recursion is: " << globalVariableInRecursion(5) << std::endl;
    }

	void Recursions::ShowCaseSumOfNaturalNumbersUsingRecursion()
    {
        std::cout << "Sum of natural numbers can be calculated using recursion"
                  << std::endl;

        std::function<int (int)> sumOfNaturalNumbersUsingRecursion = [&sumOfNaturalNumbersUsingRecursion](int n) {
            if (n > 0)
            {
                return sumOfNaturalNumbersUsingRecursion(n - 1) + n;
            }
            return 0;
        };

        std::cout << "The sum of first 10 natural numbers using recursion is: " << sumOfNaturalNumbersUsingRecursion(10) << std::endl;
        std::cout << "The sum of first 10 natural numbers using formula is: " << 10 * (10 + 1) / 2 << std::endl;
    }

	void Recursions::ShowCasePowerUsingRecursion()
    {
        std::cout << "Power can be calculated in two ways using recursion, one is the basic one and other is where we reduce the number of multiplications"
                  << " by multiplying one power in the base part and dividing the exponent part by 2"
                  << std::endl;

        std::function<int (int, int)> powerUsingRecursion = [&powerUsingRecursion](int m, int n) {
            if (n == 0)
                return 1;
            else
                return m * powerUsingRecursion(m, n - 1);
        };

        std::function<int (int, int)> powerUsingRecursionImproved = [&powerUsingRecursionImproved](int m, int n) {
            if (n == 0)
                return 1;
            else if (n % 2 == 0)
                return powerUsingRecursionImproved(m * m, n / 2);
            else
                return m * powerUsingRecursionImproved(m * m, (n - 1) / 2);
        };

        std::cout << "2 raised to the power of 10 according to powerUsingRecursion is: " << powerUsingRecursion(2, 10) << std::endl;
        std::cout << "2 raised to the power of 10 according to powerUsingRecursionImproved is: " << powerUsingRecursionImproved(2, 10) << std::endl;
    }

	void Recursions::ShowCaseFactorialUsingRecursion()
    {
        std::cout << "Factorial can be calculated using loop as well as recursion. The recursion will be of type tail recursion so it is better to"
                  << " use loops"
                  << std::endl;

        std::function<int(int)> factorialUsingRecursion = [&factorialUsingRecursion] (int n) {
            if (n < 0)
                return 0;
            else if (n == 1)
                return 1;
            else
                return factorialUsingRecursion(n - 1) * n;
        };

        std::cout << "The factorial of 5 calculated using factorial using recursion is: " << factorialUsingRecursion(5) << std::endl;
    }

	void Recursions::ShowCaseTaylorSeriesUsingRecursion()
    {
        std::cout << "Taylor series is the infinite sun of e function"
                  << std::endl;

        std::function<double(int, int)> taylorSeriesUsingRecursion = [&taylorSeriesUsingRecursion] (int x, int n) -> double {
            static double p = 1;
            static double f = 1;
            double result;
            if (n < 0)
            {
                return 0;
            }
            else if (n == 0)
            {
                return 1;
            }
            else
            {
                result = taylorSeriesUsingRecursion(x, n - 1);
                p = p * x;
                f = f * n;
                return (result + p / f);
            }
        };

        std::function<double(int, int)> taylorSeriesUsingHornersRule = [&taylorSeriesUsingHornersRule] (int x, int n) -> double {
            static double s = 1;
            if (n == 0)
                return s;
            s = 1 + x * s / n;
            return taylorSeriesUsingHornersRule(x, n - 1);
        };

        std::cout << "Taylor series result for e^5 with sum for 15 elements is: " << taylorSeriesUsingRecursion(5, 15) << std::endl;
        std::cout << "Taylor series result for e^5 with sum for 15 elements using Horner's Rule is: " << taylorSeriesUsingHornersRule(5, 15) << std::endl;
    }

	void Recursions::ShowCaseFibonacciSeriesUsingRecursion()
    {
        std::cout << "Fibonacci is a mathematical series where one element is the sum of the previous two elements"
                  << std::endl;
        std::cout << "To improve fibonacci computation, we see that one fibonacci call will call the function recursively for a"
                  << " particular value many times so we store this in an array and this technique is called memoization"
                  << std::endl;

        std::function<int(int)> fibonacciUsingRecursion = [&fibonacciUsingRecursion] (int n) {
            if (n <= 1)
            {
                return n;
            }

            return fibonacciUsingRecursion(n - 2) + fibonacciUsingRecursion(n - 1);
        };

        static int fibonacciSeries[15];
        for (int &i: fibonacciSeries)
            i = -1;

        std::function<int(int)> fibonacciUsingMemoization = [&fibonacciUsingMemoization] (int n) {
            if (n <= 1)
            {
                fibonacciSeries[n] = n;
                return n;
            }
            else
            {
                if (fibonacciSeries[n - 2] == -1)
                    fibonacciSeries[n - 2] = fibonacciUsingMemoization(n - 2);
                if (fibonacciSeries[n - 1] == -1)
                    fibonacciSeries[n - 1] = fibonacciUsingMemoization(n - 1);
                return fibonacciSeries[n - 2] + fibonacciSeries[n - 1];
            }
        };

        std::cout << "The fibonacci number at index 10 is: " << fibonacciUsingRecursion(10) << std::endl;
        std::cout << "The fibonacci number at index 10 using memoization is: " << fibonacciUsingMemoization(10) << std::endl;
    }

	void Recursions::ShowCaseCombinationUsingRecursion()
    {
        std::cout << "Combination is calculated for the total number of ways a subset can be selected from a set"
                  << std::endl;

        std::function<int(int, int)> combinationUsingRecursion = [&combinationUsingRecursion] (int n, int r) {
            if (r == 0 or n == r)
                return 1;
            return combinationUsingRecursion(n - 1, r) + combinationUsingRecursion(n - 1, r - 1);
        };

        std::cout << "The combination value of 5C3 is: " << combinationUsingRecursion(5, 3) << std::endl;
    }
} // namespace recursions
