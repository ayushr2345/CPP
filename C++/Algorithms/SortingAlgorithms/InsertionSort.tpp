#pragma once

#include "InsertionSort.h"
#include "../../utils.h"

namespace sorting_algorithms
{
    /*****************************
     ****** PRIVATE METHODS ******
    *****************************/

    template <class T>
    void InsertionSort<T>::Swap(T& elementA, T& elementB)
    {
        T temp = elementA;
        elementA = elementB;
        elementB = temp;
    }

    /*****************************
     **** PRIVATE METHODS END ****
    *****************************/

    template <class T>
    InsertionSort<T>::InsertionSort(int size):
        m_choice            ( 0 ),
        m_insertionSortMenuMap ( {} ),
        m_size              ( size ),
        m_data              { nullptr }
    {
        m_insertionSortMenuMap.insert({ m_InsertionSortMenu(SHOWCASE_INSERTION_SORT),
                                        std::string("Showcase insertion sort") });
        m_insertionSortMenuMap.insert({ m_InsertionSortMenu(SHOWCASE_INSERTION_SORT_ACTION),
                                        std::string("Showcase insertion sort in action") });
        m_insertionSortMenuMap.insert({ m_InsertionSortMenu(INSERT_ELEMENTS_IN_ARRAY),
                                        std::string("Insert elements in array") });
        m_insertionSortMenuMap.insert({ m_InsertionSortMenu(PERFORM_INSERTION_SORT),
                                        std::string("Perform insertion sort") });
        m_insertionSortMenuMap.insert({ m_InsertionSortMenu(DISPLAY_ARRAY),
                                        std::string("Display array") });
        m_insertionSortMenuMap.insert({ m_InsertionSortMenu(BACK_TO_PREVIOUS_MENU),
                                        std::string("Back to Previous Menu") });
        m_insertionSortMenuMap.insert({ m_InsertionSortMenu(EXIT_FROM_PROGRAM),
                                        std::string("Exit from program") });
        m_data = new T[m_size];
        for (int i = 0; i < m_size; i++)
        {
            m_data[i] = 0;
        }
    }

    template <class T>
    InsertionSort<T>::~InsertionSort()
    {
        delete m_data;
        m_data = nullptr;
    }
    
    template <class T>
    const int InsertionSort<T>::GetMinCase()
    {
        return m_InsertionSortMenu::MIN_COUNT;
    }

    template <class T>
    const int InsertionSort<T>::GetMaxCase()
    {
        return m_InsertionSortMenu::MAX_COUNT;
    }

    template <class T>
    const int& InsertionSort<T>::GetChoice()
    {
        return m_choice;
    }

    template <class T>
    void InsertionSort<T>::GetChoiceInputFromUser()
    {
        utils::InputNumberFromUser(m_choice, 1, static_cast<int>(m_InsertionSortMenu::MAX_COUNT));
    }

    template <class T>
    void InsertionSort<T>::PrintMenu()
    {
        std::cout << std::endl;
        for (std::map<int, std::string>::iterator it = m_insertionSortMenuMap.begin();
            it != m_insertionSortMenuMap.end();
            it++)
        {
            std::cout << it->first << ". " << it->second << std::endl;
        }
        std::cout << "Please enter your choice: ";
    }

    template <class T>
    void InsertionSort<T>::PrintSelectedChoice()
    {
        std::cout << std::endl << std::endl
                << "You have chosen choice "
                << m_insertionSortMenuMap.at(m_choice)
                << std::endl;
    }

    template <class T>
    void InsertionSort<T>::ShowcaseInsertionSort()
    {
        std::cout << "Insertion Sort is an O(N^2) sorting algorithm. It sorts the elements in (N - 1) Passes. It assumes one"
                  << " element is already sorted and starts to insert rest of the elements one by one into the sorted part of the array"
                  << " by doing a sorted insert" << std::endl
                  << "Analysis:" << std::endl
                  << "\t1. Number of comparisons ==> N * (N - 1) / 2 ==> O(N^2)" << std::endl
                  << "\t2. Number of swaps ==> N * (N - 1) / 2 ==> O(N^2)" << std::endl
                  << "\t3. Adaptive? (minimum time taken for sorting already sorted list) ==>"
                  << " It is adaptive by default" << std::endl
                  << "\t4. Stable? (order remains same for duplicate elements) ==> Yes" << std::endl;
    }

    template <class T>
    void InsertionSort<T>::ShowcaseInsertionSortAction()
    {
        std::cout << "To showcase the working of Bubble Sort, we take an array of 5 elements consisting: "
                  << " 8, 3, 4, 5, 2" << std::endl;
        int arr[] = {8, 3, 4, 5, 2};
        int size = 5;

        for (int i = 1; i < size; i++)
        {
            std::cout << "Pass: " << i << std::endl;
            int toBeInserted = arr[i];
            int j = i - 1;
            while (j >= 0 and arr[j] > toBeInserted)
            {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = toBeInserted;
            std::cout << "\tSorted range: (0 - " << i << "). Array after inserting " << toBeInserted << ": ";
            for (int i = 0; i < size; i++)
            {
                std::cout << arr[i] << " ";
            }
            std::cout << std::endl;
        }
    }

    template <class T>
    bool InsertionSort<T>::DoesDataExist()
    {
        return m_data[0] == 0 ? false : true;
    }

    template <class T>
    void InsertionSort<T>::InsertElements()
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
    bool InsertionSort<T>::PerformInsertionSort()
    {
        if (not DoesDataExist())
        {
            return false;
        }

        for (int i = 1; i < m_size; i++)
        {
            int toBeInserted = m_data[i];
            int j = i - 1;
            while (j >= 0 and m_data[j] > toBeInserted)
            {
                m_data[j + 1] = m_data[j];
                j--;
            }
            m_data[j + 1] = toBeInserted;
        }

        return true;
    }

    template <class T>
    void InsertionSort<T>::DisplayArray()
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
