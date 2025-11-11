#pragma once

#include <map>
#include <string>
#include <optional>
#include <iostream>

// for queue using two stacks from scratch,
// need a stack from scratch
// for a stack from scratch need a linked list from scratch



namespace queue
{
    template <class T>
    class LinkedListFromScratch
    {
    private:
        class Node
        {
        public:
            T     m_m_data {};
            Node* m_m_next { nullptr };
        };
        Node* m_head { nullptr };
    public:
        LinkedListFromScratch();
        ~LinkedListFromScratch();
        bool                 IsEmpty();
        int                  GetSize();
        bool                 IsIndexOutOfBounds(const int);
        std::optional<Node*> GetNodeFromIndex(int);
        bool                 Insert(const T, const int);
        std::optional<T>     Remove(const int);
    };

    template <class T>
    class StackFromScratch
    {

    };

    template <class T>
    class QueueUsingTwoStacksFromScratch
    {
    private:
        enum m_QueueUsingTwoStacksFromScratchMenu
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
        std::map<int, std::string>      m_QueueUsingTwoStacksFromScratchMenuMap {};
        stack::StackUsingLinkedList<T>* m_dataEnqueue                { nullptr };
        stack::StackUsingLinkedList<T>* m_dataDequeue                { nullptr };
    public:
        QueueUsingTwoStacksFromScratch();
        ~QueueUsingTwoStacksFromScratch();
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

# include "QueueUsingTwoStacksFromScratch.tpp"
