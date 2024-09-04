#pragma once

#include "CircularQueue.h"
#include "../../utils.h"

namespace queue
{
    template <class T>
    CircularQueue<T>::CircularQueue(int size):
        m_choice               ( 0 ),
        m_circularQueueMenuMap ( {} ),
        m_front                { 0 },
        m_rear                 { 0 },
        m_size                 { size },
        m_data                 { nullptr }
    {
        m_circularQueueMenuMap.insert({ m_CircularQueueMenu(IS_EMPTY),
                                          std::string("Check if the queue is empty") });
        m_circularQueueMenuMap.insert({ m_CircularQueueMenu(IS_FULL),
                                          std::string("Check if the queue is full") });
        m_circularQueueMenuMap.insert({ m_CircularQueueMenu(DISPLAY),
                                          std::string("Display the queue") });
        m_circularQueueMenuMap.insert({ m_CircularQueueMenu(NUM_ELEMENTS),
                                          std::string("Number of elements in the queue") });
        m_circularQueueMenuMap.insert({ m_CircularQueueMenu(ENQUEUE),
                                          std::string("Enqueue") });
        m_circularQueueMenuMap.insert({ m_CircularQueueMenu(DEQUEUE),
                                          std::string("Dequeue") });
        m_circularQueueMenuMap.insert({ m_CircularQueueMenu(FRONT),
                                          std::string("Get front of the Queue") });
        m_circularQueueMenuMap.insert({ m_CircularQueueMenu(REAR),
                                          std::string("Get rear of the Queue") });
        m_circularQueueMenuMap.insert({ m_CircularQueueMenu(RESET),
                                          std::string("Reset the queue") });
        m_circularQueueMenuMap.insert({ m_CircularQueueMenu(BACK_TO_PREVIOUS_MENU),
                                          std::string("Back to Previous Menu") });
        m_circularQueueMenuMap.insert({ m_CircularQueueMenu(EXIT_FROM_PROGRAM),
                                          std::string("Exit from program") });
        
        m_data = new T[m_size];
    }

    template <class T>
    CircularQueue<T>::~CircularQueue()
    {
        delete []m_data;
        m_size = 0;
    }
    
    template <class T>
    const int CircularQueue<T>::GetMinCase()
    {
        return m_CircularQueueMenu::MIN_COUNT;
    }

    template <class T>
    const int CircularQueue<T>::GetMaxCase()
    {
        return m_CircularQueueMenu::MAX_COUNT;
    }

    template <class T>
    const int& CircularQueue<T>::GetChoice()
    {
        return m_choice;
    }

    template <class T>
    void CircularQueue<T>::GetChoiceInputFromUser()
    {
        utils::InputNumberFromUser(m_choice, 1, static_cast<int>(m_CircularQueueMenu::MAX_COUNT));
    }

    template <class T>
    void CircularQueue<T>::PrintMenu()
    {
        std::cout << std::endl;
        for (std::map<int, std::string>::iterator it = m_circularQueueMenuMap.begin();
            it != m_circularQueueMenuMap.end();
            it++)
        {
            std::cout << it->first << ". " << it->second << std::endl;
        }
        std::cout << "Please enter your choice: ";
    }

    template <class T>
    void CircularQueue<T>::PrintSelectedChoice()
    {
        std::cout << std::endl << std::endl
                << "You have chosen choice "
                << m_circularQueueMenuMap.at(m_choice)
                << std::endl;
    }

    template <class T>
    bool CircularQueue<T>::IsEmpty()
    {
        return m_front == m_rear ? true : false;
    }

    template <class T>
    bool CircularQueue<T>::IsFull()
    {
        return ((m_rear + 1) % m_size == m_front) ? true : false;
    }

    template <class T>
    void CircularQueue<T>::Display()
    {
        if (IsEmpty())
        {
            std::cout << "The queue is empty" << std::endl;
        }
        else
        {
            std::cout << "The contents of the queue are:" << std::endl;

            for (int i = (m_front + 1) % m_size; i != m_front; i = (i + 1) % m_size)
            {
                std::cout << m_data[i] << " ";
            }
            std::cout << std::endl;
        }
    }

    template <class T>
    int CircularQueue<T>::NumElements()
    {
        if (IsEmpty())
        {
            return 0;
        }
        else
        {
            return m_front < m_rear ? m_rear - m_front : m_size - m_front + m_rear;
        }
    }

    template <class T>
    bool CircularQueue<T>::Enqueue(T element)
    {
        if (IsFull())
        {
            return false;
        }
        m_rear = (m_rear + 1) % m_size;
        m_data[m_rear] = element;
        return true;
    }

    template <class T>
    std::optional<T> CircularQueue<T>::Dequeue()
    {
        if (IsEmpty())
        {
            return std::nullopt;
        }
        m_front = (m_front + 1) % m_size;
        T deleted = m_data[m_front];
        m_data[m_front] = 0;
        return deleted;
    }

    template <class T>
    std::optional<T> CircularQueue<T>::Front()
    {
        if (IsEmpty())
        {
            return std::nullopt;
        }
        return m_data[(m_front + 1) % m_size];
    }

    template <class T>
    std::optional<T> CircularQueue<T>::Rear()
    {
        if (IsEmpty())
        {
            return std::nullopt;
        }
        return m_data[m_rear];
    }

    template <class T>
    void CircularQueue<T>::Reset()
    {
        for (int i = 0; i < m_size; i++)
        {
            m_data[i] = 0;
        }
        m_front = 0;
        m_rear  = 0;
    }
} //namespace queue
