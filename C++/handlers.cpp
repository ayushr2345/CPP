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
				break;
			}
			case 4:
			{
				exit(0);
			}
			default:
				std::cout << "The selected option is out of bounds!!! "
						  << "Please select appropriate option: " << std::endl;
				break;
			}

			basicObj.PrintMenu();
			basicObj.GetChoiceInputFromUser();
		}
	}
} // namespace handlers
