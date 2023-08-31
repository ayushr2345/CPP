#include <iostream>
#include "handlers.h"

void handlers::Handle(basics::Basics& basicObj)
{
	basicObj.PrintMenu();
	basicObj.GetChoiceInputFromUser();
	int selectedChoice = basicObj.GetChoice();

	while(selectedChoice)
	{
		basicObj.PrintSelectedChoice(selectedChoice);
		switch (selectedChoice)
		{
		case 1:
		{
			basicObj.HelloWorld();
			break;
		}
		case 2:
		{
			std::string name;
			std::cout << "Please enter your name: ";
			std::cin.clear();
			std::getline(std::cin, name);
			basicObj.HelloName(name);
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