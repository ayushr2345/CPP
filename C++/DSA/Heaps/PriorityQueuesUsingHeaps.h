#pragma once

#include <map>
#include <string>
#include <optional>
#include <iostream>
#include "MinHeap.h"
#include "MaxHeap.h"

namespace heap
{
    template <class T>
    class PriorityQueuesUsingHeaps
    {
    private:
        enum m_PriorityQueuesUsingHeapsMenu
        {
            MIN_COUNT                        = 0,
            ENQUEUE                          = 1,
            DEQUEUE                          = 2,
            DISPLAY_HEAP                     = 3,
            DISPLAY_ARRAY                    = 4,
            BACK_TO_PREVIOUS_MENU            = 5,
            EXIT_FROM_PROGRAM                = 6,
            MAX_COUNT                        = EXIT_FROM_PROGRAM
        };

        enum m_TypeOfHeap
        {
            MIN_HEAP,
            MAX_HEAP
        };

        int                        m_choice                          { 0 };
        std::map<int, std::string> m_priorityQueuesUsingHeapsMenuMap {};
        MinHeap<T>*                m_minHeap                         {};
        MaxHeap<T>*                m_maxHeap                         {};
        m_TypeOfHeap               m_currentHeapType                 {};
    public:
        PriorityQueuesUsingHeaps(int);
        ~PriorityQueuesUsingHeaps();
        const int        GetMinCase();
        const int        GetMaxCase();
        const int&       GetChoice();
        void             GetChoiceInputFromUser();
        void	         PrintMenu();
        void             PrintSelectedChoice();
        bool             Enqueue(const int);
        T                Dequeue();
        void             DisplayHeap();
        void             DisplayArray();
        void             ResetHeap();
    };
} // namespace heap

# include "PriorityQueuesUsingHeaps.tpp"
