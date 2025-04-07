#pragma once

#include "Heapify.h"
#include "../../utils.h"

namespace heap
{
    template <class T>
    Heapify<T>::Heapify(int size):
        m_choice         ( 0 ),
        m_heapifyMenuMap ( {} ),
        m_size           ( size ),
        m_numElements    ( 0 ),
        m_sizeHeap       ( 0 ),
        m_data           { nullptr }
    {
        m_heapifyMenuMap.insert({ m_HeapifyMenu(DOES_HEAP_EXIST),
                                  std::string("Does heap exist") });
        m_heapifyMenuMap.insert({ m_HeapifyMenu(TAKE_INPUT_FOR_THE_ARRAY),
                                  std::string("Take input for the array") });
        m_heapifyMenuMap.insert({ m_HeapifyMenu(MAX_HEAP_HEAPIFY),
                                  std::string("Max heap heapify") });
        m_heapifyMenuMap.insert({ m_HeapifyMenu(MIN_HEAP_HEAPIFY),
                                  std::string("Min heap heapify") });
        m_heapifyMenuMap.insert({ m_HeapifyMenu(DISPLAY_HEAP),
                                  std::string("Display heap") });
        m_heapifyMenuMap.insert({ m_HeapifyMenu(DISPLAY_ARRAY),
                                  std::string("Display array") });
        m_heapifyMenuMap.insert({ m_HeapifyMenu(RESET_HEAP),
                                  std::string("Reset Heap") });
        m_heapifyMenuMap.insert({ m_HeapifyMenu(BACK_TO_PREVIOUS_MENU),
                                  std::string("Back to Previous Menu") });
        m_heapifyMenuMap.insert({ m_HeapifyMenu(EXIT_FROM_PROGRAM),
                                  std::string("Exit from program") });
        m_data = new T[m_size];
    }

    template <class T>
    Heapify<T>::~Heapify()
    {
        ResetHeap();
        delete m_data;
    }
    
    template <class T>
    const int Heapify<T>::GetMinCase()
    {
        return m_HeapifyMenu::MIN_COUNT;
    }

    template <class T>
    const int Heapify<T>::GetMaxCase()
    {
        return m_HeapifyMenu::MAX_COUNT;
    }

    template <class T>
    const int& Heapify<T>::GetChoice()
    {
        return m_choice;
    }

    template <class T>
    void Heapify<T>::GetChoiceInputFromUser()
    {
        utils::InputNumberFromUser(m_choice, 1, static_cast<int>(m_HeapifyMenu::MAX_COUNT));
    }

    template <class T>
    void Heapify<T>::PrintMenu()
    {
        std::cout << std::endl;
        for (std::map<int, std::string>::iterator it = m_heapifyMenuMap.begin();
            it != m_heapifyMenuMap.end();
            it++)
        {
            std::cout << it->first << ". " << it->second << std::endl;
        }
        std::cout << "Please enter your choice: ";
    }

    template <class T>
    void Heapify<T>::PrintSelectedChoice()
    {
        std::cout << std::endl << std::endl
                << "You have chosen choice "
                << m_heapifyMenuMap.at(m_choice)
                << std::endl;
    }

    template <class T>
    bool Heapify<T>::DoesHeapExist()
    {
        return m_sizeHeap > 0 ? true : false;
    }

    template <class T>
    void Heapify<T>::TakeInputForTheArray()
    {
        ResetHeap();

        std::cout << "Please enter the number of elements of the heap: ";
        int numElements = 0;
        utils::InputNumberFromUser(numElements, 1, m_size - 1);
        m_numElements = numElements;
        m_sizeHeap = numElements;
        std::cout << "Please enter the elements of the heap one by one: ";
        for (int i = 1; i <= numElements; i++)
        {
            utils::InputNumberFromUser(m_data[i]);
        }
    }

    template <class T>
    void Heapify<T>::MaxHeapHeapifyHelper(const int index)
    {
        int largestIndex = index;
        int leftChildIndex = 2 * largestIndex;
        int rightChildIndex = 2 * largestIndex + 1;

        if (m_data[largestIndex] < m_data[leftChildIndex] or m_data[largestIndex] < m_data[rightChildIndex])
        {
            if (m_data[leftChildIndex] > m_data[rightChildIndex] and m_data[leftChildIndex] > m_data[largestIndex])
            {
                T temp = m_data[largestIndex];
                m_data[largestIndex] = m_data[leftChildIndex];
                m_data[leftChildIndex] = temp;
                MaxHeapHeapifyHelper(leftChildIndex);
            }
            else if (m_data[rightChildIndex] > m_data[leftChildIndex] and m_data[rightChildIndex] > m_data[largestIndex])
            {
                T temp = m_data[largestIndex];
                m_data[largestIndex] = m_data[rightChildIndex];
                m_data[rightChildIndex] = temp;
                MaxHeapHeapifyHelper(rightChildIndex);
            }
        }
    }

    template <class T>
    void Heapify<T>::MaxHeapHeapify()
    {
        for (int i = m_sizeHeap / 2; i >= 1; i--)
        {
            MaxHeapHeapifyHelper(i);
        }
    }

    template <class T>
    void Heapify<T>::MinHeapHeapifyHelper(const int index)
    {
        int smallestIndex = index;
        int leftChildIndex = 2 * smallestIndex;
        int rightChildIndex = 2 * smallestIndex + 1;

        if (m_data[smallestIndex] > m_data[leftChildIndex] or m_data[smallestIndex] > m_data[rightChildIndex])
        {
            if (m_data[leftChildIndex] < m_data[rightChildIndex] and m_data[leftChildIndex] < m_data[smallestIndex])
            {
                T temp = m_data[smallestIndex];
                m_data[smallestIndex] = m_data[leftChildIndex];
                m_data[leftChildIndex] = temp;
                MaxHeapHeapifyHelper(leftChildIndex);
            }
            else if (m_data[rightChildIndex] < m_data[leftChildIndex] and m_data[rightChildIndex] < m_data[smallestIndex])
            {
                T temp = m_data[smallestIndex];
                m_data[smallestIndex] = m_data[rightChildIndex];
                m_data[rightChildIndex] = temp;
                MaxHeapHeapifyHelper(rightChildIndex);
            }
        }
    }

    template <class T>
    void Heapify<T>::MinHeapHeapify()
    {
        for (int i = m_sizeHeap / 2; i >= 1; i--)
        {
            MinHeapHeapifyHelper(i);
        }
    }

    template <class T>
    void Heapify<T>::DisplayHeap()
    {
        if (m_sizeHeap > 0)
        {
            for (int i = 1; i <= m_sizeHeap; i++)
            {
                std::cout << m_data[i] << " ";
            }
            std::cout << std::endl;
        }
    }

    template <class T>
    void Heapify<T>::DisplayArray()
    {
        if (m_numElements > 0)
        {
            for (int i = 1; i <= m_numElements; i++)
            {
                std::cout << m_data[i] << " ";
            }
            std::cout << std::endl;
        }
        else
        {
            std::cout << "There are no elements in the array" << std::endl;
        }
    }

    template <class T>
    void Heapify<T>::ResetHeap()
    {
        for (int i = 0; i <= m_sizeHeap; i++)
        {
            m_data[i] = 0;
        }
        m_numElements = 0;
        m_sizeHeap = 0;
    }
} //namespace heap
