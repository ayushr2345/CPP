#pragma once

#include "LinearDoublyLinkedList.h"
#include "../../utils.h"

namespace linkedList
{
    template <class T>
    LinearDoublyLinkedList<T>::LinearDoublyLinkedList():
        m_choice                        ( 0 ),
        m_linearDoublyLinkedListMenuMap ( {} ),
        m_head                          ( nullptr )
    {
        m_linearDoublyLinkedListMenuMap.insert({ m_LinearDoublyLinkedListMenu(IS_EMPTY),
                                                 std::string("Check if Linked List is empty") });
        m_linearDoublyLinkedListMenuMap.insert({ m_LinearDoublyLinkedListMenu(GET),
                                                 std::string("Get an element at a given index") });
        m_linearDoublyLinkedListMenuMap.insert({ m_LinearDoublyLinkedListMenu(DISPLAY),
                                                 std::string("Display the linked list") });
        m_linearDoublyLinkedListMenuMap.insert({ m_LinearDoublyLinkedListMenu(INSERT_BEGINNING),
                                                 std::string("Insert at the beginning of the linked list") });
        m_linearDoublyLinkedListMenuMap.insert({ m_LinearDoublyLinkedListMenu(INSERT_END),
                                                 std::string("Insert at the end of the linked list") });
        m_linearDoublyLinkedListMenuMap.insert({ m_LinearDoublyLinkedListMenu(INSERT_INDEX),
                                                 std::string("Insert at a given index of the linked list") });
        m_linearDoublyLinkedListMenuMap.insert({ m_LinearDoublyLinkedListMenu(DELETE_BEGINNING),
                                                 std::string("Delete from the beginning of the linked list") });
        m_linearDoublyLinkedListMenuMap.insert({ m_LinearDoublyLinkedListMenu(DELETE_END),
                                                 std::string("Delete from the end of the linked list") });
        m_linearDoublyLinkedListMenuMap.insert({ m_LinearDoublyLinkedListMenu(DELETE_INDEX),
                                                 std::string("Delete from a given index of the linked list") });
        m_linearDoublyLinkedListMenuMap.insert({ m_LinearDoublyLinkedListMenu(LINEAR_SEARCH),
                                                 std::string("Perform a linear search on the linked list") });
        m_linearDoublyLinkedListMenuMap.insert({ m_LinearDoublyLinkedListMenu(MAX),
                                                 std::string("Find max element from the linked list") });
        m_linearDoublyLinkedListMenuMap.insert({ m_LinearDoublyLinkedListMenu(MIN),
                                                 std::string("Find min element from the linked list") });
        m_linearDoublyLinkedListMenuMap.insert({ m_LinearDoublyLinkedListMenu(SUM),
                                                 std::string("Find sum of all the elements in the linked list") });
        m_linearDoublyLinkedListMenuMap.insert({ m_LinearDoublyLinkedListMenu(AVG),
                                                 std::string("Find average of all the elements in the linked list") });
        m_linearDoublyLinkedListMenuMap.insert({ m_LinearDoublyLinkedListMenu(REVERSE),
                                                 std::string("Reverse the linked list") });
        m_linearDoublyLinkedListMenuMap.insert({ m_LinearDoublyLinkedListMenu(IS_SORTED),
                                                 std::string("Check if the linked list is sorted") });
        m_linearDoublyLinkedListMenuMap.insert({ m_LinearDoublyLinkedListMenu(SORT),
                                                 std::string("Sort the linked list") });
        m_linearDoublyLinkedListMenuMap.insert({ m_LinearDoublyLinkedListMenu(INSERT_SORTED),
                                                 std::string("Insert an element in the sorted position in the linked list") });
        m_linearDoublyLinkedListMenuMap.insert({ m_LinearDoublyLinkedListMenu(CONCATENATE),
                                                 std::string("Concatenate two linked lists") });
        m_linearDoublyLinkedListMenuMap.insert({ m_LinearDoublyLinkedListMenu(MERGE),
                                                 std::string("Merge two linked lists") });
        m_linearDoublyLinkedListMenuMap.insert({ m_LinearDoublyLinkedListMenu(BACK_TO_PREVIOUS_MENU),
                                                 std::string("Back to Previous Menu") });
        m_linearDoublyLinkedListMenuMap.insert({ m_LinearDoublyLinkedListMenu(EXIT_FROM_PROGRAM),
                                                 std::string("Exit from program") });
    }

    template <class T>
    LinearDoublyLinkedList<T>::~LinearDoublyLinkedList()
    {
        Node* temp = m_head;

        while (temp)
        {
            Node* temp2 = temp->m_m_next;
            delete temp;
            temp = temp2;
        }
    }
    
    template <class T>
    const int LinearDoublyLinkedList<T>::GetMinCase()
    {
        return m_LinearDoublyLinkedListMenu::MIN_COUNT;
    }

    template <class T>
    const int LinearDoublyLinkedList<T>::GetMaxCase()
    {
        return m_LinearDoublyLinkedListMenu::MAX_COUNT;
    }

    template <class T>
    const int& LinearDoublyLinkedList<T>::GetChoice()
    {
        return m_choice;
    }

    template <class T>
    void LinearDoublyLinkedList<T>::GetChoiceInputFromUser()
    {
        utils::InputNumberFromUser(m_choice, 1, static_cast<int>(m_LinearDoublyLinkedListMenu::MAX_COUNT));
    }

    template <class T>
    void LinearDoublyLinkedList<T>::PrintMenu()
    {
        std::cout << std::endl;
        for (std::map<int, std::string>::iterator it = m_linearDoublyLinkedListMenuMap.begin();
            it != m_linearDoublyLinkedListMenuMap.end();
            it++)
        {
            std::cout << it->first << ". " << it->second << std::endl;
        }
        std::cout << "Please enter your choice: ";
    }

    template <class T>
    void LinearDoublyLinkedList<T>::PrintSelectedChoice()
    {
        std::cout << std::endl << std::endl
                << "You have chosen choice "
                << m_linearDoublyLinkedListMenuMap.at(m_choice)
                << std::endl;
    }

    template <class T>
    int LinearDoublyLinkedList<T>::GetSize()
    {
        if (not m_head)
        {
            return 0;
        }
        int count = 1;
        Node* temp = m_head;
        while (temp->m_m_next)
        {
            count++;
            temp = temp->m_m_next;
        }
        return count;
    }

    template <class T>
    LinearDoublyLinkedList<T>::Node* LinearDoublyLinkedList<T>::MoveToIndex(int index)
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
    bool LinearDoublyLinkedList<T>::IsIndexInBounds(int index)
    {
        if (index < 0 or index > GetSize())
        {
            return false;
        }
        return true;
    }

    template <class T>
    bool LinearDoublyLinkedList<T>::IsEmpty()
    {
        return GetSize() ? false : true;
    }

    template <class T>
    std::optional<T> LinearDoublyLinkedList<T>::Get(int index)
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
    void LinearDoublyLinkedList<T>::Display()
    {
        if (IsEmpty())
        {
            std::cout << "The linked list is empty, please enter a few elements first before displaying" << std::endl;
        }
        else
        {
            Node* temp = m_head;
            while (temp)
            {
                std::cout << temp->m_m_data << "-->";
                temp = temp->m_m_next;
            }
            std::cout << std::endl;
        }
    }

    template <class T>
    bool LinearDoublyLinkedList<T>::Insert(int index, T element)
    {
        if (not IsIndexInBounds(index))
        {
            std::cout << "Index out of bounds" << std::endl;
            return false;
        }

        if (index == 0)
        {
            Node* temp = new Node;
            temp->m_m_prev = nullptr;
            temp->m_m_data = element;
            temp->m_m_next = m_head;
            m_head->m_m_prev = temp;
            m_head = temp;
        }
        else
        {
            Node* temp = new Node;
            temp->m_m_data = element;
            Node* insertionNode = MoveToIndex(index - 1);
            temp->m_m_prev = insertionNode;
            temp->m_m_next = insertionNode->m_m_next;
            insertionNode->m_m_next = temp;
            (temp->m_m_next)->m_m_prev = temp;
        }
        return true;
    }

    template <class T>
    std::optional<T> LinearDoublyLinkedList<T>::Remove(int index)
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
            m_head = m_head->m_m_next;
            deletedValue = deleted->m_m_data;
            delete deleted;
        }
        else
        {
            Node* temp = MoveToIndex(index - 1);
            Node* deleted = temp->m_m_next;

            temp->m_m_next = deleted->m_m_next;
            deletedValue = deleted->m_m_data;
            delete deleted;
        }
        return deletedValue;
    }

    template <class T>
    std::optional<int> LinearDoublyLinkedList<T>::LinearSearch(T element)
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

            while (temp and temp->m_m_data != element)
            {
                temp = temp->m_m_next;
                index++;
            }
            if (not temp)
            {
                return std::nullopt;
            }
            return index;
        }
    }

    template <class T>
    std::optional<T> LinearDoublyLinkedList<T>::Max()
    {
        if (IsEmpty())
        {
            std::cout << "Cannot calculate the Maximum value as the linked list is empty" << std::endl;
            return std::nullopt;
        }

        T max = m_head->m_m_data;

        Node* temp = m_head->m_m_next;
        while (temp)
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
    std::optional<T> LinearDoublyLinkedList<T>::Min()
    {
        if (IsEmpty())
        {
            std::cout << "Cannot calculate the Minimum value as the linked list is empty" << std::endl;
            return std::nullopt;
        }
        
        T min = m_head->m_m_data;

        Node* temp = m_head->m_m_next;
        while (temp)
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
    std::optional<T> LinearDoublyLinkedList<T>::Sum()
    {
        if (IsEmpty())
        {
            std::cout << "Cannot calculate the Sum as the linked list is empty" << std::endl;
            return std::nullopt;
        }
        
        T sum = 0;
        Node* temp = m_head;
        while (temp)
        {
            sum += temp->m_m_data;
            temp = temp->m_m_next;
        }
        return sum;
    }

    template <class T>
    std::optional<double> LinearDoublyLinkedList<T>::Avg()
    {
        if (IsEmpty())
        {
            std::cout << "Cannot calculate the Average as the linked list is empty" << std::endl;
            return std::nullopt;
        }
        
        return Sum().value() / GetSize();
    }

    template <class T>
    void LinearDoublyLinkedList<T>::Reverse()
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
                if (p == m_head)
                {
                    p->m_m_next = nullptr;
                }
                p = q;
                q = r;
                r = r ? r = r->m_m_next : nullptr;
            }
            m_head = p;
        }
    }

    template <class T>
    bool LinearDoublyLinkedList<T>::IsSorted()
    {
        if (IsEmpty())
        {
            std::cout << "The linked list is empty" << std::endl;
            return false;
        }

        Node* temp = m_head;

        while (temp)
        {
            if (temp->m_m_next and not (temp->m_m_data <= (temp->m_m_next)->m_m_data))
            {
                return false;
            }
            temp = temp->m_m_next;
        }
        return true;
    }

    template <class T>
    void LinearDoublyLinkedList<T>::Sort()
    {
        if (IsEmpty())
        {
            std::cout << "The linked list is empty" << std::endl;
        }
        else
        {
            typename LinearDoublyLinkedList<T>::Node* current = m_head;

            while (current != nullptr)
            {
                typename LinearDoublyLinkedList<T>::Node* minNode = current;
                typename LinearDoublyLinkedList<T>::Node* nextNode = current->m_m_next;

                while (nextNode != nullptr)
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
            }
        }
    }

    template <class T>
    bool LinearDoublyLinkedList<T>::InsertSorted(T element)
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
            
            while (temp->m_m_next and (element > (temp->m_m_next)->m_m_data))
            {
                index++;
                temp = temp->m_m_next;
            }
            Insert(index + 1, element);
            return true;
        }
    }

    template <class T>
    LinearDoublyLinkedList<T>* Concatenate(LinearDoublyLinkedList<T>& A, LinearDoublyLinkedList<T>& B)
    {
        if (A.IsEmpty() and B.IsEmpty())
        {
            std::cout << "Both the linked lists are empty, can't concatenate empty linked lists" << std::endl;
            return nullptr;
        }

        LinearDoublyLinkedList<T>* temp = new LinearDoublyLinkedList<T>();

        typename LinearDoublyLinkedList<T>::Node* ATemp = A.m_head;
        while (ATemp)
        {
            temp->Insert(temp->GetSize(), ATemp->m_m_data);
            ATemp = ATemp->m_m_next;
        }

        typename LinearDoublyLinkedList<T>::Node* BTemp = B.m_head;
        while (BTemp)
        {
            temp->Insert(temp->GetSize(), BTemp->m_m_data);
            BTemp = BTemp->m_m_next;
        }
        return temp;
    }

    template <class T>
    LinearDoublyLinkedList<T>* SortedMerge(LinearDoublyLinkedList<T>& A, LinearDoublyLinkedList<T>& B)
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

        LinearDoublyLinkedList<T>* temp = new LinearDoublyLinkedList<T>();

        int i = 0;
        int j = 0;
        int k = 0;

        while (i < A.GetSize() and j < B.GetSize())
        {
            const auto getA = A.Get(i);
            const auto getB = A.Get(j);
                
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
