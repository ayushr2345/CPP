#pragma once

#include <map>
#include <string>
#include <optional>
#include <iostream>
#include "QueueUsingArray.h"
#include "CircularQueue.h"
#include "QueueUsingLinkedList.h"

namespace queue
{
    class QueueMain
    {
    private:
        enum m_QueueMainMenu
        {
            MIN_COUNT                   = 0,
            QUEUE_USING_ARRAY           = 1,
            CIRCULAR_QUEUE              = 2,
            QUEUE_USING_LINKED_LIST     = 3,
            DOUBLE_ENDED_QUEUE          = 4,
            PRIORITY_QUEUE_LIMITED_SET  = 5,
            PRIORITY_QUEUE_ELEMENT      = 6,
            QUEUE_USING_TWO_STACKS      = 7,
            BACK_TO_PREVIOUS_MENU       = 8,
            EXIT_FROM_PROGRAM           = 9,
            MAX_COUNT                   = EXIT_FROM_PROGRAM
        };
        int                        m_choice           { 0 };
        std::map<int, std::string> m_queueMainMenuMap { };

    public:
        QueueMain();
        const int   GetMinCase();
        const int   GetMaxCase();
        const int&  GetChoice();
        void        GetChoiceInputFromUser();
        void	    PrintMenu();
        void        PrintSelectedChoice();
        void        QueueUsingArray();
        void        CircularQueue();
        void        QueueUsingLinkedList();
    };
} // namespace queue
