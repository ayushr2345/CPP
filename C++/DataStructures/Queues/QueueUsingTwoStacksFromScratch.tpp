#pragma once

#include "QueueUsingTwoStacksFromScratch.h"

namespace queue
{
    template <class T>
    LinkedListFromScratch<T>::LinkedListFromScratch():
        m_head { nullptr }
    {
    }

    template <class T>
    LinkedListFromScratch<T>::~LinkedListFromScratch()
    {
        Node* temp = m_head;
        while (temp != nullptr)
        {
            Node* next = temp->m_m_next;
            delete temp;
            temp = next;
        }
        m_head = nullptr;
    }

    template <class T>
    bool LinkedListFromScratch<T>::IsEmpty()
    {
        return m_head == nullptr ? true : false;
    }

    template <class T>
    int LinkedListFromScratch<T>::GetSize()
    {
        if (IsEmpty())
        {
            return 0;
        }

        Node* temp = m_head;
        int size = 0;
        while (temp != nullptr)
        {
            size++;
            temp = temp->m_m_next;
        }
        return size;
    }

    template <class T>
    bool LinkedListFromScratch<T>::IsIndexOutOfBounds(const int index)
    {
        return index < 0 or index > GetSize() - 1 ? true : false;
    }

    template <class T>
    std::optional<typename LinkedListFromScratch<T>::Node*> LinkedListFromScratch<T>::GetNodeFromIndex(int index)
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
    bool LinkedListFromScratch<T>::Insert(const T element, const int index)
    {
        if (IsIndexOutOfBounds(index) and index != GetSize())
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
    std::optional<T> LinkedListFromScratch<T>::Remove(const int index)
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

        std::optional<Node*> previousNode = GetNodeFromIndex(index - 1);
        if (not previousNode.has_value())
        {
            return std::nullopt;
        }
        Node* temp = previousNode.value()->m_m_next;
        previousNode.value()->m_m_next = temp->m_m_next;
        T deleted = temp->m_m_data;
        delete temp;
        temp = nullptr;
        return deleted;
    }

    template <class T>
    std::optional<std::vector<T>> LinkedListFromScratch<T>::GetElements(const bool forward)
    {
        std::vector<T> vec;
        if (IsEmpty())
        {
            return vec;
        }

        Node* temp = m_head;
        while (temp != nullptr)
        {
            vec.push_back(temp->m_m_data);
            temp = temp->m_m_next;
        }

        if (forward)
        {
            return vec;
        }
        else
        {
            int i = 0;
            int j = vec.size() - 1;
            while (i <= j)
            {
                T temp = vec[i];
                vec[i] = vec[j];
                vec[j] = temp;
                i++;
                j--;
            }
            return vec;
        }
    }

    template <class T>
    StackFromScratch<T>::StackFromScratch()
    {
        m_data = new LinkedListFromScratch<T>;
    }

    template <class T>
    StackFromScratch<T>::~StackFromScratch()
    {
        delete m_data;
    }

    template <class T>
    bool StackFromScratch<T>::IsEmpty()
    {
        return m_data->IsEmpty();
    }

    template <class T>
    bool StackFromScratch<T>::Push(const T element)
    {
        return m_data->Insert(element, 0);
    }

    template <class T>
    std::optional<T> StackFromScratch<T>::Pop()
    {
        if (IsEmpty())
        {
            return std::nullopt;
        }

        return m_data->Remove(0);
    }

    template <class T>
    std::optional<T> StackFromScratch<T>::GetTop()
    {
        if (IsEmpty())
        {
            return std::nullopt;
        }
        auto topNode = m_data->GetNodeFromIndex(0);
        if (topNode.has_value())
        {
            return topNode.value()->m_m_data;
        }
        return std::nullopt;
	}

    template <class T>
    void StackFromScratch<T>::Display(const bool forward)
    {
        if (IsEmpty())
        {
            return;
        }

        auto elements = m_data->GetElements(forward);
        if (not elements.has_value())
        {
            return;
        }
        auto size = elements.value().size();
        for (int i = 0; i < size; i++)
        {
            std::cout << elements.value()[i] << " ";
        }
    }

    template <class T>
    QueueUsingTwoStacksFromScratch<T>::QueueUsingTwoStacksFromScratch() :
        m_choice                                (0),
        m_QueueUsingTwoStacksFromScratchMenuMap ({}),
        m_dataEnqueue                           { nullptr },
        m_dataDequeue                           { nullptr }
    {
        m_QueueUsingTwoStacksFromScratchMenuMap.insert({ m_QueueUsingTwoStacksFromScratchMenu(IS_EMPTY),
                                                         std::string("Check if the queue is empty") });
        m_QueueUsingTwoStacksFromScratchMenuMap.insert({ m_QueueUsingTwoStacksFromScratchMenu(DISPLAY),
                                                         std::string("Display the queue") });
        m_QueueUsingTwoStacksFromScratchMenuMap.insert({ m_QueueUsingTwoStacksFromScratchMenu(ENQUEUE),
                                                         std::string("Enqueue") });
        m_QueueUsingTwoStacksFromScratchMenuMap.insert({ m_QueueUsingTwoStacksFromScratchMenu(DEQUEUE),
                                                         std::string("Dequeue") });
        m_QueueUsingTwoStacksFromScratchMenuMap.insert({ m_QueueUsingTwoStacksFromScratchMenu(FRONT),
                                                         std::string("Get front of the Queue") });
        m_QueueUsingTwoStacksFromScratchMenuMap.insert({ m_QueueUsingTwoStacksFromScratchMenu(REAR),
                                                         std::string("Get rear of the Queue") });
        m_QueueUsingTwoStacksFromScratchMenuMap.insert({ m_QueueUsingTwoStacksFromScratchMenu(RESET),
                                                         std::string("Reset the queue") });
        m_QueueUsingTwoStacksFromScratchMenuMap.insert({ m_QueueUsingTwoStacksFromScratchMenu(BACK_TO_PREVIOUS_MENU),
                                                         std::string("Back to Previous Menu") });
        m_QueueUsingTwoStacksFromScratchMenuMap.insert({ m_QueueUsingTwoStacksFromScratchMenu(EXIT_FROM_PROGRAM),
                                                         std::string("Exit from program") });
        m_dataEnqueue = new StackFromScratch<T>;
        m_dataDequeue = new StackFromScratch<T>;
    }

    template <class T>
    QueueUsingTwoStacksFromScratch<T>::~QueueUsingTwoStacksFromScratch()
    {
		delete m_dataEnqueue;
		delete m_dataDequeue;
    }

    template <class T>
    const int QueueUsingTwoStacksFromScratch<T>::GetMinCase()
    {
        return m_QueueUsingTwoStacksFromScratchMenu::MIN_COUNT;
    }

    template <class T>
    const int QueueUsingTwoStacksFromScratch<T>::GetMaxCase()
    {
        return m_QueueUsingTwoStacksFromScratchMenu::MAX_COUNT;
    }

    template <class T>
    const int& QueueUsingTwoStacksFromScratch<T>::GetChoice()
    {
        return m_choice;
    }

    template <class T>
    void QueueUsingTwoStacksFromScratch<T>::GetChoiceInputFromUser()
    {
        utils::InputNumberFromUser(m_choice, 1, static_cast<int>(m_QueueUsingTwoStacksFromScratchMenu::MAX_COUNT));
    }

    template <class T>
    void QueueUsingTwoStacksFromScratch<T>::PrintMenu()
    {
        std::cout << std::endl;
        for (std::map<int, std::string>::iterator it = m_QueueUsingTwoStacksFromScratchMenuMap.begin();
            it != m_QueueUsingTwoStacksFromScratchMenuMap.end();
            it++)
        {
            std::cout << it->first << ". " << it->second << std::endl;
        }
        std::cout << "Please enter your choice: ";
    }

    template <class T>
    void QueueUsingTwoStacksFromScratch<T>::PrintSelectedChoice()
    {
        std::cout << std::endl << std::endl
            << "You have chosen choice "
            << m_QueueUsingTwoStacksFromScratchMenuMap.at(m_choice)
            << std::endl;
    }

	template <class T>
    bool QueueUsingTwoStacksFromScratch<T>::IsEmpty()
    {
        return m_dataEnqueue->IsEmpty() and m_dataDequeue->IsEmpty();
	}

    template <class T>
    void QueueUsingTwoStacksFromScratch<T>::Display()
    {
        m_dataDequeue->Display(true);
        m_dataEnqueue->Display(false);
	}

    template <class T>
	bool QueueUsingTwoStacksFromScratch<T>::Enqueue(const T element)
    {
        return m_dataEnqueue->Push(element);
	}

    template <class T>
    std::optional<T> QueueUsingTwoStacksFromScratch<T>::Dequeue()
    {
		if (IsEmpty())
        {
            return std::nullopt;
        }

        if (m_dataDequeue->IsEmpty())
        {
            while (not m_dataEnqueue->IsEmpty())
            {
				std::optional<T> poppedValue = m_dataEnqueue->Pop();
                if (not poppedValue.has_value())
                {
                    return std::nullopt;
                }
                else
                {
                    m_dataDequeue->Push(poppedValue.value());
                }
            }
        }

		return m_dataDequeue->Pop();
    }

    template <class T>
    std::optional<T> QueueUsingTwoStacksFromScratch<T>::Front()
    {
        if (IsEmpty())
        {
            return std::nullopt;
        }

        if (m_dataDequeue->IsEmpty())
        {
            while (not m_dataEnqueue->IsEmpty())
            {
                std::optional<T> poppedValue = m_dataEnqueue->Pop();
                if (not poppedValue.has_value())
                {
                    return std::nullopt;
                }
                else
                {
                    m_dataDequeue->Push(poppedValue.value());
                }
            }
        }

        return m_dataDequeue->GetTop();
    }

    template <class T>
    std::optional<T> QueueUsingTwoStacksFromScratch<T>::Rear()
    {
        if (IsEmpty())
        {
            return std::nullopt;
        }

        if (not m_dataEnqueue->IsEmpty())
        {
			return m_dataEnqueue->GetTop();
        }
        else
        {
            while (not m_dataDequeue->IsEmpty())
            {
                std::optional<T> poppedValue = m_dataDequeue->Pop();
                if (not poppedValue.has_value())
                {
                    return std::nullopt;
                }
                else
                {
                    m_dataEnqueue->Push(poppedValue.value());
                }
            }
        }

        return m_dataEnqueue->GetTop();
    }

    template <class T>
    void QueueUsingTwoStacksFromScratch<T>::Reset()
    {
        delete m_dataEnqueue;
        delete m_dataDequeue;
        m_dataEnqueue = new StackFromScratch<T>;
        m_dataDequeue = new StackFromScratch<T>;
	}
} //namespace queue
