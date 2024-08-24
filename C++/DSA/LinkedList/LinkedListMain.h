#pragma once

#include <map>
#include <string>
#include <optional>
#include <iostream>
#include "LinearSinglyLinkedList.h"
#include "CircularSinglyLinkedList.h"

namespace linkedList
{
    class LinkedListMain
    {
    private:
        enum m_LinkedListMainMenu
        {
            MIN_COUNT                 = 0,
            LINEAR_SINGLY_LINKED_LIST = 1,
            CIRCULAR_SINGLY_LINKED_LIST = 2,
            BACK_TO_PREVIOUS_MENU     = 3,
            EXIT_FROM_PROGRAM         = 4,
            MAX_COUNT                 = EXIT_FROM_PROGRAM
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
    };
} // namespace linkedList
