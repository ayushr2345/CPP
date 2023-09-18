#pragma once

#include <iostream>
#include "handlers.h"

namespace handlers
{
	void Handle(basics::Basics& basicObj)
	{
		basicObj.PrintMenu();
		basicObj.GetChoiceInputFromUser();
		const int& selectedChoice = basicObj.GetChoice();

		while (basicObj.GetChoice())
		{
			char previousMenuFlag = 'n';
			if (selectedChoice > basicObj.GetMinCase() &&
				selectedChoice < basicObj.GetMaxCase() + 1)
			{
				basicObj.PrintSelectedChoice();
			}

			switch (selectedChoice)
			{
			case 1:
			{
				basicObj.HelloWorld();
				break;
			}
			case 2:
			{
				std::cout << "Please enter your name: ";
				basicObj.GetNameInputFromUser();
				basicObj.HelloName();
				break;
			}
			case 3:
			{
				basicObj.PrintDataTypeSizeAndRanges();
				break;
			}
			case 4:
			{
				basicObj.ShowCaseIfElse();
				break;
			}
			case 5:
			{
				basicObj.ShowCaseNestedIfElse();
				break;
			}
			case 6:
			{
				basicObj.ShowCaseIfElseLadder();
				break;
			}
			case 7:
			{
				basicObj.ShowCaseCompoundConditionalStatements();
				break;
			}
			case 8:
			{
				basicObj.ShowCaseShortCircuiting();
				break;
			}
			case 9:
			{
				basicObj.ShowCaseTernaryOperator();
				break;
			}
			case 10:
			{
				basicObj.ShowCaseSwitchStatement();
				break;
			}
			case 11:
			{
				basicObj.ShowCaseWhileLoop();
				break;
			}
			case 12:
			{
				basicObj.ShowCaseDoWhileLoop();
				break;
			}
			case 13:
			{
				basicObj.ShowCaseForLoop();
				break;
			}
			case 14:
			{
				basicObj.ShowCaseArrays();
				break;
			}
			case 15:
			{
				basicObj.ShowCaseForEachLoop();
				break;
			}
			case 16:
			{
				basicObj.ShowCase2DArrays();
				break;
			}
			case 17:
			{
				previousMenuFlag = 'y';
				break;
			}
			case 18:
			{
				exit(0);
			}
			default:
				std::cout << "The selected option is out of bounds!!! "
						  << "Please select appropriate option: " << std::endl;
				break;
			}

			if (previousMenuFlag == 'y')
			{
				break;
			}
			else
			{
				basicObj.PrintMenu();
				basicObj.GetChoiceInputFromUser();
			}
		}
	}
} // namespace handlers
