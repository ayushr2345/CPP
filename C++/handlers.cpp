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
			}
			case 4:
			{
				previousMenuFlag = 'y';
				break;
			}
			case 5:
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
