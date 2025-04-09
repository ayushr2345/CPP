#pragma once

#include "SelectionSort.h"
#include "../../utils.h"

namespace sorting_algorithms
{
    /*****************************
     ****** PRIVATE METHODS ******
    *****************************/

    template <class T>
    void SelectionSort<T>::Swap(T& elementA, T& elementB)
    {
        T temp = elementA;
        elementA = elementB;
        elementB = temp;
    }

    /*****************************
     **** PRIVATE METHODS END ****
    *****************************/

    template <class T>
    SelectionSort<T>::SelectionSort(int size):
        m_choice            ( 0 ),
        m_selectionSortMenuMap ( {} ),
        m_size              ( size ),
        m_data              { nullptr }
    {
        m_selectionSortMenuMap.insert({ m_SelectionSortMenu(SHOWCASE_SELECTION_SORT),
                                        std::string("Showcase selection sort") });
        m_selectionSortMenuMap.insert({ m_SelectionSortMenu(SHOWCASE_SELECTION_SORT_ACTION),
                                        std::string("Showcase selection sort in action") });
        m_selectionSortMenuMap.insert({ m_SelectionSortMenu(INSERT_ELEMENTS_IN_ARRAY),
                                        std::string("Insert elements in array") });
        m_selectionSortMenuMap.insert({ m_SelectionSortMenu(PERFORM_SELECTION_SORT),
                                        std::string("Perform selection sort") });
        m_selectionSortMenuMap.insert({ m_SelectionSortMenu(DISPLAY_ARRAY),
                                        std::string("Display array") });
        m_selectionSortMenuMap.insert({ m_SelectionSortMenu(BACK_TO_PREVIOUS_MENU),
                                        std::string("Back to Previous Menu") });
        m_selectionSortMenuMap.insert({ m_SelectionSortMenu(EXIT_FROM_PROGRAM),
                                        std::string("Exit from program") });
        m_data = new T[m_size];
        for (int i = 0; i < m_size; i++)
        {
            m_data[i] = 0;
        }
    }

    template <class T>
    SelectionSort<T>::~SelectionSort()
    {
        delete m_data;
        m_data = nullptr;
    }
    
    template <class T>
    const int SelectionSort<T>::GetMinCase()
    {
        return m_SelectionSortMenu::MIN_COUNT;
    }

    template <class T>
    const int SelectionSort<T>::GetMaxCase()
    {
        return m_SelectionSortMenu::MAX_COUNT;
    }

    template <class T>
    const int& SelectionSort<T>::GetChoice()
    {
        return m_choice;
    }

    template <class T>
    void SelectionSort<T>::GetChoiceInputFromUser()
    {
        utils::InputNumberFromUser(m_choice, 1, static_cast<int>(m_SelectionSortMenu::MAX_COUNT));
    }

    template <class T>
    void SelectionSort<T>::PrintMenu()
    {
        std::cout << std::endl;
        for (std::map<int, std::string>::iterator it = m_selectionSortMenuMap.begin();
            it != m_selectionSortMenuMap.end();
            it++)
        {
            std::cout << it->first << ". " << it->second << std::endl;
        }
        std::cout << "Please enter your choice: ";
    }

    template <class T>
    void SelectionSort<T>::PrintSelectedChoice()
    {
        std::cout << std::endl << std::endl
                << "You have chosen choice "
                << m_selectionSortMenuMap.at(m_choice)
                << std::endl;
    }

    template <class T>
    void SelectionSort<T>::ShowcaseSelectionSort()
    {
        std::cout << "Bubble Sort is an O(N^2) sorting algorithm. It sorts the elements in (N - 1) Passes and in each pass"
                  << " one position is taken and suitable element is found for that particular position" << std::endl
                  << "Analysis:" << std::endl
                  << "\t1. Number of comparisons ==> N * (N - 1) / 2 ==> O(N^2)" << std::endl
                  << "\t2. Number of swaps ==> N ==> O(N)" << std::endl
                  << "\t3. Adaptive? (minimum time taken for sorting already sorted list) ==>"
                  << " No (As, if already sorted list is provided, it will still compare and swap, no way to find if list is already sorted)" << std::endl
                  << "\t4. Stable? (order remains same for duplicate elements) ==> No (As swapping is done, can change order of duplicate elements)" << std::endl;
    }

    template <class T>
    void SelectionSort<T>::ShowcaseSelectionSortAction()
    {
        std::cout << "To showcase the working of Bubble Sort, we take an array of 5 elements consisting: "
                  << " 8, 10, 3, 1, 2" << std::endl;
        int arr[] = {8, 10, 3, 1, 2};
        int size = 5;

        for (int i = 0; i < size; i++)
        {
            T smallestIndex = i;
            for (int j = i; j < size; j++)
            {
                if (arr[j] < arr[smallestIndex])
                {
                    smallestIndex = j;
                }
            }
            if (i != smallestIndex)
            {
                Swap(arr[i], arr[smallestIndex]);
            }
            std::cout << "\tArray after Pass number " << i + 1 << ": ";
            for (int i = 0; i < size; i++)
            {
                std::cout << arr[i] << " ";
            }
            std::cout << std::endl;
        }
    }

    template <class T>
    bool SelectionSort<T>::DoesDataExist()
    {
        return m_data[0] == 0 ? false : true;
    }

    template <class T>
    void SelectionSort<T>::InsertElements()
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
    bool SelectionSort<T>::PerformSelectionSort()
    {
        if (not DoesDataExist())
        {
            return false;
        }

        for (int i = 0; i < m_size; i++)
        {
            T smallestIndex = i;
            for (int j = i; j < m_size; j++)
            {
                if (m_data[j] < m_data[smallestIndex])
                {
                    smallestIndex = j;
                }
            }
            if (i != smallestIndex)
            {
                Swap(m_data[i], m_data[smallestIndex]);
            }
        }

        return true;
    }

    template <class T>
    void SelectionSort<T>::DisplayArray()
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
