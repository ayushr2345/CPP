#pragma once

#include "CircularSinglyLinkedList.h"
#include "../../utils.h"

namespace linkedList
{
    template <class T>
    CircularSinglyLinkedList<T>::CircularSinglyLinkedList():
        m_choice                          ( 0 ),
        m_circularSinglyLinkedListMenuMap ( {} ),
        m_head                            ( nullptr )
    {
        m_circularSinglyLinkedListMenuMap.insert({ m_CircularSinglyLinkedListMenu(IS_EMPTY),
                                                   std::string("Check if Linked List is empty") });
        m_circularSinglyLinkedListMenuMap.insert({ m_CircularSinglyLinkedListMenu(GET),
                                                   std::string("Get an element at a given index") });
        m_circularSinglyLinkedListMenuMap.insert({ m_CircularSinglyLinkedListMenu(DISPLAY),
                                                   std::string("Display the linked list") });
        m_circularSinglyLinkedListMenuMap.insert({ m_CircularSinglyLinkedListMenu(INSERT_BEGINNING),
                                                   std::string("Insert at the beginning of the linked list") });
        m_circularSinglyLinkedListMenuMap.insert({ m_CircularSinglyLinkedListMenu(INSERT_END),
                                                   std::string("Insert at the end of the linked list") });
        m_circularSinglyLinkedListMenuMap.insert({ m_CircularSinglyLinkedListMenu(INSERT_INDEX),
                                                   std::string("Insert at a given index of the linked list") });
        m_circularSinglyLinkedListMenuMap.insert({ m_CircularSinglyLinkedListMenu(DELETE_BEGINNING),
                                                   std::string("Delete from the beginning of the linked list") });
        m_circularSinglyLinkedListMenuMap.insert({ m_CircularSinglyLinkedListMenu(DELETE_END),
                                                   std::string("Delete from the end of the linked list") });
        m_circularSinglyLinkedListMenuMap.insert({ m_CircularSinglyLinkedListMenu(DELETE_INDEX),
                                                   std::string("Delete from a given index of the linked list") });
        m_circularSinglyLinkedListMenuMap.insert({ m_CircularSinglyLinkedListMenu(LINEAR_SEARCH),
                                                   std::string("Perform a linear search on the linked list") });
        m_circularSinglyLinkedListMenuMap.insert({ m_CircularSinglyLinkedListMenu(MAX),
                                                   std::string("Find max element from the linked list") });
        m_circularSinglyLinkedListMenuMap.insert({ m_CircularSinglyLinkedListMenu(MIN),
                                                   std::string("Find min element from the linked list") });
        m_circularSinglyLinkedListMenuMap.insert({ m_CircularSinglyLinkedListMenu(SUM),
                                                   std::string("Find sum of all the elements in the linked list") });
        m_circularSinglyLinkedListMenuMap.insert({ m_CircularSinglyLinkedListMenu(AVG),
                                                   std::string("Find average of all the elements in the linked list") });
        m_circularSinglyLinkedListMenuMap.insert({ m_CircularSinglyLinkedListMenu(REVERSE),
                                                   std::string("Reverse the linked list") });
        m_circularSinglyLinkedListMenuMap.insert({ m_CircularSinglyLinkedListMenu(IS_SORTED),
                                                   std::string("Check if the linked list is sorted") });
        m_circularSinglyLinkedListMenuMap.insert({ m_CircularSinglyLinkedListMenu(SORT),
                                                   std::string("Sort the linked list") });
        m_circularSinglyLinkedListMenuMap.insert({ m_CircularSinglyLinkedListMenu(INSERT_SORTED),
                                                   std::string("Insert an element in the sorted position in the linked list") });
        m_circularSinglyLinkedListMenuMap.insert({ m_CircularSinglyLinkedListMenu(CONCATENATE),
                                                   std::string("Concatenate two linked lists") });
        m_circularSinglyLinkedListMenuMap.insert({ m_CircularSinglyLinkedListMenu(MERGE),
                                                   std::string("Merge two linked lists") });
        m_circularSinglyLinkedListMenuMap.insert({ m_CircularSinglyLinkedListMenu(BACK_TO_PREVIOUS_MENU),
                                                   std::string("Back to Previous Menu") });
        m_circularSinglyLinkedListMenuMap.insert({ m_CircularSinglyLinkedListMenu(EXIT_FROM_PROGRAM),
                                                   std::string("Exit from program") });
    }

    template <class T>
    CircularSinglyLinkedList<T>::~CircularSinglyLinkedList()
    {
        Node* temp = m_head;
        while (temp)
        {
            Node* temp2 = temp->m_m_next;
            if (temp2 == m_head)
            {
                break;
            }
            delete temp;
            temp = temp2;
        }
    }
    
    template <class T>
    const int CircularSinglyLinkedList<T>::GetMinCase()
    {
        return m_CircularSinglyLinkedListMenu::MIN_COUNT;
    }

    template <class T>
    const int CircularSinglyLinkedList<T>::GetMaxCase()
    {
        return m_CircularSinglyLinkedListMenu::MAX_COUNT;
    }

    template <class T>
    const int& CircularSinglyLinkedList<T>::GetChoice()
    {
        return m_choice;
    }

    template <class T>
    void CircularSinglyLinkedList<T>::GetChoiceInputFromUser()
    {
        utils::InputNumberFromUser(m_choice, 1, static_cast<int>(m_CircularSinglyLinkedListMenu::MAX_COUNT));
    }

    template <class T>
    void CircularSinglyLinkedList<T>::PrintMenu()
    {
        std::cout << std::endl;
        for (std::map<int, std::string>::iterator it = m_circularSinglyLinkedListMenuMap.begin();
            it != m_circularSinglyLinkedListMenuMap.end();
            it++)
        {
            std::cout << it->first << ". " << it->second << std::endl;
        }
        std::cout << "Please enter your choice: ";
    }

    template <class T>
    void CircularSinglyLinkedList<T>::PrintSelectedChoice()
    {
        std::cout << std::endl << std::endl
                << "You have chosen choice "
                << m_circularSinglyLinkedListMenuMap.at(m_choice)
                << std::endl;
    }

    template <class T>
    int CircularSinglyLinkedList<T>::GetSize()
    {
        if (not m_head)
        {
            return 0;
        }
        int count = 1;
        Node* temp = m_head;
        while (temp->m_m_next != m_head)
        {
            count++;
            temp = temp->m_m_next;
        }
        return count;
    }

    template <class T>
    CircularSinglyLinkedList<T>::Node* CircularSinglyLinkedList<T>::MoveToIndex(int index)
    {
        if (not IsIndexInBounds(index))
        {
            return nullptr;
        }
        Node* temp = m_head;
        int count = 0;

        while (index != count)
        {
            temp = temp->m_m_next;
            count++;
        }
        return temp;
    }

    template <class T>
    bool CircularSinglyLinkedList<T>::IsIndexInBounds(int index)
    {
        if (index < 0 or index > GetSize())
        {
            return false;
        }
        return true;
    }

    template <class T>
    bool CircularSinglyLinkedList<T>::IsEmpty()
    {
        return GetSize() ? false : true;
    }

    template <class T>
    std::optional<T> CircularSinglyLinkedList<T>::Get(int index)
    {
        if ((not IsIndexInBounds(index))or IsEmpty())
        {
            return std::nullopt;
        }
        Node* temp = MoveToIndex(index);
        T data = temp->m_m_data;
        return data;
    }

    template <class T>
    void CircularSinglyLinkedList<T>::Display()
    {
        if (IsEmpty())
        {
            std::cout << "The linked list is empty, please enter a few elements first before displaying" << std::endl;
        }
        else
        {
            Node* temp = m_head;
            std::cout << "------>";
            while (temp->m_m_next != m_head)
            {
                std::cout << temp->m_m_data << "-->";
                temp = temp->m_m_next;
            }
            std::cout << temp->m_m_data << "------>" << std::endl;
        }
    }

    template <class T>
    bool CircularSinglyLinkedList<T>::Insert(int index, T element)
    {
        if (not IsIndexInBounds(index))
        {
            std::cout << "Index out of bounds" << std::endl;
            return false;
        }

        if (index == 0)
        {
            Node* temp = new Node;
            temp->m_m_data = element;
            temp->m_m_next = m_head;
            
            Node* lastNode = MoveToIndex(GetSize() - 1);
            if (lastNode)
            {
                lastNode->m_m_next = temp;
            }
            else
            {
                temp->m_m_next = temp;
            }
            m_head = temp;
        }
        else
        {
            Node* temp = new Node;
            temp->m_m_data = element;
            Node* insertionNode = MoveToIndex(index - 1);
            temp->m_m_next = insertionNode->m_m_next;
            insertionNode->m_m_next = temp;
        }
        return true;
    }

    template <class T>
    std::optional<T> CircularSinglyLinkedList<T>::Remove(int index)
    {
        if (not IsIndexInBounds(index))
        {
            std::cout << "Index out of bounds" << std::endl;
            return std::nullopt;
        }

        if (IsEmpty())
        {
            std::cout << "Linked list is empty, cannot delete from the linked list" << std::endl;
            return std::nullopt;
        }

        T deletedValue;
        if (index == 0)
        {
            Node* deleted = m_head;

            Node* lastNode = MoveToIndex(GetSize() - 1);
            lastNode->m_m_next = deleted->m_m_next;

            m_head = m_head->m_m_next;
            deletedValue = deleted->m_m_data;

            if (deleted == m_head)
            {
                delete deleted;
                m_head = nullptr;
            }
            else
            {
                delete deleted;
            }
        }
        else
        {
            Node* temp = MoveToIndex(index - 1);
            Node* deleted = temp->m_m_next;

            temp->m_m_next = deleted->m_m_next;
            deletedValue = deleted->m_m_data;
            if (deleted == m_head)
            {
                delete deleted;
                m_head = nullptr;
            }
            else
            {
                delete deleted;
            }
        }
        return deletedValue;
    }

    template <class T>
    std::optional<int> CircularSinglyLinkedList<T>::LinearSearch(T element)
    {
        if (IsEmpty())
        {
            std::cout << "Cannot perform linear search as the linked list is empty" << std::endl;
            return std::nullopt;
        }
        else
        {
            Node* temp = m_head;
            int index = 0;

            while (temp->m_m_next != m_head and temp->m_m_data != element)
            {
                temp = temp->m_m_next;
                index++;
            }
            if (temp->m_m_data != element)
            {
                return std::nullopt;
            }
            return index;
        }
    }

    template <class T>
    std::optional<T> CircularSinglyLinkedList<T>::Max()
    {
        if (IsEmpty())
        {
            std::cout << "Cannot calculate the Maximum value as the linked list is empty" << std::endl;
            return std::nullopt;
        }

        T max = m_head->m_m_data;

        Node* temp = m_head->m_m_next;
        while (temp != m_head)
        {
            if (temp->m_m_data > max)
            {
                max = temp->m_m_data;
            }
            temp = temp->m_m_next;
        }
        return max;
    }

    template <class T>
    std::optional<T> CircularSinglyLinkedList<T>::Min()
    {
        if (IsEmpty())
        {
            std::cout << "Cannot calculate the Minimum value as the linked list is empty" << std::endl;
            return std::nullopt;
        }
        
        T min = m_head->m_m_data;

        Node* temp = m_head->m_m_next;
        while (temp != m_head)
        {
            if (temp->m_m_data < min)
            {
                min = temp->m_m_data;
            }
            temp = temp->m_m_next;
        }
        return min;
    }

    template <class T>
    std::optional<T> CircularSinglyLinkedList<T>::Sum()
    {
        if (IsEmpty())
        {
            std::cout << "Cannot calculate the Sum as the linked list is empty" << std::endl;
            return std::nullopt;
        }
        
        T sum = m_head->m_m_data;

        Node* temp = m_head->m_m_next;
        while (temp != m_head)
        {
            sum += temp->m_m_data;
            temp = temp->m_m_next;
        }
        return sum;
    }

    template <class T>
    std::optional<double> CircularSinglyLinkedList<T>::Avg()
    {
        if (IsEmpty())
        {
            std::cout << "Cannot calculate the Average as the linked list is empty" << std::endl;
            return std::nullopt;
        }
        
        return Sum().value() / GetSize();
    }

    template <class T>
    void CircularSinglyLinkedList<T>::Reverse()
    {
        if (IsEmpty())
        {
            std::cout << "Cannot reverse the linked list as it is empty" << std::endl;
        }
        else
        {
            Node* p = m_head;
            Node* q = p->m_m_next;
            Node* r = q->m_m_next;

            while (q or r)
            {
                q->m_m_next = p;
                if (q == m_head)
                {
                    m_head = p;
                    break;
                }
                p = q;
                q = r;
                r = r->m_m_next;
            }
        }
    }

    template <class T>
    bool CircularSinglyLinkedList<T>::IsSorted()
    {
        if (IsEmpty())
        {
            std::cout << "The linked list is empty" << std::endl;
            return false;
        }

        Node* temp = m_head;

        while (true)
        {
            if (temp->m_m_next != m_head and not (temp->m_m_data <= (temp->m_m_next)->m_m_data))
            {
                return false;
            }
            temp = temp->m_m_next;
            if (temp == m_head)
            {
                return true;
            }
        }
    }

    template <class T>
    void CircularSinglyLinkedList<T>::Sort()
    {
        if (IsEmpty())
        {
            std::cout << "The linked list is empty" << std::endl;
        }
        else
        {
            typename CircularSinglyLinkedList<T>::Node* current = m_head;

            int flag = 0;

            while (not flag)
            {
                typename CircularSinglyLinkedList<T>::Node* minNode = current;
                typename CircularSinglyLinkedList<T>::Node* nextNode = current->m_m_next;

                while (nextNode != m_head)
                {
                    if (nextNode->m_m_data < minNode->m_m_data)
                    {
                        minNode = nextNode;
                    }
                    nextNode = nextNode->m_m_next;
                }

                // Swap the data of current node with the minNode found
                if (minNode != current)
                {
                    T temp = current->m_m_data;
                    current->m_m_data = minNode->m_m_data;
                    minNode->m_m_data = temp;
                }

                current = current->m_m_next;

                if (current == m_head)
                {
                    flag = 1;
                }
            }
        }
    }


    template <class T>
    bool CircularSinglyLinkedList<T>::InsertSorted(T element)
    {

        if (IsEmpty())
        {
            std::cout << "The linked list is empty, inserting at 0 position" << std::endl;
            Insert(0, element);
            return true;
        }
        
        if (not IsSorted())
        {
            std::cout << "The linked list is not sorted, sorting the linked list first" << std::endl;
            Sort();
        }

        if (element < Get(0))
        {
            return Insert(0, element);
        }
        else if (element > Get(GetSize() - 1))
        {
            return Insert(GetSize(), element);
        }
        else
        {
            Node* temp = m_head;
            int index = 0;
            
            while (temp->m_m_next != m_head and (element > (temp->m_m_next)->m_m_data))
            {
                index++;
                temp = temp->m_m_next;
            }
            Insert(index + 1, element);
            return true;
        }
    }

    template <class T>
    CircularSinglyLinkedList<T>* Concatenate(CircularSinglyLinkedList<T>& A, CircularSinglyLinkedList<T>& B)
    {
        if (A.IsEmpty() and B.IsEmpty())
        {
            std::cout << "Both the linked lists are empty, can't concatenate empty linked lists" << std::endl;
            return nullptr;
        }

        CircularSinglyLinkedList<T>* temp = new CircularSinglyLinkedList<T>();

        typename CircularSinglyLinkedList<T>::Node* ATemp = A.m_head;
        int flag = 0;
        while (ATemp and not flag)
        {
            temp->Insert(temp->GetSize(), ATemp->m_m_data);
            ATemp = ATemp->m_m_next;
            if (ATemp == A.m_head)
            {
                flag = 1;
            }
        }

        flag = 0;

        typename CircularSinglyLinkedList<T>::Node* BTemp = B.m_head;
        while (BTemp and not flag)
        {
            temp->Insert(temp->GetSize(), BTemp->m_m_data);
            BTemp = BTemp->m_m_next;
            if (BTemp == B.m_head)
            {
                flag = 1;
            }
        }
        return temp;
    }

    template <class T>
    CircularSinglyLinkedList<T>* SortedMerge(CircularSinglyLinkedList<T>& A, CircularSinglyLinkedList<T>& B)
    {
        if (A.IsEmpty() and B.IsEmpty())
        {
            std::cout << "Both the linked lists are empty, can't do sorted merge" << std::endl;
            return nullptr;
        }

        if (not A.IsSorted())
        {
            std::cout << "Sorted merge can be performed only on sorted linked lists, A is not sorted, sorting it first" << std::endl;
            A.Sort();
        }

        if (not B.IsSorted())
        {
            std::cout << "Sorted merge can be performed only on sorted linked lists, B is not sorted, sorting it first" << std::endl;
            B.Sort();
        }

        CircularSinglyLinkedList<T>* temp = new CircularSinglyLinkedList<T>();

        int i = 0;
        int j = 0;
        int k = 0;

        while (i < A.GetSize() and j < B.GetSize())
        {
            const auto getA = A.Get(i);
            const auto getB = B.Get(j);
                
            if (getA.value() <= getB.value())
            {
                temp->Insert(k, getA.value());
                i++;
                k++;
            }
            else
            {
                temp->Insert(k, getB.value());
                j++;
                k++;
            }
        }

        while (i < A.GetSize())
        {   
            const auto getA = A.Get(i);
            temp->Insert(k, getA.value());
            i++;
            k++;
        }

        while (j < B.GetSize())
        {
            const auto getB = B.Get(j);
            temp->Insert(k, getB.value());
            j++;
            k++;
        }

        return temp;
    }
} // namespace linkedList
