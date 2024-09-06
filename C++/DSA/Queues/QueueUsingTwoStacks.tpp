#pragma once

#include "QueueUsingTwoStacks.h"
#include "../../utils.h"

namespace queue
{
    template <class T>
    QueueUsingTwoStacks<T>::QueueUsingTwoStacks():
        m_choice                      ( 0 ),
        m_queueUsingTwoStacksMenuMap ( {} ),
        m_dataEnqueue                { nullptr },
        m_dataDequeue                { nullptr }
    {
        m_queueUsingTwoStacksMenuMap.insert({ m_QueueUsingTwoStacksMenu(IS_EMPTY),
                                              std::string("Check if the queue is empty") });
        m_queueUsingTwoStacksMenuMap.insert({ m_QueueUsingTwoStacksMenu(DISPLAY),
                                              std::string("Display the queue") });
        m_queueUsingTwoStacksMenuMap.insert({ m_QueueUsingTwoStacksMenu(ENQUEUE),
                                              std::string("Enqueue") });
        m_queueUsingTwoStacksMenuMap.insert({ m_QueueUsingTwoStacksMenu(DEQUEUE),
                                              std::string("Dequeue") });
        m_queueUsingTwoStacksMenuMap.insert({ m_QueueUsingTwoStacksMenu(FRONT),
                                              std::string("Get front of the Queue") });
        m_queueUsingTwoStacksMenuMap.insert({ m_QueueUsingTwoStacksMenu(REAR),
                                              std::string("Get rear of the Queue") });
        m_queueUsingTwoStacksMenuMap.insert({ m_QueueUsingTwoStacksMenu(RESET),
                                              std::string("Reset the queue") });
        m_queueUsingTwoStacksMenuMap.insert({ m_QueueUsingTwoStacksMenu(BACK_TO_PREVIOUS_MENU),
                                              std::string("Back to Previous Menu") });
        m_queueUsingTwoStacksMenuMap.insert({ m_QueueUsingTwoStacksMenu(EXIT_FROM_PROGRAM),
                                              std::string("Exit from program") });
        m_dataEnqueue = new stack::StackUsingLinkedList<T>;
        m_dataDequeue = new stack::StackUsingLinkedList<T>;
    }

    template <class T>
    QueueUsingTwoStacks<T>::~QueueUsingTwoStacks()
    {
        Reset();
        m_dataEnqueue = nullptr;
        m_dataDequeue = nullptr;
    }

    template <class T>
    const int QueueUsingTwoStacks<T>::GetMinCase()
    {
        return m_QueueUsingTwoStacksMenu::MIN_COUNT;
    }

    template <class T>
    const int QueueUsingTwoStacks<T>::GetMaxCase()
    {
        return m_QueueUsingTwoStacksMenu::MAX_COUNT;
    }

    template <class T>
    const int& QueueUsingTwoStacks<T>::GetChoice()
    {
        return m_choice;
    }

    template <class T>
    void QueueUsingTwoStacks<T>::GetChoiceInputFromUser()
    {
        utils::InputNumberFromUser(m_choice, 1, static_cast<int>(m_QueueUsingTwoStacksMenu::MAX_COUNT));
    }

    template <class T>
    void QueueUsingTwoStacks<T>::PrintMenu()
    {
        std::cout << std::endl;
        for (std::map<int, std::string>::iterator it = m_queueUsingTwoStacksMenuMap.begin();
            it != m_queueUsingTwoStacksMenuMap.end();
            it++)
        {
            std::cout << it->first << ". " << it->second << std::endl;
        }
        std::cout << "Please enter your choice: ";
    }

    template <class T>
    void QueueUsingTwoStacks<T>::PrintSelectedChoice()
    {
        std::cout << std::endl << std::endl
                << "You have chosen choice "
                << m_queueUsingTwoStacksMenuMap.at(m_choice)
                << std::endl;
    }

    template <class T>
    bool QueueUsingTwoStacks<T>::IsEmpty()
    {
        return m_dataEnqueue->IsEmpty() and m_dataDequeue->IsEmpty();
    }

    template <class T>
    void QueueUsingTwoStacks<T>::Display()
    {
        m_dataEnqueue->Display();
        m_dataDequeue->Display();
    }

    template <class T>
    bool QueueUsingTwoStacks<T>::Enqueue(T element)
    {
        return m_dataEnqueue->Push(element);
    }

    template <class T>
    std::optional<T> QueueUsingTwoStacks<T>::Dequeue()
    {
        if (m_dataDequeue->IsEmpty())
        {
            while (not m_dataEnqueue->IsEmpty())
            {
                m_dataDequeue->Push(m_dataEnqueue->Pop().value());
            }
            return m_dataDequeue->Pop();
        }
        else
        {
            return m_dataDequeue->Pop();
        }
    }

    template <class T>
    std::optional<T> QueueUsingTwoStacks<T>::Front()
    {
        return m_dataDequeue->GetTop();
    }

    template <class T>
    std::optional<T> QueueUsingTwoStacks<T>::Rear()
    {
        return m_dataEnqueue->GetTop();
    }

    template <class T>
    void QueueUsingTwoStacks<T>::Reset()
    {
        while (not m_dataDequeue->IsEmpty())
        {
            m_dataDequeue->Pop();
        }
        while (not m_dataEnqueue->IsEmpty())
        {
            m_dataEnqueue->Pop();
        }
    }
} //namespace queue
