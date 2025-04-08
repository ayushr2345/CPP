#pragma once

#include "DoubleEndedQueue.h"
#include "../../utils.h"

namespace queue
{
    template <class T>
    DoubleEndedQueue<T>::DoubleEndedQueue():
        m_choice                      ( 0 ),
        m_doubleEndedQueueMenuMap ( {} ),
        m_front                       { nullptr },
        m_rear                        { nullptr }
    {
        m_doubleEndedQueueMenuMap.insert({ m_DoubleEndedQueueMenu(IS_EMPTY),
                                           std::string("Check if the queue is empty") });
        m_doubleEndedQueueMenuMap.insert({ m_DoubleEndedQueueMenu(DISPLAY),
                                           std::string("Display the queue") });
        m_doubleEndedQueueMenuMap.insert({ m_DoubleEndedQueueMenu(NUM_ELEMENTS),
                                           std::string("Number of elements in the queue") });
        m_doubleEndedQueueMenuMap.insert({ m_DoubleEndedQueueMenu(ENQUEUE_FRONT),
                                           std::string("Enqueue front") });
        m_doubleEndedQueueMenuMap.insert({ m_DoubleEndedQueueMenu(ENQUEUE_REAR),
                                           std::string("Enqueue rear") });
        m_doubleEndedQueueMenuMap.insert({ m_DoubleEndedQueueMenu(DEQUEUE_FRONT),
                                           std::string("Dequeue front") });
        m_doubleEndedQueueMenuMap.insert({ m_DoubleEndedQueueMenu(DEQUEUE_REAR),
                                           std::string("Dequeue rear") });
        m_doubleEndedQueueMenuMap.insert({ m_DoubleEndedQueueMenu(FRONT),
                                           std::string("Get front of the Queue") });
        m_doubleEndedQueueMenuMap.insert({ m_DoubleEndedQueueMenu(REAR),
                                           std::string("Get rear of the Queue") });
        m_doubleEndedQueueMenuMap.insert({ m_DoubleEndedQueueMenu(RESET),
                                           std::string("Reset the queue") });
        m_doubleEndedQueueMenuMap.insert({ m_DoubleEndedQueueMenu(BACK_TO_PREVIOUS_MENU),
                                           std::string("Back to Previous Menu") });
        m_doubleEndedQueueMenuMap.insert({ m_DoubleEndedQueueMenu(EXIT_FROM_PROGRAM),
                                           std::string("Exit from program") });
    }

    template <class T>
    DoubleEndedQueue<T>::~DoubleEndedQueue()
    {
        Reset();
    }

    template <class T>
    const int DoubleEndedQueue<T>::GetMinCase()
    {
        return m_DoubleEndedQueueMenu::MIN_COUNT;
    }

    template <class T>
    const int DoubleEndedQueue<T>::GetMaxCase()
    {
        return m_DoubleEndedQueueMenu::MAX_COUNT;
    }

    template <class T>
    const int& DoubleEndedQueue<T>::GetChoice()
    {
        return m_choice;
    }

    template <class T>
    void DoubleEndedQueue<T>::GetChoiceInputFromUser()
    {
        utils::InputNumberFromUser(m_choice, 1, static_cast<int>(m_DoubleEndedQueueMenu::MAX_COUNT));
    }

    template <class T>
    void DoubleEndedQueue<T>::PrintMenu()
    {
        std::cout << std::endl;
        for (std::map<int, std::string>::iterator it = m_doubleEndedQueueMenuMap.begin();
            it != m_doubleEndedQueueMenuMap.end();
            it++)
        {
            std::cout << it->first << ". " << it->second << std::endl;
        }
        std::cout << "Please enter your choice: ";
    }

    template <class T>
    void DoubleEndedQueue<T>::PrintSelectedChoice()
    {
        std::cout << std::endl << std::endl
                << "You have chosen choice "
                << m_doubleEndedQueueMenuMap.at(m_choice)
                << std::endl;
    }

    template <class T>
    bool DoubleEndedQueue<T>::IsEmpty()
    {
        return m_front == nullptr ? true : false;
    }

    template <class T>
    void DoubleEndedQueue<T>::Display()
    {
        if (IsEmpty())
        {
            std::cout << "The queue is empty" << std::endl;
        }
        else
        {
            std::cout << "The contents of the queue are:" << std::endl;

            Node* temp = m_front;
            while (temp)
            {
                std::cout << temp->m_m_data << " ";
                temp = temp->m_m_next;
            }
            std::cout << std::endl;
        }
    }

    template <class T>
    int DoubleEndedQueue<T>::NumElements()
    {
        if (IsEmpty())
        {
            return 0;
        }
        else
        {
            int num = 0;
            Node* temp = m_front;
            while (temp)
            {
                num++;
                temp = temp->m_m_next;
            }
            return num;
        }
    }

    template <class T>
    bool DoubleEndedQueue<T>::EnqueueFront(T element)
    {
        if (IsEmpty())
        {
            Node* temp = new Node;
            temp->m_m_data = element;
            temp->m_m_next = nullptr;
            m_front = temp;
            m_rear  = temp;
        }
        else
        {
            Node* temp = new Node;
            temp->m_m_data = element;
            temp->m_m_next = m_front;
            m_front = temp;
        }
        return true;
    }

    template <class T>
    bool DoubleEndedQueue<T>::EnqueueRear(T element)
    {
        if (IsEmpty())
        {
            Node* temp = new Node;
            temp->m_m_data = element;
            temp->m_m_next = nullptr;
            m_front = temp;
            m_rear  = temp;
        }
        else
        {
            Node* temp = new Node;
            temp->m_m_data = element;
            temp->m_m_next = nullptr;
            m_rear->m_m_next = temp;
            m_rear = temp;
        }
        return true;
    }

    template <class T>
    std::optional<T> DoubleEndedQueue<T>::DequeueFront()
    {
        if (IsEmpty())
        {
            return std::nullopt;
        }
        T deleted = m_front->m_m_data;
        Node* temp = m_front;
        m_front = m_front->m_m_next;
        delete temp;
        return deleted;
    }

    template <class T>
    std::optional<T> DoubleEndedQueue<T>::DequeueRear()
    {
        if (IsEmpty())
        {
            return std::nullopt;
        }
        T deleted = m_rear->m_m_data;
        if (m_front == m_rear)
        {
            delete m_front;
            m_front = nullptr;
            m_rear  = nullptr;
            return deleted;
        }

        Node* temp = m_front;
        
        while (temp->m_m_next != m_rear)
        {
            temp = temp->m_m_next;
        }
        delete m_rear;
        temp->m_m_next = nullptr;
        m_rear = temp;
        return deleted;
    }

    template <class T>
    std::optional<T> DoubleEndedQueue<T>::Front()
    {
        if (IsEmpty())
        {
            return std::nullopt;
        }
        return m_front->m_m_data;
    }

    template <class T>
    std::optional<T> DoubleEndedQueue<T>::Rear()
    {
        if (IsEmpty())
        {
            return std::nullopt;
        }
        return m_rear->m_m_data;
    }

    template <class T>
    void DoubleEndedQueue<T>::Reset()
    {
        Node* temp = m_front;

        while (temp)
        {
            Node* temp2 = temp->m_m_next;
            delete temp;
            temp = temp2;
        }

        m_front = nullptr;
        m_rear  = nullptr;
    }
} //namespace queue
