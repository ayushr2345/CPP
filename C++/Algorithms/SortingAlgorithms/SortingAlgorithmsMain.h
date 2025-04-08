#pragma once

#include <map>
#include <cmath>
#include <string>
#include <optional>
#include <iostream>
#include "BubbleSort.h"

namespace sorting_algorithms
{
    class SortingAlgorithmsMain
    {
    private:
        enum m_SortingAlgorithmsMainMenu
        {
            MIN_COUNT                               = 0,
            BUBBLE_SORT                             = 1,
            BACK_TO_PREVIOUS_MENU                   = 2,
            EXIT_FROM_PROGRAM                       = 3,
            MAX_COUNT                               = EXIT_FROM_PROGRAM
        };
        int                        m_choice          { 0 };
        std::map<int, std::string> m_sortingAlgorithmsMainMenuMap { };

    public:
        SortingAlgorithmsMain();
        const int   GetMinCase();
        const int   GetMaxCase();
        const int&  GetChoice();
        void        GetChoiceInputFromUser();
        void	    PrintMenu();
        void        PrintSelectedChoice();
        void        BubbleSort();
    };
} // namespace sorting_algorithms
