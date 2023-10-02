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
				break;
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
						  << pointersAndReferencesObj.GetDataInReference() << std::endl;
				break;
			}
			case 8:
			{
				std::cout << "The addredd of the member reference variable is: "
					      << pointersAndReferencesObj.GetAddressOfReference() << std::endl;
				break;
			}
			case 9:
			{
				std::cout << "Please enter a preference (0 - addition / 1 - subtraction): ";
				int ch{ 0 };
				utils::InputIntegerFromUser(ch, 0, 1);
				pointersAndReferencesObj.IncrementOrDecrementDataViaRegular(ch);
				std::cout << "The data in member data variable now is: " << pointersAndReferencesObj.GetData() << std::endl;
				break;
			}
			case 10:
			{
				std::cout << "Please enter a preference (0 - addition / 1 - subtraction): ";
				int ch{ 0 };
				utils::InputIntegerFromUser(ch, 0, 1);
				pointersAndReferencesObj.IncrementOrDecrementDataViaReference(ch);
				std::cout << "The data in member data variable now is: " << pointersAndReferencesObj.GetData() << std::endl;
				break;
			}
			case 11:
			{
				std::cout << "Please enter a preference (0 - addition / 1 - subtraction): ";
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
				char ch { 'y' };
				if (not pointersAndReferencesObj.IsArrayNull())
				{
					std::cout << "Data exists in the array. Do you wish to overwrite it? (y/n): ";
					std::cin >> ch;
				}
				if (ch == 'y' or ch == 'Y')
				{
					std::cout << "Please enter the size of the array: ";
					int size{ 0 };
					utils::InputIntegerFromUser(size, 1, 10);
					pointersAndReferencesObj.InitializeArray(size);
					pointersAndReferencesObj.FillTheArray();
				}
				break;
			}
			case 15:
			{
				std::cout << "The size of the array is: " << pointersAndReferencesObj.GetArraySize() << std::endl;
				break;
			}
			case 16:
			{
				pointersAndReferencesObj.ShowCaseArraysWithPointers();
				break;
			}
			case 17:
			{
				pointersAndReferencesObj.DisplayArray();
				break;
			}
			case 18:
			{
				pointersAndReferencesObj.ShowCaseProblemsWithArrays();
				break;
			}
			case 19:
			{
				previousMenuFlag = 'y';
				break;
			}
			case 20:
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

	void Handle(cStyleStrings::CStyleStrings& cStyleStringsObj)
	{
		cStyleStringsObj.PrintMenu();
		cStyleStringsObj.GetChoiceInputFromUser();
		const int& selectedChoice = cStyleStringsObj.GetChoice();

		while (cStyleStringsObj.GetChoice())
		{
			char previousMenuFlag = 'n';
			if (selectedChoice > cStyleStringsObj.GetMinCase() &&
				selectedChoice < cStyleStringsObj.GetMaxCase() + 1)
			{
				cStyleStringsObj.PrintSelectedChoice();
			}

			switch (selectedChoice)
			{
			case 1:
			{
				cStyleStringsObj.ShowcaseCStyleStrings();
				break;
			}
			case 2:
			{
				std::cout << "The string is: " << cStyleStringsObj.GetString() << std::endl;
				break;
			}
			case 3:
			{
				std::cout << "The length of the string is: " << cStyleStringsObj.GetStringLength() << std::endl;
				break;
			}
			case 4:
			{
				int lengthOfString { 0 };
				std::cout << "Enter the length of the string you want to input: ";
				utils::InputIntegerFromUser(lengthOfString, 1, 20);
				cStyleStringsObj.SetStringPointer(lengthOfString);
				break;
			}
			case 5:
			{
				if (cStyleStringsObj.GetStringPointer() != nullptr)
				{
					std::cout << "The string pointer points to string: " << cStyleStringsObj.GetStringPointer() << std::endl;
				}
				break;
			}
			case 6:
			{
				std::cout << "The length of the string the string pointer points to is: " << cStyleStringsObj.GetStringPointerLength() << std::endl;
				break;
			}
			case 7:
			{
				if (cStyleStringsObj.IsStringPointerEmpty())
				{
					std::cout << "The string pointer points to nullptr, hence the length of the string pointer is 0" << std::endl;
				}
				else
				{
					std::cout << "The length of the string pointer is: " << cStyleStringsObj.GetStringPointerLength() << std::endl;
				}
				break;
			}
			case 8:
			{
				int res = cStyleStringsObj.CompareStringWithStringPointer();
				if (res == 0)
				{
					std::cout << "Both the strings are equal: " << cStyleStringsObj.GetString() << " == " << cStyleStringsObj.GetStringPointer() << std::endl;
				}
				else if (res < 0)
				{
					std::cout << "Both the strings are not equal: " << cStyleStringsObj.GetString() << " < " << cStyleStringsObj.GetStringPointer() << std::endl;
					std::cout << "The difference is: " << res << std::endl;
				}
				else
				{
					std::cout << "Both the strings are not equal: " << cStyleStringsObj.GetString() << " > " << cStyleStringsObj.GetStringPointer() << std::endl;
					std::cout << "The difference is: " << res << std::endl;
				}
				break;
			}
			case 9:
			{
				if (cStyleStringsObj.GetStringPointerLength() == 0)
				{
					std::cout << "String not set in string pointer member variable. Set that first!" << std::endl;
					break;
				}
				int totalLength = cStyleStringsObj.GetStringLength() + cStyleStringsObj.GetStringPointerLength() + 1;
				char* concat = new char[totalLength];
				cStyleStringsObj.ConcatenateStringAndStringPointer(concat, totalLength);
				std::cout << "The concatenated string is: " << concat << " and the original strings were: " << cStyleStringsObj.GetString() << ", " << cStyleStringsObj.GetStringPointer() << std::endl;
				delete[] concat;
				break;
			}
			case 10:
			{
				if (cStyleStringsObj.GetStringPointerLength() == 0)
				{
					std::cout << "String not set in string pointer member variable. Set that first!" << std::endl;
					break;
				}
				int ind { 0 };
				std::cout << "Enter the index length till which you want to concatenate: ";
				utils::InputIntegerFromUser(ind, 0, (int)cStyleStringsObj.GetStringPointerLength());
				int totalLength = cStyleStringsObj.GetStringLength() + cStyleStringsObj.GetStringPointerLength() + 1;
				char* concat = new char[totalLength];
				cStyleStringsObj.NConcatenateStringAndStringPointer(concat, totalLength, ind);
				std::cout << "The concatenated string is: " << concat << " and the original strings were: " << cStyleStringsObj.GetString() << ", " << cStyleStringsObj.GetStringPointer() << std::endl;
				delete[] concat;
				break;
			}
			case 11:
			{
				cStyleStringsObj.ShowcaseStringToLong();
				break;
			}
			case 12:
			{
				cStyleStringsObj.ShowcaseStringToFloat();
				break;
			}
			case 13:
			{
				cStyleStringsObj.ShowcaseStringToToken();
				break;
			}
			case 14:
			{
				previousMenuFlag = 'y';
				break;
			}
			case 15:
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
				cStyleStringsObj.PrintMenu();
				cStyleStringsObj.GetChoiceInputFromUser();
			}
		}
	}
} // namespace handlers
