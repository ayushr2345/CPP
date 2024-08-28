#pragma once

#include <map>
#include <string>
#include <optional>
#include <iostream>
#include "LinearSinglyLinkedList.h"
#include "CircularSinglyLinkedList.h"
#include "LinearDoublyLinkedList.h"
#include "CircularDoublyLinkedList.h"
#include "SparseMatrix.h"

namespace linkedList
{
    class LinkedListMain
    {
    private:
        enum m_LinkedListMainMenu
        {
            MIN_COUNT                   = 0,
            LINEAR_SINGLY_LINKED_LIST   = 1,
            CIRCULAR_SINGLY_LINKED_LIST = 2,
            LINEAR_DOUBLY_LINKED_LIST   = 3,
            CIRCULAR_DOUBLY_LINKED_LIST = 4,
            SPARSE_MATRIX               = 5,
            SPARSE_MATRIX_ADDITION      = 6,
            BACK_TO_PREVIOUS_MENU       = 7,
            EXIT_FROM_PROGRAM           = 8,
            MAX_COUNT                   = EXIT_FROM_PROGRAM
        };
        int                        m_choice                { 0 };
        std::map<int, std::string> m_linkedListMainMenuMap {};

    public:
        LinkedListMain();
        const int  GetMinCase();
        const int  GetMaxCase();
        const int& GetChoice();
        void       GetChoiceInputFromUser();
        void	   PrintMenu();
        void       PrintSelectedChoice();
        void       LinearSinglyLinkedList();
        void       CircularSinglyLinkedList();
        void       LinearDoublyLinkedList();
        void       CircularDoublyLinkedList();
        void       SparseMatrixUsingLinkedList();
        void       SparseMatrixAdditionUsingLinkedList();
    };
} // namespace linkedList
