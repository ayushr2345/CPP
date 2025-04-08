#pragma once

#include <map>
#include <cmath>
#include <string>
#include <optional>
#include <iostream>
#include "MaxHeap.h"
#include "MinHeap.h"
#include "Heapify.h"
#include "PriorityQueuesUsingHeaps.h"

namespace heap
{
    class HeapMain
    {
    private:
        enum m_HeapMainMenu
        {
            MIN_COUNT                               = 0,
            MAX_HEAP                                = 1,
            MIN_HEAP                                = 2,
            HEAPIFY                                 = 3,
            PRIORITY_QUEUES_USING_HEAPS             = 4,
            BACK_TO_PREVIOUS_MENU                   = 5,
            EXIT_FROM_PROGRAM                       = 6,
            MAX_COUNT                               = EXIT_FROM_PROGRAM
        };
        int                        m_choice          { 0 };
        std::map<int, std::string> m_heapMainMenuMap { };

    public:
        HeapMain();
        const int   GetMinCase();
        const int   GetMaxCase();
        const int&  GetChoice();
        void        GetChoiceInputFromUser();
        void	    PrintMenu();
        void        PrintSelectedChoice();
        void        MaxHeap();
        void        MinHeap();
        void        Heapify();
        void        PriorityQueuesUsingHeaps();
    };
} // namespace heap
