#pragma once

#include "PriorityQueuesUsingHeaps.h"
#include "../../utils.h"

namespace heap
{
    template <class T>
    PriorityQueuesUsingHeaps<T>::PriorityQueuesUsingHeaps(int typeOfHeap):
        m_choice                          ( 0 ),
        m_priorityQueuesUsingHeapsMenuMap ( {} ),
        m_currentHeapType                 (  )
    {
        m_priorityQueuesUsingHeapsMenuMap.insert({ m_PriorityQueuesUsingHeapsMenu(ENQUEUE),
                                                   std::string("Enqueue") });
        m_priorityQueuesUsingHeapsMenuMap.insert({ m_PriorityQueuesUsingHeapsMenu(DEQUEUE),
                                                  std::string("Dequeue") });
        m_priorityQueuesUsingHeapsMenuMap.insert({ m_PriorityQueuesUsingHeapsMenu(DISPLAY_HEAP),
                                                   std::string("Display heap") });
        m_priorityQueuesUsingHeapsMenuMap.insert({ m_PriorityQueuesUsingHeapsMenu(DISPLAY_ARRAY),
                                                   std::string("Display array") });
        m_priorityQueuesUsingHeapsMenuMap.insert({ m_PriorityQueuesUsingHeapsMenu(BACK_TO_PREVIOUS_MENU),
                                                   std::string("Back to Previous Menu") });
        m_priorityQueuesUsingHeapsMenuMap.insert({ m_PriorityQueuesUsingHeapsMenu(EXIT_FROM_PROGRAM),
                                                   std::string("Exit from program") });
        if (typeOfHeap == 1)
        {
            m_currentHeapType = m_TypeOfHeap::MAX_HEAP;
            std::cout << "Please enter the max number of elements in the priority queue: ";
            int elements;
            utils::InputNumberFromUser(elements, 0, 20);
            std::cout << "Creating an array of " << elements + 1 << " size to store the elements in the max heap" << std::endl;
            m_maxHeap = new MaxHeap<T>(elements + 1);
        }
        else
        {
            m_currentHeapType = m_TypeOfHeap::MIN_HEAP;
            std::cout << "Please enter the max number of elements in the priority queue: ";
            int elements;
            utils::InputNumberFromUser(elements, 0, 20);
            std::cout << "Creating an array of " << elements + 1 << " size to store the elements in the min heap" << std::endl;
            m_minHeap = new MinHeap<T>(elements + 1);
        }
    }

    template <class T>
    PriorityQueuesUsingHeaps<T>::~PriorityQueuesUsingHeaps()
    {
        ResetHeap();
        if (m_currentHeapType == m_TypeOfHeap::MAX_HEAP)
        {
            delete m_maxHeap;
        }
        else
        {
            delete m_minHeap;
        }
        m_currentHeapType = {};
        m_maxHeap = nullptr;
        m_minHeap = nullptr;
    }
    
    template <class T>
    const int PriorityQueuesUsingHeaps<T>::GetMinCase()
    {
        return m_PriorityQueuesUsingHeapsMenu::MIN_COUNT;
    }

    template <class T>
    const int PriorityQueuesUsingHeaps<T>::GetMaxCase()
    {
        return m_PriorityQueuesUsingHeapsMenu::MAX_COUNT;
    }

    template <class T>
    const int& PriorityQueuesUsingHeaps<T>::GetChoice()
    {
        return m_choice;
    }

    template <class T>
    void PriorityQueuesUsingHeaps<T>::GetChoiceInputFromUser()
    {
        utils::InputNumberFromUser(m_choice, 1, static_cast<int>(m_PriorityQueuesUsingHeapsMenu::MAX_COUNT));
    }

    template <class T>
    void PriorityQueuesUsingHeaps<T>::PrintMenu()
    {
        std::cout << std::endl;
        for (std::map<int, std::string>::iterator it = m_priorityQueuesUsingHeapsMenuMap.begin();
            it != m_priorityQueuesUsingHeapsMenuMap.end();
            it++)
        {
            std::cout << it->first << ". " << it->second << std::endl;
        }
        std::cout << "Please enter your choice: ";
    }

    template <class T>
    void PriorityQueuesUsingHeaps<T>::PrintSelectedChoice()
    {
        std::cout << std::endl << std::endl
                << "You have chosen choice "
                << m_priorityQueuesUsingHeapsMenuMap.at(m_choice)
                << std::endl;
    }

    template <class T>
    bool PriorityQueuesUsingHeaps<T>::Enqueue(const int element)
    {
        if (m_currentHeapType == m_TypeOfHeap::MAX_HEAP)
        {
            return m_maxHeap->InsertInHeap(element);
        }
        else
        {
            return m_minHeap->InsertInHeap(element);
        }
    }

    template <class T>
    T PriorityQueuesUsingHeaps<T>::Dequeue()
    {
        if (m_currentHeapType == m_TypeOfHeap::MAX_HEAP)
        {
            return m_maxHeap->DeleteFromHeap();
        }
        else
        {
            return m_minHeap->DeleteFromHeap();
        }
    }

    template <class T>
    void PriorityQueuesUsingHeaps<T>::DisplayHeap()
    {
        if (m_currentHeapType == m_TypeOfHeap::MAX_HEAP)
        {
            return m_maxHeap->DisplayHeap();
        }
        else
        {
            return m_minHeap->DisplayHeap();
        }
    }

    template <class T>
    void PriorityQueuesUsingHeaps<T>::DisplayArray()
    {
        if (m_currentHeapType == m_TypeOfHeap::MAX_HEAP)
        {
            return m_maxHeap->DisplayArray();
        }
        else
        {
            return m_minHeap->DisplayArray();
        }
    }

    template <class T>
    void PriorityQueuesUsingHeaps<T>::ResetHeap()
    {
        if (m_currentHeapType == m_TypeOfHeap::MAX_HEAP)
        {
            return m_maxHeap->ResetHeap();
        }
        else
        {
            return m_minHeap->ResetHeap();
        }
    }
} //namespace heap
