#pragma once

#include "PointersAndReferences.h"
#include "Basics.h"
#include "utils.h"
#include <iostream>

namespace pointersAndReferences
{
    PointersAndReferences::PointersAndReferences(const int& data) :
        m_choice                   (0),
        m_ptr                      (nullptr),
        m_data                     (0),
        m_dataRef                  (m_data),
        m_array                    (nullptr),
        m_arraySize                (0),
        m_PointersAndReferencesMap ({})
    {
        m_data = data;
        m_PointersAndReferencesMap.insert({ m_PointersAndReferencesMenu(PRINT_DATA_IN_MEMBER_DATA_VARIABLE),
                                            std::string("Print data in member data variable") });
        m_PointersAndReferencesMap.insert({ m_PointersAndReferencesMenu(PRINT_ADDRESS_OF_MEMBER_DATA_VARIABLE),
                                            std::string("Print address of member data variable") });
        m_PointersAndReferencesMap.insert({ m_PointersAndReferencesMenu(SET_DATA_IN_MEMBER_POINTER_VARIABLE),
                                            std::string("Set data in member pointer variable") });
        m_PointersAndReferencesMap.insert({ m_PointersAndReferencesMenu(DEREFERENCE_MEMBER_POINTER_VARIABLE),
                                            std::string("Dereference member pointer variable") });
        m_PointersAndReferencesMap.insert({ m_PointersAndReferencesMenu(PRINT_ADDRESS_STORED_IN_MEMBER_POINTER_VARIABLE),
                                             std::string("Print address stored in member pointer variable") });
        m_PointersAndReferencesMap.insert({ m_PointersAndReferencesMenu(PRINT_ADDRESS_OF_MEMBER_POINTER_VARIABLE),
                                            std::string("Print address of member pointer variable") });
        m_PointersAndReferencesMap.insert({ m_PointersAndReferencesMenu(PRINT_DATA_IN_MEMBER_REFERENCE_VARIABLE),
                                            std::string("Print data in member reference variable") });
        m_PointersAndReferencesMap.insert({ m_PointersAndReferencesMenu(PRINT_ADDRESS_OF_MEMBER_REFERENCE_VARIABLE),
                                            std::string("Print address of member reference variable") });
        m_PointersAndReferencesMap.insert({ m_PointersAndReferencesMenu(INCREMENT_OR_DECREMENT_MEMBER_DATA_VARIABLE_VIA_REGULAR),
                                            std::string("Increment or decrement member data variable via regular") });
        m_PointersAndReferencesMap.insert({ m_PointersAndReferencesMenu(INCREMENT_OR_DECREMENT_MEMBER_DATA_VARIABLE_VIA_MEMBER_REFERENCE_VARIABLE),
                                            std::string("Increment or decrement member data variable via member reference variable") });
        m_PointersAndReferencesMap.insert({ m_PointersAndReferencesMenu(INCREMENT_OR_DECREMENT_MEMBER_DATA_VARIABLE_VIA_MEMBER_POINTER_VARIABLE),
                                            std::string("Increment or decrement member data variable via member pointer variable") });
        m_PointersAndReferencesMap.insert({ m_PointersAndReferencesMenu(COMPARE_ADDRESS_OF_REFERENCE_DATA_POINTER_MEMBER_VARIABLES),
                                            std::string("Compare addresses of reference, data, pointer member variables") });
        m_PointersAndReferencesMap.insert({ m_PointersAndReferencesMenu(COMPARE_DATA_OF_REFERENCE_DATA_POINTER_MEMBER_VARIABLES),
                                            std::string("Compare data of reference, data, pointer member variables") });
        m_PointersAndReferencesMap.insert({ m_PointersAndReferencesMenu(INITIALIZE_THE_ARRAY),
                                            std::string("Initialize the array") });
        m_PointersAndReferencesMap.insert({ m_PointersAndReferencesMenu(PRINT_SIZE_OF_ARRAY),
                                            std::string("Print size of array") });
        m_PointersAndReferencesMap.insert({ m_PointersAndReferencesMenu(SHOWCASE_ARRAYS_WITH_POINTERS),
                                            std::string("Show case array with pointers") });
        m_PointersAndReferencesMap.insert({ m_PointersAndReferencesMenu(DISPLAY_THE_ARRAY),
                                            std::string("Display the array") });
        m_PointersAndReferencesMap.insert({ m_PointersAndReferencesMenu(PROBLEMS_WITH_POINTERS ),
                                            std::string("Problems with Pointers") });
        m_PointersAndReferencesMap.insert({ m_PointersAndReferencesMenu(BACK_TO_PREVIOUS_MENU),
                                            std::string("Back to previous menu") });
        m_PointersAndReferencesMap.insert({ m_PointersAndReferencesMenu(EXIT_FROM_PROGRAM),
                                            std::string("Exit from program") });
        std::cout << "######################################################################################################################################################" << std::endl;
        std::cout << "Pointers are used to allocate data in heap or to access resources outside the program such as network, devices, file system, etc" << std::endl
                  << "Pointers in C++ are defined as:" << std::endl
                  << "....<DATA-TYPE>* <VARIABLE-NAME>              // for declaring a pointer to a data-type" << std::endl << std::endl
                  << "To allocate memory in the heap, we use the 'new' keyword and 'delete' keyword to delete it" << std::endl
                  << "....<DATA-TYPE>* <VARIABLE-NAME> = new <DATA-TYPE>                        // for declaring a pointer to a data-type" << std::endl
                  << "....<DATA-TYPE>* <VARIABLE-NAME> = new <DATA-TYPE> [length-of-array]      // for declaring a pointer to a data-type" << std::endl << std::endl
                  << "make sure to delete the reserved memory in heap as it is not done by default in C++" << std::endl
                  << "....delete <POINTER-VARIABLE>     // for normal pointers" << std::endl
                  << "....delete[] <POINTER-VARIABLE>   // for arrays reserved from pointers" << std::endl << std::endl;
        std::cout << "######################################################################################################################################################" << std::endl;
    }

    PointersAndReferences::~PointersAndReferences()
    {
        delete   m_ptr;
        delete[] m_array;
    }

    const int& PointersAndReferences::GetMinCase()
    {
        return m_PointersAndReferencesMenu::MIN_COUNT;
    }

    const int& PointersAndReferences::GetMaxCase()
    {
        return m_PointersAndReferencesMenu::MAX_COUNT;
    }

    const int& PointersAndReferences::GetChoice()
    {
        return m_choice;
    }

    void PointersAndReferences::GetChoiceInputFromUser()
    {
        utils::InputIntegerFromUser(m_choice, 1, m_PointersAndReferencesMenu::MAX_COUNT);
    }

    void PointersAndReferences::PrintMenu()
    {
        std::cout << std::endl;
        for (std::map<int, std::string>::iterator it = m_PointersAndReferencesMap.begin();
            it != m_PointersAndReferencesMap.end();
            it++)
        {
            std::cout << it->first << ". " << it->second << std::endl;
        }
        std::cout << "Please enter your choice: ";
    }

    void PointersAndReferences::PrintSelectedChoice()
    {
        std::cout << std::endl << std::endl
                  << "You have chosen choice "
                  << m_PointersAndReferencesMap.at(m_choice)
                  << std::endl;
    }

    const int& PointersAndReferences::GetData()
    {
        return m_data;
    }

    const int* PointersAndReferences::GetDataAddress()
    {
        return &m_data;
    }

    void PointersAndReferences::SetDataInPtr()
    {
        m_ptr = &m_data;
    }

    const int& PointersAndReferences::DereferenceMemberPointer()
    {
        return *m_ptr;
    }

    const int* PointersAndReferences::GetDataInPointer()
    {
        return m_ptr;
    }

    const int** PointersAndReferences::GetPointerAddress()
    {
        return (const int**) & m_ptr;
    }

    const int& PointersAndReferences::GetDataInReference()
    {
        return m_dataRef;
    }

    const int* PointersAndReferences::GetAddressOfReference()
    {
        return &m_dataRef;
    }

    void PointersAndReferences::IncrementOrDecrementDataViaRegular(const int& ch)
    {
        ch ? m_data++ : m_data--; 
    }

    void PointersAndReferences::IncrementOrDecrementDataViaReference(const int& ch)
    {
        ch ? m_dataRef++ : m_dataRef--; 
    }
    
    void PointersAndReferences::IncrementOrDecrementDataViaPointer(const int& ch)
    {
        ch ? (*m_ptr)++ : (*m_ptr)--; 
    }

    void PointersAndReferences::CompareDataOfThree()
    {
        std::cout << "The data stored in member data variable is: " << GetData() << std::endl
                  << "The data stored in member reference variable is: " << GetDataInReference() << std::endl
                  << "The data stored in member pointer variable is: " << GetDataInPointer()
                  << " which is pointing to a location with data: " << DereferenceMemberPointer() << std::endl;
    }

    void PointersAndReferences::CompareAddressesOfThree()
    {
        std::cout << "The address of member data variable is: " << GetDataAddress() << std::endl
                  << "The address of member reference variable is: " << GetAddressOfReference() << std::endl
                  << "The address of member pointer variable is: " << GetPointerAddress() << std::endl
                  << "And the address stored in the member pointer variable is: " << GetDataInPointer()
                  << " which is pointing to a location with data: " << DereferenceMemberPointer() << std::endl;
    }
    
    void PointersAndReferences::InitializeArray(const int& arraySize)
    {
        m_arraySize = arraySize;
        m_array = new int[m_arraySize];
    }

    void PointersAndReferences::FillTheArray()
    {
        int element { 0 };
        for (int i = 0; i < m_arraySize; i++)
        {
            std::cout << "Enter array element: ";
            utils::InputIntegerFromUser(element);
        }
    }

    void PointersAndReferences::ShowCaseArraysWithPointers()
    {
        std::cout << "Array declaration is C++ can be done as follows: ";
        basics::Basics basicsObj;
        basicsObj.ShowCaseArrays();
        std::cout << "Declaring array normally, ...int A[10];...will reserve memory in stack while ...int *A = new int[10]... will reserve memory in heap" << std::endl;
        std::cout << "The address of first element of member array is (&A): " << m_array << std::endl;
        std::cout << "The first element of the array is (*A): " << *m_array << std::endl;
        std::cout << "Indexing can be done via ([]) or via *(A + sizeof(<data type of array>))" << std::endl;

        std::cout << "To print the array using *A, " << std::endl
                  << "....for (int i = 0; i < sizeOfArray; i++)" << std::endl
                  << "....{" << std::endl
                  << "........std::cout << *(A + i)" << std::endl
                  << "....}" << std::endl;

        for (int i = 0; i < m_arraySize; i++)
        {
            std::cout << *(m_array + i) << " ";
        }
        std::cout << std::endl;
    }

    void PointersAndReferences::DisplayArray()
    {
        if (IsArrayNull())
        {
            std::cout << "The array is empty! Please initialize the array first" << std::endl;
        }
        else
        {
            for (int i = 0; i < m_arraySize; i++)
            {
                std::cout << m_array[i] << " ";
            }
            std::cout << std::endl;
        }
    }

    void PointersAndReferences::ShowCaseProblemsWithArrays()
    {
        std::cout << "######################################################################################################################################################" << std::endl;
        std::cout << "There are 3 problems with using pointers in C++:" << std::endl
                  << "\t1. Uninitialized Pointer: If pointer is declared but not initialized and someone dereferences it, it will throw runtime errors which will crash the program." << std::endl
                  << "\t1. Memory Leak: If we don't delete the memory reserved in heap after making use of it, at one point of time, the memory will be full and the program may crash. That is why Pointers should be handled with caution." << std::endl
                  << "\t1. Dangling Pointer: If two pointers point to a single memory location, one pointer deletes the memory, the other one does not know about it and when it will try to access that location, runtime errors will be thrown." << std::endl
                  << "It is important to delete the memory we reserves using the 'new' keyword and immediately point the pointer-variable to 0, NULL or nullptr in which, nullptr is prefered in C++." << std::endl;
        std::cout << "######################################################################################################################################################" << std::endl;\
    }

    const int& PointersAndReferences::GetArraySize()
    {
        return m_arraySize;
    }

    const bool PointersAndReferences::IsArrayNull()
    {
        return m_arraySize ? false : true;
    }
} // namespace pointersAndReferences
