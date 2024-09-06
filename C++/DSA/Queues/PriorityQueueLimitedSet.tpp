#pragma once

#include "PriorityQueueLimitedSet.h"
#include "../../utils.h"

namespace queue
{
    template <class T>
    PriorityQueueLimitedSet<T>::PriorityQueueLimitedSet(int numPriorities):
        m_choice                         ( 0 ),
        m_priorityQueueLimitedSetMenuMap ( {} ),
        m_numPriorities                  { numPriorities },
        m_data                           { nullptr }
    {
        m_priorityQueueLimitedSetMenuMap.insert({ m_PriorityQueueLimitedSetMenu(IS_EMPTY),
                                                  std::string("Check if the queue is empty") });
        m_priorityQueueLimitedSetMenuMap.insert({ m_PriorityQueueLimitedSetMenu(DISPLAY),
                                                  std::string("Display the queue") });
        m_priorityQueueLimitedSetMenuMap.insert({ m_PriorityQueueLimitedSetMenu(NUM_ELEMENTS),
                                                  std::string("Number of elements in the queue") });
        m_priorityQueueLimitedSetMenuMap.insert({ m_PriorityQueueLimitedSetMenu(ENQUEUE),
                                                  std::string("Enqueue") });
        m_priorityQueueLimitedSetMenuMap.insert({ m_PriorityQueueLimitedSetMenu(DEQUEUE),
                                                  std::string("Dequeue") });
        m_priorityQueueLimitedSetMenuMap.insert({ m_PriorityQueueLimitedSetMenu(PEEK_FRONT),
                                                  std::string("Peek at front of the Queue") });
        m_priorityQueueLimitedSetMenuMap.insert({ m_PriorityQueueLimitedSetMenu(PEEK_PRIORITY),
                                                  std::string("Peek front of a particular priority") });
        m_priorityQueueLimitedSetMenuMap.insert({ m_PriorityQueueLimitedSetMenu(RESET),
                                                  std::string("Reset the queue") });
        m_priorityQueueLimitedSetMenuMap.insert({ m_PriorityQueueLimitedSetMenu(BACK_TO_PREVIOUS_MENU),
                                                  std::string("Back to Previous Menu") });
        m_priorityQueueLimitedSetMenuMap.insert({ m_PriorityQueueLimitedSetMenu(EXIT_FROM_PROGRAM),
                                                  std::string("Exit from program") });
        m_data = new queue::QueueUsingLinkedList<T>[m_numPriorities];
    }

    template <class T>
    PriorityQueueLimitedSet<T>::~PriorityQueueLimitedSet()
    {
        Reset();
        m_data = nullptr;
    }

    template <class T>
    const int PriorityQueueLimitedSet<T>::GetMinCase()
    {
        return m_PriorityQueueLimitedSetMenu::MIN_COUNT;
    }

    template <class T>
    const int PriorityQueueLimitedSet<T>::GetMaxCase()
    {
        return m_PriorityQueueLimitedSetMenu::MAX_COUNT;
    }

    template <class T>
    const int& PriorityQueueLimitedSet<T>::GetChoice()
    {
        return m_choice;
    }

    template <class T>
    void PriorityQueueLimitedSet<T>::GetChoiceInputFromUser()
    {
        utils::InputNumberFromUser(m_choice, 1, static_cast<int>(m_PriorityQueueLimitedSetMenu::MAX_COUNT));
    }

    template <class T>
    void PriorityQueueLimitedSet<T>::PrintMenu()
    {
        std::cout << std::endl;
        for (std::map<int, std::string>::iterator it = m_priorityQueueLimitedSetMenuMap.begin();
            it != m_priorityQueueLimitedSetMenuMap.end();
            it++)
        {
            std::cout << it->first << ". " << it->second << std::endl;
        }
        std::cout << "Please enter your choice: ";
    }

    template <class T>
    void PriorityQueueLimitedSet<T>::PrintSelectedChoice()
    {
        std::cout << std::endl << std::endl
                << "You have chosen choice "
                << m_priorityQueueLimitedSetMenuMap.at(m_choice)
                << std::endl;
    }

    template <class T>
    bool PriorityQueueLimitedSet<T>::IsEmpty()
    {
        for (int i = 0; i < m_numPriorities; i++)
        {
            if (not m_data[i].IsEmpty())
            {
                return false;
            }
        }
        return true;
    }
    
    template <class T>
    int PriorityQueueLimitedSet<T>::GetNumPriorities()
    {
        return m_numPriorities;
    }

    template <class T>
    void PriorityQueueLimitedSet<T>::Display()
    {
        if (IsEmpty())
        {
            std::cout << "The queue is empty" << std::endl;
        }
        else
        {
            for (int i = 0; i < m_numPriorities; i++)
            {
                std::cout << "Displaying priority: " << i + 1 << ":" << std::endl;
                m_data[i].Display();
            }
        }
    }

    template <class T>
    int PriorityQueueLimitedSet<T>::NumElements()
    {
        if (IsEmpty())
        {
            return 0;
        }
        else
        {
            int numElements = 0;
            for (int i = 0; i < m_numPriorities; i++)
            {
                numElements += m_data[i].NumElements();
            }
            return numElements;
        }
    }

    template <class T>
    bool PriorityQueueLimitedSet<T>::Enqueue(T element, int priority)
    {
        return m_data[priority - 1].Enqueue(element);
    }

    template <class T>
    std::optional<T> PriorityQueueLimitedSet<T>::Dequeue()
    {
        if (IsEmpty())
        {
            return std::nullopt;
        }
        for (int i = m_numPriorities; i >= 0; i--)
        {
            if (m_data[i - 1].IsEmpty())
            {
                continue;
            }
            else
            {
                return m_data[i - 1].Dequeue();
            }
        }
        return std::nullopt;
    }

    template <class T>
    std::optional<T> PriorityQueueLimitedSet<T>::PeekFront()
    {
        if (IsEmpty())
        {
            return std::nullopt;
        }
        return m_data[m_numPriorities - 1].Front();
    }

    template <class T>
    std::optional<T> PriorityQueueLimitedSet<T>::PeekPriority(int priority)
    {
        if (IsEmpty())
        {
            return std::nullopt;
        }
        return m_data[priority - 1].Front();
    }

    template <class T>
    void PriorityQueueLimitedSet<T>::Reset()
    {
        for (int i = 0; i < m_numPriorities; i++)
        {
            m_data[i].Reset();
        }
    }
} //namespace queue
