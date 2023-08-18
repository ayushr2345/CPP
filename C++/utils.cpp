#include<iostream>
#include<iomanip>
#include "utils.h"

void utils::PrintWelcomeScreen()
{
	std::cout << "#################### WELCOME ####################" << std::endl;
	std::cout << "Welcome to the World of Learning C++, we have programs of all sorts starting"
		" from Hello World to DSAs implemented using Classes or C style programs. Choose one"
		" from the menu below : " << std::endl;
}

void utils::PrintMainMenu()
{
	std::cout << "1. Basics" << std::endl
		<< "2. Exit" << std::endl;
	std::cout << "Please enter your choice: ";
}