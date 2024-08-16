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
        MIN_COUNT = 0,
        LANGUAGE  = 1,
        DSA       = 2,
        EXIT	  = 3,
        MAX_COUNT = EXIT
    };

    enum class LanguageMenu
    {
        MIN_COUNT               = 0,
        BASICS	                = 1,
        POINTERS_AND_REFERENCES = 2,
        C_STYLE_STRINGS			= 3,
        CPP_STRINGS			    = 4,
        FUNCTIONS				= 5,
        CLASSES_AND_OBJECTS     = 6,
        IOSTREAMS				= 7,
        BACK_TO_PREVIOUS_MENU   = 8,
        EXIT                    = 9,
        MAX_COUNT               = EXIT
    };

    enum class DSAMenu
    {
        MIN_COUNT             = 0,
        RECURSIONS            = 1,
        ARRAY_ADT			  = 2,
        BACK_TO_PREVIOUS_MENU = 3,
        EXIT                  = 4,
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
            static_cast<int>(MainMenu::DSA),
            std::string("DSA")
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

    static std::map<int, std::string> DSAMenuMap =
    {
        {
            static_cast<int>(DSAMenu::RECURSIONS),
            std::string("Recursions")
        },
        {
            static_cast<int>(DSAMenu::ARRAY_ADT),
            std::string("Array ADT")
        },
        {
            static_cast<int>(DSAMenu::BACK_TO_PREVIOUS_MENU),
            std::string("Back to previous menu")
        },
        {
            static_cast<int>(DSAMenu::EXIT),
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
    void InputNumberFromUser(T& choice, T range_start = std::numeric_limits<T>::min(), T range_stop = std::numeric_limits<T>::max())
    {
        std::cin >> choice;
        while (std::cin.fail() || std::cin.peek() != '\n' || choice < range_start || choice > range_stop)
        {
            ClearCinFlag();
            IgnoreStdCinBufferTillEOL();
            std::cout << "Wrong input type! Please enter a value within range: "
                      << range_start << " to " << range_stop << ": ";
            std::cin >> choice;
        }
    }
} //namespace utils
