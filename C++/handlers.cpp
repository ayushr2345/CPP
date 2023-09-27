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
			{
				std::cout << "The selected option is out of bounds!!! "
						  << "Please select appropriate option: " << std::endl;
				break;
			}
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

	void Handle(pointersAndReferences::PointersAndReferences& pointersAndReferencesObj)
	{
		pointersAndReferencesObj.PrintMenu();
		pointersAndReferencesObj.GetChoiceInputFromUser();
		const int& selectedChoice = pointersAndReferencesObj.GetChoice();

		while (pointersAndReferencesObj.GetChoice())
		{
			char previousMenuFlag = 'n';
			if (selectedChoice > pointersAndReferencesObj.GetMinCase() &&
				selectedChoice < pointersAndReferencesObj.GetMaxCase() + 1)
			{
				pointersAndReferencesObj.PrintSelectedChoice();
			}

			switch (selectedChoice)
			{
			case 1:
			{
				std::cout << "Data in member data variable is: " << pointersAndReferencesObj.GetData() << std::endl;
				break;
			}
			case 2:
			{
				std::cout << "Address of member data variable is: " << pointersAndReferencesObj.GetDataAddress() << std::endl;
				break;
			}
			case 3:
			{
				pointersAndReferencesObj.SetDataInPtr();
				break;
			}
			case 4:
			{
				std::cout << "The member pointer variable points to location with data as: "
					<< pointersAndReferencesObj.DereferenceMemberPointer() << std::endl;
			}
			case 5:
			{
				std::cout << "The address stored in the member pointer variable is: "
					<< pointersAndReferencesObj.GetDataInPointer() << std::endl;
				break;
			}
			case 6:
			{
				std::cout << "The address of the member pointer is: "
					<< pointersAndReferencesObj.GetPointerAddress() << std::endl;
				break;
			}
			case 7:
			{
				std::cout << "The data in member reference variable is: "
					<< pointersAndReferencesObj.GetDataInReference();
				break;
			}
			case 8:
			{
				std::cout << "The addredd of the member reference variable is: "
					<< pointersAndReferencesObj.GetAddressOfReference();
				break;
			}
			case 9:
			{
				std::cout << "Please enter a preference: (0 - addition / 1 - subtraction)";
				int ch{ 0 };
				utils::InputIntegerFromUser(ch, 0, 1);
				pointersAndReferencesObj.IncrementOrDecrementDataViaRegular(ch);
				std::cout << "The data in member data variable now is: " << pointersAndReferencesObj.GetData() << std::endl;
				break;
			}
			case 10:
			{
				std::cout << "Please enter a preference: (0 - addition / 1 - subtraction)";
				int ch{ 0 };
				utils::InputIntegerFromUser(ch, 0, 1);
				pointersAndReferencesObj.IncrementOrDecrementDataViaReference(ch);
				std::cout << "The data in member data variable now is: " << pointersAndReferencesObj.GetData() << std::endl;
				break;
			}
			case 11:
			{
				std::cout << "Please enter a preference: (0 - addition / 1 - subtraction)";
				int ch{ 0 };
				utils::InputIntegerFromUser(ch, 0, 1);
				pointersAndReferencesObj.IncrementOrDecrementDataViaPointer(ch);
				std::cout << "The data in member data variable now is: " << pointersAndReferencesObj.GetData() << std::endl;
				break;
			}
			case 12:
			{
				pointersAndReferencesObj.CompareAddressesOfThree();
				break;
			}
			case 13:
			{
				pointersAndReferencesObj.CompareDataOfThree();
				break;
			}
			case 14:
			{
				std::cout << "Please enter the size of the array: ";
				int size{ 0 };
				utils::InputIntegerFromUser(size, 1, 10);
				pointersAndReferencesObj.InitializeArray(size);
				break;
			}
			case 15:
			{
				std::cout << "The size of the array is: " << pointersAndReferencesObj.GetArraySize() << std::endl;
				break;
			}
			case 16:
			{
				pointersAndReferencesObj.FillTheArray();
				break;
			}
			case 17:
			{
				pointersAndReferencesObj.ShowCaseArraysWithPointers();
				break;
			}
			case 18:
			{
				pointersAndReferencesObj.DisplayArray();
				break;
			}
			case 19:
			{
				pointersAndReferencesObj.ShowCaseProblemsWithArrays();
				break;
			}
			case 20:
			{
				previousMenuFlag = 'y';
				break;
			}
			case 21:
			{
				exit(0);
			}
			default:
			{
				std::cout << "The selected option is out of bounds!!! "
					      << "Please select appropriate option: " << std::endl;
				break;
			}
			}

			if (previousMenuFlag == 'y')
			{
				break;
			}
			else
			{
				pointersAndReferencesObj.PrintMenu();
				pointersAndReferencesObj.GetChoiceInputFromUser();
			}
		}
	}
} // namespace handlers
