#pragma once

#include "HeapSort.h"
#include "../../utils.h"

namespace sorting_algorithms
{
    /*****************************
     ****** PRIVATE METHODS ******
    *****************************/

    template <class T>
    void HeapSort<T>::Swap(T& elementA, T& elementB)
    {
        T temp = elementA;
        elementA = elementB;
        elementB = temp;
    }

    template <class T>
    void HeapSort<T>::HeapifyHelper(T* arr, int index)
    {
        int largestIndex = index;
        int leftChildIndex = 2 * largestIndex;
        int rightChildIndex = 2 * largestIndex + 1;

        if (arr[largestIndex] < arr[leftChildIndex] or arr[largestIndex] < arr[rightChildIndex])
        {
            if (arr[leftChildIndex] > arr[rightChildIndex] and arr[leftChildIndex] > arr[largestIndex])
            {
                T temp = arr[largestIndex];
                arr[largestIndex] = arr[leftChildIndex];
                arr[leftChildIndex] = temp;
                HeapifyHelper(arr, leftChildIndex);
            }
            else if (arr[rightChildIndex] > arr[leftChildIndex] and arr[rightChildIndex] > arr[largestIndex])
            {
                T temp = arr[largestIndex];
                arr[largestIndex] = arr[rightChildIndex];
                arr[rightChildIndex] = temp;
                HeapifyHelper(arr, rightChildIndex);
            }
        }
    }

    template <class T>
    void HeapSort<T>::Heapify(T* arr, const int size)
    {
        for (int i = size / 2; i >= 1; i--)
        {
            HeapifyHelper(arr, i);
        }
    }

    template <class T>
    void HeapSort<T>::DeleteFromHeap(T* arr, int size)
    {
        T deleted = arr[1];
        arr[1] = arr[size];
        size--;

        int i = 1;
        while (2 * i <= size)
        {
            int leftChild = 2 * i;
            int rightChild = 2 * i + 1;

            int largest = i;

            if (leftChild <= size && arr[leftChild] > arr[largest])
            {
                largest = leftChild;
            }
            if (rightChild <= size && arr[rightChild] > arr[largest])
            {
                largest = rightChild;
            }

            if (largest != i)
            {
                T temp = arr[i];
                arr[i] = arr[largest];
                arr[largest] = temp;

                i = largest;
            }
            else
            {
                break;
            }
        }
        arr[size + 1] = deleted;
        // return deleted;
    }

    /*****************************
     **** PRIVATE METHODS END ****
    *****************************/

    template <class T>
    HeapSort<T>::HeapSort(int size):
        m_choice          ( 0 ),
        m_heapSortMenuMap ( {} ),
        m_size            ( size ),
        m_data            { nullptr }
    {
        m_heapSortMenuMap.insert({ m_HeapSortMenu(SHOWCASE_HEAP_SORT),
                                   std::string("Showcase heap sort") });
        m_heapSortMenuMap.insert({ m_HeapSortMenu(SHOWCASE_HEAP_SORT_ACTION),
                                   std::string("Showcase heap sort in action") });
        m_heapSortMenuMap.insert({ m_HeapSortMenu(INSERT_ELEMENTS_IN_ARRAY),
                                   std::string("Insert elements in array") });
        m_heapSortMenuMap.insert({ m_HeapSortMenu(PERFORM_HEAP_SORT),
                                   std::string("Perform heap sort") });
        m_heapSortMenuMap.insert({ m_HeapSortMenu(DISPLAY_ARRAY),
                                   std::string("Display array") });
        m_heapSortMenuMap.insert({ m_HeapSortMenu(BACK_TO_PREVIOUS_MENU),
                                   std::string("Back to Previous Menu") });
        m_heapSortMenuMap.insert({ m_HeapSortMenu(EXIT_FROM_PROGRAM),
                                   std::string("Exit from program") });
        m_data = new T[m_size];
        for (int i = 0; i < m_size; i++)
        {
            m_data[i] = 0;
        }
    }

    template <class T>
    HeapSort<T>::~HeapSort()
    {
        delete m_data;
        m_data = nullptr;
    }
    
    template <class T>
    const int HeapSort<T>::GetMinCase()
    {
        return m_HeapSortMenu::MIN_COUNT;
    }

    template <class T>
    const int HeapSort<T>::GetMaxCase()
    {
        return m_HeapSortMenu::MAX_COUNT;
    }

    template <class T>
    const int& HeapSort<T>::GetChoice()
    {
        return m_choice;
    }

    template <class T>
    void HeapSort<T>::GetChoiceInputFromUser()
    {
        utils::InputNumberFromUser(m_choice, 1, static_cast<int>(m_HeapSortMenu::MAX_COUNT));
    }

    template <class T>
    void HeapSort<T>::PrintMenu()
    {
        std::cout << std::endl;
        for (std::map<int, std::string>::iterator it = m_heapSortMenuMap.begin();
            it != m_heapSortMenuMap.end();
            it++)
        {
            std::cout << it->first << ". " << it->second << std::endl;
        }
        std::cout << "Please enter your choice: ";
    }

    template <class T>
    void HeapSort<T>::PrintSelectedChoice()
    {
        std::cout << std::endl << std::endl
                << "You have chosen choice "
                << m_heapSortMenuMap.at(m_choice)
                << std::endl;
    }

    template <class T>
    void HeapSort<T>::ShowcaseHeapSort()
    {
        std::cout << "Quick Sort is an O(N * logN) sorting algorithm. It makes use of a heap to sort the elements. A max heap is a complete binary tree where each parent >= its children."
                  << " Deletion is done from the root node of the tree and hence the largest element is deleted first and if we store the largest deleted element at the end of array"
                  << " and if the complete heap is deleted, then we get a sorted array." << std::endl;
    }

    template <class T>
    void HeapSort<T>::ShowcaseHeapSortAction()
    {
        std::cout << "To showcase the working of Heap Sort, we take an array of 5 elements consisting: "
                  << " 8, 10, 3, 1, 2" << std::endl;
        int arr[] = {0, 8, 10, 3, 1, 2};
        int size = 5;

        Heapify(arr, size);
        std::cout << "Then we heapify the array which results in the following array: ";
        for (int i = 1; i <= size; i++)
        {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;

        std::cout << "The we delete all the elements from the array one by one and finally our array will be sorted" << std::endl;

        for (int i = 1; i <= size; i++)
        {
            DeleteFromHeap(arr, size + 1 - i);
        }
        for (int i = 1; i <= size; i++)
        {
            std::cout << arr[i] << " ";
        }
    }

    template <class T>
    bool HeapSort<T>::DoesDataExist()
    {
        return m_data[1] == 0 ? false : true;
    }

    template <class T>
    void HeapSort<T>::InsertElements()
    {
        if (DoesDataExist())
        {
            std::cout << "Data already exists, overwriting the array" << std::endl;
        }
        std::cout << "Please enter the elements ( " << m_size - 1 << " ) of the array: " << std::endl; 
        for (int i = 1; i < m_size; i++)
        {
            utils::InputNumberFromUser(m_data[i]);
        }
    }

    template <class T>
    bool HeapSort<T>::PerformHeapSort()
    {
        if (not DoesDataExist())
        {
            return false;
        }

        Heapify(m_data, m_size - 1);
        m_sizeHeap = 5;
        for (int i = 1; i < m_size; i++)
        {
            DeleteFromHeap(m_data, m_sizeHeap);
            m_sizeHeap--;
        }
        return true;
    }

    template <class T>
    void HeapSort<T>::DisplayArray()
    {
        if (DoesDataExist())
        {
            for (int i = 1; i < m_size; i++)
            {
                std::cout << m_data[i] << " ";
            }
            std::cout << std::endl;
        }
    }
} //namespace sorting_algorithms
