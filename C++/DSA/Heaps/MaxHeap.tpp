#pragma once

#include "MaxHeap.h"
#include "../../utils.h"

namespace heap
{
    template <class T>
    MaxHeap<T>::MaxHeap(int size):
        m_choice         ( 0 ),
        m_maxHeapMenuMap ( {} ),
        m_size           ( size ),
        m_numElements    ( 0 ),
        m_sizeHeap       ( 0 ),
        m_data           { nullptr }
    {
        m_maxHeapMenuMap.insert({ m_MaxHeapMenu(DOES_HEAP_EXIST),
                                  std::string("Does heap exist") });
        m_maxHeapMenuMap.insert({ m_MaxHeapMenu(INSERT_IN_HEAP),
                                  std::string("Insert in heap") });
        m_maxHeapMenuMap.insert({ m_MaxHeapMenu(DELETE_FROM_HEAP),
                                  std::string("Delete from heap") });
        m_maxHeapMenuMap.insert({ m_MaxHeapMenu(DISPLAY_HEAP),
                                  std::string("Display heap") });
        m_maxHeapMenuMap.insert({ m_MaxHeapMenu(DISPLAY_ARRAY),
                                  std::string("Display array") });
        m_maxHeapMenuMap.insert({ m_MaxHeapMenu(HEAP_SORT),
                                  std::string("Sort the heap") });
        m_maxHeapMenuMap.insert({ m_MaxHeapMenu(RESET_HEAP),
                                  std::string("Reset Heap") });
        m_maxHeapMenuMap.insert({ m_MaxHeapMenu(BACK_TO_PREVIOUS_MENU),
                                  std::string("Back to Previous Menu") });
        m_maxHeapMenuMap.insert({ m_MaxHeapMenu(EXIT_FROM_PROGRAM),
                                  std::string("Exit from program") });
        m_data = new T[m_size];
    }

    template <class T>
    MaxHeap<T>::~MaxHeap()
    {
        ResetHeap();
        delete m_data;
    }
    
    template <class T>
    const int MaxHeap<T>::GetMinCase()
    {
        return m_MaxHeapMenu::MIN_COUNT;
    }

    template <class T>
    const int MaxHeap<T>::GetMaxCase()
    {
        return m_MaxHeapMenu::MAX_COUNT;
    }

    template <class T>
    const int& MaxHeap<T>::GetChoice()
    {
        return m_choice;
    }

    template <class T>
    void MaxHeap<T>::GetChoiceInputFromUser()
    {
        utils::InputNumberFromUser(m_choice, 1, static_cast<int>(m_MaxHeapMenu::MAX_COUNT));
    }

    template <class T>
    void MaxHeap<T>::PrintMenu()
    {
        std::cout << std::endl;
        for (std::map<int, std::string>::iterator it = m_maxHeapMenuMap.begin();
            it != m_maxHeapMenuMap.end();
            it++)
        {
            std::cout << it->first << ". " << it->second << std::endl;
        }
        std::cout << "Please enter your choice: ";
    }

    template <class T>
    void MaxHeap<T>::PrintSelectedChoice()
    {
        std::cout << std::endl << std::endl
                << "You have chosen choice "
                << m_maxHeapMenuMap.at(m_choice)
                << std::endl;
    }

    template <class T>
    bool MaxHeap<T>::DoesHeapExist()
    {
        return m_sizeHeap > 0 ? true : false;
    }

    template <class T>
    bool MaxHeap<T>::InsertInHeap(const int element)
    {
        if (m_numElements == m_size)
        {
            return 0;
        }
        else
        {
            m_data[m_sizeHeap + 1] = element;
            m_sizeHeap++;
            m_numElements++;
            int i = m_sizeHeap;
            while (i > 1)
            {
                if (m_data[i] > m_data[i / 2])
                {
                    int temp = m_data[i];
                    m_data[i] = m_data[i / 2];
                    m_data[i / 2] = temp;
                }
                i = i / 2;
            }
            return 1;
        }
    }

    template <class T>
    T MaxHeap<T>::DeleteFromHeap()
    {
        if (m_sizeHeap == 0)
        {
            return 0;
        }
        else
        {
            T deleted = m_data[1];
            m_data[1] = m_data[m_sizeHeap];
            m_sizeHeap--;
    

            int i = 1;
            while (2 * i <= m_sizeHeap)
            {
                int leftChild = 2 * i;
                int rightChild = 2 * i + 1;
    
                int largest = i;
    
                if (leftChild <= m_sizeHeap && m_data[leftChild] > m_data[largest])
                {
                    largest = leftChild;
                }

                if (rightChild <= m_sizeHeap && m_data[rightChild] > m_data[largest])
                {
                    largest = rightChild;
                }
    
                if (largest != i)
                {
                    T temp = m_data[i];
                    m_data[i] = m_data[largest];
                    m_data[largest] = temp;
    
                    i = largest;
                }
                else
                {
                    break;
                }
            }
            m_data[m_sizeHeap + 1] = deleted;
            return deleted;
        }
    }
    

    template <class T>
    void MaxHeap<T>::DisplayHeap()
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
    void MaxHeap<T>::DisplayArray()
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
    void MaxHeap<T>::HeapSort()
    {
        if (DoesHeapExist())
        {
            while (m_sizeHeap)
            {
                DeleteFromHeap();
            }
        }
    }

    template <class T>
    void MaxHeap<T>::ResetHeap()
    {
        for (int i = 0; i <= m_sizeHeap; i++)
        {
            m_data[i] = 0;
        }
        m_numElements = 0;
        m_sizeHeap = 0;
    }
} //namespace heap
