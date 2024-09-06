#pragma once

#include <map>
#include <string>
#include <optional>
#include <iostream>
#include "QueueUsingLinkedList.h"

namespace queue
{
    template <class T>
    class PriorityQueueElement
    {
    private:
        enum m_PriorityQueueElementMenu
        {
            MIN_COUNT             = 0,
            IS_EMPTY              = 1,
            DISPLAY               = 2,
            NUM_ELEMENTS          = 3,  
            ENQUEUE               = 4,
            DEQUEUE               = 5,
            FRONT                 = 6,
            REAR                  = 7,
            RESET                 = 8,
            BACK_TO_PREVIOUS_MENU = 9,
            EXIT_FROM_PROGRAM     = 10,
            MAX_COUNT             = EXIT_FROM_PROGRAM
        };

        int                             m_choice                      { 0 };
        std::map<int, std::string>      m_priorityQueueElementMenuMap {};
        queue::QueueUsingLinkedList<T>* m_data                        { nullptr };
    public:
        PriorityQueueElement();
        ~PriorityQueueElement();
        const int        GetMinCase();
        const int        GetMaxCase();
        const int&       GetChoice();
        void             GetChoiceInputFromUser();
        void	         PrintMenu();
        void             PrintSelectedChoice();
        bool             IsEmpty();
        void             Display();
        int              NumElements();
        bool             Enqueue(T);
        std::optional<T> Dequeue();
        std::optional<T> Front();
        std::optional<T> Rear();
        void             Reset();
    };
} // namespace queue

# include "PriorityQueueElement.tpp"
