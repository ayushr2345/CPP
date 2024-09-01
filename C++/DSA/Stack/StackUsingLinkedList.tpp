#pragma once

#include "StackUsingLinkedList.h"
#include "../../utils.h"

namespace stack
{
    template <class T>
    StackUsingLinkedList<T>::StackUsingLinkedList():
        m_choice                      ( 0 ),
        m_stackUsingLinkedListMenuMap ( {} ),
        m_data                        { nullptr }
    {
        m_stackUsingLinkedListMenuMap.insert({ m_StackUsingLinkedListMenu(IS_EMPTY),
                                               std::string("Check if the stack is empty") });
        m_stackUsingLinkedListMenuMap.insert({ m_StackUsingLinkedListMenu(DISPLAY),
                                               std::string("Display the stack") });
        m_stackUsingLinkedListMenuMap.insert({ m_StackUsingLinkedListMenu(PUSH),
                                               std::string("Push into the stack") });
        m_stackUsingLinkedListMenuMap.insert({ m_StackUsingLinkedListMenu(POP),
                                               std::string("Pop from the stack") });
        m_stackUsingLinkedListMenuMap.insert({ m_StackUsingLinkedListMenu(PEEK),
                                               std::string("Peek to a position in the stack") });
        m_stackUsingLinkedListMenuMap.insert({ m_StackUsingLinkedListMenu(GET_TOP),
                                               std::string("Get the top position of the stack") });
        m_stackUsingLinkedListMenuMap.insert({ m_StackUsingLinkedListMenu(BACK_TO_PREVIOUS_MENU),
                                               std::string("Back to Previous Menu") });
        m_stackUsingLinkedListMenuMap.insert({ m_StackUsingLinkedListMenu(EXIT_FROM_PROGRAM),
                                               std::string("Exit from program") });
        
        m_data = new linkedList::LinearSinglyLinkedList<int>;
    }

    template <class T>
    StackUsingLinkedList<T>::~StackUsingLinkedList()
    {
        delete m_data;
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
        for (std::map<int, std::string>::iterator it = m_stackUsingLinkedListMenuMap.begin();
            it != m_stackUsingLinkedListMenuMap.end();
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
                << m_stackUsingLinkedListMenuMap.at(m_choice)
                << std::endl;
    }

    template <class T>
    bool StackUsingLinkedList<T>::IsEmpty()
    {
        return m_data->IsEmpty() ? true : false;
    }

    template <class T>
    bool StackUsingLinkedList<T>::Push(T element)
    {
        bool isInserted = m_data->Insert(0, element);
        
        return isInserted ? true : false;
    }

    template <class T>
    std::optional<T> StackUsingLinkedList<T>::Pop()
    {
        if (IsEmpty())
        {
            std::cout << "The stack is empty" << std::endl;
            return std::nullopt;
        }

        const auto deleted = m_data->Remove(0);
        
        if (deleted.has_value())
        {
            return deleted.value();
        }
        return std::nullopt;
    }

    template <class T>
    std::optional<T> StackUsingLinkedList<T>::Peek(int position)
    {
        if (IsEmpty())
        {
            std::cout << "The stack is empty" << std::endl;
            return std::nullopt;
        }

        int index = position - 1;

        if (index >= 0 and index <= (m_data->GetSize() - 1))
        {
            const auto peekedValue = m_data->Get(index);

            if (peekedValue.has_value())
            {
                return peekedValue.value();
            }
            return std::nullopt;
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

        const auto topValue = m_data->Get(0);

        if (topValue.has_value())
        {
            return topValue.value();
        }
        return std::nullopt;
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
            m_data->Display();
        }
    }
} //namespace stack
