#pragma once

#include <map>
#include <string>
#include <optional>
#include <iostream>

namespace heap
{
    template <class T>
    class Heapify
    {
    private:
        enum m_HeapifyMenu
        {
            MIN_COUNT                        = 0,
            DOES_HEAP_EXIST                  = 1,
            TAKE_INPUT_FOR_THE_ARRAY         = 2,
            MAX_HEAP_HEAPIFY                 = 3,
            MIN_HEAP_HEAPIFY                 = 4,
            DISPLAY_HEAP                     = 5,
            DISPLAY_ARRAY                    = 6,
            RESET_HEAP                       = 7,
            BACK_TO_PREVIOUS_MENU            = 8,
            EXIT_FROM_PROGRAM                = 9,
            MAX_COUNT                        = EXIT_FROM_PROGRAM
        };

        int                        m_choice         { 0 };
        std::map<int, std::string> m_heapifyMenuMap {};
        int                        m_size           { 0 };
        int                        m_numElements    { 0 };
        int                        m_sizeHeap       { 0 };
        T*                         m_data           { nullptr };
    public:
        Heapify(int);
        ~Heapify();
        const int        GetMinCase();
        const int        GetMaxCase();
        const int&       GetChoice();
        void             GetChoiceInputFromUser();
        void	         PrintMenu();
        void             PrintSelectedChoice();
        bool             DoesHeapExist();
        void             TakeInputForTheArray();
        void             MinHeapHeapifyHelper(const int);
        void             MinHeapHeapify();
        void             MaxHeapHeapifyHelper(const int);
        void             MaxHeapHeapify();
        void             DisplayHeap();
        void             DisplayArray();
        void             ResetHeap();
    };
} // namespace heap

# include "Heapify.tpp"
