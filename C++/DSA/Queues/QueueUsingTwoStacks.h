#pragma once

#include <map>
#include <string>
#include <optional>
#include <iostream>
#include "../Stack/StackUsingLinkedList.h"

namespace queue
{
    template <class T>
    class QueueUsingTwoStacks
    {
    private:
        enum m_QueueUsingTwoStacksMenu
        {
            MIN_COUNT             = 0,
            IS_EMPTY              = 1,
            DISPLAY               = 2,
            ENQUEUE               = 3,
            DEQUEUE               = 4,
            FRONT                 = 5,
            REAR                  = 6,
            RESET                 = 7,
            BACK_TO_PREVIOUS_MENU = 8,
            EXIT_FROM_PROGRAM     = 9,
            MAX_COUNT             = EXIT_FROM_PROGRAM
        };

        int                             m_choice                     { 0 };
        std::map<int, std::string>      m_queueUsingTwoStacksMenuMap {};
        stack::StackUsingLinkedList<T>* m_dataEnqueue                { nullptr };
        stack::StackUsingLinkedList<T>* m_dataDequeue                { nullptr };
    public:
        QueueUsingTwoStacks();
        ~QueueUsingTwoStacks();
        const int        GetMinCase();
        const int        GetMaxCase();
        const int&       GetChoice();
        void             GetChoiceInputFromUser();
        void	         PrintMenu();
        void             PrintSelectedChoice();
        bool             IsEmpty();
        void             Display();
        bool             Enqueue(T);
        std::optional<T> Dequeue();
        std::optional<T> Front();
        std::optional<T> Rear();
        void             Reset();
    };
} // namespace queue

# include "QueueUsingTwoStacks.tpp"
