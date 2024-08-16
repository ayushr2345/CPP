#include <iostream>
#include <iomanip>
#include <limits>	
#include "Basics.h"
#include "../utils.h"

namespace basics
{
    Basics::Basics():
        m_choice        (0),
        m_name          (""),
        m_BasicsMenuMap ({})
    {
        m_BasicsMenuMap.insert({ m_BasicsMenu(HELLO_WORLD), 
                                 std::string("Hello World") });
        m_BasicsMenuMap.insert({ m_BasicsMenu(HELLO_NAME), 
                                 std::string("Hello Name") });
        m_BasicsMenuMap.insert({ m_BasicsMenu(PRINT_DATA_TYPES_SIZE_AND_RANGES),
                                 std::string("Print data types with their sizes and ranges") });
        m_BasicsMenuMap.insert({ m_BasicsMenu(SHOW_CASE_IF_ELSE),
                                 std::string("Show Case If-Else") });
        m_BasicsMenuMap.insert({ m_BasicsMenu(SHOW_CASE_NESTED_IF_ELSE),
                                 std::string("Show Case Nested If-Else") });
        m_BasicsMenuMap.insert({ m_BasicsMenu(SHOW_CASE_IF_ELSE_LADDER),
                                 std::string("Show Case If-Else Ladder") });
        m_BasicsMenuMap.insert({ m_BasicsMenu(SHOW_CASE_COMPOUND_CONDITIONAL_STATEMENTS),
                                 std::string("Show Case Compound Conditional Statements") });
        m_BasicsMenuMap.insert({ m_BasicsMenu(SHOW_CASE_SHORT_CIRCUITING),
                                 std::string("Show Case Short Circuiting") });
        m_BasicsMenuMap.insert({ m_BasicsMenu(SHOW_CASE_TERNARY_OPERATOR),
                                 std::string("Show Case Ternary Operator") });
        m_BasicsMenuMap.insert({ m_BasicsMenu(SHOW_CASE_SWITCH_STATEMENT),
                                 std::string("Show Case Switch Statement") });
        m_BasicsMenuMap.insert({ m_BasicsMenu(SHOW_CASE_WHILE_LOOP),
                                 std::string("Show Case While Loop") });
        m_BasicsMenuMap.insert({ m_BasicsMenu(SHOW_CASE_DO_WHILE_LOOP),
                                 std::string("Show Case Do-While Loop") });
        m_BasicsMenuMap.insert({ m_BasicsMenu(SHOW_CASE_FOR_LOOP),
                                 std::string("Show Case For Loop") });
        m_BasicsMenuMap.insert({ m_BasicsMenu(SHOW_CASE_ARRAYS),
                                 std::string("Show Case Arrays") });
        m_BasicsMenuMap.insert({ m_BasicsMenu(SHOW_CASE_FOR_EACH_LOOP),
                                 std::string("Show Case For Each Loop") });
        m_BasicsMenuMap.insert({ m_BasicsMenu(SHOW_CASE_2D_ARRAYS),
                                 std::string("Show Case 2D Arrays") });
        m_BasicsMenuMap.insert({ m_BasicsMenu(BACK_TO_PREVIOUS_MENU), 
                                 std::string("Back to Previous Menu") });
        m_BasicsMenuMap.insert({ m_BasicsMenu(EXIT_FROM_PROGRAM), 
                                 std::string("Exit from program") });
    }

    const int Basics::GetMinCase()
    {
        return m_BasicsMenu::MIN_COUNT;
    }

    const int Basics::GetMaxCase()
    {
        return m_BasicsMenu::MAX_COUNT;
    }

    const int& Basics::GetChoice()
    {
        return m_choice;
    }

    void Basics::GetChoiceInputFromUser()
    {
        utils::InputNumberFromUser(m_choice, 1, (int)m_BasicsMenu::MAX_COUNT);
    }

    void Basics::PrintMenu()
    {
        std::cout << std::endl;
        for (std::map<int, std::string>::iterator it = m_BasicsMenuMap.begin();
            it != m_BasicsMenuMap.end();
            it++)
        {
            std::cout << it->first << ". " << it->second << std::endl;
        }
        std::cout << "Please enter your choice: ";
    }

    void Basics::PrintSelectedChoice()
    {
        std::cout << std::endl << std::endl
                  << "You have chosen choice "
                  << m_BasicsMenuMap.at(m_choice)
                  << std::endl;
    }
    
    void Basics::HelloWorld()
    {
        std::cout << "Hello World!" << std::endl;
    }

    void Basics::GetNameInputFromUser()
    {
        utils::IgnoreStdCinBufferTillEOL();
        std::getline(std::cin, m_name);
    }

    void Basics::HelloName()
    {
        std::cout << "Hello " << m_name << std::endl;
    }

    void Basics::PrintDataTypeSizeAndRanges()
    {
        // As there are 22 types in the table, counter is set to 23 and counterDec is a lambda which will decrement the counter
        // counterDec is called in each row of the table. As all the counterDec are called in same cout statement, they will get executed
        // in reverse order hence we use this approach. 
        // NOTE: This is illegal in C++ and can give undefined behaviour
        int counter { 23 };
        auto counterDec = [&counter] () -> int
            {
                counter -= 1;
                return counter; 
            };


        std::cout << std::left <<
            " ---------------------------------------------------------------------------------------------------------\n"                              <<
            "| " << std::setw(9) << "[S. NO.]"   << "| " << std::setw(19) << "[DATA TYPE]"        << "| " << std::setw(7) << "[SIZE]"                   << "| " << std::setw(17) << "[SIZE (in bits)]"             << "| " << std::setw(21) << "[RANGE (Min)]"                                << "| " << std::setw(21) << "[RANGE (Max)]"                                << "|\n" <<
            " ---------------------------------------------------------------------------------------------------------\n"                <<																		  
            "| " << std::setw(9) << counterDec() << "| " << std::setw(19) << "BOOL"               << "| " << std::setw(7) << sizeof(bool)               << "| " << std::setw(17) << 8 * sizeof(bool)               << "| " << std::setw(21) << std::numeric_limits<bool>::min()               << "| " << std::setw(21) << std::numeric_limits<bool>::max()               << "|\n" <<
            "| " << std::setw(9) << counterDec() << "| " << std::setw(19) << "CHAR"               << "| " << std::setw(7) << sizeof(char)               << "| " << std::setw(17) << 8 * sizeof(char)               << "| " << std::setw(21) << (int)std::numeric_limits<char>::min()          << "| " << std::setw(21) << (int)std::numeric_limits<char>::max()          << "|\n" <<
            "| " << std::setw(9) << counterDec() << "| " << std::setw(19) << "SIGNED CHAR"        << "| " << std::setw(7) << sizeof(signed char)        << "| " << std::setw(17) << 8 * sizeof(signed char)        << "| " << std::setw(21) << (int)std::numeric_limits<signed char>::min()   << "| " << std::setw(21) << (int)std::numeric_limits<signed char>::max()   << "|\n" <<
            "| " << std::setw(9) << counterDec() << "| " << std::setw(19) << "UNSIGNED CHAR"      << "| " << std::setw(7) << sizeof(unsigned char)      << "| " << std::setw(17) << 8 * sizeof(unsigned char)      << "| " << std::setw(21) << (int)std::numeric_limits<unsigned char>::min() << "| " << std::setw(21) << (int)std::numeric_limits<unsigned char>::max() << "|\n" <<
            "| " << std::setw(9) << counterDec() << "| " << std::setw(19) << "WCHAR_T"            << "| " << std::setw(7) << sizeof(wchar_t)            << "| " << std::setw(17) << 8 * sizeof(wchar_t)            << "| " << std::setw(21) << (int)std::numeric_limits<wchar_t>::min()       << "| " << std::setw(21) << (int)std::numeric_limits<wchar_t>::max()       << "|\n" <<
            "| " << std::setw(9) << counterDec() << "| " << std::setw(19) << "CHAR16_T"           << "| " << std::setw(7) << sizeof(char16_t)           << "| " << std::setw(17) << 8 * sizeof(char16_t)           << "| " << std::setw(21) << (int)std::numeric_limits<char16_t>::min()      << "| " << std::setw(21) << (int)std::numeric_limits<char16_t>::max()      << "|\n" <<
            "| " << std::setw(9) << counterDec() << "| " << std::setw(19) << "CHAR32_T"           << "| " << std::setw(7) << sizeof(char32_t)           << "| " << std::setw(17) << 8 * sizeof(char32_t)           << "| " << std::setw(21) << (int)std::numeric_limits<char32_t>::min()      << "| " << std::setw(21) << (int)std::numeric_limits<char32_t>::max()      << "|\n" <<
            "| " << std::setw(9) << counterDec() << "| " << std::setw(19) << "SHORT"              << "| " << std::setw(7) << sizeof(short)              << "| " << std::setw(17) << 8 * sizeof(short)              << "| " << std::setw(21) << std::numeric_limits<short>::min()              << "| " << std::setw(21) << std::numeric_limits<short>::max()              << "|\n" <<
            "| " << std::setw(9) << counterDec() << "| " << std::setw(19) << "SIGNED SHORT"       << "| " << std::setw(7) << sizeof(signed short)       << "| " << std::setw(17) << 8 * sizeof(signed short)       << "| " << std::setw(21) << std::numeric_limits<signed short>::min()       << "| " << std::setw(21) << std::numeric_limits<signed short>::max()       << "|\n" <<
            "| " << std::setw(9) << counterDec() << "| " << std::setw(19) << "UNSIGNED SHORT"     << "| " << std::setw(7) << sizeof(unsigned short)     << "| " << std::setw(17) << 8 * sizeof(unsigned short)     << "| " << std::setw(21) << std::numeric_limits<unsigned short>::min()     << "| " << std::setw(21) << std::numeric_limits<unsigned short>::max()     << "|\n" <<
            "| " << std::setw(9) << counterDec() << "| " << std::setw(19) << "INT"                << "| " << std::setw(7) << sizeof(int)                << "| " << std::setw(17) << 8 * sizeof(int)                << "| " << std::setw(21) << std::numeric_limits<int>::min()                << "| " << std::setw(21) << std::numeric_limits<int>::max()                << "|\n" <<
            "| " << std::setw(9) << counterDec() << "| " << std::setw(19) << "SIGNED INT"         << "| " << std::setw(7) << sizeof(signed int)         << "| " << std::setw(17) << 8 * sizeof(signed int)         << "| " << std::setw(21) << std::numeric_limits<signed int>::min()         << "| " << std::setw(21) << std::numeric_limits<signed int>::max()         << "|\n" <<
            "| " << std::setw(9) << counterDec() << "| " << std::setw(19) << "UNSIGNED INT"       << "| " << std::setw(7) << sizeof(unsigned int)       << "| " << std::setw(17) << 8 * sizeof(unsigned int)       << "| " << std::setw(21) << std::numeric_limits<unsigned int>::min()       << "| " << std::setw(21) << std::numeric_limits<unsigned int>::max()       << "|\n" <<
            "| " << std::setw(9) << counterDec() << "| " << std::setw(19) << "LONG"               << "| " << std::setw(7) << sizeof(long)               << "| " << std::setw(17) << 8 * sizeof(long)               << "| " << std::setw(21) << std::numeric_limits<long>::min()               << "| " << std::setw(21) << std::numeric_limits<long>::max()               << "|\n" <<
            "| " << std::setw(9) << counterDec() << "| " << std::setw(19) << "SIGNED LONG"        << "| " << std::setw(7) << sizeof(signed long)        << "| " << std::setw(17) << 8 * sizeof(signed long)        << "| " << std::setw(21) << std::numeric_limits<signed long>::min()        << "| " << std::setw(21) << std::numeric_limits<signed long>::max()        << "|\n" <<
            "| " << std::setw(9) << counterDec() << "| " << std::setw(19) << "UNSIGNED LONG"      << "| " << std::setw(7) << sizeof(unsigned long)      << "| " << std::setw(17) << 8 * sizeof(unsigned long)      << "| " << std::setw(21) << std::numeric_limits<unsigned long>::min()      << "| " << std::setw(21) << std::numeric_limits<unsigned long>::max()      << "|\n" <<
            "| " << std::setw(9) << counterDec() << "| " << std::setw(19) << "LONG LONG"          << "| " << std::setw(7) << sizeof(long long)          << "| " << std::setw(17) << 8 * sizeof(long long)          << "| " << std::setw(21) << std::numeric_limits<long long>::min()          << "| " << std::setw(21) << std::numeric_limits<long long>::max()          << "|\n" <<
            "| " << std::setw(9) << counterDec() << "| " << std::setw(19) << "SIGNED LONG LONG"   << "| " << std::setw(7) << sizeof(signed long long)   << "| " << std::setw(17) << 8 * sizeof(signed long long)   << "| " << std::setw(21) << std::numeric_limits<signed long long>::min()   << "| " << std::setw(21) << std::numeric_limits<signed long long>::max()   << "|\n" <<
            "| " << std::setw(9) << counterDec() << "| " << std::setw(19) << "UNSIGNED LONG LONG" << "| " << std::setw(7) << sizeof(unsigned long long) << "| " << std::setw(17) << 8 * sizeof(unsigned long long) << "| " << std::setw(21) << std::numeric_limits<unsigned long long>::min() << "| " << std::setw(21) << std::numeric_limits<unsigned long long>::max() << "|\n" <<
            "| " << std::setw(9) << counterDec() << "| " << std::setw(19) << "FLOAT"              << "| " << std::setw(7) << sizeof(float)              << "| " << std::setw(17) << 8 * sizeof(float)              << "| " << std::setw(21) << std::numeric_limits<float>::min()              << "| " << std::setw(21) << std::numeric_limits<float>::max()              << "|\n" <<
            "| " << std::setw(9) << counterDec() << "| " << std::setw(19) << "DOUBLE"             << "| " << std::setw(7) << sizeof(double)	            << "| " << std::setw(17) << 8 * sizeof(double)             << "| " << std::setw(21) << std::numeric_limits<double>::min()             << "| " << std::setw(21) << std::numeric_limits<double>::max()             << "|\n" <<
            "| " << std::setw(9) << counterDec() << "| " << std::setw(19) << "LONG DOUBLE"        << "| " << std::setw(7) << sizeof(long double)        << "| " << std::setw(17) << 8 * sizeof(long double)        << "| " << std::setw(21) << std::numeric_limits<long double>::min()        << "| " << std::setw(21) << std::numeric_limits<long double>::max()        << "|\n" <<
            " ---------------------------------------------------------------------------------------------------------\n";

    }

    void Basics::ShowCaseIfElse()
    {
        std::cout << "The structure of an if-else statement looks like this: " << std::endl;
        std::cout << "....if (<condition>)" << std::endl
                  << "....{" << std::endl
                  << "........<IF CODE BLOCK>" << std::endl
                  << "....}" << std::endl
                  << "....else" << std::endl
                  << "....{" << std::endl
                  << "........<ELSE CODE BLOCK>" << std::endl
                  << "....}" << std::endl << std::endl;

        int age { 0 };
        std::cout << "DEMO Problem: If the age is greater than or equal to 18, then the user is valid to access otherwise not!!" << std::endl;
        std::cout << "Please enter age of the user: ";
        utils::InputNumberFromUser(age, 1, 100);
        
        if (age >= 18)
        {
            std::cout << "Access granted" << std::endl;
        }
        else
        {
            std::cout << "Access denied" << std::endl;
        }
        std::cout << std::endl;
    }

    void Basics::ShowCaseNestedIfElse()
    {
        std::cout << "The structure of a nested if-else statement looks like this: " << std::endl;
        std::cout << "....if (<condition>)" << std::endl
                  << "....{" << std::endl
                  << "........<IF CODE BLOCK>" << std::endl
                  << "....}" << std::endl
                  << "....else" << std::endl
                  << "....{" << std::endl
                  << "........if (<nested if condition>)" << std::endl
                  << "........{" << std::endl
                  << "............<NESTED IF CODE BLOCK>" << std::endl
                  << "........}" << std::endl
                  << "........else" << std::endl
                  << "........{" << std::endl
                  << "............<NESTED ELSE CODE BLOCK>" << std::endl
                  << "........}" << std::endl
                  << "....}" << std::endl << std::endl;

        int age { 0 };
        std::cout << "DEMO Problem: If the age is greater than or equal to 13 and less than 19 then the user is a teenager!!" << std::endl;
        std::cout << "Please enter age of the user: ";
        utils::InputNumberFromUser(age, 1, 100);

        if (age >= 13)
        {
            if (age <= 19)
            {
                std::cout << "User is a teenager" << std::endl;
            }
            else
            {
                std::cout << "User is not a teenager" << std::endl;
            }
        }
        else
        {
            std::cout << "User is not a teenager" << std::endl;
        }
        std::cout << std::endl;
    }

    void Basics::ShowCaseIfElseLadder()
    {
        std::cout << "The structure of an if-else statement looks like this: " << std::endl;
        std::cout << "....if (<condition>)" << std::endl
                  << "....{" << std::endl
                  << "........<IF CODE BLOCK>" << std::endl
                  << "....}" << std::endl
                  << "....else if (<ladder if condition>)" << std::endl
                  << "....{" << std::endl
                  << "........<LADDER IF CODE BLOCK>" << std::endl
                  << "....}" << std::endl
                  << "....else if (<ladder if condition>)" << std::endl
                  << "....{" << std::endl
                  << "........<LADDER IF CODE BLOCK>" << std::endl
                  << "....}" << std::endl
                  << ".\n.\n.\n." << std::endl
                  << "....else" << std::endl
                  << "....{" << std::endl
                  << "........<ELSE CODE BLOCK>" << std::endl
                  << "....}" << std::endl << std::endl;

        int age { 0 };
        std::cout << "DEMO Problem: If the age is greater than or equal to 13 and less than 19 then the user is a teenager!!" << std::endl;
        std::cout << "Please enter age of the user: ";
        utils::InputNumberFromUser(age, 1, 100);

        // Just to showcase if-else ladder, the if and the else condition are same and can be combined in the else condition only as shown in 
        // ShowCaseCompoundConditionalStatements()
        if (age < 13)
        {
            std::cout << "User is not a teenager" << std::endl;
        }
        else if (age >= 13 && age <= 19)
        {
            std::cout << "User is a teenager" << std::endl;
        }
        else
        {
            std::cout << "User is not a teenager" << std::endl;
        }
        std::cout << std::endl;
    }

    void Basics::ShowCaseCompoundConditionalStatements()
    {
        std::cout << "We can combine conditional statements using &&, ||, !" << std::endl;
        std::cout << "The structure of an if-else statement looks like this: " << std::endl;
        std::cout << "....if (<condition #1> && <condition #2>)" << std::endl
                  << "....if (<condition #1> || <condition #2>)" << std::endl
                  << "....if (!<condition #2>)"                  << std::endl << std::endl;

        int age { 0 };
        std::cout << "DEMO Problem: If the age is greater than or equal to 13 and less than 19 then the user is a teenager!!" << std::endl;
        std::cout << "Please enter age of the user: ";
        utils::InputNumberFromUser(age, 1, 100);

        if (age >= 13 && age <= 19) 
        {
            std::cout << "User is a teenager" << std::endl;
        }
        else
        {
            std::cout << "User is not a teenager" << std::endl;
        }
        std::cout << std::endl;
    }

    void Basics::ShowCaseShortCircuiting()
    {
        // TODO: From here, add to menu, verify from If statements
        std::cout << "If in a compound conditional statement, the first condition result will be the result of the overall combined condition, the "
                  << "compiler will skip executing the second condition and will directly assign the result in final result" << std::endl;
        
        int a { 2 };
        int b { 5 };
        int c { 9 };

        std::cout << "DEMO Problem #1: a: " << a << " b: " << b << " c: " << c
                  << " we will run a condition here which will verify short circuiting!" << std::endl;
        if (a > b && ++c > b)
        {
        }
        else
        {
            std::cout << "The condition that was applied was" << std::endl
                      << "....if (a > b && ++c > b)" << std::endl
                      << " and not the values are a: " << a << " b: " << b  << " c: " << c 
                      << " respectively. The second condition is skipped " << std::endl;
        }

        std::cout << "#########################################" << std::endl;

        std::cout << "DEMO Problem #2: a: " << a << " b: " << b << " c: " << c
                  << " we will run a condition here which will verify short circuiting!" << std::endl;
        if (b > a || ++c < b)
        {
            std::cout << "The condition that was applied was" << std::endl
                << "....if (b > a || ++c < b)" << std::endl
                << " and not the values are a: " << a << " b: " << b << " c: " << c
                << " respectively. The second condition is skipped " << std::endl;
        }
        else
        {
        }
        std::cout << std::endl;
    }

    void Basics::ShowCaseTernaryOperator()
    {
        std::cout << "The structure of a ternary operator looks like this: " << std::endl;
        std::cout << "....<condition> ? <true block> : <false block>" << std::endl << std::endl;

        int age { 0 };
        std::cout << "DEMO Problem: If the age is greater than or equal to 18, then the user is valid to access otherwise not!! This could be solved "
                  << "via the if - else block but we use ternary operator here" << std::endl;
        std::cout << "Please enter age of the user: ";
        utils::InputNumberFromUser(age, 1, 100);

        (age > 18) ?
            std::cout << "Access is granted" << std::endl
            :
            std::cout << "Access is denied"  << std::endl;
        std::cout << std::endl;
    }

    void Basics::ShowCaseSwitchStatement()
    {
        std::cout << "The structure of a switcj statement looks like this: " << std::endl;
        std::cout << "....switch (<expression>)" << std::endl
            << "....{" << std::endl
            << "........case 1:" << std::endl
            << "........{" << std::endl
            << "............<CASE 1 CODE BLOCK>" << std::endl
            << "............break;" << std::endl
            << "........}" << std::endl
            << "........case 2:" << std::endl
            << "........{" << std::endl
            << "............<CASE 2 CODE BLOCK>" << std::endl
            << "............break;" << std::endl
            << "........}" << std::endl
            << ".\n.\n.\n." << std::endl
            << "........default:" << std::endl
            << "........{" << std::endl
            << "............<DEFAULT CODE BLOCK>" << std::endl
            << "........}" << std::endl
            << "....}" << std::endl << std::endl
            << "If break is not present in a case, the control will fall through the next case till it finds break or it reaches the end" << std::endl;

        int month { 0 };
        std::cout << "DEMO Problem: Take month input from user as number and print the name of the month" << std::endl;
        std::cout << "Please month (numeric): ";
        utils::InputNumberFromUser(month, 1, 12);

        switch (month)
        {
        case 1:
        {
            std::cout << "Entered month is: " << month << " January" << std::endl;
            break;
        }
        case 2:
        {
            std::cout << "Entered month is: " << month << " February" << std::endl;
            break;
        }
        case 3:
        {
            std::cout << "Entered month is: " << month << " March" << std::endl;
            break;
        }
        case 4:
        {
            std::cout << "Entered month is: " << month << " April" << std::endl;
            break;
        }
        case 5:
        {
            std::cout << "Entered month is: " << month << " May" << std::endl;
            break;
        }
        case 6:
        {
            std::cout << "Entered month is: " << month << " June" << std::endl;
            break;
        }
        case 7:
        {
            std::cout << "Entered month is: " << month << " July" << std::endl;
            break;
        }
        case 8:
        {
            std::cout << "Entered month is: " << month << " August" << std::endl;
            break;
        }
        case 9:
        {
            std::cout << "Entered month is: " << month << " September" << std::endl;
            break;
        }
        case 10:
        {
            std::cout << "Entered month is: " << month << " October" << std::endl;
            break;
        }
        case 11:
        {
            std::cout << "Entered month is: " << month << " November" << std::endl;
            break;
        }
        case 12:
        {
            std::cout << "Entered month is: " << month << " December" << std::endl;
            break;
        }
        default:
        {
            std::cout << "Wrong choice entered!" << std::endl << "Exiting" << std::endl;
            break;
        }
        std::cout << std::endl;
        }
    }

    void Basics::ShowCaseWhileLoop()
    {
        int number { 0 };
        std::cout << "The structure of while loop looks like this: " << std::endl
                  << "....while (<condition>)" << std::endl
                  << "....{" << std::endl
                  << "........<WHILE CODE BLOCK>" << std::endl
                  << "....}" << std::endl << std::endl;
        std::cout << "DEMO Problem: Enter a number from user and print numbers from 0 till that number!!" << std::endl;
        std::cout << "Please enter the number: ";
        utils::InputNumberFromUser(number, 0, 10);

        int i = 0;
        while (i <= number)
        {
            std::cout << i++ << " ";
        }
        std::cout << std::endl << std::endl;
    }

    void Basics::ShowCaseDoWhileLoop()
    {
        int number{ 0 };
        std::cout << "The structure of do-while loop looks like this: " << std::endl
                  << "....do" << std::endl
                  << "....{" << std::endl
                  << "........<WHILE CODE BLOCK>" << std::endl
                  << "....} while (<condition>);" << std::endl << std::endl
                  << "Unlike the while loop, this loop gets executed atleast once" << std::endl;
        std::cout << "DEMO Problem: Enter a number from user and print numbers from 0 till that number if the number is less than 20, if greater than 20, print only once!!" << std::endl;
        std::cout << "Please enter the number: ";
        utils::InputNumberFromUser(number, 0, 100);

        int i = 0;
        do
        {
            std::cout << "i: " << i << " number: " << number << std::endl;
            i++;
        } while (number <= 20 && i <= number);
        std::cout << "Unlike the while loop, this loop will print the i and number at least once before checking for the condition" << std::endl;
        std::cout << std::endl << std::endl;
    }

    void Basics::ShowCaseForLoop()
    {
        int number{ 0 };
        std::cout << "The structure of for loop looks like this: " << std::endl
                  << "....for (<initiation>; <condition>; <updation>)" << std::endl
                  << "....{" << std::endl
                  << "........<FOR CODE BLOCK>" << std::endl
                  << "....}" << std::endl << std::endl
                  << " 1. Initiation\n 2. Condition check\n 3. FOR code block execution\n 4. Updation\n 5. Repeat from step 2" << std::endl;
        std::cout << "DEMO Problem: Enter a number from user and print numbers from 0 till that number!!" << std::endl;
        std::cout << "Please enter the number: ";
        utils::InputNumberFromUser(number, 0, 10);

        int i = 0;
        for (i; i <= number; i++)
        {
            std::cout << i << " ";
        }
        std::cout << std::endl << std::endl;
    }

    void Basics::ShowCaseArrays()
    {
        std::cout << "Arrays in C++ look like this: " << std::endl
                  << "....int A[<length of array>];" << std::endl
                  << "....int A[<length of array>] = {<>, <>, ..., <>};" << std::endl
                  << "....int A[] = {<>, <>, ..., <>};" << std::endl
                  << "....int *A = new int[<length of array>] // memory reserved in heap;" << std::endl << std::endl
                  << "Indexing is done using A[index], does not check bounds" << std::endl;

        int A[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
        std::cout << "DEMO Problem: Print all the elements of an array" << std::endl;

        for (int i = 0; i < 10; i++)
        {
            std::cout << A[i] << " ";
        }
        std::cout << std::endl << std::endl;
    }

    void Basics::ShowCaseForEachLoop()
    {
        std::cout << "The structure of for loop looks like this: " << std::endl
                  << "....for (<DATA TYPE> <variable name>: <container name>)" << std::endl
                  << "....{" << std::endl
                  << "........<FOR EACH CODE BLOCK>" << std::endl
                  << "....}" << std::endl << std::endl;
        
        int A[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
        std::cout << "DEMO Problem: Print all the elements of an array" << std::endl;

        for (int& element: A)
        {
            std::cout << element << " ";
        }
        std::cout << std::endl << std::endl;
    }

    void Basics::ShowCase2DArrays()
    {
        std::cout << "2D Arrays in C++ look like this: " << std::endl
            << "....int A[<rows>][<columns>];" << std::endl
            << "....int A[<rows>][<columns>] = {{<>, <>, ..., <>}, {<>, <>, ..., <>}, ...};" << std::endl
            << "....int A[][<columns>] = {{<>, <>, ..., <>}, {<>, <>, ..., <>}, ...};" << std::endl
            << "....int *A = new int[<rows> * <columns>] // memory reserved in heap;" << std::endl << std::endl
            << "Indexing is done using A[<row>][<column>], does not check bounds" << std::endl;

        int A[][3] = { {1, 2, 3},
                       {4, 5, 6},
                       {7, 8, 9} };
        std::cout << "DEMO Problem: Print all the elements of a 2D Array" << std::endl;

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                std::cout << A[i][j] << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl << std::endl;
    }
} // namespace basics
