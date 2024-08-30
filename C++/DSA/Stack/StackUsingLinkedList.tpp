#pragma once

#include "StackUsingLinkedList.h"
#include "../../utils.h"

namespace stack
{
    template <class T>
    StackUsingLinkedList<T>::StackUsingLinkedList(int size):
        m_choice                      ( 0 ),
        m_StackUsingLinkedListMenuMap ( {} ),
        m_top                         { -1 },
        m_data                        { nullptr }
    {
        m_StackUsingLinkedListMenuMap.insert({ m_StackUsingLinkedListMenu(IS_EMPTY),
                                               std::string("Check if the stack is empty") });
        m_StackUsingLinkedListMenuMap.insert({ m_StackUsingLinkedListMenu(IS_FULL),
                                               std::string("Check if the stack is full") });
        m_StackUsingLinkedListMenuMap.insert({ m_StackUsingLinkedListMenu(DISPLAY),
                                               std::string("Display the stack") });
        m_StackUsingLinkedListMenuMap.insert({ m_StackUsingLinkedListMenu(PUSH),
                                               std::string("Push into the stack") });
        m_StackUsingLinkedListMenuMap.insert({ m_StackUsingLinkedListMenu(POP),
                                               std::string("Pop from the stack") });
        m_StackUsingLinkedListMenuMap.insert({ m_StackUsingLinkedListMenu(PEEK),
                                               std::string("Peek to a position in the stack") });
        m_StackUsingLinkedListMenuMap.insert({ m_StackUsingLinkedListMenu(GET_TOP),
                                               std::string("Get the top position of the stack") });
        m_StackUsingLinkedListMenuMap.insert({ m_StackUsingLinkedListMenu(BACK_TO_PREVIOUS_MENU),
                                               std::string("Back to Previous Menu") });
        m_StackUsingLinkedListMenuMap.insert({ m_StackUsingLinkedListMenu(EXIT_FROM_PROGRAM),
                                               std::string("Exit from program") });
        
        m_data = new LinearSinglyLinkedList<int>;
    }

    template <class T>
    StackUsingLinkedList<T>::~StackUsingLinkedList()
    {
        delete m_data;
        m_size = 0;
    }
    
    template <class T>
    const int StackUsingLinkedList<T>::GetMinCase()
    {
        return m_StackUsingLinkedListMenu::MIN_COUNT;
    }

    template <class T>
    const int StackUsingLinkedList<T>::GetMaxCase()
    {
        return m_StackUsingLinkedListMenu::MAX_COUNT;
    }

    template <class T>
    const int& StackUsingLinkedList<T>::GetChoice()
    {
        return m_choice;
    }

    template <class T>
    void StackUsingLinkedList<T>::GetChoiceInputFromUser()
    {
        utils::InputNumberFromUser(m_choice, 1, static_cast<int>(m_StackUsingLinkedListMenu::MAX_COUNT));
    }

    template <class T>
    void StackUsingLinkedList<T>::PrintMenu()
    {
        std::cout << std::endl;
        for (std::map<int, std::string>::iterator it = m_StackUsingLinkedListMenuMap.begin();
            it != m_StackUsingLinkedListMenuMap.end();
            it++)
        {
            std::cout << it->first << ". " << it->second << std::endl;
        }
        std::cout << "Please enter your choice: ";
    }

    template <class T>
    void StackUsingLinkedList<T>::PrintSelectedChoice()
    {
        std::cout << std::endl << std::endl
                << "You have chosen choice "
                << m_StackUsingLinkedListMenuMap.at(m_choice)
                << std::endl;
    }

    template <class T>
    bool StackUsingLinkedList<T>::IsEmpty()
    {
        return m_top > -1 ? false : true;
    }

    template <class T>
    bool StackUsingLinkedList<T>::IsFull()
    {
        return m_top == m_size - 1 ? true : false;
    }

    template <class T>
    bool StackUsingLinkedList<T>::Push(T element)
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
    std::optional<T> StackUsingLinkedList<T>::Pop()
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
    std::optional<T> StackUsingLinkedList<T>::Peek(int position)
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
    std::optional<T> StackUsingLinkedList<T>::GetTop()
    {
        if (IsEmpty())
        {
            std::cout << "The stack is empty" << std::endl;
            return std::nullopt;
        }

        return m_data[m_top];
    }

    template <class T>
    void StackUsingLinkedList<T>::Display()
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
