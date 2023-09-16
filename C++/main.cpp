#pragma once

#include <iostream>
#include "utils.h"
#include "handlers.h"
#include "Basics.h"

int main()
{
	utils::PrintWelcomeScreen();
	utils::PrintMainMenu();

	int choice { 0 };
	utils::InputIntegerChoiceFromUser(choice);

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
