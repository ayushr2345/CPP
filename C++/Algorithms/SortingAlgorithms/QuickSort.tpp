#pragma once

#include "QuickSort.h"
#include "../../utils.h"

namespace sorting_algorithms
{
    /*****************************
     ****** PRIVATE METHODS ******
    *****************************/

    template <class T>
    void QuickSort<T>::Swap(T& elementA, T& elementB)
    {
        T temp = elementA;
        elementA = elementB;
        elementB = temp;
    }

    template <class T>
    int QuickSort<T>::Partition(T *arr, const int low, const int high)
    {
        int pivot = arr[low];
        int i = low;
        int j = high;

        do
        {
            do
            {
                i++;
            } while (arr[i] <= pivot);

            do
            {
                j--;
            } while (arr[j] > pivot);

            if (i < j)
            {
                Swap(arr[i], arr[j]);
            }
        } while (i < j);
        Swap(arr[j], arr[low]);
        return j;
    }

    template <class T>
    void QuickSort<T>::QuickSortAlgorithm(T *arr, const int low, const int high)
    {
        if (low < high)
        {
            int j = Partition(arr, low, high);
            QuickSortAlgorithm(arr, low, j);
            QuickSortAlgorithm(arr, j + 1, high);
        }
    }

    /*****************************
     **** PRIVATE METHODS END ****
    *****************************/

    template <class T>
    QuickSort<T>::QuickSort(int size):
        m_choice            ( 0 ),
        m_quickSortMenuMap ( {} ),
        m_size              ( size ),
        m_data              { nullptr }
    {
        m_quickSortMenuMap.insert({ m_QuickSortMenu(SHOWCASE_QUICK_SORT),
                                    std::string("Showcase quick sort") });
        m_quickSortMenuMap.insert({ m_QuickSortMenu(SHOWCASE_QUICK_SORT_ACTION),
                                    std::string("Showcase quick sort in action") });
        m_quickSortMenuMap.insert({ m_QuickSortMenu(INSERT_ELEMENTS_IN_ARRAY),
                                    std::string("Insert elements in array") });
        m_quickSortMenuMap.insert({ m_QuickSortMenu(PERFORM_QUICK_SORT),
                                    std::string("Perform quick sort") });
        m_quickSortMenuMap.insert({ m_QuickSortMenu(DISPLAY_ARRAY),
                                    std::string("Display array") });
        m_quickSortMenuMap.insert({ m_QuickSortMenu(BACK_TO_PREVIOUS_MENU),
                                    std::string("Back to Previous Menu") });
        m_quickSortMenuMap.insert({ m_QuickSortMenu(EXIT_FROM_PROGRAM),
                                    std::string("Exit from program") });
        m_data = new T[m_size];
        for (int i = 0; i < m_size; i++)
        {
            m_data[i] = 0;
        }
    }

    template <class T>
    QuickSort<T>::~QuickSort()
    {
        delete m_data;
        m_data = nullptr;
    }
    
    template <class T>
    const int QuickSort<T>::GetMinCase()
    {
        return m_QuickSortMenu::MIN_COUNT;
    }

    template <class T>
    const int QuickSort<T>::GetMaxCase()
    {
        return m_QuickSortMenu::MAX_COUNT;
    }

    template <class T>
    const int& QuickSort<T>::GetChoice()
    {
        return m_choice;
    }

    template <class T>
    void QuickSort<T>::GetChoiceInputFromUser()
    {
        utils::InputNumberFromUser(m_choice, 1, static_cast<int>(m_QuickSortMenu::MAX_COUNT));
    }

    template <class T>
    void QuickSort<T>::PrintMenu()
    {
        std::cout << std::endl;
        for (std::map<int, std::string>::iterator it = m_quickSortMenuMap.begin();
            it != m_quickSortMenuMap.end();
            it++)
        {
            std::cout << it->first << ". " << it->second << std::endl;
        }
        std::cout << "Please enter your choice: ";
    }

    template <class T>
    void QuickSort<T>::PrintSelectedChoice()
    {
        std::cout << std::endl << std::endl
                << "You have chosen choice "
                << m_quickSortMenuMap.at(m_choice)
                << std::endl;
    }

    template <class T>
    void QuickSort<T>::ShowcaseQuickSort()
    {
        std::cout << "Quick Sort is an O(N * logN) sorting algorithm. It takes an element and finds a suitable position for it" << std::endl
                  << "Analysis:" << std::endl
                  << "\t1. Number of comparisons ==> N * (N - 1) / 2 ==> O(N^2) - worst case (already sorted list, ascending or descending), O(N * logN) - best case" << std::endl
                  << "\t2. Number of swaps ==> N ==> O(N)" << std::endl
                  << "\t3. Adaptive? (minimum time taken for sorting already sorted list) ==> No" << std::endl
                  << "\t4. Stable? (order remains same for duplicate elements) ==> No" << std::endl;
    }

    template <class T>
    void QuickSort<T>::ShowcaseQuickSortAction()
    {
        std::cout << "To showcase the working of Bubble Sort, we take an array of 5 elements consisting: "
                  << " 8, 10, 3, 1, 2" << std::endl;
        int arr[] = {8, 10, 3, 1, 2};
        int size = 5;

        QuickSortAlgorithm(arr, 0, size);
        for (int i = 0; i < 5; i++)
        {
            std::cout << arr[i] << " ";
        }
    }

    template <class T>
    bool QuickSort<T>::DoesDataExist()
    {
        return m_data[0] == 0 ? false : true;
    }

    template <class T>
    void QuickSort<T>::InsertElements()
    {
        if (DoesDataExist())
        {
            std::cout << "Data already exists, overwriting the array" << std::endl;
        }
        std::cout << "Please enter the elements ( " << m_size << " ) of the array: " << std::endl; 
        for (int i = 0; i < m_size; i++)
        {
            utils::InputNumberFromUser(m_data[i]);
        }
    }

    template <class T>
    bool QuickSort<T>::PerformQuickSort()
    {
        if (not DoesDataExist())
        {
            return false;
        }

        QuickSortAlgorithm(m_data, 0, m_size);

        return true;
    }

    template <class T>
    void QuickSort<T>::DisplayArray()
    {
        if (DoesDataExist())
        {
            for (int i = 0; i < m_size; i++)
            {
                std::cout << m_data[i] << " ";
            }
            std::cout << std::endl;
        }
    }
} //namespace sorting_algorithms
