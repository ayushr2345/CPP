#pragma once

#include <map>
#include <string>
#include <optional>
#include <iostream>
#include <vector>

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
        bool                          IsEmpty();
        int                           GetSize();
        bool                          IsIndexOutOfBounds(const int);
        std::optional<Node*>          GetNodeFromIndex(int);
        bool                          Insert(const T, const int);
        std::optional<T>              Remove(const int);
        std::optional<std::vector<T>> GetElements(const bool forward = true);
    };

    template <class T>
    class StackFromScratch
    {
    private:
		LinkedListFromScratch<T>* m_data { nullptr };
    public:
        StackFromScratch();
        ~StackFromScratch();
        bool             IsEmpty();
        bool             Push(const T);
        std::optional<T> Pop();
        std::optional<T> GetTop();
        void             Display(const bool forward = true);
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

        int                         m_choice                                { 0 };
        std::map<int, std::string>  m_QueueUsingTwoStacksFromScratchMenuMap {};
        StackFromScratch<T>*        m_dataEnqueue                           { nullptr };
        StackFromScratch<T>*        m_dataDequeue                           { nullptr };
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
        bool             Enqueue(const T);
        std::optional<T> Dequeue();
        std::optional<T> Front();
        std::optional<T> Rear();
        void             Reset();
    };
} // namespace queue

# include "QueueUsingTwoStacksFromScratch.tpp"
