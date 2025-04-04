#pragma once

#include <map>
#include <string>
#include <optional>
#include <iostream>

namespace heap
{
    template <class T>
    class MaxHeap
    {
    private:
        enum m_MaxHeapMenu
        {
            MIN_COUNT                        = 0,
            DOES_HEAP_EXIST                  = 1,
            INSERT_IN_HEAP                   = 2,
            DELETE_FROM_HEAP                 = 3,
            DISPLAY_HEAP                     = 4,
            DISPLAY_ARRAY                    = 5,
            HEAP_SORT                        = 6,
            RESET_HEAP                       = 7,
            BACK_TO_PREVIOUS_MENU            = 8,
            EXIT_FROM_PROGRAM                = 9,
            MAX_COUNT                        = EXIT_FROM_PROGRAM
        };

        int                        m_choice         { 0 };
        std::map<int, std::string> m_maxHeapMenuMap {};
        int                        m_size           { 0 };
        int                        m_numElements    { 0 };
        int                        m_sizeHeap       { 0 };
        T*                         m_data           { nullptr };
    public:
        MaxHeap(int);
        ~MaxHeap();
        const int        GetMinCase();
        const int        GetMaxCase();
        const int&       GetChoice();
        void             GetChoiceInputFromUser();
        void	         PrintMenu();
        void             PrintSelectedChoice();
        bool             DoesHeapExist();
        bool             InsertInHeap(const int);
        T                DeleteFromHeap();
        void             DisplayHeap();
        void             DisplayArray();
        void             HeapSort();
        void             ResetHeap();
    };
} // namespace heap

# include "MaxHeap.tpp"
