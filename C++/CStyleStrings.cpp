#include <iostream>
#include "CStyleStrings.h"
#include "utils.h"

namespace cStyleStrings
{
    CStyleStrings::CStyleStrings(const char str[]) :
        m_choice           (0),
        m_string           (""),
        m_stringPtr        (nullptr),
        m_CStyleStringsMap ({})
    {
        // added 1 to the length so as to give space for the \0 delimiter
        strcpy_s(m_string, strlen(str) + 1, str);
        
        m_CStyleStringsMap.insert({ m_CStyleStringsMenu(SHOW_CASE_C_STYLE_STRINGS),
                                    std::string("Showcase C Style Strings") });
        m_CStyleStringsMap.insert({ m_CStyleStringsMenu(GET_STRING),
                                    std::string("Print string") });
        m_CStyleStringsMap.insert({ m_CStyleStringsMenu(GET_STRING_LENGTH),
                                    std::string("Print string length") });
        m_CStyleStringsMap.insert({ m_CStyleStringsMenu(SET_STRING_TO_POINTER),
                                    std::string("Set string to pointer") });
        m_CStyleStringsMap.insert({ m_CStyleStringsMenu(GET_STRING_POINTER),
                                    std::string("Print string in pointer") });
        m_CStyleStringsMap.insert({ m_CStyleStringsMenu(GET_STRING_POINTER_LENGTH),
                                    std::string("Print length of string in pointer") });
        m_CStyleStringsMap.insert({ m_CStyleStringsMenu(IS_STRING_POINTER_EMPTY),
                                    std::string("Check if string present in string pointer") });
        m_CStyleStringsMap.insert({ m_CStyleStringsMenu(COMPARE_STRING_TO_STRING_POINTER),
                                    std::string("Compare string and string in pointer") });
        m_CStyleStringsMap.insert({ m_CStyleStringsMenu(CONCATENATE_STRING_AND_STRING_POINTER),
                                    std::string("Concatenate string and string pointer") });
        m_CStyleStringsMap.insert({ m_CStyleStringsMenu(N_CONCATENATE_STRING_AND_STRING_POINTER),
                                    std::string("N Concatenate string and string pointer") });
        m_CStyleStringsMap.insert({ m_CStyleStringsMenu(SHOW_CASE_STRING_TO_LONG),
                                    std::string("Showcase string to long") });
        m_CStyleStringsMap.insert({ m_CStyleStringsMenu(SHOW_CASE_STRING_TO_FLOAT),
                                    std::string("Showcase string to float") });
        m_CStyleStringsMap.insert({ m_CStyleStringsMenu(SHOW_CASE_STRING_TO_TOKEN),
                                    std::string("Showcase string to token") });
        m_CStyleStringsMap.insert({ m_CStyleStringsMenu(BACK_TO_PREVIOUS_MENU),
                                   std::string("Back to previous menu") });
        m_CStyleStringsMap.insert({ m_CStyleStringsMenu(EXIT_FROM_PROGRAM),
                                    std::string("Exit from program") });
    }

    CStyleStrings::~CStyleStrings()
    {
        delete[] m_stringPtr;
    }

    const int CStyleStrings::GetMinCase()
    {
        return m_CStyleStringsMenu::MIN_COUNT;
    }

    const int CStyleStrings::GetMaxCase()
    {
        return m_CStyleStringsMenu::MAX_COUNT;
    }

    const int& CStyleStrings::GetChoice()
    {
        return m_choice;
    }

    void CStyleStrings::GetChoiceInputFromUser()
    {
        utils::InputNumberFromUser(m_choice, 1, (int)m_CStyleStringsMenu::MAX_COUNT);
    }

    void CStyleStrings::PrintMenu()
    {
        std::cout << std::endl;
        for (std::map<int, std::string>::iterator it = m_CStyleStringsMap.begin();
            it != m_CStyleStringsMap.end();
            it++)
        {
            std::cout << it->first << ". " << it->second << std::endl;
        }
        std::cout << "Please enter your choice: ";
    }

    void CStyleStrings::PrintSelectedChoice()
    {
        std::cout << std::endl << std::endl
            << "You have chosen choice "
            << m_CStyleStringsMap.at(m_choice)
            << std::endl;
    }

    void CStyleStrings::ShowcaseCStyleStrings()
    {
        std::cout << "C Style strings were used in C and the same are available in C++ under the header cstring" << std::endl;
        std::cout << "C Style strings are basically char arrays which stores the strings and cstring header file provides certain operations on those strings" << std::endl
                  << "To declare C Style strings:" << std::endl
                  << "....char str[<LENGTH OF STRING>];" << std::endl
                  << "....char str[<LENGTH OF STRING>] = \"Hello World\";" << std::endl
                  << "....char str[] = \"Hello World\";" << std::endl
                  << "....char str[] = {'H', 'e', 'l', 'l', 'o', '\\0'};" << std::endl
                  << "....char str[] = {65, 66, 67, 68, '\\0'};" << std::endl
                  << "The \\0 represents the delimiter character and can be represented with \\0 or 0" << std::endl   
                  << "We can also declare char arrrays in the heap with the help of pointers and the new keyword" << std::endl
                  << "....char *str = new char[<LENGTH OF STRING>];" << std::endl;
    }

    const char* CStyleStrings::GetString()
    {
        return m_string;
    }

    const size_t CStyleStrings::GetStringLength()
    {
        return strlen(m_string);
    }
    
    void CStyleStrings::SetStringPointer(const int& length)
    {
        utils::IgnoreStdCinBufferTillEOL();
        m_stringPtr = new char[length];
        std::cout << "Enter the string to be stored in string pointer member variable: ";
        std::cin.getline(m_stringPtr, length);
        bool res = utils::CheckAndClearCharactersInStream(m_stringPtr, length);
        if (res)
        {
            std::cout << "You have entered a name greater than" << length << " characters.Only" << length << " characters will be taken input" << std::endl;
        }
    }

    const char* CStyleStrings::GetStringPointer()
    {
        if (IsStringPointerEmpty())
        {
            std::cout << "The string pointer is not set currently, please set the string pointer first!!" << std::endl;
            return nullptr;
        }
        return m_stringPtr;
    }

    const size_t CStyleStrings::GetStringPointerLength()
    {
        if (IsStringPointerEmpty())
        {
            std::cout << "The string pointer is not set currently, please set the string pointer first!!" << std::endl;
            return 0;
        }
        return strlen(m_stringPtr);
    }

    const bool CStyleStrings::IsStringPointerEmpty()
    {
        return m_stringPtr ? false : true;
    }

    const int CStyleStrings::CompareStringWithStringPointer()
    {
        return strcmp(m_string, m_stringPtr);
    }

    void CStyleStrings::ConcatenateStringAndStringPointer(char dest[], const int& totalLength)
    {
        strcpy_s(dest, totalLength, m_string);
        strcat_s(dest, totalLength, m_stringPtr);
    }

    void CStyleStrings::NConcatenateStringAndStringPointer(char dest[], const int& totalLength, const int& length)
    {
        strcpy_s(dest, totalLength, m_string);
        strncat_s(dest, totalLength, m_stringPtr, length);
    }

    void CStyleStrings::ShowcaseStringToLong()
    {
        std::cout << "If a numeric value is stored in a string, we can convert it into an long and perform operations on it using" << std::endl
                  << "....strtol(string, NULL, <RADIX / BASE OF THE NUMBER SYSTEM>)" << std::endl;
        utils::IgnoreStdCinBufferTillEOL();
        char str[20];
        std::cout << "Please enter a numeric value: ";
        std::cin.getline(str, 20);
        utils::CheckAndClearCharactersInStream(str, 20);
        long int l = strtol(str, NULL, 10);
        std::cout << "The numeric value is: " << l <<std::endl;
        std::cout << "We can also perform operations such as incrementing it : " << ++l << std::endl;
    }

    void CStyleStrings::ShowcaseStringToFloat()
    {
        std::cout << "If a float value is stored in a string, we can convert it into an long and perform operations on it using" << std::endl
                  << "....strtof(string, NULL)" << std::endl;
        utils::IgnoreStdCinBufferTillEOL();
        char str[20];
        std::cout << "Please enter a float value: ";
        std::cin.getline(str, 20);
        utils::CheckAndClearCharactersInStream(str, 20);
        float f = strtof(str, NULL);
        std::cout << "The numeric value is: " << f << std::endl;
        std::cout << "We can also perform operations such as incrementing it : " << ++f << std::endl;
    }

    void CStyleStrings::ShowcaseStringToToken()
    {
        std::cout << "If a token is stored in a string, we can convert it into an long and perform operations on it using" << std::endl
                  << "....strtok(string, \"<Separators / Delimiters>\")" << std::endl;
        char str[20] = "x=5;y=10;z=35";
        std::cout << "The string contains: " << str << std::endl;
        std::cout << "We will pass the string to function strtok(str, \"=;\") and we should get the output without the =  and ;. We will run it through a while loop." << std::endl;
        char* next_token = nullptr;
        char* token = strtok_s(str, "=;", &next_token);
        while (token != NULL)
        {
            std::cout << token;
            token = strtok_s(NULL, "=;", &next_token);
            std::cout << std::endl;
        }
    }
} // namespace cstylestrings
