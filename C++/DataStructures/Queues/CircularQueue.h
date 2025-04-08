#pragma once

#include <map>
#include <string>
#include <optional>
#include <iostream>

namespace queue
{
    template <class T>
    class CircularQueue
    {
    private:
        enum m_CircularQueueMenu
        {
            MIN_COUNT             = 0,
            IS_EMPTY              = 1,
            IS_FULL               = 2,
            DISPLAY               = 3,
            NUM_ELEMENTS          = 4,  
            ENQUEUE               = 5,
            DEQUEUE               = 6,
            FRONT                 = 7,
            REAR                  = 8,
            RESET                 = 9,
            BACK_TO_PREVIOUS_MENU = 10,
            EXIT_FROM_PROGRAM     = 11,
            MAX_COUNT             = EXIT_FROM_PROGRAM
        };
        int                        m_choice               { 0 };
        std::map<int, std::string> m_circularQueueMenuMap {};
        int                        m_front                { 0 };
        int                        m_rear                 { 0 };
        int                        m_size                 { 0 };
        T*                         m_data                 { nullptr };

    public:
        CircularQueue(int);
        ~CircularQueue();
        const int        GetMinCase();
        const int        GetMaxCase();
        const int&       GetChoice();
        void             GetChoiceInputFromUser();
        void	         PrintMenu();
        void             PrintSelectedChoice();
        bool             IsEmpty();
        bool             IsFull();
        void             Display();
        int              NumElements();
        bool             Enqueue(T);
        std::optional<T> Dequeue();
        std::optional<T> Front();
        std::optional<T> Rear();
        void             Reset();
    };
} // namespace queue

# include "CircularQueue.tpp"
