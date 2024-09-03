#pragma once

#include <map>
#include <string>
#include <optional>
#include <iostream>
#include "StackUsingArray.h"
#include "StackUsingLinkedList.h"

namespace stack
{
    class StackMain
    {
    private:
        enum m_StackMainMenu
        {
            MIN_COUNT                   = 0,
            STACK_USING_ARRAY           = 1,
            STACK_USING_LINKED_LIST     = 2,
            PARANTHESIS_MATCHING        = 3,
            INFIX_TO_POSTFIX_CONVERSION = 4,
            EVALUATION_OF_EXPRESSION    = 5,
            BACK_TO_PREVIOUS_MENU       = 6,
            EXIT_FROM_PROGRAM           = 7,
            MAX_COUNT                   = EXIT_FROM_PROGRAM
        };
        int                        m_choice           { 0 };
        std::map<int, std::string> m_stackMainMenuMap { };

    public:
        StackMain();
        const int  GetMinCase();
        const int  GetMaxCase();
        const int& GetChoice();
        void       GetChoiceInputFromUser();
        void	   PrintMenu();
        void       PrintSelectedChoice();
        void       StackUsingArray();
        void       StackUsingLinkedList();
        void       ParanthesisMatching();
        void       InfixToPostfixConversion();
    };
} // namespace stack
