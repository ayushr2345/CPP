#include<iostream>
#include "handlers.h"

void handlers::Handle(basics::Basics& basicObj)
{
	basicObj.PrintMenu();
	const int selectedChoice = basicObj.GetChoiceInputFromUser();
	std::cout << "You have selected option: " << selectedChoice << std::endl;
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
		std::cin >> name;
		basicObj.HelloName(name);
		break;
	}
	case 3:
	{

	}
	default:
		std::cout << "Wrong Choice!!!" << " Please select again: " << std::endl;
		break;
	}
}