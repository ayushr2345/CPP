#include <iostream>
#include <string>
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

    void StackMain::StackUsingLinkedList()
    {
        stack::StackUsingLinkedList<int> stackUsingLinkedListObj;
        handlers::Handle(stackUsingLinkedListObj);
    }

    void StackMain::ParanthesisMatching()
    {
        std::cout << "Six expressions:" << std::endl
                  << "1. ((a + b) * (c - d))" << std::endl
                  << "2. ((a + b) * (c - d)" << std::endl
                  << "3. ((a + b) * (c - d)))" << std::endl
                  << "4. [{(a + b) - c} + {c * (d + e)}]" << std::endl
                  << "5. [{(a + b) - c} + {c * (d + e}]" << std::endl
                  << "6. [{(a + b) - c} + {c * (d + e))}]" << std::endl;

        std::string ExpressionArray[6] = {
            "((a + b) * (c - d))",
            "((a + b) * (c - d)",
            "((a + b) * (c - d)))",
            "[{(a + b) - c} + {c * (d + e)}]",
            "[{(a + b) - c} + {c * (d + e}]",
            "[{(a + b) - c} + {c * (d + e))}]"
        };

        for (const auto Expression: ExpressionArray)
        {
            stack::StackUsingArray<char> expressionStack(20);
            int flag = 0;
            std::cout << "Matching Paranthesis for expression: " << Expression << std::endl;
            for (const auto ch: Expression)
            {
                if ((ch == '(') or
                    (ch == '{') or
                    (ch == '['))
                {
                    expressionStack.Push(ch);
                    continue;
                }

                if (ch == ')')
                {
                    std::optional<char> poppedOutChar = expressionStack.Pop();

                    if (not poppedOutChar.has_value())
                    {
                        flag = 1;
                        break;
                    }
                    else
                    {
                        if (poppedOutChar.value() != '(')
                        {
                            flag = 1;
                            break;
                        }
                    }
                    continue;
                }

                if (ch == '}')
                {
                    std::optional<char> poppedOutChar = expressionStack.Pop();

                    if (not poppedOutChar.has_value())
                    {
                        flag = 1;
                        break;
                    }
                    else
                    {
                        if (poppedOutChar.value() != '{')
                        {
                            flag = 1;
                            break;
                        }
                    }
                    continue;
                }

                if (ch == ']')
                {
                    std::optional<char> poppedOutChar = expressionStack.Pop();

                    if (not poppedOutChar.has_value())
                    {
                        flag = 1;
                        break;
                    }
                    else
                    {
                        if (poppedOutChar.value() != '[')
                        {
                            flag = 1;
                            break;
                        }
                    }
                    continue;
                }
            }
            if (not expressionStack.IsEmpty() or flag == 1)
            {
                std::cout << "The paranthesis is not matching" << std::endl;
            }
            else
            {
                std::cout << "The paranthesis is matching" << std::endl;
            }
        }
    }
} // namespace stack
