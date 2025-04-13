#pragma once

#include <map>
#include <string>
#include <optional>
#include <iostream>

namespace sorting_algorithms
{
    template <class T>
    class HeapSort
    {
    private:
        enum m_HeapSortMenu
        {
            MIN_COUNT                  = 0,
            SHOWCASE_HEAP_SORT        = 1,
            SHOWCASE_HEAP_SORT_ACTION = 2,
            INSERT_ELEMENTS_IN_ARRAY   = 3,
            PERFORM_HEAP_SORT         = 4,
            DISPLAY_ARRAY              = 5,
            BACK_TO_PREVIOUS_MENU      = 6,
            EXIT_FROM_PROGRAM          = 7,
            MAX_COUNT                  = EXIT_FROM_PROGRAM
        };

        int                        m_choice           { 0 };
        std::map<int, std::string> m_heapSortMenuMap {};
        int                        m_size             { 0 };
        int                        m_sizeHeap         { 0 };
        T*                         m_data             { nullptr };
        void                       Swap(T&, T&);
        void                       HeapifyHelper(T*, int);
        void                       Heapify(T*, const int);
        void                       DeleteFromHeap(T*, int);

    public:
        HeapSort(int);
        ~HeapSort();
        const int        GetMinCase();
        const int        GetMaxCase();
        const int&       GetChoice();
        void             GetChoiceInputFromUser();
        void	         PrintMenu();
        void             PrintSelectedChoice();
        void             ShowcaseHeapSort();
        void             ShowcaseHeapSortAction();
        bool             DoesDataExist();
        void             InsertElements();
        bool             PerformHeapSort();
        void             DisplayArray();
    };
} // namespace sorting_algorithms

# include "HeapSort.tpp"
