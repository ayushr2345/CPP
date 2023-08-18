#include<iostream>
#include "utils.h"
#include "handlers.h"
#include "Basics.h"

int main()
{
	utils::PrintWelcomeScreen();
	utils::PrintMainMenu();

	int choice;
	std::cin >> choice;

	while (choice)
	{
		switch (choice)
		{
		case 1:
		{
			std::cout << std::endl << std::endl
				<< "You have chosen choice "
				<< utils::MainMenuMap.at(utils::MainMenu::BASICS)
				<< std::endl;
			basics::Basics basicObj;
			handlers::Handle(basicObj);
			break;
		}
		case 2:
		{
			exit(0);
		}
		default:
			std::cout << "herer";
			break;
		}
		utils::PrintMainMenu();
		std::cin >> choice;
	}

	return 0;
}