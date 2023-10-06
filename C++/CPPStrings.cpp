#pragma once

#include <iostream>
#include "CPPStrings.h"
#include "utils.h"

namespace cppStrings
{
    CPPStrings::CPPStrings(const std::string& str):
        m_choice             (0), 
        m_string             (""),
        m_stringPtr          (nullptr),
        m_CPPStyleStringsMap ({})
    {
        m_string = str;

        m_CPPStyleStringsMap.insert({ m_CPPStyleStringsMenu(SHOW_CASE_CPP_STYLE_STRINGS),
                                      std::string("Showcase CPP Style Strings") });
        m_CPPStyleStringsMap.insert({ m_CPPStyleStringsMenu(GET_STRING),
                                      std::string("Print string") });
        m_CPPStyleStringsMap.insert({ m_CPPStyleStringsMenu(GET_STRING_LENGTH),
                                      std::string("Print string length") });
        m_CPPStyleStringsMap.insert({ m_CPPStyleStringsMenu(GET_STRING_CAPACITY),
                                     std::string("Print string capacity") });
        m_CPPStyleStringsMap.insert({ m_CPPStyleStringsMenu(SET_STRING_TO_POINTER),
                                      std::string("Set string to pointer") });
        m_CPPStyleStringsMap.insert({ m_CPPStyleStringsMenu(GET_STRING_POINTER),
                                      std::string("Print string in pointer") });
        m_CPPStyleStringsMap.insert({ m_CPPStyleStringsMenu(GET_STRING_POINTER_LENGTH),
                                      std::string("Print length of string in pointer") });
        m_CPPStyleStringsMap.insert({ m_CPPStyleStringsMenu(IS_STRING_POINTER_EMPTY),
                                      std::string("Check if string present in string pointer") });
        m_CPPStyleStringsMap.insert({ m_CPPStyleStringsMenu(COMPARE_STRING_TO_STRING_POINTER),
                                      std::string("Compare string and string in pointer") });
        m_CPPStyleStringsMap.insert({ m_CPPStyleStringsMenu(CONCATENATE_STRING_AND_STRING_POINTER),
                                      std::string("Concatenate string and string pointer") });
        m_CPPStyleStringsMap.insert({ m_CPPStyleStringsMenu(N_CONCATENATE_STRING_AND_STRING_POINTER),
                                      std::string("N Concatenate string and string pointer") });
        m_CPPStyleStringsMap.insert({ m_CPPStyleStringsMenu(SHOW_CASE_STRING_TO_INT),
                                      std::string("Showcase string to int") });
        m_CPPStyleStringsMap.insert({ m_CPPStyleStringsMenu(SHOW_CASE_STRING_TO_LONG),
                                      std::string("Showcase string to long") });
        m_CPPStyleStringsMap.insert({ m_CPPStyleStringsMenu(SHOW_CASE_STRING_TO_FLOAT),
                                      std::string("Showcase string to float") });
        m_CPPStyleStringsMap.insert({ m_CPPStyleStringsMenu(BACK_TO_PREVIOUS_MENU),
                                      std::string("Back to previous menu") });
        m_CPPStyleStringsMap.insert({ m_CPPStyleStringsMenu(EXIT_FROM_PROGRAM),
                                      std::string("Exit from program") });
    }

    CPPStrings::~CPPStrings()
    {
        delete m_stringPtr;
    }

    const int& CPPStrings::GetMinCase()
    {
        return m_CPPStyleStringsMenu::MIN_COUNT;
    }

    const int& CPPStrings::GetMaxCase()
    {
        return m_CPPStyleStringsMenu::MAX_COUNT;
    }

    const int& CPPStrings::GetChoice()
    {
        return m_choice;
    }

    void CPPStrings::GetChoiceInputFromUser()
    {
        utils::InputIntegerFromUser(m_choice, 1, m_CPPStyleStringsMenu::MAX_COUNT);
    }

    void CPPStrings::PrintMenu()
    {
        std::cout << std::endl;
        for (std::map<int, std::string>::iterator it = m_CPPStyleStringsMap.begin();
            it != m_CPPStyleStringsMap.end();
            it++)
        {
            std::cout << it->first << ". " << it->second << std::endl;
        }
        std::cout << "Please enter your choice: ";
    }

    void CPPStrings::PrintSelectedChoice()
    {
        std::cout << std::endl << std::endl
            << "You have chosen choice "
            << m_CPPStyleStringsMap.at(m_choice)
            << std::endl;
    }

    void CPPStrings::ShowcaseCPPStyleStrings()
    {
        std::cout << "CPP Style strings are used in C++. They are implemented in the form of class and many methods are available for string operations." << std::endl
                  << "To declare CPP Style strings:" << std::endl
                  << "....std::string str;" << std::endl
                  << "....std::string str = \"Hello World\";" << std::endl
                  << "....std::string str = {'H', 'e', 'l', 'l', 'o', '\0'};" << std::endl
                  << "....std::string str = {65, 66, 67, 68, '\0'};" << std::endl
                  << "The \\0 represents the delimiter character and can be represented with \0 or 0" << std::endl
                  << "We can also declare char arrrays in the heap with the help of pointers and the new keyword" << std::endl
                  << "....std::string* str = new std::string;" << std::endl;
    }

    const std::string& CPPStrings::GetString()
    {
        return m_string;
    }

    const size_t CPPStrings::GetStringLength()
    {
        return m_string.length();
    }

    const size_t CPPStrings::GetStringCapacity()
    {
        return m_string.capacity();
     }

    void CPPStrings::SetStringPointer()
    {
        utils::IgnoreStdCinBufferTillEOL();
        m_stringPtr = new std::string;
        std::cout << "Enter the string to be stored in string pointer member variable: ";
        std::getline(std::cin, *m_stringPtr);
    }

    const std::string CPPStrings::GetStringPointer()
    {
        if (IsStringPointerEmpty())
        {
            std::cout << "The string pointer is not set currently, please set the string pointer first!!" << std::endl;
            return "";
        }
        return *m_stringPtr;
    }

    const size_t CPPStrings::GetStringPointerLength()
    {
        if (IsStringPointerEmpty())
        {
            std::cout << "The string pointer is not set currently, please set the string pointer first!!" << std::endl;
            return 0;
        }
        return m_stringPtr->length();
    }

    const bool CPPStrings::IsStringPointerEmpty()
    {
        return m_stringPtr ? false : true;
    }

    const int& CPPStrings::CompareStringWithStringPointer()
    {
        return m_string.compare(*m_stringPtr);
    }

    void CPPStrings::ConcatenateStringAndStringPointer(std::string& str)
    {
        str.append(m_string);
        str.append(*m_stringPtr);
    }

    void CPPStrings::NConcatenateStringAndStringPointer(std::string& str, const int& length)
    {
        str.append(m_string);
        str.insert(str.end(), (*m_stringPtr).begin(), (*m_stringPtr).begin() + length);
    }

    void CPPStrings::ShowcaseStringToInt()
    {
        utils::IgnoreStdCinBufferTillEOL();
        std::cout << "If a numeric value is stored in a string, we can convert it into an int and perform operations on it using" << std::endl
                  << "....stoi(string, NULL, <RADIX / BASE OF THE NUMBER SYSTEM>)" << std::endl;
        std::string str;
        std::cout << "Please enter a numeric value: ";
        std::getline(std::cin, str);
        int l = stoi(str, NULL, 10);
        std::cout << "The numeric value is: " << l << std::endl;
        std::cout << "We can also perform operations such as incrementing it : " << ++l << std::endl;
    }

    void CPPStrings::ShowcaseStringToLong()
    {
        utils::IgnoreStdCinBufferTillEOL();
        std::cout << "If a numeric value is stored in a string, we can convert it into a long and perform operations on it using" << std::endl
                  << "....stol(string, NULL, <RADIX / BASE OF THE NUMBER SYSTEM>)" << std::endl;
        std::string str;
        std::cout << "Please enter a numeric value: ";
        std::getline(std::cin, str);
        float l = stol(str, NULL, 10);
        std::cout << "The numeric value is: " << l << std::endl;
        std::cout << "We can also perform operations such as incrementing it : " << ++l << std::endl;
    }

    void CPPStrings::ShowcaseStringToFloat()
    {
        utils::IgnoreStdCinBufferTillEOL();
        std::cout << "If a numeric value is stored in a string, we can convert it into a float and perform operations on it using" << std::endl
                  << "....stof(string, NULL)" << std::endl;
        std::string str;
        std::cout << "Please enter a numeric value: ";
        std::getline(std::cin, str);
        float l = stof(str, NULL);
        std::cout << "The numeric value is: " << l << std::endl;
        std::cout << "We can also perform operations such as incrementing it : " << ++l << std::endl;
    }
} // namespace cppStrings
