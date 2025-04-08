#pragma once

#include "BubbleSort.h"
#include "../../utils.h"

namespace sorting_algorithms
{
    /*****************************
     ****** PRIVATE METHODS ******
    *****************************/

    template <class T>
    void BubbleSort<T>::Swap(T& elementA, T& elementB)
    {
        T temp = elementA;
        elementA = elementB;
        elementB = temp;
    }

    /*****************************
     **** PRIVATE METHODS END ****
    *****************************/

    template <class T>
    BubbleSort<T>::BubbleSort(int size):
        m_choice            ( 0 ),
        m_bubbleSortMenuMap ( {} ),
        m_size              ( size ),
        m_data              { nullptr }
    {
        m_bubbleSortMenuMap.insert({ m_BubbleSortMenu(SHOWCASE_BUBBLE_SORT),
                                     std::string("Showcase bubble sort") });
        m_bubbleSortMenuMap.insert({ m_BubbleSortMenu(SHOWCASE_BUBBLE_SORT_ACTION),
                                     std::string("Showcase bubble sort in action") });
        m_bubbleSortMenuMap.insert({ m_BubbleSortMenu(INSERT_ELEMENTS_IN_ARRAY),
                                     std::string("Insert elements in array") });
        m_bubbleSortMenuMap.insert({ m_BubbleSortMenu(PERFORM_BUBBLE_SORT),
                                     std::string("Perform bubble sort") });
        m_bubbleSortMenuMap.insert({ m_BubbleSortMenu(DISPLAY_ARRAY),
                                     std::string("Display array") });
        m_bubbleSortMenuMap.insert({ m_BubbleSortMenu(BACK_TO_PREVIOUS_MENU),
                                     std::string("Back to Previous Menu") });
        m_bubbleSortMenuMap.insert({ m_BubbleSortMenu(EXIT_FROM_PROGRAM),
                                     std::string("Exit from program") });
        m_data = new T[m_size];
        for (int i = 0; i < m_size; i++)
        {
            m_data[i] = 0;
        }
    }

    template <class T>
    BubbleSort<T>::~BubbleSort()
    {
        delete m_data;
        m_data = nullptr;
    }
    
    template <class T>
    const int BubbleSort<T>::GetMinCase()
    {
        return m_BubbleSortMenu::MIN_COUNT;
    }

    template <class T>
    const int BubbleSort<T>::GetMaxCase()
    {
        return m_BubbleSortMenu::MAX_COUNT;
    }

    template <class T>
    const int& BubbleSort<T>::GetChoice()
    {
        return m_choice;
    }

    template <class T>
    void BubbleSort<T>::GetChoiceInputFromUser()
    {
        utils::InputNumberFromUser(m_choice, 1, static_cast<int>(m_BubbleSortMenu::MAX_COUNT));
    }

    template <class T>
    void BubbleSort<T>::PrintMenu()
    {
        std::cout << std::endl;
        for (std::map<int, std::string>::iterator it = m_bubbleSortMenuMap.begin();
            it != m_bubbleSortMenuMap.end();
            it++)
        {
            std::cout << it->first << ". " << it->second << std::endl;
        }
        std::cout << "Please enter your choice: ";
    }

    template <class T>
    void BubbleSort<T>::PrintSelectedChoice()
    {
        std::cout << std::endl << std::endl
                << "You have chosen choice "
                << m_bubbleSortMenuMap.at(m_choice)
                << std::endl;
    }

    template <class T>
    void BubbleSort<T>::ShowcaseBubbleSort()
    {
        std::cout << "Bubble Sort is an O(N^2) sorting algorithm. It sorts the elements in (N - 1) Passes and in each pass"
                  << " one element is sorted and reaches the end. Thus it sorts the heaviest element first and then the"
                  << " second and so on." << std::endl
                  << "Analysis:" << std::endl
                  << "\t1. Number of comparisons ==> N * (N - 1) / 2 ==> O(N^2)" << std::endl
                  << "\t2. Number of swaps ==> N * (N - 1) / 2 ==> O(N^2)" << std::endl
                  << "\t3. Adaptive? (minimum time taken for sorting already sorted list) ==>"
                  << " Not by default but can be made using a flag" << std::endl
                  << "\t4. Stable? (order remains same for duplicate elements) ==> Yes" << std::endl;
    }

    template <class T>
    void BubbleSort<T>::ShowcaseBubbleSortAction()
    {
        std::cout << "To showcase the working of Bubble Sort, we take an array of 5 elements consisting: "
                  << " 8, 3, 4, 5, 2" << std::endl;
        int arr[] = {8, 3, 4, 5, 2};
        int size = 5;

        for (int i = 0; i < size - 1; i++)
        {
            std::cout << "Pass: " << i + 1 << std::endl;
            for (int j = 0; j < size - 1 - i; j++)
            {
                if (arr[j] > arr[j + 1])
                {
                    Swap(arr[j], arr[j + 1]);
                }
                std::cout << "\tArray after comparison number " << j + 1 << ": ";
                for (int i = 0; i < size; i++)
                {
                    std::cout << arr[i] << " ";
                }
                std::cout << std::endl;
            }
        }
    }

    template <class T>
    bool BubbleSort<T>::DoesDataExist()
    {
        return m_data[0] == 0 ? false : true;
    }

    template <class T>
    void BubbleSort<T>::InsertElements()
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
    bool BubbleSort<T>::PerformBubbleSort()
    {
        if (not DoesDataExist())
        {
            return false;
        }

        // introduce the flag variable to make this algorithm adaptive
        int flag = 0;
        for (int i = 0; i < m_size - 1; i++)
        {
            for (int j = 0; j < m_size - 1 - i; j++)
            {
                if (m_data[j] > m_data[j + 1])
                {
                    Swap(m_data[j], m_data[j + 1]);
                    flag = 1;
                }
            }
            if (flag == 0) // no swap done in 1st Pass, hence array is already sorted
            {
                std::cout << "The list provided is already sorted, the algorithm is made adaptive to reduce the time"
                          << " taken to sort already sorted list" << std::endl;
                break;
            }
        }

        return true;
    }

    template <class T>
    void BubbleSort<T>::DisplayArray()
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
