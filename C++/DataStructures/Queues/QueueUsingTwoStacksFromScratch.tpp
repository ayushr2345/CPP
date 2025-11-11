#pragma once

#include "QueueUsingTwoStacksFromScratch.h"

namespace queue
{
    template <class T>
    LinkedListFromScratch::LinkedListFromScratch():
        m_head { nullptr }
    {
    }

    template <class T>
    LinkedListFromScratch::~LinkedListFromScratch()
    {
        delete m_head;
        m_head == nullptr;
    }

    template <class T>
    bool LinkedListFromScratch::IsEmpty()
    {
        return m_head == nullptr ? true : false;
    }

    template <class T>
    int LinkedListFromScratch::GetSize()
    {
        if (IsEmpty())
        {
            return 0;
        }
        Node* temp == m_head;
        int size = 0;
        while (temp != nullptr)
        {
            size++;
        }
        return size;
    }

    template <class T>
    int LinkedListFromScratch::IsIndexOutOfBounds(const int index)
    {
        return index < 0 or index > GetSize() ? true : false;
    }

    template <class T>
    std::optional<Node*> LinkedListFromScratch::GetNodeFromIndex(int index)
    {
        if (IsIndexOutOfBounds(index))
        {
            return std::nullopt;
        }

        if (not IsEmpty())
        {
            Node* temp = m_head;
            while (index != 0)
            {
                temp = temp->m_m_next;
                index--;
            }
            return temp;
        }
        return std::nullopt;
    }

    template <class T>
    bool LinkedListFromScratch::Insert(const T element, const int index)
    {
        if (IsIndexOutOfBounds(index))
        {
            return false;
        }

        Node* temp = new Node();
        temp->m_m_data = element;
        temp->m_m_next = nullptr;

        if (IsEmpty())
        {
            m_head = temp;
            return true;
        }

        if (index == 0)
        {
            temp->m_m_next = m_head;
            m_head = temp;
            return true;
        }

        std::optional<Node*> currentLastNode = GetNodeFromIndex(index - 1);
        if (not currentLastNode.has_value())
        {
            return false;
        }
        temp->m_m_next = currentLastNode.value()->m_m_next;
        currentLastNode.value()->m_m_next = temp;
        return true;
    }

    template <class T>
    std::optional<T> LinkedListFromScratch::Remove(const int index)
    {
        if (IsIndexOutOfBounds(index) or IsEmpty())
        {
            return std::nullopt;
        }

        if (index == 0)
        {
            Node* temp = m_head;
            m_head = temp->m_m_next;
            T deleted = temp->m_m_data;
            delete temp;
            temp = nullptr;
            return deleted;
        }

        
    }
} //namespace queue
