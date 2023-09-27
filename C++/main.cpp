#pragma once

#include <iostream>
#include "handlers.h"

int main()
{
	utils::PrintWelcomeScreen();
	utils::PrintMainMenu();

	int choice { 0 };
	utils::InputIntegerFromUser(choice, 1, utils::MainMenu::MAX_COUNT);

	while (choice)
	{
		if (choice > utils::MainMenu::MIN_COUNT &&
			choice < utils::MainMenu::MAX_COUNT + 1)
		{
			utils::PrintSelectedChoice(choice);
		}
		switch (choice)
		{
		case 1:
		{
			basics::Basics basicObj;
			handlers::Handle(basicObj);
			break;
		}
		case 2:
		{
			int choiceForPointersAndReferences { 0 };
			std::cout << "Please enter a number to get started with Pointers and References: ";
			utils::InputIntegerFromUser(choiceForPointersAndReferences);
			pointersAndReferences::PointersAndReferences pointersAndReferencesObj(choiceForPointersAndReferences);
			handlers::Handle(pointersAndReferencesObj);
			break;
		}
		case 3:
		{
			exit(0);
		}
		default:
			std::cout << "The selected option is out of bounds!!! "
					  << "Please select appropriate option: " << std::endl;
			break;
		}
		utils::PrintMainMenu();
		std::cin >> choice;
	}

	return 0;
}
