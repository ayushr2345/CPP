#pragma once

#include "PriorityQueueElement.h"
#include "../../utils.h"

namespace queue
{
    template <class T>
    PriorityQueueElement<T>::PriorityQueueElement():
        m_choice                      ( 0 ),
        m_priorityQueueElementMenuMap ( {} ),
        m_data                        { nullptr }
    {
        m_priorityQueueElementMenuMap.insert({ m_PriorityQueueElementMenu(IS_EMPTY),
                                               std::string("Check if the queue is empty") });
        m_priorityQueueElementMenuMap.insert({ m_PriorityQueueElementMenu(DISPLAY),
                                               std::string("Display the queue") });
        m_priorityQueueElementMenuMap.insert({ m_PriorityQueueElementMenu(NUM_ELEMENTS),
                                               std::string("Number of elements in the queue") });
        m_priorityQueueElementMenuMap.insert({ m_PriorityQueueElementMenu(ENQUEUE),
                                               std::string("Enqueue") });
        m_priorityQueueElementMenuMap.insert({ m_PriorityQueueElementMenu(DEQUEUE),
                                               std::string("Dequeue") });
        m_priorityQueueElementMenuMap.insert({ m_PriorityQueueElementMenu(FRONT),
                                               std::string("Get front of the Queue") });
        m_priorityQueueElementMenuMap.insert({ m_PriorityQueueElementMenu(REAR),
                                               std::string("Get rear of the Queue") });
        m_priorityQueueElementMenuMap.insert({ m_PriorityQueueElementMenu(RESET),
                                               std::string("Reset the queue") });
        m_priorityQueueElementMenuMap.insert({ m_PriorityQueueElementMenu(BACK_TO_PREVIOUS_MENU),
                                               std::string("Back to Previous Menu") });
        m_priorityQueueElementMenuMap.insert({ m_PriorityQueueElementMenu(EXIT_FROM_PROGRAM),
                                               std::string("Exit from program") });
        m_data = new queue::QueueUsingLinkedList<T>;
    }

    template <class T>
    PriorityQueueElement<T>::~PriorityQueueElement()
    {
        Reset();
        m_data = nullptr;
    }

    template <class T>
    const int PriorityQueueElement<T>::GetMinCase()
    {
        return m_PriorityQueueElementMenu::MIN_COUNT;
    }

    template <class T>
    const int PriorityQueueElement<T>::GetMaxCase()
    {
        return m_PriorityQueueElementMenu::MAX_COUNT;
    }

    template <class T>
    const int& PriorityQueueElement<T>::GetChoice()
    {
        return m_choice;
    }

    template <class T>
    void PriorityQueueElement<T>::GetChoiceInputFromUser()
    {
        utils::InputNumberFromUser(m_choice, 1, static_cast<int>(m_PriorityQueueElementMenu::MAX_COUNT));
    }

    template <class T>
    void PriorityQueueElement<T>::PrintMenu()
    {
        std::cout << std::endl;
        for (std::map<int, std::string>::iterator it = m_priorityQueueElementMenuMap.begin();
            it != m_priorityQueueElementMenuMap.end();
            it++)
        {
            std::cout << it->first << ". " << it->second << std::endl;
        }
        std::cout << "Please enter your choice: ";
    }

    template <class T>
    void PriorityQueueElement<T>::PrintSelectedChoice()
    {
        std::cout << std::endl << std::endl
                << "You have chosen choice "
                << m_priorityQueueElementMenuMap.at(m_choice)
                << std::endl;
    }

    template <class T>
    bool PriorityQueueElement<T>::IsEmpty()
    {
        return m_data->IsEmpty();
    }

    template <class T>
    void PriorityQueueElement<T>::Display()
    {
        return m_data->Display();
    }

    template <class T>
    int PriorityQueueElement<T>::NumElements()
    {
        return m_data->NumElements();
    }

    template <class T>
    bool PriorityQueueElement<T>::Enqueue(T element)
    {
        return m_data->EnqueueSorted(element);
    }

    template <class T>
    std::optional<T> PriorityQueueElement<T>::Dequeue()
    {
        return m_data->Dequeue();
    }

    template <class T>
    std::optional<T> PriorityQueueElement<T>::Front()
    {
        return m_data->Front();
    }

    template <class T>
    std::optional<T> PriorityQueueElement<T>::Rear()
    {
        return m_data->Rear();
    }

    template <class T>
    void PriorityQueueElement<T>::Reset()
    {
        m_data->Reset();
    }
} //namespace queue
