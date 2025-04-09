#pragma once

#include <map>
#include <cmath>
#include <string>
#include <optional>
#include <iostream>
#include "BubbleSort.h"
#include "InsertionSort.h"
#include "SelectionSort.h"

namespace sorting_algorithms
{
    class SortingAlgorithmsMain
    {
    private:
        enum m_SortingAlgorithmsMainMenu
        {
            MIN_COUNT             = 0,
            BUBBLE_SORT           = 1,
            INSERTION_SORT        = 2,
            SELECTION_SORT        = 3,
            BACK_TO_PREVIOUS_MENU = 4,
            EXIT_FROM_PROGRAM     = 5,
            MAX_COUNT             = EXIT_FROM_PROGRAM
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
        void        InsertionSort();
        void        SelectionSort();
    };
} // namespace sorting_algorithms
