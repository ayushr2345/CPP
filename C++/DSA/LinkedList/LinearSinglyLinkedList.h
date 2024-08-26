#pragma once

#include <map>
#include <string>
#include <optional>
#include <iostream>

namespace linkedList
{
    template <class T>
    class LinearSinglyLinkedList
    {
    private:
        enum m_LinearSinglyLinkedListMenu
        {
            MIN_COUNT             = 0,
            IS_EMPTY              = 1,
            GET                   = 2,
            DISPLAY               = 3,
            INSERT_BEGINNING      = 4,
            INSERT_END            = 5,
            INSERT_INDEX          = 6,
            DELETE_BEGINNING      = 7,
            DELETE_END            = 8,
            DELETE_INDEX          = 9,
            LINEAR_SEARCH         = 10,
            MAX                   = 11,
            MIN                   = 12,
            SUM                   = 13,
            AVG                   = 14,
            REVERSE               = 15,
            IS_SORTED             = 16,
            SORT                  = 17,
            INSERT_SORTED         = 18,
            CONCATENATE           = 19,
            MERGE                 = 20,
            BACK_TO_PREVIOUS_MENU = 21,
            EXIT_FROM_PROGRAM     = 22,
            MAX_COUNT             = EXIT_FROM_PROGRAM
        };
        class Node
        {
        public:
            T     m_m_data;
            Node* m_m_next;
        };
        int                        m_choice                        { 0 };
        std::map<int, std::string> m_linearSinglyLinkedListMenuMap {};
        Node*                      m_head                          { nullptr };

    public:
        LinearSinglyLinkedList();
        ~LinearSinglyLinkedList();
        const int             GetMinCase();
        const int             GetMaxCase();
        const int&            GetChoice();
        void                  GetChoiceInputFromUser();
        void	              PrintMenu();
        void                  PrintSelectedChoice();
        int                   GetSize();
        Node*                 MoveToIndex(int);
        bool                  IsIndexInBounds(int);
        bool                  IsEmpty();
        std::optional<T>      Get(int);
        void                  Display();
        bool                  Insert(int, T);
        std::optional<T>      Remove(int);
        std::optional<int>    LinearSearch(T);
        std::optional<T>      Max();
        std::optional<T>      Min();
        std::optional<T>      Sum();
        std::optional<double> Avg();
        void                  Reverse();
        bool                  IsSorted();
        void                  Sort();
        bool                  InsertSorted(T);

        template <class U>
        friend LinearSinglyLinkedList<U>* Concatenate(LinearSinglyLinkedList<U>&, LinearSinglyLinkedList<U>&);

        template <class U>
        friend LinearSinglyLinkedList<U>* SortedMerge(LinearSinglyLinkedList<U>&, LinearSinglyLinkedList<U>&);
    };
} // namespace linkedList

# include "LinearSinglyLinkedList.tpp"
