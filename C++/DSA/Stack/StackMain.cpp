#include <iostream>
#include <functional>
#include "StackMain.h"
#include "../../utils.h"
#include "../../handlers.h"

namespace stack
{
    StackMain::StackMain():
        m_choice           ( 0 ),
        m_stackMainMenuMap ( {} )
    {
        m_stackMainMenuMap.insert({ m_StackMainMenu(STACK_USING_ARRAY),
                                    std::string("Stack using array") });
        m_stackMainMenuMap.insert({ m_StackMainMenu(STACK_USING_LINKED_LIST),
                                    std::string("Stack using linked list") });
        m_stackMainMenuMap.insert({ m_StackMainMenu(PARANTHESIS_MATCHING),
                                    std::string("Paranthesis matching") });
        m_stackMainMenuMap.insert({ m_StackMainMenu(INFIX_TO_POSTFIX_CONVERSION),
                                    std::string("Infix to postfix conversion") });
        m_stackMainMenuMap.insert({ m_StackMainMenu(EVALUATION_OF_EXPRESSION),
                                    std::string("Evaluation of an expression") });
        m_stackMainMenuMap.insert({ m_StackMainMenu(BACK_TO_PREVIOUS_MENU),
                                    std::string("Back to Previous Menu") });
        m_stackMainMenuMap.insert({ m_StackMainMenu(EXIT_FROM_PROGRAM),
                                    std::string("Exit from program") });
    }

    const int StackMain::GetMinCase()
    {
        return m_StackMainMenu::MIN_COUNT;
    }

    const int StackMain::GetMaxCase()
    {
        return m_StackMainMenu::MAX_COUNT;
    }

    const int& StackMain::GetChoice()
    {
        return m_choice;
    }

    void StackMain::GetChoiceInputFromUser()
    {
        utils::InputNumberFromUser(m_choice, 1, static_cast<int>(m_StackMainMenu::MAX_COUNT));
    }

    void StackMain::PrintMenu()
    {
        std::cout << std::endl;
        for (std::map<int, std::string>::iterator it = m_stackMainMenuMap.begin();
            it != m_stackMainMenuMap.end();
            it++)
        {
            std::cout << it->first << ". " << it->second << std::endl;
        }
        std::cout << "Please enter your choice: ";
    }

    void StackMain::PrintSelectedChoice()
    {
        std::cout << std::endl << std::endl
                  << "You have chosen choice "
                  << m_stackMainMenuMap.at(m_choice)
                  << std::endl;
    }

    void StackMain::StackUsingArray()
    {
        int size;
        std::cout << "Enter the size of the stack: ";
        utils::InputNumberFromUser(size, 1, 10);
        stack::StackUsingArray<int> stackUsingArrayObj(size);
        handlers::Handle(stackUsingArrayObj);
    }
} // namespace stack
