#pragma once

#include <map>
#include <string>
#include <optional>
#include <iostream>
#include "QueueUsingLinkedList.h"

namespace queue
{
    template <class T>
    class PriorityQueueLimitedSet
    {
    private:
        enum m_PriorityQueueLimitedSetMenu
        {
            MIN_COUNT             = 0,
            IS_EMPTY              = 1,
            DISPLAY               = 2,
            NUM_ELEMENTS          = 3,  
            ENQUEUE               = 4,
            DEQUEUE               = 5,
            PEEK_FRONT            = 6,
            PEEK_PRIORITY         = 7,
            RESET                 = 8,
            BACK_TO_PREVIOUS_MENU = 9,
            EXIT_FROM_PROGRAM     = 10,
            MAX_COUNT             = EXIT_FROM_PROGRAM
        };

        int                             m_choice                         { 0 };
        std::map<int, std::string>      m_priorityQueueLimitedSetMenuMap {};
        int                             m_numPriorities                  { 0 };
        queue::QueueUsingLinkedList<T>* m_data                           { nullptr };
    public:
        PriorityQueueLimitedSet(int);
        ~PriorityQueueLimitedSet();
        const int        GetMinCase();
        const int        GetMaxCase();
        const int&       GetChoice();
        void             GetChoiceInputFromUser();
        void	         PrintMenu();
        void             PrintSelectedChoice();
        bool             IsEmpty();
        int              GetNumPriorities();
        void             Display();
        int              NumElements();
        bool             Enqueue(T, int);
        std::optional<T> Dequeue();
        std::optional<T> PeekFront();
        std::optional<T> PeekPriority(int);
        void             Reset();
    };
} // namespace queue

# include "PriorityQueueLimitedSet.tpp"
