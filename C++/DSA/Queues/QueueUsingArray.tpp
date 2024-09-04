#pragma once

#include "QueueUsingArray.h"
#include "../../utils.h"

namespace queue
{
    template <class T>
    QueueUsingArray<T>::QueueUsingArray(int size):
        m_choice                 ( 0 ),
        m_queueUsingArrayMenuMap ( {} ),
        m_front                  { -1 },
        m_rear                   { -1 },
        m_size                   { size },
        m_data                   { nullptr }
    {
        m_queueUsingArrayMenuMap.insert({ m_QueueUsingArrayMenu(IS_EMPTY),
                                          std::string("Check if the queue is empty") });
        m_queueUsingArrayMenuMap.insert({ m_QueueUsingArrayMenu(IS_FULL),
                                          std::string("Check if the queue is full") });
        m_queueUsingArrayMenuMap.insert({ m_QueueUsingArrayMenu(DISPLAY),
                                          std::string("Display the queue") });
        m_queueUsingArrayMenuMap.insert({ m_QueueUsingArrayMenu(NUM_ELEMENTS),
                                          std::string("Number of elements in the queue") });
        m_queueUsingArrayMenuMap.insert({ m_QueueUsingArrayMenu(ENQUEUE),
                                          std::string("Enqueue") });
        m_queueUsingArrayMenuMap.insert({ m_QueueUsingArrayMenu(DEQUEUE),
                                          std::string("Dequeue") });
        m_queueUsingArrayMenuMap.insert({ m_QueueUsingArrayMenu(FRONT),
                                          std::string("Get front of the Queue") });
        m_queueUsingArrayMenuMap.insert({ m_QueueUsingArrayMenu(REAR),
                                          std::string("Get rear of the Queue") });
        m_queueUsingArrayMenuMap.insert({ m_QueueUsingArrayMenu(RESET),
                                          std::string("Reset the queue") });
        m_queueUsingArrayMenuMap.insert({ m_QueueUsingArrayMenu(BACK_TO_PREVIOUS_MENU),
                                          std::string("Back to Previous Menu") });
        m_queueUsingArrayMenuMap.insert({ m_QueueUsingArrayMenu(EXIT_FROM_PROGRAM),
                                          std::string("Exit from program") });
        
        m_data = new T[m_size];
    }

    template <class T>
    QueueUsingArray<T>::~QueueUsingArray()
    {
        delete []m_data;
        m_size = 0;
    }
    
    template <class T>
    const int QueueUsingArray<T>::GetMinCase()
    {
        return m_QueueUsingArrayMenu::MIN_COUNT;
    }

    template <class T>
    const int QueueUsingArray<T>::GetMaxCase()
    {
        return m_QueueUsingArrayMenu::MAX_COUNT;
    }

    template <class T>
    const int& QueueUsingArray<T>::GetChoice()
    {
        return m_choice;
    }

    template <class T>
    void QueueUsingArray<T>::GetChoiceInputFromUser()
    {
        utils::InputNumberFromUser(m_choice, 1, static_cast<int>(m_QueueUsingArrayMenu::MAX_COUNT));
    }

    template <class T>
    void QueueUsingArray<T>::PrintMenu()
    {
        std::cout << std::endl;
        for (std::map<int, std::string>::iterator it = m_queueUsingArrayMenuMap.begin();
            it != m_queueUsingArrayMenuMap.end();
            it++)
        {
            std::cout << it->first << ". " << it->second << std::endl;
        }
        std::cout << "Please enter your choice: ";
    }

    template <class T>
    void QueueUsingArray<T>::PrintSelectedChoice()
    {
        std::cout << std::endl << std::endl
                << "You have chosen choice "
                << m_queueUsingArrayMenuMap.at(m_choice)
                << std::endl;
    }

    template <class T>
    bool QueueUsingArray<T>::IsEmpty()
    {
        return m_front == m_rear ? true : false;
    }

    template <class T>
    bool QueueUsingArray<T>::IsFull()
    {
        return m_rear == m_size - 1 ? true : false;
    }

    template <class T>
    void QueueUsingArray<T>::Display()
    {
        if (IsEmpty())
        {
            std::cout << "The queue is empty" << std::endl;
        }
        else
        {
            std::cout << "The contents of the queue are:" << std::endl;

            for (int i = m_front + 1; i <= m_rear; i++)
            {
                std::cout << m_data[i] << " ";
            }
            std::cout << std::endl;
        }
    }

    template <class T>
    int QueueUsingArray<T>::NumElements()
    {
        if (IsEmpty())
        {
            return 0;
        }
        else
        {
            int num = 0;
            for (int i = m_front + 1; i <= m_rear; i++)
            {
                num++;
            }
            return num;
        }
    }

    template <class T>
    bool QueueUsingArray<T>::Enqueue(T element)
    {
        if (IsFull())
        {
            return false;
        }
        m_data[++m_rear] = element;
        return true;
    }

    template <class T>
    std::optional<T> QueueUsingArray<T>::Dequeue()
    {
        if (IsEmpty())
        {
            return std::nullopt;
        }
        T deleted = m_data[m_front + 1];
        m_data[m_front + 1] = 0;
        m_front++;
        return deleted;
    }

    template <class T>
    std::optional<T> QueueUsingArray<T>::Front()
    {
        if (IsEmpty())
        {
            return std::nullopt;
        }
        return m_data[m_front + 1];
    }

    template <class T>
    std::optional<T> QueueUsingArray<T>::Rear()
    {
        if (IsEmpty())
        {
            return std::nullopt;
        }
        return m_data[m_rear];
    }

    template <class T>
    void QueueUsingArray<T>::Reset()
    {
        for (int i = 0; i < m_size; i++)
        {
            m_data[i] = 0;
        }
        m_front = -1;
        m_rear  = -1;
    }
} //namespace queue
