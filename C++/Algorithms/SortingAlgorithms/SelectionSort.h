#pragma once

#include <map>
#include <string>
#include <optional>
#include <iostream>

namespace sorting_algorithms
{
    template <class T>
    class SelectionSort
    {
    private:
        enum m_SelectionSortMenu
        {
            MIN_COUNT                      = 0,
            SHOWCASE_SELECTION_SORT        = 1,
            SHOWCASE_SELECTION_SORT_ACTION = 2,
            INSERT_ELEMENTS_IN_ARRAY       = 3,
            PERFORM_SELECTION_SORT         = 4,
            DISPLAY_ARRAY                  = 5,
            BACK_TO_PREVIOUS_MENU          = 6,
            EXIT_FROM_PROGRAM              = 7,
            MAX_COUNT                      = EXIT_FROM_PROGRAM
        };

        int                        m_choice         { 0 };
        std::map<int, std::string> m_selectionSortMenuMap {};
        int                        m_size           { 0 };
        T*                         m_data           { nullptr };
        void                       Swap(T&, T&);

    public:
        SelectionSort(int);
        ~SelectionSort();
        const int        GetMinCase();
        const int        GetMaxCase();
        const int&       GetChoice();
        void             GetChoiceInputFromUser();
        void	         PrintMenu();
        void             PrintSelectedChoice();
        void             ShowcaseSelectionSort();
        void             ShowcaseSelectionSortAction();
        bool             DoesDataExist();
        void             InsertElements();
        bool             PerformSelectionSort();
        void             DisplayArray();
    };
} // namespace sorting_algorithms

# include "SelectionSort.tpp"
