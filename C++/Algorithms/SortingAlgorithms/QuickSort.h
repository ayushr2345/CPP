#pragma once

#include <map>
#include <string>
#include <optional>
#include <iostream>

namespace sorting_algorithms
{
    template <class T>
    class QuickSort
    {
    private:
        enum m_QuickSortMenu
        {
            MIN_COUNT                  = 0,
            SHOWCASE_QUICK_SORT        = 1,
            SHOWCASE_QUICK_SORT_ACTION = 2,
            INSERT_ELEMENTS_IN_ARRAY   = 3,
            PERFORM_QUICK_SORT         = 4,
            DISPLAY_ARRAY              = 5,
            BACK_TO_PREVIOUS_MENU      = 6,
            EXIT_FROM_PROGRAM          = 7,
            MAX_COUNT                  = EXIT_FROM_PROGRAM
        };

        int                        m_choice           { 0 };
        std::map<int, std::string> m_quickSortMenuMap {};
        int                        m_size             { 0 };
        T*                         m_data             { nullptr };
        void                       Swap(T&, T&);
        int                        Partition(T*, const int, const int);
        void                       QuickSortAlgorithm(T*, const int, const int);

    public:
        QuickSort(int);
        ~QuickSort();
        const int        GetMinCase();
        const int        GetMaxCase();
        const int&       GetChoice();
        void             GetChoiceInputFromUser();
        void	         PrintMenu();
        void             PrintSelectedChoice();
        void             ShowcaseQuickSort();
        void             ShowcaseQuickSortAction();
        bool             DoesDataExist();
        void             InsertElements();
        bool             PerformQuickSort();
        void             DisplayArray();
    };
} // namespace sorting_algorithms

# include "QuickSort.tpp"
