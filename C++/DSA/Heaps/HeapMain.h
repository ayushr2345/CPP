#pragma once

#include <map>
#include <cmath>
#include <string>
#include <optional>
#include <iostream>
#include "MaxHeap.h"

namespace heap
{
    class HeapMain
    {
    private:
        enum m_HeapMainMenu
        {
            MIN_COUNT                               = 0,
            MAX_HEAP                                = 1,
            BACK_TO_PREVIOUS_MENU                   = 2,
            EXIT_FROM_PROGRAM                       = 3,
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
    };
} // namespace heap
