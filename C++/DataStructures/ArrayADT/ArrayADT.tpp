#pragma once

#include "ArrayADT.h"

namespace arrayAdt
{
    template <class T>
    ArrayADT<T>::ArrayADT(int length):
        m_choice            (0),
        m_arrayADTMenuMap   ({}),
        m_size              (0),
        m_length            (length),
        m_arr               (nullptr)
    {
        m_arrayADTMenuMap.insert({ m_ArrayADTMenu(IS_EMPTY),
                                   std::string("Check if the array is empty") });
        m_arrayADTMenuMap.insert({ m_ArrayADTMenu(IS_FULL),
                                   std::string("Check if the array is full") });
        m_arrayADTMenuMap.insert({ m_ArrayADTMenu(GET),
                                   std::string("Get an element at a particular index") });
        m_arrayADTMenuMap.insert({ m_ArrayADTMenu(SET),
                                   std::string("Set an element at a particular index") });
        m_arrayADTMenuMap.insert({ m_ArrayADTMenu(DISPLAY),
                                   std::string("Display the array") });
        m_arrayADTMenuMap.insert({ m_ArrayADTMenu(INSERT_BEGINNING),
                                   std::string("Insert at the beginning of the array") });
        m_arrayADTMenuMap.insert({ m_ArrayADTMenu(INSERT_END),
                                   std::string("Insert at the end of the array") });
        m_arrayADTMenuMap.insert({ m_ArrayADTMenu(INSERT_INDEX),
                                   std::string("Insert at a particular index in the array") });
        m_arrayADTMenuMap.insert({ m_ArrayADTMenu(DELETE_BEGINNING),
                                   std::string("Delete from the beginning of the array") });
        m_arrayADTMenuMap.insert({ m_ArrayADTMenu(DELETE_END),
                                   std::string("Delete from the end of the array") });
        m_arrayADTMenuMap.insert({ m_ArrayADTMenu(DELETE_INDEX),
                                   std::string("Delete from an index of the array") });                           
        m_arrayADTMenuMap.insert({ m_ArrayADTMenu(LINEAR_SEARCH),
                                   std::string("Perform a linear search on the array") });
        m_arrayADTMenuMap.insert({ m_ArrayADTMenu(BINARY_SEARCH),
                                   std::string("Perform a binary search on the array") });
        m_arrayADTMenuMap.insert({ m_ArrayADTMenu(MAX),
                                   std::string("Find the maximum element of the array") });
        m_arrayADTMenuMap.insert({ m_ArrayADTMenu(MIN),
                                   std::string("Find the minimum element of the array") });
        m_arrayADTMenuMap.insert({ m_ArrayADTMenu(SUM),
                                   std::string("Calculate sum of all elements of the array") });
        m_arrayADTMenuMap.insert({ m_ArrayADTMenu(AVG),
                                   std::string("Calculate average of all elements of the array") });
        m_arrayADTMenuMap.insert({ m_ArrayADTMenu(REVERSE),
                                   std::string("Reverse the array") });
        m_arrayADTMenuMap.insert({ m_ArrayADTMenu(LEFT_SHIFT),
                                   std::string("Left shift the array") });
        m_arrayADTMenuMap.insert({ m_ArrayADTMenu(RIGHT_SHIFT),
                                   std::string("Right shift the array") });
        m_arrayADTMenuMap.insert({ m_ArrayADTMenu(LEFT_ROTATE),
                                   std::string("Left rotate the array") });
        m_arrayADTMenuMap.insert({ m_ArrayADTMenu(RIGHT_ROTATE),
                                   std::string("Right rotate the array") });
        m_arrayADTMenuMap.insert({ m_ArrayADTMenu(IS_SORTED),
                                   std::string("Check if the array is sorted") });
        m_arrayADTMenuMap.insert({ m_ArrayADTMenu(SORT),
                                   std::string("Sort the array") });
        m_arrayADTMenuMap.insert({ m_ArrayADTMenu(INSERT_SORTED),
                                   std::string("Insert an element in a sorted position in the array") });
        m_arrayADTMenuMap.insert({ m_ArrayADTMenu(CONCATENATE),
                                   std::string("Concatenate two arrays") });
        m_arrayADTMenuMap.insert({ m_ArrayADTMenu(MERGE),
                                   std::string("Sorted merge two arrays") });
        m_arrayADTMenuMap.insert({ m_ArrayADTMenu(UNION),
                                   std::string("Perform union of two arrays") });
        m_arrayADTMenuMap.insert({ m_ArrayADTMenu(INTERSECTION),
                                   std::string("Perform intersection of two arrays") });
        m_arrayADTMenuMap.insert({ m_ArrayADTMenu(DIFFERENCE),
                                   std::string("Perform difference of two arrays") });
        m_arrayADTMenuMap.insert({ m_ArrayADTMenu(BACK_TO_PREVIOUS_MENU),
                                   std::string("Back to Previous Menu") });
        m_arrayADTMenuMap.insert({ m_ArrayADTMenu(EXIT_FROM_PROGRAM),
                                   std::string("Exit from program") });

        m_arr = new T[length];
    }

    template <class T>
    ArrayADT<T>::~ArrayADT()
    {
        delete m_arr;
        m_arr = nullptr;
        m_size = 0;
        m_length = 0;
    }
    
    template <class T>
    const int ArrayADT<T>::GetMinCase()
    {
        return m_ArrayADTMenu::MIN_COUNT;
    }

    template <class T>
    const int ArrayADT<T>::GetMaxCase()
    {
        return m_ArrayADTMenu::MAX_COUNT;
    }

    template <class T>
    const int& ArrayADT<T>::GetChoice()
    {
        return m_choice;
    }

    template <class T>
    void ArrayADT<T>::GetChoiceInputFromUser()
    {
        utils::InputNumberFromUser(m_choice, 1, static_cast<int>(m_ArrayADTMenu::MAX_COUNT));
    }

    template <class T>
    void ArrayADT<T>::PrintMenu()
    {
        std::cout << std::endl;
        for (std::map<int, std::string>::iterator it = m_arrayADTMenuMap.begin();
            it != m_arrayADTMenuMap.end();
            it++)
        {
            std::cout << it->first << ". " << it->second << std::endl;
        }
        std::cout << "Please enter your choice: ";
    }

    template <class T>
    void ArrayADT<T>::PrintSelectedChoice()
    {
        std::cout << std::endl << std::endl
                << "You have chosen choice "
                << m_arrayADTMenuMap.at(m_choice)
                << std::endl;
    }

    template <class T>
    int ArrayADT<T>::GetSize()
    {
        return m_size;
    }

    template <class T>
    int ArrayADT<T>::GetLength()
    {
        return m_length;
    }

    template <class T>
    bool ArrayADT<T>::IsIndexInBounds(int index)
    {
        if (index < 0 or index > m_length - 1)
        {
            return false;
        }
        return true;
    }

    template <class T>
    bool ArrayADT<T>::IsEmpty()
    {
        return m_size ? false : true;
    }

    template <class T>
    bool ArrayADT<T>::IsFull()
    {
        if (IsEmpty())
        {
            return false;
        }
        return m_size == m_length ? true : false;
    }

    template <class T>
    std::optional<T> ArrayADT<T>::Get(int index)
    {
        if ((not IsIndexInBounds(index))or IsEmpty())
        {
            return std::nullopt;
        }
        return m_arr[index];
    }

    template <class T>
    bool ArrayADT<T>::Set(int index, T element)
    {
        if ((not IsIndexInBounds(index)) or IsEmpty())
        {
            return false;
        }
        m_arr[index] = element;
        return true;
    }

    template <class T>
    void ArrayADT<T>::Display()
    {
        if (IsEmpty())
        {
            std::cout << "The array is empty, please enter a few elements first before displaying" << std::endl;
        }
        else
        {
            std::cout << "The indexes of the array are:  ";
            for (int i = 0; i < m_size; i++)
            {
                std::cout << i << " ";
            }
            std::cout << std::endl;

            std::cout << "The contents of the array are: ";
            for (int i = 0; i < m_size; i++)
            {
                std::cout << m_arr[i] << " ";
            }
            std::cout << std::endl;
        }
    }

    template <class T>
    bool ArrayADT<T>::Insert(int index, T element)
    {
        if (not IsIndexInBounds(index))
        {
            std::cout << "Index out of bounds" << std::endl;
            return false;
        }

        if(IsFull())
        {
            std::cout << "The array is full, cannot insert any more elements" << std::endl;
            return false;
        }

        if (index == m_size)
        {
            m_arr[index] = element;
            m_size++;
        }
        else if (index == 0)
        {
            m_arr[m_size] = m_arr[m_size - 1];
            RightShift(0, m_size);
            m_arr[index] = element;
            m_size++;
        }
        else
        {
            m_arr[m_size] = m_arr[m_size - 1];
            RightShift(index, m_size);
            m_arr[index] = element;
            m_size++;
        }
        return true;
    }

    template <class T>
    std::optional<T> ArrayADT<T>::Remove(int index)
    {
        if (not IsIndexInBounds(index))
        {
            std::cout << "Index out of bounds" << std::endl;
            return std::nullopt;
        }

        if (IsEmpty())
        {
            std::cout << "Array is empty, cannot delete from the array" << std::endl;
            return std::nullopt;
        }

        T deletedValue = {};
        if (index == m_size - 1)
        {
            deletedValue = m_arr[index];
            m_size--;
        }
        else if (index == 0)
        {
            deletedValue = m_arr[index];
            LeftShift(0, m_size);
            m_size--;
        }
        else
        {
            deletedValue = m_arr[index];
            LeftShift(index, m_size);
            m_size--;
        }

        return deletedValue;
    }

    template <class T>
    std::optional<int> ArrayADT<T>::LinearSearch(T element)
    {
        if (IsEmpty())
        {
            std::cout << "Cannot perform linear search as the array is empty" << std::endl;
            return std::nullopt;
        }
        else
        {
            for (int i = 0; i < m_size; i++)
            {
                if (element == m_arr[i])
                {
                    return i;
                }
            }
            return std::nullopt;
        }
    }

    template <class T>
    std::optional<int> ArrayADT<T>::BinarySearch(T element)
    {
        if (IsEmpty())
        {
            std::cout << "Cannot perform binary search as the array is empty" << std::endl;
            return std::nullopt;
        }
        else
        {
            int l = 0;
            int h = m_size - 1;
            int mid = (l + h) / 2;

            while (l <= h)
            {

                if (element == m_arr[mid])
                {
                        return mid;
                }
                else if (element < m_arr[mid])
                {
                        h = mid - 1;
                        mid = (l + h) / 2;
                }
                else if (element > m_arr[mid])
                {
                        l = mid + 1;
                        mid = (l + h) / 2;
                }
            }

            return std::nullopt;
        }
    }

    template <class T>
    std::optional<T> ArrayADT<T>::Max()
    {
        if (IsEmpty())
        {
            std::cout << "Cannot calculate the Maximum value as the array is empty" << std::endl;
            return std::nullopt;
        }

        T max = m_arr[0];
        for (int i = 0; i < m_size; i++)
        {
            if (m_arr[i] > max)
            {
                max = m_arr[i];
            }
        }
        return max;
    }

    template <class T>
    std::optional<T> ArrayADT<T>::Min()
    {
        if (IsEmpty())
        {
            std::cout << "Cannot calculate the Minimum value as the array is empty" << std::endl;
            return std::nullopt;
        }
        
        T min = m_arr[0];
        for (int i = 0; i < m_size; i++)
        {
            if (m_arr[i] < min)
            {
                min = m_arr[i];
            }
        }
        return min;
    }

    template <class T>
    std::optional<T> ArrayADT<T>::Sum()
    {
        if (IsEmpty())
        {
            std::cout << "Cannot calculate the Sum as the array is empty" << std::endl;
            return std::nullopt;
        }
        
        T sum = 0;
        for (int i = 0; i < m_size; i++)
        {
            sum += m_arr[i];
        }
        return sum;
    }

    template <class T>
    std::optional<double> ArrayADT<T>::Avg()
    {
        if (IsEmpty())
        {
            std::cout << "Cannot calculate the Average as the array is empty" << std::endl;
            return std::nullopt;
        }
        
        return Sum().value() / m_size;
    }

    template <class T>
    void ArrayADT<T>::Reverse()
    {
        if (IsEmpty())
        {
            std::cout << "Cannot reverse the array as it is empty" << std::endl;
        }
        else
        {
            int i = 0;
            int j = m_size - 1;

            T temp;
            while (i <= j)
            {
                temp = m_arr[i];
                m_arr[i] = m_arr[j];
                m_arr[j] = temp;
                i++;
                j--;
            }
        }
    }

    template <class T>
    void ArrayADT<T>::LeftShift(int from, int to)
    {
        if (IsEmpty())
        {
            std::cout << "The array is empty. Please enter some data and then try to Left Shift" << std::endl;
        }
        else
        {
            for (int i = from; i < to; i++)
            {
                m_arr[i] = m_arr[i + 1];
            }
            m_arr[to] = 0;
        }
    }

    template <class T>
    void ArrayADT<T>::RightShift(int from, int to)
    {
        if (IsEmpty())
        {
            std::cout << "The array is empty. Please enter some data and then try to Right Shift" << std::endl;
        }
        else
        {
            for (int i = to; i > from; i--)
            {
                m_arr[i] = m_arr[i - 1];
            }
            m_arr[from] = 0;
        }
    }

    template <class T>
    void ArrayADT<T>::LeftRotate(int from, int to)
    {
        if (IsEmpty())
        {
            std::cout << "The array is empty. Please enter some data and then try to Left Rotate" << std::endl;
        }
        else
        {
            T temp = m_arr[from];
            LeftShift(from, to);
            m_arr[to] = temp;
        }
    }

    template <class T>
    void ArrayADT<T>::RightRotate(int from, int to)
    {
        if (IsEmpty())
        {
            std::cout << "The array is empty. Please enter some data and then try to Right Rotate" << std::endl;
        }
        else
        {
            T temp = m_arr[to];
            RightShift(from, to);
            m_arr[from] = temp;
        }
    }

    template <class T>
    bool ArrayADT<T>::IsSorted()
    {
        if (IsEmpty())
        {
            std::cout << "The array is empty" << std::endl;
            return false;
        }

        for (int i = 0; i < m_size - 1; i++)
        {
            if (not (m_arr[i] < m_arr[i + 1]))
            {
                return false;
            }
        }
        return true;
    }

    template <class T>
    void ArrayADT<T>::Sort()
    {
        if (IsEmpty())
        {
            std::cout << "The array is empty" << std::endl;
        }
        else
        {
            for (int i = 0; i < m_size - 1; i++)
            {
                int minIndex = i;
                for (int j = i + 1; j < m_size; j++)
                {
                    if (m_arr[j] < m_arr[minIndex])
                    {
                        minIndex = j;
                    }
                }

                if (minIndex != i)
                {
                    T temp = m_arr[i];
                    m_arr[i] = m_arr[minIndex];
                    m_arr[minIndex] = temp;
                }
            }
        }
    }

    template <class T>
    bool ArrayADT<T>::InsertSorted(T element)
    {
        if(IsFull())
        {
            std::cout << "The array is full, please remove an element and try again" << std::endl;
            return false;
        }

        if (IsEmpty())
        {
            std::cout << "The array is empty, inserting at 0 position" << std::endl;
            m_arr[0] = element;
            return true;
        }
        
        if (not IsSorted())
        {
            std::cout << "The array is not sorted, sorting the array first" << std::endl;
            Sort();
        }

        if (element < m_arr[0])
        {
            return Insert(0, element);
        }
        else if (element > m_arr[m_size - 1])
        {
            return Insert(m_size, element);
        }
        else
        {
            for (int i = 0; i < m_size; i++)
            {
                if (element > m_arr[i] and element < m_arr[i + 1])
                {
                    m_arr[m_size] = m_arr[m_size - 1];
                    RightShift(i + 1, m_size);
                    m_arr[i + 1] = element;
                    m_size++;
                    return true;
                }
            }
            return false;     
        }
    }

    template <class T>
    ArrayADT<T>* Concatenate(ArrayADT<T>& A, ArrayADT<T>& B)
    {
        if (A.IsEmpty() and B.IsEmpty())
        {
            std::cout << "Both the arrays are empty, can't concatenate empty arrays" << std::endl;
            return nullptr;
        }

        ArrayADT<T>* temp = new ArrayADT<T>(A.m_size + B.m_size);

        for (int i = 0; i < A.m_size; i++)
        {
            temp->Insert(i, A.m_arr[i]);
        }

        for (int i = 0; i < B.m_size; i++)
        {
            temp->Insert(A.m_size + i, B.m_arr[i]);
        }

        return temp;
    }

    template <class T>
    ArrayADT<T>* SortedMerge(ArrayADT<T>& A, ArrayADT<T>& B)
    {
        if (A.IsEmpty() and B.IsEmpty())
        {
            std::cout << "Both the arrays are empty, can't do sorted merge" << std::endl;
            return nullptr;
        }

        if (not A.IsSorted())
        {
            std::cout << "Sorted merge can be performed only on sorted arrays, A is not sorted, sorting it first" << std::endl;
            A.Sort();
        }

        if (not B.IsSorted())
        {
            std::cout << "Sorted merge can be performed only on sorted arrays, B is not sorted, sorting it first" << std::endl;
            B.Sort();
        }

        ArrayADT<T>* temp = new ArrayADT<T>(A.m_size + B.m_size);

        int i = 0;
        int j = 0;
        int k = 0;

        while (i < A.m_size)
        {
            if (A.m_arr[i] <= B.m_arr[j])
            {
                temp->Insert(k, A.m_arr[i]);
                k++;
                i++;
            }
            else
            {
                temp->Insert(k, B.m_arr[j]);
                k++;
                j++;
            }
        }

        while (j < B.m_size)
        {
            temp->Insert(k, B.m_arr[j]);
            j++;
            k++;
        }

        return temp;
    }

    template <class T>
    ArrayADT<T>* Union(ArrayADT<T>& A, ArrayADT<T>& B)
    {
        if (A.IsEmpty() and B.IsEmpty())
        {
            std::cout << "Both the arrays are empty, can't perform union of empty arrays" << std::endl;
            return nullptr;
        }

        if (not A.IsSorted())
        {
            std::cout << "Union can be performed only on sorted arrays, A is not sorted, sorting it first" << std::endl;
            A.Sort();
            A.Display();
        }

        if (not B.IsSorted())
        {
            std::cout << "Union can be performed only on sorted arrays, B is not sorted, sorting it first" << std::endl;
            B.Sort();
        }

        ArrayADT<T>* temp = new ArrayADT<T>(A.m_size + B.m_size);

        int i = 0;
        int j = 0;
        int k = 0;

        while (i < A.m_size and j < B.m_size)
        {
            if (A.m_arr[i] == B.m_arr[j])
            {
                i++;
            }
            else if (A.m_arr[i] < B.m_arr[j])
            {
                temp->Insert(k, A.m_arr[i]);
                k++;
                i++;
            }
            else
            {
                temp->Insert(k, B.m_arr[j]);
                k++;
                j++;
            }
        }

        while (i < A.m_size)
        {
            temp->Insert(k, A.m_arr[i]);
            i++;
            k++;
        }

        while (j < B.m_size)
        {
            temp->Insert(k, B.m_arr[j]);
            j++;
            k++;
        }

        return temp;
    }

    template <class T>
    ArrayADT<T>* Intersection(ArrayADT<T>& A, ArrayADT<T>& B)
    {
        if (A.IsEmpty() and B.IsEmpty())
        {
            std::cout << "Both the arrays are empty, can't perform intersection of empty arrays" << std::endl;
            return nullptr;
        }

        if (not A.IsSorted())
        {
            std::cout << "Intersection can be performed only on sorted arrays, A is not sorted, sorting it first" << std::endl;
            A.Sort();
            A.Display();
        }

        if (not B.IsSorted())
        {
            std::cout << "Intersection can be performed only on sorted arrays, B is not sorted, sorting it first" << std::endl;
            B.Sort();
        }

        ArrayADT<T>* temp = new ArrayADT<T>(A.m_size + B.m_size);

        int i = 0;
        int j = 0;
        int k = 0;

        while (i < A.m_size and j < B.m_size)
        {
            if (A.m_arr[i] < B.m_arr[j])
            {
                i++;
            }
            else if (A.m_arr[i] > B.m_arr[j])
            {
                j++;
            }
            else
            {
                temp->Insert(k, A.m_arr[i]);
                i++;
                j++;
                k++;
            }
        }

        return temp;
    }

    template <class T>
    ArrayADT<T>* Difference(ArrayADT<T>& A, ArrayADT<T>& B)
    {
        if (A.IsEmpty() and B.IsEmpty())
        {
            std::cout << "Both the arrays are empty, can't perform difference of empty arrays" << std::endl;
            return nullptr;
        }

        if (not A.IsSorted())
        {
            std::cout << "Difference can be performed only on sorted arrays, A is not sorted, sorting it first" << std::endl;
            A.Sort();
            A.Display();
        }

        if (not B.IsSorted())
        {
            std::cout << "Difference can be performed only on sorted arrays, B is not sorted, sorting it first" << std::endl;
            B.Sort();
        }

        ArrayADT<T>* temp = new ArrayADT<T>(A.m_size + B.m_size);

        int i = 0;
        int j = 0;
        int k = 0;

        while (i < A.m_size and j < B.m_size)
        {
            if (A.m_arr[i] == B.m_arr[j])
            {
                i++;
                j++;
            }
            else if (A.m_arr[i] < B.m_arr[j])
            {
                temp->Insert(k, A.m_arr[i]);
                i++;
                k++;
            }
            else
            {
                temp->Insert(k, B.m_arr[j]);
                j++;
                k++;
            }
        }

        while (i < A.m_size)
        {
            temp->Insert(k, A.m_arr[i]);
            i++;
            k++;
        }

        while (j < B.m_size)
        {
            temp->Insert(k, B.m_arr[j]);
            j++;
            k++;
        }

        return temp;
    }
} // namespace arrayAdt
