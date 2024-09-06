#pragma once

#include "QueueUsingLinkedList.h"
#include "../../utils.h"

namespace queue
{
    template <class T>
    QueueUsingLinkedList<T>::QueueUsingLinkedList():
        m_choice                      ( 0 ),
        m_queueUsingLinkedListMenuMap ( {} ),
        m_front                       { nullptr },
        m_rear                        { nullptr }
    {
        m_queueUsingLinkedListMenuMap.insert({ m_QueueUsingLinkedListMenu(IS_EMPTY),
                                               std::string("Check if the queue is empty") });
        m_queueUsingLinkedListMenuMap.insert({ m_QueueUsingLinkedListMenu(DISPLAY),
                                               std::string("Display the queue") });
        m_queueUsingLinkedListMenuMap.insert({ m_QueueUsingLinkedListMenu(NUM_ELEMENTS),
                                               std::string("Number of elements in the queue") });
        m_queueUsingLinkedListMenuMap.insert({ m_QueueUsingLinkedListMenu(ENQUEUE),
                                               std::string("Enqueue") });
        m_queueUsingLinkedListMenuMap.insert({ m_QueueUsingLinkedListMenu(DEQUEUE),
                                               std::string("Dequeue") });
        m_queueUsingLinkedListMenuMap.insert({ m_QueueUsingLinkedListMenu(FRONT),
                                               std::string("Get front of the Queue") });
        m_queueUsingLinkedListMenuMap.insert({ m_QueueUsingLinkedListMenu(REAR),
                                               std::string("Get rear of the Queue") });
        m_queueUsingLinkedListMenuMap.insert({ m_QueueUsingLinkedListMenu(RESET),
                                               std::string("Reset the queue") });
        m_queueUsingLinkedListMenuMap.insert({ m_QueueUsingLinkedListMenu(BACK_TO_PREVIOUS_MENU),
                                               std::string("Back to Previous Menu") });
        m_queueUsingLinkedListMenuMap.insert({ m_QueueUsingLinkedListMenu(EXIT_FROM_PROGRAM),
                                               std::string("Exit from program") });
    }

    template <class T>
    QueueUsingLinkedList<T>::~QueueUsingLinkedList()
    {
        Reset();
    }

    template <class T>
    const int QueueUsingLinkedList<T>::GetMinCase()
    {
        return m_QueueUsingLinkedListMenu::MIN_COUNT;
    }

    template <class T>
    const int QueueUsingLinkedList<T>::GetMaxCase()
    {
        return m_QueueUsingLinkedListMenu::MAX_COUNT;
    }

    template <class T>
    const int& QueueUsingLinkedList<T>::GetChoice()
    {
        return m_choice;
    }

    template <class T>
    void QueueUsingLinkedList<T>::GetChoiceInputFromUser()
    {
        utils::InputNumberFromUser(m_choice, 1, static_cast<int>(m_QueueUsingLinkedListMenu::MAX_COUNT));
    }

    template <class T>
    void QueueUsingLinkedList<T>::PrintMenu()
    {
        std::cout << std::endl;
        for (std::map<int, std::string>::iterator it = m_queueUsingLinkedListMenuMap.begin();
            it != m_queueUsingLinkedListMenuMap.end();
            it++)
        {
            std::cout << it->first << ". " << it->second << std::endl;
        }
        std::cout << "Please enter your choice: ";
    }

    template <class T>
    void QueueUsingLinkedList<T>::PrintSelectedChoice()
    {
        std::cout << std::endl << std::endl
                << "You have chosen choice "
                << m_queueUsingLinkedListMenuMap.at(m_choice)
                << std::endl;
    }

    template <class T>
    bool QueueUsingLinkedList<T>::IsEmpty()
    {
        return m_front == nullptr ? true : false;
    }

    template <class T>
    void QueueUsingLinkedList<T>::Display()
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
    int QueueUsingLinkedList<T>::NumElements()
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
    bool QueueUsingLinkedList<T>::Enqueue(T element)
    {
        if (m_front == nullptr)
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
    bool QueueUsingLinkedList<T>::EnqueueSorted(T element)
    {
        if (m_front == nullptr)
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
            
            if (element < m_front->m_m_data)
            {
                temp->m_m_next = m_front;
                m_front = temp;
            }
            else if (element > m_rear->m_m_data)
            {
                temp->m_m_next = nullptr;
                m_rear->m_m_next = temp;
                m_rear = temp;
            }
            else
            {
                Node* itTemp = m_front;

                while (itTemp != nullptr)
                {
                    if ((itTemp->m_m_next)->m_m_data >= element)
                    {
                        temp->m_m_next = itTemp->m_m_next;
                        itTemp->m_m_next = temp;
                        break;
                    }
                    itTemp = itTemp->m_m_next;
                }
            }
        }
        return true;
    }

    template <class T>
    std::optional<T> QueueUsingLinkedList<T>::Dequeue()
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
    std::optional<T> QueueUsingLinkedList<T>::Front()
    {
        if (IsEmpty())
        {
            return std::nullopt;
        }
        return m_front->m_m_data;
    }

    template <class T>
    std::optional<T> QueueUsingLinkedList<T>::Rear()
    {
        if (IsEmpty())
        {
            return std::nullopt;
        }
        return m_rear->m_m_data;
    }

    template <class T>
    void QueueUsingLinkedList<T>::Reset()
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
