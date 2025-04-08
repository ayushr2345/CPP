#include <iostream>
#include <string>
#include <functional>
#include "SortingAlgorithmsMain.h"
#include "../../utils.h"
#include "../../handlers.h"

namespace sorting_algorithms
{
    SortingAlgorithmsMain::SortingAlgorithmsMain():
        m_choice                       ( 0 ),
        m_sortingAlgorithmsMainMenuMap ( {} )
    {
        m_sortingAlgorithmsMainMenuMap.insert({ m_SortingAlgorithmsMainMenu(BUBBLE_SORT),
                                                std::string("Bubble Sort") });
        m_sortingAlgorithmsMainMenuMap.insert({ m_SortingAlgorithmsMainMenu(INSERTION_SORT),
                                                std::string("Insertion Sort") });
        m_sortingAlgorithmsMainMenuMap.insert({ m_SortingAlgorithmsMainMenu(BACK_TO_PREVIOUS_MENU),
                                                std::string("Back to Previous Menu") });
        m_sortingAlgorithmsMainMenuMap.insert({ m_SortingAlgorithmsMainMenu(EXIT_FROM_PROGRAM),
                                                std::string("Exit from program") });
    }

    const int SortingAlgorithmsMain::GetMinCase()
    {
        return m_SortingAlgorithmsMainMenu::MIN_COUNT;
    }

    const int SortingAlgorithmsMain::GetMaxCase()
    {
        return m_SortingAlgorithmsMainMenu::MAX_COUNT;
    }

    const int& SortingAlgorithmsMain::GetChoice()
    {
        return m_choice;
    }

    void SortingAlgorithmsMain::GetChoiceInputFromUser()
    {
        utils::InputNumberFromUser(m_choice, 1, static_cast<int>(m_SortingAlgorithmsMainMenu::MAX_COUNT));
    }

    void SortingAlgorithmsMain::PrintMenu()
    {
        std::cout << std::endl;
        for (std::map<int, std::string>::iterator it = m_sortingAlgorithmsMainMenuMap.begin();
            it != m_sortingAlgorithmsMainMenuMap.end();
            it++)
        {
            std::cout << it->first << ". " << it->second << std::endl;
        }
        std::cout << "Please enter your choice: ";
    }

    void SortingAlgorithmsMain::PrintSelectedChoice()
    {
        std::cout << std::endl << std::endl
                  << "You have chosen choice "
                  << m_sortingAlgorithmsMainMenuMap.at(m_choice)
                  << std::endl;
    }

    void SortingAlgorithmsMain::BubbleSort()
    {
        std::cout << "Enter the number of elements to be present in the array: ";
        int numElements;
        utils::InputNumberFromUser(numElements, 1, 20);
        sorting_algorithms::BubbleSort<int> bubbleSortObj(numElements);
        handlers::Handle(bubbleSortObj);
    }

    void SortingAlgorithmsMain::InsertionSort()
    {
        std::cout << "Enter the number of elements to be present in the array: ";
        int numElements;
        utils::InputNumberFromUser(numElements, 1, 20);
        sorting_algorithms::InsertionSort<int> insertionSortObj(numElements);
        handlers::Handle(insertionSortObj);
    }
} // namespace sorting_algorithms
