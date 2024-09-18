#pragma once

#include <map>
#include <string>
#include <optional>
#include <iostream>
#include "../LinkedList/LinearSinglyLinkedList.h"

namespace stack
{
    template <class T>
    class StackUsingLinkedList
    {
    private:
        enum m_StackUsingLinkedListMenu
        {
            MIN_COUNT             = 0,
            IS_EMPTY              = 1,
            DISPLAY               = 2,
            PUSH                  = 3,
            POP                   = 4,
            PEEK                  = 5,
            GET_TOP               = 6,
            BACK_TO_PREVIOUS_MENU = 7,
            EXIT_FROM_PROGRAM     = 8,
            MAX_COUNT             = EXIT_FROM_PROGRAM
        };
        int                                      m_choice                      { 0 };
        std::map<int, std::string>               m_stackUsingLinkedListMenuMap {};
        linkedList::LinearSinglyLinkedList<T>*   m_data                        { nullptr };

    public:
        StackUsingLinkedList();
        ~StackUsingLinkedList();
        const int        GetMinCase();
        const int        GetMaxCase();
        const int&       GetChoice();
        void             GetChoiceInputFromUser();
        void	         PrintMenu();
        void             PrintSelectedChoice();
        bool             IsEmpty();
        std::optional<T> GetTop();
        bool             Push(T);
        std::optional<T> Pop();
        std::optional<T> Peek(int);
        void             Display();
    };
} // namespace stack

# include "StackUsingLinkedList.tpp"
