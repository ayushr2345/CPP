#include <iostream>
#include <string>
#include <functional>
#include "HeapMain.h"
#include "../../utils.h"
#include "../../handlers.h"

namespace heap
{
    HeapMain::HeapMain():
        m_choice          ( 0 ),
        m_heapMainMenuMap ( {} )
    {
        m_heapMainMenuMap.insert({ m_HeapMainMenu(MAX_HEAP),
                                   std::string("Max Heap") });
        m_heapMainMenuMap.insert({ m_HeapMainMenu(MIN_HEAP),
                                   std::string("Min Heap") });
        m_heapMainMenuMap.insert({ m_HeapMainMenu(BACK_TO_PREVIOUS_MENU),
                                   std::string("Back to Previous Menu") });
        m_heapMainMenuMap.insert({ m_HeapMainMenu(EXIT_FROM_PROGRAM),
                                   std::string("Exit from program") });
    }

    const int HeapMain::GetMinCase()
    {
        return m_HeapMainMenu::MIN_COUNT;
    }

    const int HeapMain::GetMaxCase()
    {
        return m_HeapMainMenu::MAX_COUNT;
    }

    const int& HeapMain::GetChoice()
    {
        return m_choice;
    }

    void HeapMain::GetChoiceInputFromUser()
    {
        utils::InputNumberFromUser(m_choice, 1, static_cast<int>(m_HeapMainMenu::MAX_COUNT));
    }

    void HeapMain::PrintMenu()
    {
        std::cout << std::endl;
        for (std::map<int, std::string>::iterator it = m_heapMainMenuMap.begin();
            it != m_heapMainMenuMap.end();
            it++)
        {
            std::cout << it->first << ". " << it->second << std::endl;
        }
        std::cout << "Please enter your choice: ";
    }

    void HeapMain::PrintSelectedChoice()
    {
        std::cout << std::endl << std::endl
                  << "You have chosen choice "
                  << m_heapMainMenuMap.at(m_choice)
                  << std::endl;
    }

    void HeapMain::MaxHeap()
    {
        std::cout << "Please enter the max number of elements in the max heap: ";
        int elements;
        utils::InputNumberFromUser(elements, 0, 20);
        std::cout << "Creating an array of " << elements + 1 << " size to store the elements" << std::endl;
        heap::MaxHeap<int> maxHeapObj(elements + 1);
        handlers::Handle(maxHeapObj);
    }

    void HeapMain::MinHeap()
    {
        std::cout << "Please enter the max number of elements in the min heap: ";
        int elements;
        utils::InputNumberFromUser(elements, 0, 20);
        std::cout << "Creating an array of " << elements + 1 << " size to store the elements" << std::endl;
        heap::MinHeap<int> minHeapObj(elements + 1);
        handlers::Handle(minHeapObj);
    }
} // namespace heap
