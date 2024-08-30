#pragma once

#include <map>
#include <string>
#include <optional>
#include <iostream>
#include "LinkedList/LinearSinglyLinkedList.h"

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
            IS_FULL               = 2,
            DISPLAY               = 3,
            PUSH                  = 4,
            POP                   = 5,
            PEEK                  = 6,
            GET_TOP               = 7,
            BACK_TO_PREVIOUS_MENU = 8,
            EXIT_FROM_PROGRAM     = 9,
            MAX_COUNT             = EXIT_FROM_PROGRAM
        };
        int                                      m_choice                      { 0 };
        std::map<int, std::string>               m_stackUsingLinkedListMenuMap {};
        int                                      m_top                         { -1 };
        linkedList::LinearSinglyLinkedList<int>* m_data                        { nullptr };

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
        bool             IsFull();
        std::optional<T> GetTop();
        bool             Push(T);
        std::optional<T> Pop();
        std::optional<T> Peek(int);
        void             Display();
    };
} // namespace stack

# include "StackUsingLinkedList.tpp"
