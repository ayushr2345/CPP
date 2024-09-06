#include <iostream>
#include <string>
#include <functional>
#include "QueueMain.h"
#include "../../utils.h"
#include "../../handlers.h"

namespace queue
{
    QueueMain::QueueMain():
        m_choice           ( 0 ),
        m_queueMainMenuMap ( {} )
    {
        m_queueMainMenuMap.insert({ m_QueueMainMenu(QUEUE_USING_ARRAY),
                                    std::string("Queue using array") });
        m_queueMainMenuMap.insert({ m_QueueMainMenu(CIRCULAR_QUEUE),
                                    std::string("Circular Queue") });
        m_queueMainMenuMap.insert({ m_QueueMainMenu(QUEUE_USING_LINKED_LIST),
                                    std::string("Queue using linked list") });
        m_queueMainMenuMap.insert({ m_QueueMainMenu(DOUBLE_ENDED_QUEUE),
                                    std::string("Double ended queue DEQueue") });
        m_queueMainMenuMap.insert({ m_QueueMainMenu(PRIORITY_QUEUE_LIMITED_SET),
                                    std::string("Priority queue using limited set priority") });
        m_queueMainMenuMap.insert({ m_QueueMainMenu(PRIORITY_QUEUE_ELEMENT),
                                    std::string("Priority queue using element priority") });
        m_queueMainMenuMap.insert({ m_QueueMainMenu(QUEUE_USING_TWO_STACKS),
                                    std::string("Queue using two stacks") });
        m_queueMainMenuMap.insert({ m_QueueMainMenu(BACK_TO_PREVIOUS_MENU),
                                    std::string("Back to Previous Menu") });
        m_queueMainMenuMap.insert({ m_QueueMainMenu(EXIT_FROM_PROGRAM),
                                    std::string("Exit from program") });
    }

    const int QueueMain::GetMinCase()
    {
        return m_QueueMainMenu::MIN_COUNT;
    }

    const int QueueMain::GetMaxCase()
    {
        return m_QueueMainMenu::MAX_COUNT;
    }

    const int& QueueMain::GetChoice()
    {
        return m_choice;
    }

    void QueueMain::GetChoiceInputFromUser()
    {
        utils::InputNumberFromUser(m_choice, 1, static_cast<int>(m_QueueMainMenu::MAX_COUNT));
    }

    void QueueMain::PrintMenu()
    {
        std::cout << std::endl;
        for (std::map<int, std::string>::iterator it = m_queueMainMenuMap.begin();
            it != m_queueMainMenuMap.end();
            it++)
        {
            std::cout << it->first << ". " << it->second << std::endl;
        }
        std::cout << "Please enter your choice: ";
    }

    void QueueMain::PrintSelectedChoice()
    {
        std::cout << std::endl << std::endl
                  << "You have chosen choice "
                  << m_queueMainMenuMap.at(m_choice)
                  << std::endl;
    }

    void QueueMain::QueueUsingArray()
    {
        std::cout << "Enter the max size of the queue: ";
        int sizeOfQueue = 0;
        utils::InputNumberFromUser(sizeOfQueue, 1, 20);
        queue::QueueUsingArray<int> queueUsingArrayObj(sizeOfQueue);
        handlers::Handle(queueUsingArrayObj);
    }

    void QueueMain::CircularQueue()
    {
        std::cout << "Enter the max size of the queue: ";
        int sizeOfQueue = 0;
        utils::InputNumberFromUser(sizeOfQueue, 1, 20);
        queue::CircularQueue<int> circularQueueObj(sizeOfQueue);
        handlers::Handle(circularQueueObj);
    }

    void QueueMain::QueueUsingLinkedList()
    {
        queue::QueueUsingLinkedList<int> queueUsingLinkedListObj;
        handlers::Handle(queueUsingLinkedListObj);
    }

    void QueueMain::DoubleEndedQueue()
    {
        queue::DoubleEndedQueue<int> doubleEndedQueueObj;
        handlers::Handle(doubleEndedQueueObj);
    }

    void QueueMain::PriorityQueueLimitedSet()
    {
        int numPriorities = 0;
        std::cout << "Please enter the number of priorities: ";
        utils::InputNumberFromUser(numPriorities, 0, 5);
        queue::PriorityQueueLimitedSet<int> priorityQueueLimitedSetObj(numPriorities);
        handlers::Handle(priorityQueueLimitedSetObj);
    }

    void QueueMain::PriorityQueueElement()
    {
        queue::PriorityQueueElement<int> priorityQueueElementObj;
        handlers::Handle(priorityQueueElementObj);
    }
} // namespace queue
