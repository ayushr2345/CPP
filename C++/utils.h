#pragma once

#include <map>
#include <string>
#include <iostream>

#ifndef _WIN32
    #include <limits>
    #include <cstring>
#endif	


namespace utils
{
    enum class MainMenu
    {
        MIN_COUNT       = 0,
        LANGUAGE        = 1,
        DATA_STRUCTURES = 2,
        ALGORITHMS      = 3,
        EXIT	        = 4,
        MAX_COUNT       = EXIT
    };

    enum class LanguageMenu
    {
        MIN_COUNT               = 0,
        BASICS                  = 1,
        POINTERS_AND_REFERENCES = 2,
        C_STYLE_STRINGS         = 3,
        CPP_STRINGS             = 4,
        FUNCTIONS               = 5,
        CLASSES_AND_OBJECTS     = 6,
        IOSTREAMS               = 7,
        BACK_TO_PREVIOUS_MENU   = 8,
        EXIT                    = 9,
        MAX_COUNT               = EXIT
    };

    enum class DataStructuresMenu
    {
        MIN_COUNT             = 0,
        RECURSIONS            = 1,
        ARRAY_ADT             = 2,
        STRINGS               = 3,
        MATRICES              = 4,
        LINKED_LIST           = 5,
        STACK                 = 6,
        QUEUE                 = 7,
        TREES                 = 8,
        HEAPS                 = 9,
        BACK_TO_PREVIOUS_MENU = 10,
        EXIT                  = 11,
        MAX_COUNT             = EXIT
    };

    enum class AlgorithmsMenu
    {
        MIN_COUNT             = 0,
        SORTING_ALGORITHMS    = 1,
        BACK_TO_PREVIOUS_MENU = 2,
        EXIT                  = 3,
        MAX_COUNT             = EXIT
    };

    // The extern keyword in C++ is used to declare a global variable 
    // or function which can be accessed from any part of the program 
    // or from other files included in the program's header.

    // Used so that this MainMenuArray is available to the main.cpp
    // and we can print the selected choice.
    static std::map<int, std::string> MainMenuMap =
    {
        {
            static_cast<int>(MainMenu::LANGUAGE),
            std::string("Language")
        },
        {
            static_cast<int>(MainMenu::DATA_STRUCTURES),
            std::string("Data Structures")
        },
        {
            static_cast<int>(MainMenu::ALGORITHMS),
            std::string("Algorithms")
        },
        {
            static_cast<int>(MainMenu::EXIT),
            std::string("Exit from program")
        }
    };

    static std::map<int, std::string> LanguageMenuMap =
    {
        {
            static_cast<int>(LanguageMenu::BASICS),
            std::string("Basics")
        },
        {
            static_cast<int>(LanguageMenu::POINTERS_AND_REFERENCES),
            std::string("Pointers and References")
        },
        {
            static_cast<int>(LanguageMenu::C_STYLE_STRINGS),
            std::string("C Style Strings")
        },
        {
            static_cast<int>(LanguageMenu::CPP_STRINGS),
            std::string("CPP Style Strings")
        },
        {
            static_cast<int>(LanguageMenu::FUNCTIONS),
            std::string("Functions")
        },
        {
            static_cast<int>(LanguageMenu::CLASSES_AND_OBJECTS),
            std::string("Classes and Objects")
        },
        {
            static_cast<int>(LanguageMenu::IOSTREAMS),
            std::string("I/O Streams")
        },
        {
            static_cast<int>(LanguageMenu::BACK_TO_PREVIOUS_MENU),
            std::string("Back to previous menu")
        },
        {
            static_cast<int>(LanguageMenu::EXIT),
            std::string("Exit from program")
        }
    };

    static std::map<int, std::string> DataStructuresMenuMap =
    {
        {
            static_cast<int>(DataStructuresMenu::RECURSIONS),
            std::string("Recursions")
        },
        {
            static_cast<int>(DataStructuresMenu::ARRAY_ADT),
            std::string("Array ADT")
        },
        {
            static_cast<int>(DataStructuresMenu::STRINGS),
            std::string("Strings")
        },
        {
            static_cast<int>(DataStructuresMenu::MATRICES),
            std::string("Matrices")
        },
        {
            static_cast<int>(DataStructuresMenu::LINKED_LIST),
            std::string("Linked Lists")
        },
        {
            static_cast<int>(DataStructuresMenu::STACK),
            std::string("Stacks")
        },
        {
            static_cast<int>(DataStructuresMenu::QUEUE),
            std::string("Queues")
        },
        {
            static_cast<int>(DataStructuresMenu::TREES),
            std::string("Trees")
        },
        {
            static_cast<int>(DataStructuresMenu::HEAPS),
            std::string("Heaps")
        },
        {
            static_cast<int>(DataStructuresMenu::BACK_TO_PREVIOUS_MENU),
            std::string("Back to previous menu")
        },
        {
            static_cast<int>(DataStructuresMenu::EXIT),
            std::string("Exit from program")
        }
    };

    static std::map<int, std::string> AlgorithmsMenuMap =
    {
        {
            static_cast<int>(AlgorithmsMenu::SORTING_ALGORITHMS),
            std::string("Sorting Algorithms")
        },
        {
            static_cast<int>(AlgorithmsMenu::BACK_TO_PREVIOUS_MENU),
            std::string("Back to previous menu")
        },
        {
            static_cast<int>(AlgorithmsMenu::EXIT),
            std::string("Exit from program")
        }
    };

    void PrintWelcomeScreen();
    void PrintMenu(std::map<int, std::string>&);
    void PrintSelectedChoice(const int&, std::map<int, std::string>&);
    void ClearCinFlag();
    void IgnoreStdCinBufferTillEOL();
    bool CheckAndClearCharactersInStream(const char[], const int);

    // templates should not have definition in a separate source file 
    // as it would give compilation and linking errors
    template<typename T>
    void InputNumberFromUser(T& choice, T range_start = std::numeric_limits<T>::min(), T range_stop = std::numeric_limits<T>::max(), char newLine = 'y')
    {
        std::cin >> choice;

        bool condition = ((std::cin.fail()) || (std::cin.peek() != '\n') || (choice < range_start) || (choice > range_stop));
        if (newLine == 'n')
        {
            condition = std::cin.fail() or choice < range_start or choice > range_stop;
        }

        while(condition)
        {
            ClearCinFlag();
            IgnoreStdCinBufferTillEOL();
            std::cout << "Wrong input type! Please enter a value within range: "
                      << range_start << " to " << range_stop << ": ";
            std::cin >> choice;

            condition = ((std::cin.fail()) || (std::cin.peek() != '\n') || (choice < range_start) || (choice > range_stop));
            if (newLine == 'n')
            {
                condition = std::cin.fail() or choice < range_start or choice > range_stop;
            }
        }
    }
} //namespace utils
