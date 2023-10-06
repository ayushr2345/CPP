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
				utils::InputNumberFromUser(ch, 0, 1);
				pointersAndReferencesObj.IncrementOrDecrementDataViaRegular(ch);
				std::cout << "The data in member data variable now is: " << pointersAndReferencesObj.GetData() << std::endl;
				break;
			}
			case 10:
			{
				std::cout << "Please enter a preference (0 - addition / 1 - subtraction): ";
				int ch{ 0 };
				utils::InputNumberFromUser(ch, 0, 1);
				pointersAndReferencesObj.IncrementOrDecrementDataViaReference(ch);
				std::cout << "The data in member data variable now is: " << pointersAndReferencesObj.GetData() << std::endl;
				break;
			}
			case 11:
			{
				std::cout << "Please enter a preference (0 - addition / 1 - subtraction): ";
				int ch{ 0 };
				utils::InputNumberFromUser(ch, 0, 1);
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
					utils::InputNumberFromUser(size, 1, 10);
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
				utils::InputNumberFromUser(lengthOfString, 1, 20);
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
				utils::InputNumberFromUser(ind, 0, (int)cStyleStringsObj.GetStringPointerLength());
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

	void Handle(cppStrings::CPPStrings& cppStringsObj)
	{
		cppStringsObj.PrintMenu();
		cppStringsObj.GetChoiceInputFromUser();
		const int& selectedChoice = cppStringsObj.GetChoice();

		while (cppStringsObj.GetChoice())
		{
			char previousMenuFlag = 'n';
			if (selectedChoice > cppStringsObj.GetMinCase() &&
				selectedChoice < cppStringsObj.GetMaxCase() + 1)
			{
				cppStringsObj.PrintSelectedChoice();
			}

			switch (selectedChoice)
			{
			case 1:
			{
				cppStringsObj.ShowcaseCPPStyleStrings();
				break;
			}
			case 2:
			{
				std::cout << "The string is: " << cppStringsObj.GetString() << std::endl;
				break;
			}
			case 3:
			{
				std::cout << "The length of the string is: " << cppStringsObj.GetStringLength() << std::endl;
				break;
			}
			case 4:
			{
				std::cout << "The capacity of the string is: " << cppStringsObj.GetStringCapacity() << std::endl;
				break;
			}
			case 5:
			{
				cppStringsObj.SetStringPointer();
				break;
			}
			case 6:
			{
				if (cppStringsObj.GetStringPointer() != "")
				{
					std::cout << "The string pointer points to string: " << cppStringsObj.GetStringPointer() << std::endl;
				}
				break;
			}
			case 7:
			{
				std::cout << "The length of the string the string pointer points to is: " << cppStringsObj.GetStringPointerLength() << std::endl;
				break;
			}
			case 8:
			{
				if (cppStringsObj.IsStringPointerEmpty())
				{
					std::cout << "The string pointer points to nullptr, hence the length of the string pointer is 0" << std::endl;
				}
				else
				{
					std::cout << "The length of the string pointer is: " << cppStringsObj.GetStringPointerLength() << std::endl;
				}
				break;
			}
			case 9:
			{
				int res = cppStringsObj.CompareStringWithStringPointer();
				if (res == 0)
				{
					std::cout << "Both the strings are equal: " << cppStringsObj.GetString() << " == " << cppStringsObj.GetStringPointer() << std::endl;
				}
				else if (res < 0)
				{
					std::cout << "Both the strings are not equal: " << cppStringsObj.GetString() << " < " << cppStringsObj.GetStringPointer() << std::endl;
					std::cout << "The difference is: " << res << std::endl;
				}
				else
				{
					std::cout << "Both the strings are not equal: " << cppStringsObj.GetString() << " > " << cppStringsObj.GetStringPointer() << std::endl;
					std::cout << "The difference is: " << res << std::endl;
				}
				break;
			}
			case 10:
			{
				std::string str;
				cppStringsObj.ConcatenateStringAndStringPointer(str);
				std::cout << "The concatenated string is: " << str << " and the original strings were: " << cppStringsObj.GetString() << ", " << cppStringsObj.GetStringPointer() << std::endl;
				break;
			}
			case 11:
			{
				if (cppStringsObj.GetStringPointerLength() == 0)
				{
					std::cout << "String not set in string pointer member variable. Set that first!" << std::endl;
					break;
				}
				int ind{ 0 };
				std::string str;
				std::cout << "Enter the index length till which you want to concatenate: ";
				utils::InputNumberFromUser(ind, 0, (int)cppStringsObj.GetStringPointerLength());
				cppStringsObj.NConcatenateStringAndStringPointer(str, ind);
				std::cout << "The concatenated string is: " << str << " and the original strings were: " << cppStringsObj.GetString() << ", " << cppStringsObj.GetStringPointer() << std::endl;
				break;
			}
			case 12:
			{
				cppStringsObj.ShowcaseStringToInt();
				break;
			}
			case 13:
			{
				cppStringsObj.ShowcaseStringToLong();
				break;
			}
			case 14:
			{
				cppStringsObj.ShowcaseStringToFloat();
				break;
			}
			case 15:
			{
				previousMenuFlag = 'y';
				break;
			}
			case 16:
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
				cppStringsObj.PrintMenu();
				cppStringsObj.GetChoiceInputFromUser();
			}
		}
	}

	void Handle(functions::Functions& functionsObj)
	{
		functionsObj.PrintMenu();
		functionsObj.GetChoiceInputFromUser();
		const int& selectedChoice = functionsObj.GetChoice();

		while (functionsObj.GetChoice())
		{
			char previousMenuFlag = 'n';
			if (selectedChoice > functionsObj.GetMinCase() &&
				selectedChoice < functionsObj.GetMaxCase() + 1)
			{
				functionsObj.PrintSelectedChoice();
			}

			switch (selectedChoice)
			{
			case 1:
			{
				functionsObj.ShowcaseFunctions();
				break;
			}
			case 2:
			{
				functionsObj.ShowcaseOverloadedFunctions();
				break;
			}
			case 3:
			{
				int a { 0 }, b { 0 };
				std::cout << "Please enter first integer: ";
				utils::InputNumberFromUser(a);
				utils::IgnoreStdCinBufferTillEOL();

				std::cout << "Please enter second integer: ";
				utils::InputNumberFromUser(b);
				utils::IgnoreStdCinBufferTillEOL();
				
				std::cout << "The sum is: " << functionsObj.Add2IntsOverloading(a, b) << std::endl;
				break;
			}
			case 4:
			{
				float a { 0 }, b { 0 };
				std::cout << "Please enter first float: ";
				utils::InputNumberFromUser(a);
				utils::IgnoreStdCinBufferTillEOL();

				std::cout << "Please enter second float: ";
				utils::InputNumberFromUser(b);
				utils::IgnoreStdCinBufferTillEOL();

				std::cout << "The sum is: " << functionsObj.Add2FloatsOverloading(a, b) << std::endl;
				break;
			}
			case 5:
			{
				int a { 0 }, b { 0 }, c { 0 };
				std::cout << "Please enter first integer: ";
				utils::InputNumberFromUser(a);
				utils::IgnoreStdCinBufferTillEOL();
				
				std::cout << "Please enter second integer: ";
				utils::InputNumberFromUser(b);
				utils::IgnoreStdCinBufferTillEOL();
				
				std::cout << "Please enter third integer: ";
				utils::InputNumberFromUser(c);
				utils::IgnoreStdCinBufferTillEOL();
				
				std::cout << "The sum is: " << functionsObj.Add3IntsOverloading(a, b, c) << std::endl;
				break;
			}
			case 6:
			{
				functionsObj.ShowcaseFunctionTemplates();
				break;
			}
			case 7:
			{
				int a { 0 }, b { 0 };
				std::cout << "Please enter first integer: ";
				utils::InputNumberFromUser(a);
				utils::IgnoreStdCinBufferTillEOL();

				std::cout << "Please enter second integer: ";
				utils::InputNumberFromUser(b);
				utils::IgnoreStdCinBufferTillEOL();

				std::cout << "The sum is: " << functionsObj.AddTemplate(a, b) << std::endl;
				break;
			}
			case 8:
			{
				float a { 0 }, b { 0 };
				std::cout << "Please enter first float: ";
				utils::InputNumberFromUser(a);

				std::cout << "Please enter second float: ";
				utils::InputNumberFromUser(b);

				std::cout << "The sum is: " << functionsObj.AddTemplate(a, b) << std::endl;
				break;
			}
			case 9:
			{
				utils::IgnoreStdCinBufferTillEOL();
				std::string str1, str2;
				std::cout << "Please enter first string: ";
				std::getline(std::cin, str1);
				
				std::cout << "Please enter second string: ";
				std::getline(std::cin, str2);

				std::cout << "The sum is: " << functionsObj.AddTemplate(str1, str2) << std::endl;
				break;
			}
			case 10:
			{
				functionsObj.ShowcaseDefaultArguments();
				break;
			}
			case 11:
			{
				int a { 0 }, b { 0 };
				std::cout << "Please enter first integer: ";
				utils::InputNumberFromUser(a);
				utils::IgnoreStdCinBufferTillEOL();

				std::cout << "Please enter second integer: ";
				utils::InputNumberFromUser(b);
				utils::IgnoreStdCinBufferTillEOL();

				std::cout << "The sum is: " << functionsObj.Add2Or3Or4IntsDefaultArgument(a, b) << std::endl;
				break;
			}
			case 12:
			{
				int a { 0 }, b { 0 }, c { 0 };
				std::cout << "Please enter first integer: ";
				utils::InputNumberFromUser(a);
				utils::IgnoreStdCinBufferTillEOL();

				std::cout << "Please enter second integer: ";
				utils::InputNumberFromUser(b);
				utils::IgnoreStdCinBufferTillEOL();

				std::cout << "Please enter third integer: ";
				utils::InputNumberFromUser(c);
				utils::IgnoreStdCinBufferTillEOL();

				std::cout << "The sum is: " << functionsObj.Add2Or3Or4IntsDefaultArgument(a, b, c) << std::endl;
				break;
			}
			case 13:
			{
				int a { 0 }, b { 0 }, c { 0 }, d { 0 };
				std::cout << "Please enter first integer: ";
				utils::InputNumberFromUser(a);
				utils::IgnoreStdCinBufferTillEOL();

				std::cout << "Please enter second integer: ";
				utils::InputNumberFromUser(b);
				utils::IgnoreStdCinBufferTillEOL();

				std::cout << "Please enter third integer: ";
				utils::InputNumberFromUser(c);
				utils::IgnoreStdCinBufferTillEOL();

				std::cout << "Please enter fourth integer: ";
				utils::InputNumberFromUser(d);
				utils::IgnoreStdCinBufferTillEOL();

				std::cout << "The sum is: " << functionsObj.Add2Or3Or4IntsDefaultArgument(a, b, c, d) << std::endl;
				break;
			}
			case 14:
			{
				functionsObj.ShowcasePassingArgsToFunction();
				break;
			}
			case 15:
			{
				int a { 0 }, b { 0 };
				std::cout << "Please enter first integer: ";
				utils::InputNumberFromUser(a);
				utils::IgnoreStdCinBufferTillEOL();

				std::cout << "Please enter second integer: ";
				utils::InputNumberFromUser(b);
				utils::IgnoreStdCinBufferTillEOL();

				std::cout << "BEFORE FUNCTION CALL: The value of a is: " << a << " and b is: " << b << std::endl;
				std::cout << "CALLING FUNCTION: " << std::endl;
				functionsObj.SwapByValue(a, b);
				std::cout << "AFTER FUNCTION CALL: The value of a is: " << a << " and b is: " << b << std::endl;
				std::cout << "The values of a and b  are not swapped as call by value cannot change the values of the actual parameters passed to the function" << std::endl;
				break;
			}
			case 16:
			{
				int a { 0 }, b { 0 };
				std::cout << "Please enter first integer: ";
				utils::InputNumberFromUser(a);
				utils::IgnoreStdCinBufferTillEOL();

				std::cout << "Please enter second integer: ";
				utils::InputNumberFromUser(b);
				utils::IgnoreStdCinBufferTillEOL();

				std::cout << "BEFORE FUNCTION CALL: The value of a is: " << a << " and b is: " << b << std::endl;
				std::cout << "CALLING FUNCTION: " << std::endl;
				functionsObj.SwapByAddress(&a, &b);
				std::cout << "AFTER FUNCTION CALL: The value of a is: " << a << " and b is: " << b << std::endl;
				std::cout << "The values of a and b  are swapped as call by address can change the values of the actual parameters passed to the function" << std::endl;
				break;
			}
			case 17:
			{
				int a { 0 }, b { 0 };
				std::cout << "Please enter first integer: ";
				utils::InputNumberFromUser(a);
				utils::IgnoreStdCinBufferTillEOL();

				std::cout << "Please enter second integer: ";
				utils::InputNumberFromUser(b);
				utils::IgnoreStdCinBufferTillEOL();

				std::cout << "BEFORE FUNCTION CALL: The value of a is: " << a << " and b is: " << b << std::endl;
				std::cout << "CALLING FUNCTION: " << std::endl;
				functionsObj.SwapByReference(a, b);
				std::cout << "AFTER FUNCTION CALL: The value of a is: " << a << " and b is: " << b << std::endl;
				std::cout << "The values of a and b  are swapped as call by reference can change the values of the actual parameters passed to the function" << std::endl;
				break;
			}
			case 18:
			{
				std::cout << "Return by pointer functions can be used to create an array on heap" << std::endl;
				
				int size { 0 };
				std::cout << "Please enter size of the array: ";
				utils::InputNumberFromUser(size);
				utils::IgnoreStdCinBufferTillEOL();
				
				std::cout << "CALLING FUNCTION" << std::endl;
				int* arr = functionsObj.ReturnByAddressCreateArray(size);

				std::cout << "FILLING THE ARRAY" << std::endl;
				int element { 0 };
				for (int i = 0; i < size; i++)
				{
					std::cout << "Enter array element: ";
					utils::InputNumberFromUser(element);
					arr[i] = element;
				}

				std::cout << "DISPLAY THE ARRAY" << std::endl;
				for (int i = 0; i < size; i++)
				{
					std::cout << arr[i] << " ";
				}
				std::cout << std::endl;

				std::cout << "DELETING THE ARRAY MEMORY FROM HEAP" << std::endl;
				delete[] arr;
				arr = nullptr;
				break;
			}
			case 19:
			{
				std::cout << "A function returns a value or a pointer, then it is rvalue but if it is returning a reference to a variable that exists in the caller stack frame then, "
						  << "it can act as lvalue" << std::endl;

				int a { 0 };
				std::cout << "Please enter an integer: ";
				utils::InputNumberFromUser(a);
				utils::IgnoreStdCinBufferTillEOL();

				std::cout << "The value of a is: " << a << std::endl;
				std::cout << "Changing the value of a to 25 through return by reference function call acting as lvalue" << std::endl;
				functionsObj.ReturnByReference(a) = 25;
				std::cout << "The new value of a is: " << a << std::endl;
				break;
			}
			case 20:
			{
				functionsObj.ShowcaseGlobalVsStaticVariables();
				break;
			}
			case 21:
			{
				functionsObj.ShowcaseRecursiveFunctions();
				break;
			}
			case 22:
			{
				functionsObj.ShowcaseFunctionPointers();
				break;
			}
			case 23:
			{
				int a { 0 }, b { 0 };
				std::cout << "Please enter first integer: ";
				utils::InputNumberFromUser(a);
				utils::IgnoreStdCinBufferTillEOL();

				std::cout << "Please enter second integer: ";
				utils::InputNumberFromUser(b);
				utils::IgnoreStdCinBufferTillEOL();

				int (functions::Functions::* fp)(int, int);
				fp = &functions::Functions::Max2Int;
				std::cout << "The max of the two values is: " << (functionsObj.*fp)(a, b) << std::endl;
				std::cout << "Currectly the function pointer points to the MAX method in the Functions class, changing it to point to the MIN method" << std::endl;

				fp = &functions::Functions::Min2Int;
				std::cout << "The min of the two values is: " << (functionsObj.*fp)(a, b) << std::endl;
				std::cout << "Currectly the function pointer points to the MIN method in the Functions class" << std::endl;
				break;
			}
			case 24:
			{
				int a { 0 };
				std::cout << "Please enter an integer to calculate recursice factorial for: ";
				utils::InputNumberFromUser(a, 0);
				utils::IgnoreStdCinBufferTillEOL();

				std::cout << "The factorial of " << a << " is: " << functionsObj.Factorial(a) << std::endl;
				break;
			}
			case 25:
			{
				previousMenuFlag = 'y';
				break;
			}
			case 26:
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
				functionsObj.PrintMenu();
				functionsObj.GetChoiceInputFromUser();
			}
		}
	}
} // namespace handlers
