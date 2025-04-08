#pragma once

#include <map>
#include <string>
#include <optional>
#include <iostream>

namespace arrayAdt
{
    template <class T>
    class ArrayADT
    {
    private:
        enum m_ArrayADTMenu
        {
            MIN_COUNT             = 0,
            IS_EMPTY              = 1,
            IS_FULL               = 2,
            GET                   = 3,
            SET                   = 4,
            DISPLAY               = 5,
            INSERT_BEGINNING      = 6,
            INSERT_END            = 7,
            INSERT_INDEX          = 8,
            DELETE_BEGINNING      = 9,
            DELETE_END            = 10,
            DELETE_INDEX          = 11,
            LINEAR_SEARCH         = 12,
            BINARY_SEARCH         = 13,
            MAX                   = 14,
            MIN                   = 15,
            SUM                   = 16,
            AVG                   = 17,
            REVERSE               = 18,
            LEFT_SHIFT            = 19,
            RIGHT_SHIFT           = 20,
            LEFT_ROTATE           = 21,
            RIGHT_ROTATE          = 22,
            IS_SORTED             = 23,
            SORT                  = 24,
            INSERT_SORTED         = 25,
            CONCATENATE           = 26,
            MERGE                 = 27,
            UNION                 = 28,
            INTERSECTION          = 29,
            DIFFERENCE            = 30,
            BACK_TO_PREVIOUS_MENU = 31,
            EXIT_FROM_PROGRAM     = 32,
            MAX_COUNT             = EXIT_FROM_PROGRAM
        };
        int                        m_choice          { 0 };
        std::map<int, std::string> m_arrayADTMenuMap {};
        int                        m_size            { 0 };
        int                        m_length          { 0 };
        T*                         m_arr             { nullptr };

    public:
        ArrayADT(int);
        ~ArrayADT();
        const int             GetMinCase();
        const int             GetMaxCase();
        const int&            GetChoice();
        void                  GetChoiceInputFromUser();
        void	              PrintMenu();
        void                  PrintSelectedChoice();
        int                   GetSize();
        int                   GetLength();
        bool                  IsIndexInBounds(int);
        bool                  IsEmpty();
        bool                  IsFull();
        std::optional<T>      Get(int);
        bool                  Set(int, T);
        void                  Display();
        bool                  Insert(int, T);
        std::optional<T>      Remove(int);
        std::optional<int>    LinearSearch(T);
        std::optional<int>    BinarySearch(T);
        std::optional<T>      Max();
        std::optional<T>      Min();
        std::optional<T>      Sum();
        std::optional<double> Avg();
        void                  Reverse();
        void                  LeftShift(int, int);
        void                  RightShift(int, int);
        void                  LeftRotate(int, int);
        void                  RightRotate(int, int);
        bool                  IsSorted();
        void                  Sort();
        bool                  InsertSorted(T);

        template <class U>
        friend ArrayADT<U>*   Concatenate(ArrayADT<U>&, ArrayADT<U>&);

        template <class U>
        friend ArrayADT<U>*   SortedMerge(ArrayADT<U>&, ArrayADT<U>&);

        template <class U>
        friend ArrayADT<U>*   Union(ArrayADT<U>&, ArrayADT<U>&);
        
        template <class U>
        friend ArrayADT<U>*   Intersection(ArrayADT<U>&, ArrayADT<U>&);
        
        template <class U>
        friend ArrayADT<U>*   Difference(ArrayADT<U>&, ArrayADT<U>&);
    };
} // namespace arrayAdt

# include "ArrayADT.tpp"
