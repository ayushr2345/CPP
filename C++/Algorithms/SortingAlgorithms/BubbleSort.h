#pragma once

#include <map>
#include <string>
#include <optional>
#include <iostream>

namespace sorting_algorithms
{
    template <class T>
    class BubbleSort
    {
    private:
        enum m_BubbleSortMenu
        {
            MIN_COUNT                        = 0,
            SHOWCASE_BUBBLE_SORT             = 1,
            SHOWCASE_BUBBLE_SORT_ACTION      = 2,
            INSERT_ELEMENTS_IN_ARRAY         = 3,
            PERFORM_BUBBLE_SORT              = 4,
            DISPLAY_ARRAY                    = 5,
            BACK_TO_PREVIOUS_MENU            = 6,
            EXIT_FROM_PROGRAM                = 7,
            MAX_COUNT                        = EXIT_FROM_PROGRAM
        };

        int                        m_choice         { 0 };
        std::map<int, std::string> m_bubbleSortMenuMap {};
        int                        m_size           { 0 };
        T*                         m_data           { nullptr };
        void                       Swap(T&, T&);

    public:
        BubbleSort(int);
        ~BubbleSort();
        const int        GetMinCase();
        const int        GetMaxCase();
        const int&       GetChoice();
        void             GetChoiceInputFromUser();
        void	         PrintMenu();
        void             PrintSelectedChoice();
        void             ShowcaseBubbleSort();
        void             ShowcaseBubbleSortAction();
        bool             DoesDataExist();
        void             InsertElements();
        bool             PerformBubbleSort();
        void             DisplayArray();
    };
} // namespace sorting_algorithms

# include "BubbleSort.tpp"
