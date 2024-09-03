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

    std::string StackMain::InfixToPostfixConversion(std::string infixExpression)
    {
        std::cout << "Normally inifix expressions are solved by moving randomly, but internally"
                  << " converts it into postfix to convert evaluate it in one scan" << std::endl;

        // std::string infixExpression = "((a+b)-(c-d))";
        // std::string infixExpression = "((a+b)*c)-d^e^f";
        std::string postfixExpression;

        std::function<int (char)> outOfStackPrecedence = [](char ch) -> int {
            switch (ch)
            {
            case '+':
            case '-':
                return 1;
            case '*':
            case '/':
                return 3;
            case '^':
                return 6;
            case '(':
                return 7;
            case ')':
                return 0;
            default:
                return -1;
            }
        };

        std::function<int (char)> insideStackPrecedence = [](char ch) -> int {
            switch (ch)
            {
            case '+':
            case '-':
                return 2;
            case '*':
            case '/':
                return 4;
            case '^':
                return 5;
            case '(':
                return 0;
            case ')':
                return -1;
            default:
                return -1;
            }
        };

        stack::StackUsingArray<char> expressionStack(20);
        int flag = 0;

        for (char ch: infixExpression)
        {
            if (ch == '(')
            {
                expressionStack.Push(ch);
            } 
            else if (isalnum(ch))
            {
                postfixExpression.push_back(ch);
            } 
            else if (ch == ')')
            {
                while (not (expressionStack.IsEmpty()) and expressionStack.GetTop().value() != '(') 
                {
                    postfixExpression.push_back(expressionStack.Pop().value());
                }
                expressionStack.Pop(); // Remove the '(' from the stack
            } 
            else
            {
                while (not (expressionStack.IsEmpty()) and 
                       outOfStackPrecedence(ch) <= insideStackPrecedence(expressionStack.GetTop().value()))
                {
                    postfixExpression.push_back(expressionStack.Pop().value());
                }
                expressionStack.Push(ch);
            }
        }

        while (!expressionStack.IsEmpty())
        {
            char poppedChar = expressionStack.Pop().value();
            if (poppedChar != '(')
            {
                postfixExpression.push_back(poppedChar);
            }
        }

        if (flag == 1 or not (expressionStack.IsEmpty()))
        {
            std::cout << "Conversion was unsuccessful" << std::endl;
        }
        else 
        {
            std::cout << "The conversion was successful: " << postfixExpression << std::endl;
        }

        return postfixExpression;
    }

    void StackMain::EvaluationOfExpression()
    {
        std::string infixExpression = "6+5+3*4";
        std::string postfixExpression = InfixToPostfixConversion(infixExpression);

        stack::StackUsingArray<int> valueStack(20);

        int flag = 0;
        for (const char ch: postfixExpression)
        {
            if (isdigit(ch))
            {
                valueStack.Push(static_cast<int>(ch - '0'));
            }
            else if (ch == '+' or
                     ch == '-' or
                     ch == '*' or
                     ch == '/')
            {
                std::optional<int> poppedValue1 = valueStack.Pop();
                std::optional<int> poppedValue2 = valueStack.Pop();

                if (not (poppedValue1.has_value() and poppedValue2.has_value()))
                {
                    flag = 1;
                    break;
                }
                else
                {
                    switch (ch)
                    {
                    case '+':
                    {
                        int res = poppedValue2.value() + poppedValue1.value();
                        valueStack.Push(res);
                        break;
                    }
                    case '-':
                    {
                        int res = poppedValue2.value() - poppedValue1.value();
                        valueStack.Push(res);
                        break;
                    }
                    case '*':
                    {
                        int res = poppedValue2.value() * poppedValue1.value();
                        valueStack.Push(res);
                        break;
                    }
                    case '/':
                    {
                        int res = poppedValue2.value() / poppedValue1.value();
                        valueStack.Push(res);
                        break;
                    }
                    default:
                        break;
                    }
                }
            }
        }

        if (flag == 1)
        {
            std::cout << "Evaluation failed" << std::endl;
        }
        else
        {
            std::cout << "Evaluation successful: " << valueStack.GetTop().value() << std::endl;
        }
    }
} // namespace stack
