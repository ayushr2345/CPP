#pragma once

#include <map>
#include <string>
#include <optional>
#include <iostream>

namespace queue
{
    template <class T>
    class DoubleEndedQueue
    {
    private:
        enum m_DoubleEndedQueueMenu
        {
            MIN_COUNT             = 0,
            IS_EMPTY              = 1,
            DISPLAY               = 2,
            NUM_ELEMENTS          = 3,  
            ENQUEUE_FRONT         = 4,
            ENQUEUE_REAR          = 5,
            DEQUEUE_FRONT         = 6,
            DEQUEUE_REAR          = 7,
            FRONT                 = 8,
            REAR                  = 9,
            RESET                 = 10,
            BACK_TO_PREVIOUS_MENU = 11,
            EXIT_FROM_PROGRAM     = 12,
            MAX_COUNT             = EXIT_FROM_PROGRAM
        };

        class Node
        {
        public:
            T     m_m_data {};
            Node* m_m_next {nullptr};
        };
        int                        m_choice                  { 0 };
        std::map<int, std::string> m_doubleEndedQueueMenuMap {};
        Node*                      m_front                   { nullptr };
        Node*                      m_rear                    { nullptr };
    public:
        DoubleEndedQueue();
        ~DoubleEndedQueue();
        const int        GetMinCase();
        const int        GetMaxCase();
        const int&       GetChoice();
        void             GetChoiceInputFromUser();
        void	         PrintMenu();
        void             PrintSelectedChoice();
        bool             IsEmpty();
        void             Display();
        int              NumElements();
        bool             EnqueueFront(T);
        bool             EnqueueRear(T);
        std::optional<T> DequeueFront();
        std::optional<T> DequeueRear();
        std::optional<T> Front();
        std::optional<T> Rear();
        void             Reset();
    };
} // namespace queue

# include "DoubleEndedQueue.tpp"
