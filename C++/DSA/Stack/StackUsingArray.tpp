#pragma once

#include "StackUsingArray.h"
#include "../../utils.h"

namespace stack
{
    template <class T>
    StackUsingArray<T>::StackUsingArray(int size):
        m_choice                 ( 0 ),
        m_stackUsingArrayMenuMap ( {} ),
        m_top                    { -1 },
        m_size                   { size },
        m_data                   { nullptr }
    {
        m_stackUsingArrayMenuMap.insert({ m_StackUsingArrayMenu(IS_EMPTY),
                                          std::string("Check if the stack is empty") });
        m_stackUsingArrayMenuMap.insert({ m_StackUsingArrayMenu(IS_FULL),
                                          std::string("Check if the stack is full") });
        m_stackUsingArrayMenuMap.insert({ m_StackUsingArrayMenu(DISPLAY),
                                          std::string("Display the stack") });
        m_stackUsingArrayMenuMap.insert({ m_StackUsingArrayMenu(PUSH),
                                          std::string("Push into the stack") });
        m_stackUsingArrayMenuMap.insert({ m_StackUsingArrayMenu(POP),
                                          std::string("Pop from the stack") });
        m_stackUsingArrayMenuMap.insert({ m_StackUsingArrayMenu(PEEK),
                                          std::string("Peek to a position in the stack") });
        m_stackUsingArrayMenuMap.insert({ m_StackUsingArrayMenu(GET_TOP),
                                          std::string("Get the top position of the stack") });
        m_stackUsingArrayMenuMap.insert({ m_StackUsingArrayMenu(BACK_TO_PREVIOUS_MENU),
                                          std::string("Back to Previous Menu") });
        m_stackUsingArrayMenuMap.insert({ m_StackUsingArrayMenu(EXIT_FROM_PROGRAM),
                                          std::string("Exit from program") });
        
        m_data = new T[m_size];
    }

    template <class T>
    StackUsingArray<T>::~StackUsingArray()
    {
        delete []m_data;
        m_size = 0;
    }
    
    template <class T>
    const int StackUsingArray<T>::GetMinCase()
    {
        return m_StackUsingArrayMenu::MIN_COUNT;
    }

    template <class T>
    const int StackUsingArray<T>::GetMaxCase()
    {
        return m_StackUsingArrayMenu::MAX_COUNT;
    }

    template <class T>
    const int& StackUsingArray<T>::GetChoice()
    {
        return m_choice;
    }

    template <class T>
    void StackUsingArray<T>::GetChoiceInputFromUser()
    {
        utils::InputNumberFromUser(m_choice, 1, static_cast<int>(m_StackUsingArrayMenu::MAX_COUNT));
    }

    template <class T>
    void StackUsingArray<T>::PrintMenu()
    {
        std::cout << std::endl;
        for (std::map<int, std::string>::iterator it = m_stackUsingArrayMenuMap.begin();
            it != m_stackUsingArrayMenuMap.end();
            it++)
        {
            std::cout << it->first << ". " << it->second << std::endl;
        }
        std::cout << "Please enter your choice: ";
    }

    template <class T>
    void StackUsingArray<T>::PrintSelectedChoice()
    {
        std::cout << std::endl << std::endl
                << "You have chosen choice "
                << m_stackUsingArrayMenuMap.at(m_choice)
                << std::endl;
    }

    template <class T>
    bool StackUsingArray<T>::IsEmpty()
    {
        return m_top > -1 ? false : true;
    }

    template <class T>
    bool StackUsingArray<T>::IsFull()
    {
        return m_top == m_size - 1 ? true : false;
    }

    template <class T>
    bool StackUsingArray<T>::Push(T element)
    {
        if (IsFull())
        {
            std::cout << "The stack is full" << std::endl;
            return 0;
        }
        
        m_data[++m_top] = element;
        return true;
    }

    template <class T>
    std::optional<T> StackUsingArray<T>::Pop()
    {
        if (IsEmpty())
        {
            std::cout << "The stack is empty" << std::endl;
            return std::nullopt;
        }

        T deleted = m_data[m_top];
        m_data[m_top--] = 0;
        return deleted;
    }

    template <class T>
    std::optional<T> StackUsingArray<T>::Peek(int position)
    {
        if (IsEmpty())
        {
            std::cout << "The stack is empty" << std::endl;
            return std::nullopt;
        }

        int index = m_top - (position - 1);

        if (index >= 0 and index <= m_top)
        {
            return m_data[index];
        }

        std::cout << "The position does not exist" << std::endl;
        return std::nullopt;
    }

    template <class T>
    std::optional<T> StackUsingArray<T>::GetTop()
    {
        if (IsEmpty())
        {
            std::cout << "The stack is empty" << std::endl;
            return std::nullopt;
        }

        return m_data[m_top];
    }

    template <class T>
    void StackUsingArray<T>::Display()
    {
        if (IsEmpty())
        {
            std::cout << "The stack is empty" << std::endl;
        }
        else
        {
            std::cout << "Printing the stack from top:" << std::endl;
            for (int i = m_top; i > -1; i--)
            {
                std::cout << m_data[i] << std::endl;
            }
        }
    }
} //namespace stack
