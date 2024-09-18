#pragma once

#include "utils.h"


namespace handlers
{
    template <class T>
    void Handle(arrayAdt::ArrayADT<T>& arrayAdtObj)
    {
        arrayAdtObj.PrintMenu();
        arrayAdtObj.GetChoiceInputFromUser();
        const int& selectedChoice = arrayAdtObj.GetChoice();

        while (arrayAdtObj.GetChoice())
        {
            char previousMenuFlag = 'n';
            if (selectedChoice > arrayAdtObj.GetMinCase() &&
                selectedChoice < arrayAdtObj.GetMaxCase() + 1)
            {
                arrayAdtObj.PrintSelectedChoice();
            }

            switch (selectedChoice)
            {
            case 1:
            {
                bool isEmpty = arrayAdtObj.IsEmpty();
                if (isEmpty)
                {
                    std::cout << "The array is empty" << std::endl;
                }
                else
                {
                    std::cout << "The array is not empty" << std::endl;
                }
                break;
            }
            case 2:
            {
                bool isFull = arrayAdtObj.IsFull();
                if (isFull)
                {
                    std::cout << "The array is full" << std::endl;
                }
                else
                {
                    std::cout << "The array is not full" << std::endl;
                }
                break;
            }
            case 3:
            {
                int index = 0;
                std::cout << "Enter the index which you want to get: ";
                utils::InputNumberFromUser(index, 0, arrayAdtObj.GetLength());

                const auto element = arrayAdtObj.Get(index);
                
                if (element.has_value())
                {
                    std::cout << "The element at index: " << index << " is: " << element.value() << std::endl;
                }
                else
                {
                    std::cout << "The index does not exist" << std::endl;
                }

                break;
            }
            case 4:
            {
                int index = 0;
                std::cout << "Enter the index at which you want to set: ";
                utils::InputNumberFromUser(index, 0, arrayAdtObj.GetLength());

                T element = 0;
                std::cout << "Enter the element which you want to set: ";
                utils::InputNumberFromUser(element);

                const bool setCompleted = arrayAdtObj.Set(index, element);
                
                if (setCompleted)
                {
                    std::cout << "The element at index: " << index << " is: " << element << std::endl;
                }
                else
                {
                    std::cout << "The index has not been filled previously, cannot set the element" << std::endl;
                }

                break;
            }
            case 5:
            {
                arrayAdtObj.Display();
                break;
            }
            case 6:
            {
                T element = 0;
                std::cout << "Enter the element which you want to insert at the beginning: ";
                utils::InputNumberFromUser(element);

                const bool insertCompleted = arrayAdtObj.Insert(0, element);
                
                if (insertCompleted)
                {
                    std::cout << "The element: " << element
                              <<  " has been inserted at index: 0" << std::endl;
                }
                else
                {
                    std::cout << "The element cannot be inserted" << std::endl;
                }

                break;
            }
            case 7:
            {
                T element = 0;
                std::cout << "Enter the element which you want to insert at the end: ";
                utils::InputNumberFromUser(element);

                const bool insertCompleted = arrayAdtObj.Insert(arrayAdtObj.GetSize(), element);
                
                if (insertCompleted)
                {
                    std::cout << "The element: " << element
                              <<  " has been inserted at index: " << arrayAdtObj.GetSize() - 1 << std::endl;
                }
                else
                {
                    std::cout << "The element cannot be inserted" << std::endl;
                }

                break;
            }
            case 8:
            {
                int index = 0;
                std::cout << "Enter the index at which you want to insert: ";
                utils::InputNumberFromUser(index, 0, arrayAdtObj.GetSize() - 1);

                T element = 0;
                std::cout << "Enter the element which you want to insert at the index: ";
                utils::InputNumberFromUser(element);

                const bool insertCompleted = arrayAdtObj.Insert(index, element);
                
                if (insertCompleted)
                {
                    std::cout << "The element: " << element
                              <<  " has been inserted at index: " << index << std::endl;
                }
                else
                {
                    std::cout << "The element cannot be inserted" << std::endl;
                }

                break;
            }
            case 9:
            {
                const std::optional<T> deleteCompleted = arrayAdtObj.Remove(0);
                
                if (deleteCompleted.has_value())
                {
                    std::cout << "The element: " << deleteCompleted.value()
                              <<  " has been deleted from index: " << 0 << std::endl;
                }
                else
                {
                    std::cout << "The element cannot be deleted" << std::endl;
                }

                break;
            }
            case 10:
            {
                const std::optional<T> deleteCompleted = arrayAdtObj.Remove(arrayAdtObj.GetSize() - 1);
                
                if (deleteCompleted.has_value())
                {
                    std::cout << "The element: " << deleteCompleted.value()
                              <<  " has been deleted from index: " << arrayAdtObj.GetSize() << std::endl;
                }
                else
                {
                    std::cout << "The element cannot be deleted" << std::endl;
                }

                break;
            }
            case 11:
            {
                int index = 0;
                std::cout << "Enter the index from which you want to delete: ";
                utils::InputNumberFromUser(index, 0, arrayAdtObj.GetLength());

                const std::optional<T> deleteCompleted = arrayAdtObj.Remove(index);
                
                if (deleteCompleted.has_value())
                {
                    std::cout << "The element: " << deleteCompleted.value()
                              <<  " has been deleted from index: " << index << std::endl;
                }
                else
                {
                    std::cout << "The element cannot be deleted" << std::endl;
                }

                break;
            }
            case 12:
            {
                T element = 0;
                std::cout << "Enter the element you want to linear search for in the array: ";
                utils::InputNumberFromUser(element);

                const std::optional<int> linearSearchResult = arrayAdtObj.LinearSearch(element);
                
                if (linearSearchResult.has_value())
                {
                    std::cout << "The linear search was successful, element: " << element
                              << " found at index: " << linearSearchResult.value() << std::endl;
                }
                else
                {
                    std::cout << "The element was not found in the array" << std::endl;
                }

                break;
            }
            case 13:
            {
                T element = 0;
                std::cout << "Enter the element you want to binary search for in the array: ";
                utils::InputNumberFromUser(element);

                const std::optional<int> binarySearchResult = arrayAdtObj.BinarySearch(element);
                
                if (binarySearchResult.has_value())
                {
                    std::cout << "The binary search was successful, element: " << element
                              << " found at index: " << binarySearchResult.value() << std::endl;
                }
                else
                {
                    std::cout << "The element was not found in the array" << std::endl;
                }

                break;
            }
            case 14:
            {
                const std::optional<T> maxResult = arrayAdtObj.Max();
                
                if (maxResult.has_value())
                {
                    std::cout << "The max value in the array is: " << maxResult.value() << std::endl;
                }
                else
                {
                    std::cout << "Could not find the maximum value in the array" << std::endl;
                }

                break;
            }
            case 15:
            {
                const std::optional<T> minResult = arrayAdtObj.Min();
                
                if (minResult.has_value())
                {
                    std::cout << "The min value in the array is: " << minResult.value() << std::endl;
                }
                else
                {
                    std::cout << "Could not find the minimum value in the array" << std::endl;
                }

                break;
            }
            case 16:
            {
                const std::optional<T> sumResult = arrayAdtObj.Sum();
                
                if (sumResult.has_value())
                {
                    std::cout << "The sum of all the elements in the array is: " << sumResult.value() << std::endl;
                }
                else
                {
                    std::cout << "Could not find the sum of all the elements in the array" << std::endl;
                }

                break;
            }
            case 17:
            {
                const std::optional<double> averageResult = arrayAdtObj.Avg();
                
                if (averageResult.has_value())
                {
                    std::cout << "The average of all the elements in the array is: " << averageResult.value() << std::endl;
                }
                else
                {
                    std::cout << "Could not find the average of all the elements in the array" << std::endl;
                }

                break;
            }
            case 18:
            {
                arrayAdtObj.Reverse();
                break;
            }
            case 19:
            {
                arrayAdtObj.LeftShift(0, arrayAdtObj.GetSize() - 1);
                break;
            }
            case 20:
            {
                arrayAdtObj.RightShift(0, arrayAdtObj.GetSize() - 1);
                break;
            }
            case 21:
            {
                arrayAdtObj.LeftRotate(0, arrayAdtObj.GetSize() - 1);
                break;
            }
            case 22:
            {
                arrayAdtObj.RightRotate(0, arrayAdtObj.GetSize() - 1);
                break;
            }
            case 23:
            {
                const bool isSorted = arrayAdtObj.IsSorted();
                if (isSorted)
                {
                    std::cout << "The array is sorted" << std::endl;
                }
                else
                {
                    std::cout << "The array is not sorted" << std::endl;
                }
                break;
            }
            case 24:
            {
                arrayAdtObj.Sort();
                break;
            }
            case 25:
            {
                T element = 0;
                std::cout << "Enter the element you want to insert in a sorted position in the array: ";
                utils::InputNumberFromUser(element);

                const bool insertSortedResult = arrayAdtObj.InsertSorted(element);

                if (insertSortedResult)
                {
                    std::cout << "The element was successfully inserted at its sorted position in the array" << std::endl;
                }
                else
                {
                    std::cout << "The element could not be inserted in the array" << std::endl;
                }
                break;
            }
            case 26:
            {
                arrayAdt::ArrayADT<int> arrayAdtObjB(5);

                for (int i = 0; i < 5; i++)
                {
                    arrayAdtObjB.Insert(arrayAdtObjB.GetSize(), i + 1);
                }

                std::cout << "Concatenating the present array with the array 1 2 3 4 5" << std::endl;

                arrayAdt::ArrayADT<int>* tempArray = arrayAdt::Concatenate(arrayAdtObj, arrayAdtObjB);
                tempArray->Display();
                delete tempArray;
                break;
            }
            case 27:
            {
                arrayAdt::ArrayADT<int> arrayAdtObjB(5);

                for (int i = 0; i < 5; i++)
                {
                    arrayAdtObjB.Insert(arrayAdtObjB.GetSize(), i + 1);
                }

                std::cout << "Sorted merging the present array with the array 1 2 3 4 5" << std::endl;

                arrayAdt::ArrayADT<int>* tempArray = arrayAdt::SortedMerge(arrayAdtObj, arrayAdtObjB);
                tempArray->Display();
                delete tempArray;
                break;
            }
            case 28:
            {
                arrayAdt::ArrayADT<int> arrayAdtObjB(5);

                for (int i = 0; i < 5; i++)
                {
                    arrayAdtObjB.Insert(arrayAdtObjB.GetSize(), i + 1);
                }

                std::cout << "Doing union of the present array with  the array 1 2 3 4 5" << std::endl;

                arrayAdt::ArrayADT<int>* tempArray = arrayAdt::Union(arrayAdtObj, arrayAdtObjB);
                tempArray->Display();
                delete tempArray;
                break;
            }
            case 29:
            {
                arrayAdt::ArrayADT<int> arrayAdtObjB(5);

                for (int i = 0; i < 5; i++)
                {
                    arrayAdtObjB.Insert(arrayAdtObjB.GetSize(), i + 1);
                }

                std::cout << "Doing intersection of the present array with the array 1 2 3 4 5" << std::endl;

                arrayAdt::ArrayADT<int>* tempArray = arrayAdt::Intersection(arrayAdtObj, arrayAdtObjB);
                tempArray->Display();
                delete tempArray;
                break;
            }
            case 30:
            {
                arrayAdt::ArrayADT<int> arrayAdtObjB(5);

                for (int i = 0; i < 5; i++)
                {
                    arrayAdtObjB.Insert(arrayAdtObjB.GetSize(), i + 1);
                }

                std::cout << "Doing difference of the present array with the array 1 2 3 4 5" << std::endl;

                arrayAdt::ArrayADT<int>* tempArray = arrayAdt::Difference(arrayAdtObj, arrayAdtObjB);
                tempArray->Display();
                delete tempArray;
                break;
            }
            case 31:
            {
                previousMenuFlag = 'y';
                break;
            }
            case 32:
            {
                exit(0);
            }
            default:
            {
                std::cout << "The selected option is out of bounds!!! "
                          << "Please select appropriate option: " << std::endl;
                break;
            }
            }

            if (previousMenuFlag == 'y')
            {
                break;
            }
            else
            {
                arrayAdtObj.PrintMenu();
                arrayAdtObj.GetChoiceInputFromUser();
            }
        }
    }

    template <class T>
    void Handle(linkedList::LinearSinglyLinkedList<T>& linearSinglyLinkedListObj)
    {
        linearSinglyLinkedListObj.PrintMenu();
        linearSinglyLinkedListObj.GetChoiceInputFromUser();
        const int& selectedChoice = linearSinglyLinkedListObj.GetChoice();

        while (linearSinglyLinkedListObj.GetChoice())
        {
            char previousMenuFlag = 'n';
            if (selectedChoice > linearSinglyLinkedListObj.GetMinCase() &&
                selectedChoice < linearSinglyLinkedListObj.GetMaxCase() + 1)
            {
                linearSinglyLinkedListObj.PrintSelectedChoice();
            }

            switch (selectedChoice)
            {
            case 1:
            {
                bool isEmpty = linearSinglyLinkedListObj.IsEmpty();
                if (isEmpty)
                {
                    std::cout << "The linked list is empty" << std::endl;
                }
                else
                {
                    std::cout << "The linked list is not empty" << std::endl;
                }
                break;
            }
            case 2:
            {
                if (linearSinglyLinkedListObj.IsEmpty())
                {
                    std::cout << "The Linked list is empty" << std::endl;
                    break;
                }
                int index = 0;
                std::cout << "Enter the index which you want to get: ";
                utils::InputNumberFromUser(index, 0, linearSinglyLinkedListObj.GetSize() - 1);

                const auto element = linearSinglyLinkedListObj.Get(index);
                
                if (element.has_value())
                {
                    std::cout << "The element at index: " << index << " is: " << element.value() << std::endl;
                }
                else
                {
                    std::cout << "The index does not exist" << std::endl;
                }

                break;
            }
            case 3:
            {
                linearSinglyLinkedListObj.Display();
                break;
            }
            case 4:
            {
                T element = 0;
                std::cout << "Enter the element which you want to insert at the beginning: ";
                utils::InputNumberFromUser(element);

                const bool insertCompleted = linearSinglyLinkedListObj.Insert(0, element);
                
                if (insertCompleted)
                {
                    std::cout << "The element: " << element
                              <<  " has been inserted at index: 0" << std::endl;
                }
                else
                {
                    std::cout << "The element cannot be inserted" << std::endl;
                }
                break;
            }
            case 5:
            {
                T element = 0;
                std::cout << "Enter the element which you want to insert at the end: ";
                utils::InputNumberFromUser(element);

                const bool insertCompleted = linearSinglyLinkedListObj.Insert(linearSinglyLinkedListObj.GetSize(), element);
                
                if (insertCompleted)
                {
                    std::cout << "The element: " << element
                              <<  " has been inserted at index: " << linearSinglyLinkedListObj.GetSize() - 1 << std::endl;
                }
                else
                {
                    std::cout << "The element cannot be inserted" << std::endl;
                }

                break;
            }
            case 6:
            {
                int index = 0;
                std::cout << "Enter the index at which you want to insert: ";
                utils::InputNumberFromUser(index, 0, linearSinglyLinkedListObj.GetSize());

                T element = 0;
                std::cout << "Enter the element which you want to insert at the index: ";
                utils::InputNumberFromUser(element);

                const bool insertCompleted = linearSinglyLinkedListObj.Insert(index, element);
                
                if (insertCompleted)
                {
                    std::cout << "The element: " << element
                              <<  " has been inserted at index: " << index << std::endl;
                }
                else
                {
                    std::cout << "The element cannot be inserted" << std::endl;
                }

                break;
            }
            case 7:
            {
                const std::optional<T> deleteCompleted = linearSinglyLinkedListObj.Remove(0);
                
                if (deleteCompleted.has_value())
                {
                    std::cout << "The element: " << deleteCompleted.value()
                              <<  " has been deleted from index: " << 0 << std::endl;
                }
                else
                {
                    std::cout << "The element cannot be deleted" << std::endl;
                }

                break;
            }
            case 8:
            {
                const std::optional<T> deleteCompleted = linearSinglyLinkedListObj.Remove(linearSinglyLinkedListObj.GetSize() - 1);
                
                if (deleteCompleted.has_value())
                {
                    std::cout << "The element: " << deleteCompleted.value()
                              <<  " has been deleted from index: " << linearSinglyLinkedListObj.GetSize() << std::endl;
                }
                else
                {
                    std::cout << "The element cannot be deleted" << std::endl;
                }

                break;
            }
            case 9:
            {
                if (linearSinglyLinkedListObj.IsEmpty())
                {
                    std::cout << "The Linked list is empty" << std::endl;
                    break;
                }
                int index = 0;
                std::cout << "Enter the index from which you want to delete: ";
                utils::InputNumberFromUser(index, 0, linearSinglyLinkedListObj.GetSize() - 1);

                const std::optional<T> deleteCompleted = linearSinglyLinkedListObj.Remove(index);
                
                if (deleteCompleted.has_value())
                {
                    std::cout << "The element: " << deleteCompleted.value()
                              <<  " has been deleted from index: " << index << std::endl;
                }
                else
                {
                    std::cout << "The element cannot be deleted" << std::endl;
                }

                break;
            }
            case 10:
            {
                T element = 0;
                std::cout << "Enter the element you want to linear search for in the linked list: ";
                utils::InputNumberFromUser(element);

                const std::optional<int> linearSearchResult = linearSinglyLinkedListObj.LinearSearch(element);
                
                if (linearSearchResult.has_value())
                {
                    std::cout << "The linear search was successful, element: " << element
                              << " found at index: " << linearSearchResult.value() << std::endl;
                }
                else
                {
                    std::cout << "The element was not found in the array" << std::endl;
                }

                break;
            }
            case 11:
            {
                const std::optional<T> maxResult = linearSinglyLinkedListObj.Max();
                
                if (maxResult.has_value())
                {
                    std::cout << "The max value in the linked list is: " << maxResult.value() << std::endl;
                }
                else
                {
                    std::cout << "Could not find the maximum value in the linked list" << std::endl;
                }

                break;
            }
            case 12:
            {
                const std::optional<T> minResult = linearSinglyLinkedListObj.Min();
                
                if (minResult.has_value())
                {
                    std::cout << "The min value in the linked list is: " << minResult.value() << std::endl;
                }
                else
                {
                    std::cout << "Could not find the minimum value in the linked list" << std::endl;
                }

                break;
            }
            case 13:
            {
                const std::optional<T> sumResult = linearSinglyLinkedListObj.Sum();
                
                if (sumResult.has_value())
                {
                    std::cout << "The sum of all the elements in the linked list is: " << sumResult.value() << std::endl;
                }
                else
                {
                    std::cout << "Could not find the sum of all the elements in the linked list" << std::endl;
                }

                break;
            }
            case 14:
            {
                const std::optional<double> averageResult = linearSinglyLinkedListObj.Avg();
                
                if (averageResult.has_value())
                {
                    std::cout << "The average of all the elements in the linked list is: " << averageResult.value() << std::endl;
                }
                else
                {
                    std::cout << "Could not find the average of all the elements in the linked list" << std::endl;
                }

                break;
            }
            case 15:
            {
                linearSinglyLinkedListObj.Reverse();
                break;
            }
            case 16:
            {
                const bool isSorted = linearSinglyLinkedListObj.IsSorted();
                if (isSorted)
                {
                    std::cout << "The linked list is sorted" << std::endl;
                }
                else
                {
                    std::cout << "The linked list is not sorted" << std::endl;
                }
                break;
            }
            case 17:
            {
                linearSinglyLinkedListObj.Sort();
                break;
            }
            case 18:
            {
                T element = 0;
                std::cout << "Enter the element you want to insert in a sorted position in the linked list: ";
                utils::InputNumberFromUser(element);

                const bool insertSortedResult = linearSinglyLinkedListObj.InsertSorted(element);

                if (insertSortedResult)
                {
                    std::cout << "The element was successfully inserted at its sorted position in the linked list" << std::endl;
                }
                else
                {
                    std::cout << "The element could not be inserted in the linked list" << std::endl;
                }
                break;
            }
            case 19:
            {
                linkedList::LinearSinglyLinkedList<int>* BList = new linkedList::LinearSinglyLinkedList<int>;

                for (int i = 0; i < 5; i ++)
                {
                    BList->Insert(BList->GetSize(), i + 1);
                }

                std::cout << "Concatenating the linked list with another linked list with contents as 1 2 3 4 5" << std::endl;

                linkedList::LinearSinglyLinkedList<int>* concatenatedList = linkedList::Concatenate<int>(linearSinglyLinkedListObj, *BList);
                concatenatedList->Display();
                delete concatenatedList;
                break;
            }
            case 20:
            {
                linkedList::LinearSinglyLinkedList<int>* BList = new linkedList::LinearSinglyLinkedList<int>;

                for (int i = 0; i < 5; i ++)
                {
                    BList->Insert(BList->GetSize(), i + 1);
                }

                std::cout << "Merging the linked list with another linked list with contents as 1 2 3 4 5" << std::endl;

                linkedList::LinearSinglyLinkedList<int>* mergedList = linkedList::SortedMerge<int>(linearSinglyLinkedListObj, *BList);
                mergedList->Display();
                delete mergedList;
                break;
            }
            case 21:
            {
                previousMenuFlag = 'y';
                break;
            }
            case 22:
            {
                exit(0);
            }
            default:
            {
                std::cout << "The selected option is out of bounds!!! "
                          << "Please select appropriate option: " << std::endl;
                break;
            }
            }

            if (previousMenuFlag == 'y')
            {
                break;
            }
            else
            {
                linearSinglyLinkedListObj.PrintMenu();
                linearSinglyLinkedListObj.GetChoiceInputFromUser();
            }
        }
    }

    template <class T>
    void Handle(linkedList::CircularSinglyLinkedList<T>& circularSinglyLinkedListObj)
    {
        circularSinglyLinkedListObj.PrintMenu();
        circularSinglyLinkedListObj.GetChoiceInputFromUser();
        const int& selectedChoice = circularSinglyLinkedListObj.GetChoice();

        while (circularSinglyLinkedListObj.GetChoice())
        {
            char previousMenuFlag = 'n';
            if (selectedChoice > circularSinglyLinkedListObj.GetMinCase() &&
                selectedChoice < circularSinglyLinkedListObj.GetMaxCase() + 1)
            {
                circularSinglyLinkedListObj.PrintSelectedChoice();
            }

            switch (selectedChoice)
            {
            case 1:
            {
                bool isEmpty = circularSinglyLinkedListObj.IsEmpty();
                if (isEmpty)
                {
                    std::cout << "The linked list is empty" << std::endl;
                }
                else
                {
                    std::cout << "The linked list is not empty" << std::endl;
                }
                break;
            }
            case 2:
            {
                if (circularSinglyLinkedListObj.IsEmpty())
                {
                    std::cout << "The Linked list is empty" << std::endl;
                    break;
                }
                int index = 0;
                std::cout << "Enter the index which you want to get: ";
                utils::InputNumberFromUser(index, 0, circularSinglyLinkedListObj.GetSize() - 1);

                const auto element = circularSinglyLinkedListObj.Get(index);
                
                if (element.has_value())
                {
                    std::cout << "The element at index: " << index << " is: " << element.value() << std::endl;
                }
                else
                {
                    std::cout << "The index does not exist" << std::endl;
                }

                break;
            }
            case 3:
            {
                circularSinglyLinkedListObj.Display();
                break;
            }
            case 4:
            {
                T element = 0;
                std::cout << "Enter the element which you want to insert at the beginning: ";
                utils::InputNumberFromUser(element);

                const bool insertCompleted = circularSinglyLinkedListObj.Insert(0, element);
                
                if (insertCompleted)
                {
                    std::cout << "The element: " << element
                              <<  " has been inserted at index: 0" << std::endl;
                }
                else
                {
                    std::cout << "The element cannot be inserted" << std::endl;
                }
                break;
            }
            case 5:
            {
                T element = 0;
                std::cout << "Enter the element which you want to insert at the end: ";
                utils::InputNumberFromUser(element);

                const bool insertCompleted = circularSinglyLinkedListObj.Insert(circularSinglyLinkedListObj.GetSize(), element);
                
                if (insertCompleted)
                {
                    std::cout << "The element: " << element
                              <<  " has been inserted at index: " << circularSinglyLinkedListObj.GetSize() - 1 << std::endl;
                }
                else
                {
                    std::cout << "The element cannot be inserted" << std::endl;
                }

                break;
            }
            case 6:
            {
                int index = 0;
                std::cout << "Enter the index at which you want to insert: ";
                utils::InputNumberFromUser(index, 0, circularSinglyLinkedListObj.GetSize());

                T element = 0;
                std::cout << "Enter the element which you want to insert at the index: ";
                utils::InputNumberFromUser(element);

                const bool insertCompleted = circularSinglyLinkedListObj.Insert(index, element);
                
                if (insertCompleted)
                {
                    std::cout << "The element: " << element
                              <<  " has been inserted at index: " << index << std::endl;
                }
                else
                {
                    std::cout << "The element cannot be inserted" << std::endl;
                }

                break;
            }
            case 7:
            {
                const std::optional<T> deleteCompleted = circularSinglyLinkedListObj.Remove(0);
                
                if (deleteCompleted.has_value())
                {
                    std::cout << "The element: " << deleteCompleted.value()
                              <<  " has been deleted from index: " << 0 << std::endl;
                }
                else
                {
                    std::cout << "The element cannot be deleted" << std::endl;
                }

                break;
            }
            case 8:
            {
                const std::optional<T> deleteCompleted = circularSinglyLinkedListObj.Remove(circularSinglyLinkedListObj.GetSize() - 1);
                
                if (deleteCompleted.has_value())
                {
                    std::cout << "The element: " << deleteCompleted.value()
                              <<  " has been deleted from index: " << circularSinglyLinkedListObj.GetSize() << std::endl;
                }
                else
                {
                    std::cout << "The element cannot be deleted" << std::endl;
                }

                break;
            }
            case 9:
            {
                if (circularSinglyLinkedListObj.IsEmpty())
                {
                    std::cout << "The Linked list is empty" << std::endl;
                    break;
                }
                int index = 0;
                std::cout << "Enter the index from which you want to delete: ";
                utils::InputNumberFromUser(index, 0, circularSinglyLinkedListObj.GetSize() - 1);

                const std::optional<T> deleteCompleted = circularSinglyLinkedListObj.Remove(index);
                
                if (deleteCompleted.has_value())
                {
                    std::cout << "The element: " << deleteCompleted.value()
                              <<  " has been deleted from index: " << index << std::endl;
                }
                else
                {
                    std::cout << "The element cannot be deleted" << std::endl;
                }

                break;
            }
            case 10:
            {
                T element = 0;
                std::cout << "Enter the element you want to linear search for in the linked list: ";
                utils::InputNumberFromUser(element);

                const std::optional<int> linearSearchResult = circularSinglyLinkedListObj.LinearSearch(element);
                
                if (linearSearchResult.has_value())
                {
                    std::cout << "The linear search was successful, element: " << element
                              << " found at index: " << linearSearchResult.value() << std::endl;
                }
                else
                {
                    std::cout << "The element was not found in the array" << std::endl;
                }

                break;
            }
            case 11:
            {
                const std::optional<T> maxResult = circularSinglyLinkedListObj.Max();
                
                if (maxResult.has_value())
                {
                    std::cout << "The max value in the linked list is: " << maxResult.value() << std::endl;
                }
                else
                {
                    std::cout << "Could not find the maximum value in the linked list" << std::endl;
                }

                break;
            }
            case 12:
            {
                const std::optional<T> minResult = circularSinglyLinkedListObj.Min();
                
                if (minResult.has_value())
                {
                    std::cout << "The min value in the linked list is: " << minResult.value() << std::endl;
                }
                else
                {
                    std::cout << "Could not find the minimum value in the linked list" << std::endl;
                }

                break;
            }
            case 13:
            {
                const std::optional<T> sumResult = circularSinglyLinkedListObj.Sum();
                
                if (sumResult.has_value())
                {
                    std::cout << "The sum of all the elements in the linked list is: " << sumResult.value() << std::endl;
                }
                else
                {
                    std::cout << "Could not find the sum of all the elements in the linked list" << std::endl;
                }

                break;
            }
            case 14:
            {
                const std::optional<double> averageResult = circularSinglyLinkedListObj.Avg();
                
                if (averageResult.has_value())
                {
                    std::cout << "The average of all the elements in the linked list is: " << averageResult.value() << std::endl;
                }
                else
                {
                    std::cout << "Could not find the average of all the elements in the linked list" << std::endl;
                }

                break;
            }
            case 15:
            {
                circularSinglyLinkedListObj.Reverse();
                break;
            }
            case 16:
            {
                const bool isSorted = circularSinglyLinkedListObj.IsSorted();
                if (isSorted)
                {
                    std::cout << "The linked list is sorted" << std::endl;
                }
                else
                {
                    std::cout << "The linked list is not sorted" << std::endl;
                }
                break;
            }
            case 17:
            {
                circularSinglyLinkedListObj.Sort();
                break;
            }
            case 18:
            {
                T element = 0;
                std::cout << "Enter the element you want to insert in a sorted position in the linked list: ";
                utils::InputNumberFromUser(element);

                const bool insertSortedResult = circularSinglyLinkedListObj.InsertSorted(element);

                if (insertSortedResult)
                {
                    std::cout << "The element was successfully inserted at its sorted position in the linked list" << std::endl;
                }
                else
                {
                    std::cout << "The element could not be inserted in the linked list" << std::endl;
                }
                break;
            }
            case 19:
            {
                linkedList::CircularSinglyLinkedList<int>* BList = new linkedList::CircularSinglyLinkedList<int>;

                for (int i = 0; i < 5; i ++)
                {
                    BList->Insert(BList->GetSize(), i + 1);
                }

                std::cout << "Concatenating the linked list with another linked list with contents as 1 2 3 4 5" << std::endl;

                linkedList::CircularSinglyLinkedList<int>* concatenatedList = linkedList::Concatenate<int>(circularSinglyLinkedListObj, *BList);
                concatenatedList->Display();
                delete concatenatedList;
                break;
            }
            case 20:
            {
                linkedList::CircularSinglyLinkedList<int>* BList = new linkedList::CircularSinglyLinkedList<int>;

                for (int i = 0; i < 5; i ++)
                {
                    BList->Insert(BList->GetSize(), i + 1);
                }

                std::cout << "Merging the linked list with another linked list with contents as 1 2 3 4 5" << std::endl;

                linkedList::CircularSinglyLinkedList<int>* mergedList = linkedList::SortedMerge<int>(circularSinglyLinkedListObj, *BList);
                mergedList->Display();
                delete mergedList;
                break;
            }
            case 21:
            {
                previousMenuFlag = 'y';
                break;
            }
            case 22:
            {
                exit(0);
            }
            default:
            {
                std::cout << "The selected option is out of bounds!!! "
                          << "Please select appropriate option: " << std::endl;
                break;
            }
            }

            if (previousMenuFlag == 'y')
            {
                break;
            }
            else
            {
                circularSinglyLinkedListObj.PrintMenu();
                circularSinglyLinkedListObj.GetChoiceInputFromUser();
            }
        }
    }

    template <class T>
    void Handle(linkedList::LinearDoublyLinkedList<T>& linearDoublyLinkedListObj)
    {
        linearDoublyLinkedListObj.PrintMenu();
        linearDoublyLinkedListObj.GetChoiceInputFromUser();
        const int& selectedChoice = linearDoublyLinkedListObj.GetChoice();

        while (linearDoublyLinkedListObj.GetChoice())
        {
            char previousMenuFlag = 'n';
            if (selectedChoice > linearDoublyLinkedListObj.GetMinCase() &&
                selectedChoice < linearDoublyLinkedListObj.GetMaxCase() + 1)
            {
                linearDoublyLinkedListObj.PrintSelectedChoice();
            }

            switch (selectedChoice)
            {
            case 1:
            {
                bool isEmpty = linearDoublyLinkedListObj.IsEmpty();
                if (isEmpty)
                {
                    std::cout << "The linked list is empty" << std::endl;
                }
                else
                {
                    std::cout << "The linked list is not empty" << std::endl;
                }
                break;
            }
            case 2:
            {
                if (linearDoublyLinkedListObj.IsEmpty())
                {
                    std::cout << "The Linked list is empty" << std::endl;
                    break;
                }
                int index = 0;
                std::cout << "Enter the index which you want to get: ";
                utils::InputNumberFromUser(index, 0, linearDoublyLinkedListObj.GetSize() - 1);

                const auto element = linearDoublyLinkedListObj.Get(index);
                
                if (element.has_value())
                {
                    std::cout << "The element at index: " << index << " is: " << element.value() << std::endl;
                }
                else
                {
                    std::cout << "The index does not exist" << std::endl;
                }

                break;
            }
            case 3:
            {
                linearDoublyLinkedListObj.Display();
                break;
            }
            case 4:
            {
                T element = 0;
                std::cout << "Enter the element which you want to insert at the beginning: ";
                utils::InputNumberFromUser(element);

                const bool insertCompleted = linearDoublyLinkedListObj.Insert(0, element);
                
                if (insertCompleted)
                {
                    std::cout << "The element: " << element
                              <<  " has been inserted at index: 0" << std::endl;
                }
                else
                {
                    std::cout << "The element cannot be inserted" << std::endl;
                }
                break;
            }
            case 5:
            {
                T element = 0;
                std::cout << "Enter the element which you want to insert at the end: ";
                utils::InputNumberFromUser(element);

                const bool insertCompleted = linearDoublyLinkedListObj.Insert(linearDoublyLinkedListObj.GetSize(), element);
                
                if (insertCompleted)
                {
                    std::cout << "The element: " << element
                              <<  " has been inserted at index: " << linearDoublyLinkedListObj.GetSize() - 1 << std::endl;
                }
                else
                {
                    std::cout << "The element cannot be inserted" << std::endl;
                }

                break;
            }
            case 6:
            {
                int index = 0;
                std::cout << "Enter the index at which you want to insert: ";
                utils::InputNumberFromUser(index, 0, linearDoublyLinkedListObj.GetSize());

                T element = 0;
                std::cout << "Enter the element which you want to insert at the index: ";
                utils::InputNumberFromUser(element);

                const bool insertCompleted = linearDoublyLinkedListObj.Insert(index, element);
                
                if (insertCompleted)
                {
                    std::cout << "The element: " << element
                              <<  " has been inserted at index: " << index << std::endl;
                }
                else
                {
                    std::cout << "The element cannot be inserted" << std::endl;
                }

                break;
            }
            case 7:
            {
                const std::optional<T> deleteCompleted = linearDoublyLinkedListObj.Remove(0);
                
                if (deleteCompleted.has_value())
                {
                    std::cout << "The element: " << deleteCompleted.value()
                              <<  " has been deleted from index: " << 0 << std::endl;
                }
                else
                {
                    std::cout << "The element cannot be deleted" << std::endl;
                }

                break;
            }
            case 8:
            {
                const std::optional<T> deleteCompleted = linearDoublyLinkedListObj.Remove(linearDoublyLinkedListObj.GetSize() - 1);
                
                if (deleteCompleted.has_value())
                {
                    std::cout << "The element: " << deleteCompleted.value()
                              <<  " has been deleted from index: " << linearDoublyLinkedListObj.GetSize() << std::endl;
                }
                else
                {
                    std::cout << "The element cannot be deleted" << std::endl;
                }

                break;
            }
            case 9:
            {
                if (linearDoublyLinkedListObj.IsEmpty())
                {
                    std::cout << "The Linked list is empty" << std::endl;
                    break;
                }
                int index = 0;
                std::cout << "Enter the index from which you want to delete: ";
                utils::InputNumberFromUser(index, 0, linearDoublyLinkedListObj.GetSize() - 1);

                const std::optional<T> deleteCompleted = linearDoublyLinkedListObj.Remove(index);
                
                if (deleteCompleted.has_value())
                {
                    std::cout << "The element: " << deleteCompleted.value()
                              <<  " has been deleted from index: " << index << std::endl;
                }
                else
                {
                    std::cout << "The element cannot be deleted" << std::endl;
                }

                break;
            }
            case 10:
            {
                T element = 0;
                std::cout << "Enter the element you want to linear search for in the linked list: ";
                utils::InputNumberFromUser(element);

                const std::optional<int> linearSearchResult = linearDoublyLinkedListObj.LinearSearch(element);
                
                if (linearSearchResult.has_value())
                {
                    std::cout << "The linear search was successful, element: " << element
                              << " found at index: " << linearSearchResult.value() << std::endl;
                }
                else
                {
                    std::cout << "The element was not found in the array" << std::endl;
                }

                break;
            }
            case 11:
            {
                const std::optional<T> maxResult = linearDoublyLinkedListObj.Max();
                
                if (maxResult.has_value())
                {
                    std::cout << "The max value in the linked list is: " << maxResult.value() << std::endl;
                }
                else
                {
                    std::cout << "Could not find the maximum value in the linked list" << std::endl;
                }

                break;
            }
            case 12:
            {
                const std::optional<T> minResult = linearDoublyLinkedListObj.Min();
                
                if (minResult.has_value())
                {
                    std::cout << "The min value in the linked list is: " << minResult.value() << std::endl;
                }
                else
                {
                    std::cout << "Could not find the minimum value in the linked list" << std::endl;
                }

                break;
            }
            case 13:
            {
                const std::optional<T> sumResult = linearDoublyLinkedListObj.Sum();
                
                if (sumResult.has_value())
                {
                    std::cout << "The sum of all the elements in the linked list is: " << sumResult.value() << std::endl;
                }
                else
                {
                    std::cout << "Could not find the sum of all the elements in the linked list" << std::endl;
                }

                break;
            }
            case 14:
            {
                const std::optional<double> averageResult = linearDoublyLinkedListObj.Avg();
                
                if (averageResult.has_value())
                {
                    std::cout << "The average of all the elements in the linked list is: " << averageResult.value() << std::endl;
                }
                else
                {
                    std::cout << "Could not find the average of all the elements in the linked list" << std::endl;
                }

                break;
            }
            case 15:
            {
                linearDoublyLinkedListObj.Reverse();
                break;
            }
            case 16:
            {
                const bool isSorted = linearDoublyLinkedListObj.IsSorted();
                if (isSorted)
                {
                    std::cout << "The linked list is sorted" << std::endl;
                }
                else
                {
                    std::cout << "The linked list is not sorted" << std::endl;
                }
                break;
            }
            case 17:
            {
                linearDoublyLinkedListObj.Sort();
                break;
            }
            case 18:
            {
                T element = 0;
                std::cout << "Enter the element you want to insert in a sorted position in the linked list: ";
                utils::InputNumberFromUser(element);

                const bool insertSortedResult = linearDoublyLinkedListObj.InsertSorted(element);

                if (insertSortedResult)
                {
                    std::cout << "The element was successfully inserted at its sorted position in the linked list" << std::endl;
                }
                else
                {
                    std::cout << "The element could not be inserted in the linked list" << std::endl;
                }
                break;
            }
            case 19:
            {
                linkedList::LinearDoublyLinkedList<int>* BList = new linkedList::LinearDoublyLinkedList<int>;

                for (int i = 0; i < 5; i ++)
                {
                    BList->Insert(BList->GetSize(), i + 1);
                }

                std::cout << "Concatenating the linked list with another linked list with contents as 1 2 3 4 5" << std::endl;

                linkedList::LinearDoublyLinkedList<int>* concatenatedList = linkedList::Concatenate<int>(linearDoublyLinkedListObj, *BList);
                concatenatedList->Display();
                delete concatenatedList;
                break;
            }
            case 20:
            {
                linkedList::LinearDoublyLinkedList<int>* BList = new linkedList::LinearDoublyLinkedList<int>;

                for (int i = 0; i < 5; i ++)
                {
                    BList->Insert(BList->GetSize(), i + 1);
                }

                std::cout << "Merging the linked list with another linked list with contents as 1 2 3 4 5" << std::endl;

                linkedList::LinearDoublyLinkedList<int>* mergedList = linkedList::SortedMerge<int>(linearDoublyLinkedListObj, *BList);
                mergedList->Display();
                delete mergedList;
                break;
            }
            case 21:
            {
                previousMenuFlag = 'y';
                break;
            }
            case 22:
            {
                exit(0);
            }
            default:
            {
                std::cout << "The selected option is out of bounds!!! "
                          << "Please select appropriate option: " << std::endl;
                break;
            }
            }

            if (previousMenuFlag == 'y')
            {
                break;
            }
            else
            {
                linearDoublyLinkedListObj.PrintMenu();
                linearDoublyLinkedListObj.GetChoiceInputFromUser();
            }
        }
    }

    template <class T>
    void Handle(linkedList::CircularDoublyLinkedList<T>& circularDoublyLinkedListObj)
    {
        circularDoublyLinkedListObj.PrintMenu();
        circularDoublyLinkedListObj.GetChoiceInputFromUser();
        const int& selectedChoice = circularDoublyLinkedListObj.GetChoice();

        while (circularDoublyLinkedListObj.GetChoice())
        {
            char previousMenuFlag = 'n';
            if (selectedChoice > circularDoublyLinkedListObj.GetMinCase() &&
                selectedChoice < circularDoublyLinkedListObj.GetMaxCase() + 1)
            {
                circularDoublyLinkedListObj.PrintSelectedChoice();
            }

            switch (selectedChoice)
            {
            case 1:
            {
                bool isEmpty = circularDoublyLinkedListObj.IsEmpty();
                if (isEmpty)
                {
                    std::cout << "The linked list is empty" << std::endl;
                }
                else
                {
                    std::cout << "The linked list is not empty" << std::endl;
                }
                break;
            }
            case 2:
            {
                if (circularDoublyLinkedListObj.IsEmpty())
                {
                    std::cout << "The Linked list is empty" << std::endl;
                    break;
                }
                int index = 0;
                std::cout << "Enter the index which you want to get: ";
                utils::InputNumberFromUser(index, 0, circularDoublyLinkedListObj.GetSize() - 1);

                const auto element = circularDoublyLinkedListObj.Get(index);
                
                if (element.has_value())
                {
                    std::cout << "The element at index: " << index << " is: " << element.value() << std::endl;
                }
                else
                {
                    std::cout << "The index does not exist" << std::endl;
                }

                break;
            }
            case 3:
            {
                circularDoublyLinkedListObj.Display();
                break;
            }
            case 4:
            {
                T element = 0;
                std::cout << "Enter the element which you want to insert at the beginning: ";
                utils::InputNumberFromUser(element);

                const bool insertCompleted = circularDoublyLinkedListObj.Insert(0, element);
                
                if (insertCompleted)
                {
                    std::cout << "The element: " << element
                              <<  " has been inserted at index: 0" << std::endl;
                }
                else
                {
                    std::cout << "The element cannot be inserted" << std::endl;
                }
                break;
            }
            case 5:
            {
                T element = 0;
                std::cout << "Enter the element which you want to insert at the end: ";
                utils::InputNumberFromUser(element);

                const bool insertCompleted = circularDoublyLinkedListObj.Insert(circularDoublyLinkedListObj.GetSize(), element);
                
                if (insertCompleted)
                {
                    std::cout << "The element: " << element
                              <<  " has been inserted at index: " << circularDoublyLinkedListObj.GetSize() - 1 << std::endl;
                }
                else
                {
                    std::cout << "The element cannot be inserted" << std::endl;
                }

                break;
            }
            case 6:
            {
                int index = 0;
                std::cout << "Enter the index at which you want to insert: ";
                utils::InputNumberFromUser(index, 0, circularDoublyLinkedListObj.GetSize());

                T element = 0;
                std::cout << "Enter the element which you want to insert at the index: ";
                utils::InputNumberFromUser(element);

                const bool insertCompleted = circularDoublyLinkedListObj.Insert(index, element);
                
                if (insertCompleted)
                {
                    std::cout << "The element: " << element
                              <<  " has been inserted at index: " << index << std::endl;
                }
                else
                {
                    std::cout << "The element cannot be inserted" << std::endl;
                }

                break;
            }
            case 7:
            {
                const std::optional<T> deleteCompleted = circularDoublyLinkedListObj.Remove(0);
                
                if (deleteCompleted.has_value())
                {
                    std::cout << "The element: " << deleteCompleted.value()
                              <<  " has been deleted from index: " << 0 << std::endl;
                }
                else
                {
                    std::cout << "The element cannot be deleted" << std::endl;
                }

                break;
            }
            case 8:
            {
                const std::optional<T> deleteCompleted = circularDoublyLinkedListObj.Remove(circularDoublyLinkedListObj.GetSize() - 1);
                
                if (deleteCompleted.has_value())
                {
                    std::cout << "The element: " << deleteCompleted.value()
                              <<  " has been deleted from index: " << circularDoublyLinkedListObj.GetSize() << std::endl;
                }
                else
                {
                    std::cout << "The element cannot be deleted" << std::endl;
                }

                break;
            }
            case 9:
            {
                if (circularDoublyLinkedListObj.IsEmpty())
                {
                    std::cout << "The Linked list is empty" << std::endl;
                    break;
                }
                int index = 0;
                std::cout << "Enter the index from which you want to delete: ";
                utils::InputNumberFromUser(index, 0, circularDoublyLinkedListObj.GetSize() - 1);

                const std::optional<T> deleteCompleted = circularDoublyLinkedListObj.Remove(index);
                
                if (deleteCompleted.has_value())
                {
                    std::cout << "The element: " << deleteCompleted.value()
                              <<  " has been deleted from index: " << index << std::endl;
                }
                else
                {
                    std::cout << "The element cannot be deleted" << std::endl;
                }

                break;
            }
            case 10:
            {
                T element = 0;
                std::cout << "Enter the element you want to linear search for in the linked list: ";
                utils::InputNumberFromUser(element);

                const std::optional<int> linearSearchResult = circularDoublyLinkedListObj.LinearSearch(element);
                
                if (linearSearchResult.has_value())
                {
                    std::cout << "The linear search was successful, element: " << element
                              << " found at index: " << linearSearchResult.value() << std::endl;
                }
                else
                {
                    std::cout << "The element was not found in the array" << std::endl;
                }

                break;
            }
            case 11:
            {
                const std::optional<T> maxResult = circularDoublyLinkedListObj.Max();
                
                if (maxResult.has_value())
                {
                    std::cout << "The max value in the linked list is: " << maxResult.value() << std::endl;
                }
                else
                {
                    std::cout << "Could not find the maximum value in the linked list" << std::endl;
                }

                break;
            }
            case 12:
            {
                const std::optional<T> minResult = circularDoublyLinkedListObj.Min();
                
                if (minResult.has_value())
                {
                    std::cout << "The min value in the linked list is: " << minResult.value() << std::endl;
                }
                else
                {
                    std::cout << "Could not find the minimum value in the linked list" << std::endl;
                }

                break;
            }
            case 13:
            {
                const std::optional<T> sumResult = circularDoublyLinkedListObj.Sum();
                
                if (sumResult.has_value())
                {
                    std::cout << "The sum of all the elements in the linked list is: " << sumResult.value() << std::endl;
                }
                else
                {
                    std::cout << "Could not find the sum of all the elements in the linked list" << std::endl;
                }

                break;
            }
            case 14:
            {
                const std::optional<double> averageResult = circularDoublyLinkedListObj.Avg();
                
                if (averageResult.has_value())
                {
                    std::cout << "The average of all the elements in the linked list is: " << averageResult.value() << std::endl;
                }
                else
                {
                    std::cout << "Could not find the average of all the elements in the linked list" << std::endl;
                }

                break;
            }
            case 15:
            {
                circularDoublyLinkedListObj.Reverse();
                break;
            }
            case 16:
            {
                const bool isSorted = circularDoublyLinkedListObj.IsSorted();
                if (isSorted)
                {
                    std::cout << "The linked list is sorted" << std::endl;
                }
                else
                {
                    std::cout << "The linked list is not sorted" << std::endl;
                }
                break;
            }
            case 17:
            {
                circularDoublyLinkedListObj.Sort();
                break;
            }
            case 18:
            {
                T element = 0;
                std::cout << "Enter the element you want to insert in a sorted position in the linked list: ";
                utils::InputNumberFromUser(element);

                const bool insertSortedResult = circularDoublyLinkedListObj.InsertSorted(element);

                if (insertSortedResult)
                {
                    std::cout << "The element was successfully inserted at its sorted position in the linked list" << std::endl;
                }
                else
                {
                    std::cout << "The element could not be inserted in the linked list" << std::endl;
                }
                break;
            }
            case 19:
            {
                linkedList::CircularDoublyLinkedList<int>* BList = new linkedList::CircularDoublyLinkedList<int>;

                for (int i = 0; i < 5; i ++)
                {
                    BList->Insert(BList->GetSize(), i + 1);
                }

                std::cout << "Concatenating the linked list with another linked list with contents as 1 2 3 4 5" << std::endl;

                linkedList::CircularDoublyLinkedList<int>* concatenatedList = linkedList::Concatenate<int>(circularDoublyLinkedListObj, *BList);
                concatenatedList->Display();
                delete concatenatedList;
                break;
            }
            case 20:
            {
                linkedList::CircularDoublyLinkedList<int>* BList = new linkedList::CircularDoublyLinkedList<int>;

                for (int i = 0; i < 5; i ++)
                {
                    BList->Insert(BList->GetSize(), i + 1);
                }

                std::cout << "Merging the linked list with another linked list with contents as 1 2 3 4 5" << std::endl;

                linkedList::CircularDoublyLinkedList<int>* mergedList = linkedList::SortedMerge<int>(circularDoublyLinkedListObj, *BList);
                mergedList->Display();
                delete mergedList;
                break;
            }
            case 21:
            {
                previousMenuFlag = 'y';
                break;
            }
            case 22:
            {
                exit(0);
            }
            default:
            {
                std::cout << "The selected option is out of bounds!!! "
                          << "Please select appropriate option: " << std::endl;
                break;
            }
            }

            if (previousMenuFlag == 'y')
            {
                break;
            }
            else
            {
                circularDoublyLinkedListObj.PrintMenu();
                circularDoublyLinkedListObj.GetChoiceInputFromUser();
            }
        }
    }

    template <class T>
    void Handle(stack::StackUsingArray<T>& stackUsingArrayObj)
    {
        stackUsingArrayObj.PrintMenu();
        stackUsingArrayObj.GetChoiceInputFromUser();
        const int& selectedChoice = stackUsingArrayObj.GetChoice();

        while (stackUsingArrayObj.GetChoice())
        {
            char previousMenuFlag = 'n';
            if (selectedChoice > stackUsingArrayObj.GetMinCase() &&
                selectedChoice < stackUsingArrayObj.GetMaxCase() + 1)
            {
                stackUsingArrayObj.PrintSelectedChoice();
            }

            switch (selectedChoice)
            {
            case 1:
            {
                bool isEmpty = stackUsingArrayObj.IsEmpty();
                if (isEmpty)
                {
                    std::cout << "The stack is empty" << std::endl;
                }
                else
                {
                    std::cout << "The stack is not empty" << std::endl;
                }
                break;
            }
            case 2:
            {
                bool isFull = stackUsingArrayObj.IsFull();
                if (isFull)
                {
                    std::cout << "The stack is full" << std::endl;
                }
                else
                {
                    std::cout << "The stack is not full" << std::endl;
                }
                break;
            }
            case 3:
            {
                stackUsingArrayObj.Display();
                break;
            }
            case 4:
            {
                int element;
                std::cout << "Please enter the element you want to push into the stack: ";
                utils::InputNumberFromUser(element);
                bool resultPush = stackUsingArrayObj.Push(element);                

                if (resultPush)
                {
                    std::cout << "The element: "<< element << " was successfully pushed in the stack" << std::endl;
                }
                else
                {
                    std::cout << "The element was not successfully pushed in the stack" << std::endl;
                }
                break;
            }
            case 5:
            {
                const auto resultPop = stackUsingArrayObj.Pop();

                if (resultPop)
                {
                    std::cout << "The element: " << resultPop.value() << " was successfully popped from the stack" << std::endl;
                }
                else
                {
                    std::cout << "Could not pop from the stack" << std::endl;
                }
                break;
            }
            case 6:
            {
                int position;
                std::cout << "Please enter the position at which you want to peek in the stack: ";
                utils::InputNumberFromUser(position);
                const auto resultPeek = stackUsingArrayObj.Peek(position);                

                if (resultPeek)
                {
                    std::cout << "The element present at " << position << " is: " << resultPeek.value() << std::endl;
                }
                else
                {
                    std::cout << "Could not peek in the stack" << std::endl;
                }
                break;
            }
            case 7:
            {
                const auto resultTop = stackUsingArrayObj.GetTop();                

                if (resultTop)
                {
                    std::cout << "The element present at the top is: " << resultTop.value() << std::endl;
                }
                else
                {
                    std::cout << "The stack is empty" << std::endl;
                }
                break;
            }
            case 8:
            {
                previousMenuFlag = 'y';
                break;
            }
            case 9:
            {
                exit(0);
            }
            default:
            {
                std::cout << "The selected option is out of bounds!!! "
                          << "Please select appropriate option: " << std::endl;
                break;
            }
            }

            if (previousMenuFlag == 'y')
            {
                break;
            }
            else
            {
                stackUsingArrayObj.PrintMenu();
                stackUsingArrayObj.GetChoiceInputFromUser();
            }
        }
    }

    template <class T>
    void Handle(stack::StackUsingLinkedList<T>& stackUsingLinkedListObj)
    {
        stackUsingLinkedListObj.PrintMenu();
        stackUsingLinkedListObj.GetChoiceInputFromUser();
        const int& selectedChoice = stackUsingLinkedListObj.GetChoice();

        while (stackUsingLinkedListObj.GetChoice())
        {
            char previousMenuFlag = 'n';
            if (selectedChoice > stackUsingLinkedListObj.GetMinCase() &&
                selectedChoice < stackUsingLinkedListObj.GetMaxCase() + 1)
            {
                stackUsingLinkedListObj.PrintSelectedChoice();
            }

            switch (selectedChoice)
            {
            case 1:
            {
                bool isEmpty = stackUsingLinkedListObj.IsEmpty();
                if (isEmpty)
                {
                    std::cout << "The stack is empty" << std::endl;
                }
                else
                {
                    std::cout << "The stack is not empty" << std::endl;
                }
                break;
            }
            case 2:
            {
                stackUsingLinkedListObj.Display();
                break;
            }
            case 3:
            {
                int element;
                std::cout << "Please enter the element you want to push into the stack: ";
                utils::InputNumberFromUser(element);
                bool resultPush = stackUsingLinkedListObj.Push(element);                

                if (resultPush)
                {
                    std::cout << "The element: "<< element << " was successfully pushed in the stack" << std::endl;
                }
                else
                {
                    std::cout << "The element was not successfully pushed in the stack" << std::endl;
                }
                break;
            }
            case 4:
            {
                const auto resultPop = stackUsingLinkedListObj.Pop();

                if (resultPop)
                {
                    std::cout << "The element: " << resultPop.value() << " was successfully popped from the stack" << std::endl;
                }
                else
                {
                    std::cout << "Could not pop from the stack" << std::endl;
                }
                break;
            }
            case 5:
            {
                int position;
                std::cout << "Please enter the position at which you want to peek in the stack: ";
                utils::InputNumberFromUser(position);
                const auto resultPeek = stackUsingLinkedListObj.Peek(position);                

                if (resultPeek)
                {
                    std::cout << "The element present at " << position << " is: " << resultPeek.value() << std::endl;
                }
                else
                {
                    std::cout << "Could not peek in the stack" << std::endl;
                }
                break;
            }
            case 6:
            {
                const auto resultTop = stackUsingLinkedListObj.GetTop();                

                if (resultTop)
                {
                    std::cout << "The element present at the top is: " << resultTop.value() << std::endl;
                }
                else
                {
                    std::cout << "The stack is empty" << std::endl;
                }
                break;
            }
            case 7:
            {
                previousMenuFlag = 'y';
                break;
            }
            case 8:
            {
                exit(0);
            }
            default:
            {
                std::cout << "The selected option is out of bounds!!! "
                          << "Please select appropriate option: " << std::endl;
                break;
            }
            }

            if (previousMenuFlag == 'y')
            {
                break;
            }
            else
            {
                stackUsingLinkedListObj.PrintMenu();
                stackUsingLinkedListObj.GetChoiceInputFromUser();
            }
        }
    }

    template <class T>
    void Handle(queue::QueueUsingArray<T>& queueUsingArrayObj)
    {
        queueUsingArrayObj.PrintMenu();
        queueUsingArrayObj.GetChoiceInputFromUser();
        const int& selectedChoice = queueUsingArrayObj.GetChoice();

        while (queueUsingArrayObj.GetChoice())
        {
            char previousMenuFlag = 'n';
            if (selectedChoice > queueUsingArrayObj.GetMinCase() &&
                selectedChoice < queueUsingArrayObj.GetMaxCase() + 1)
            {
                queueUsingArrayObj.PrintSelectedChoice();
            }

            switch (selectedChoice)
            {
            case 1:
            {
                bool isEmpty = queueUsingArrayObj.IsEmpty();
                if (isEmpty)
                {
                    std::cout << "The queue is empty" << std::endl;
                }
                else
                {
                    std::cout << "The queue is not empty" << std::endl;
                }
                break;
            }
            case 2:
            {
                bool isFull = queueUsingArrayObj.IsFull();
                if (isFull)
                {
                    std::cout << "The queue is full" << std::endl;
                }
                else
                {
                    std::cout << "The queue is not full" << std::endl;
                }
                break;
            }
            case 3:
            {
                queueUsingArrayObj.Display();
                break;
            }
            case 4:
            {
                int numElements = queueUsingArrayObj.NumElements();
                std::cout << "There are " << numElements << " elements in the queue" << std::endl;
                break;
            }
            case 5:
            {
                T element = 0;
                std::cout << "Enter the number you want to insert: ";
                utils::InputNumberFromUser(element);

                bool enqueueRes = queueUsingArrayObj.Enqueue(element);
                if (enqueueRes)
                {
                    std::cout << "The element " << element << " was successfully enqueued" << std::endl;
                }
                else
                {
                    std::cout << "The element was not enqueued" << std::endl;
                }
                break;
            }
            case 6:
            {
                std::optional<T> dequeuedElement = queueUsingArrayObj.Dequeue();

                if (dequeuedElement.has_value())
                {
                    std::cout << "Element " << dequeuedElement.value() << " was successfully dequeued from the queue" << std::endl;
                }
                else
                {
                    std::cout << "Could not perform dequeue operation" << std::endl;
                }
                break;
            }
            case 7:
            {
                std::optional<T> frontElement = queueUsingArrayObj.Front();

                if (frontElement.has_value())
                {
                    std::cout << "Element in front: " << frontElement.value() << std::endl;
                }
                else
                {
                    std::cout << "Could not perform Front() operation" << std::endl;
                }
                break;
            }
            case 8:
            {
                std::optional<T> rearElement = queueUsingArrayObj.Rear();

                if (rearElement.has_value())
                {
                    std::cout << "Element in rear: " << rearElement.value() << std::endl;
                }
                else
                {
                    std::cout << "Could not perform Rear() operation" << std::endl;
                }
                break;
            }
            case 9:
            {
                queueUsingArrayObj.Reset();
                break;
            }
            case 10:
            {
                previousMenuFlag = 'y';
                break;
            }
            case 11:
            {
                exit(0);
            }
            default:
            {
                std::cout << "The selected option is out of bounds!!! "
                          << "Please select appropriate option: " << std::endl;
                break;
            }
            }

            if (previousMenuFlag == 'y')
            {
                break;
            }
            else
            {
                queueUsingArrayObj.PrintMenu();
                queueUsingArrayObj.GetChoiceInputFromUser();
            }
        }
    }

    template <class T>
    void Handle(queue::CircularQueue<T>& circularQueueObj)
    {
        circularQueueObj.PrintMenu();
        circularQueueObj.GetChoiceInputFromUser();
        const int& selectedChoice = circularQueueObj.GetChoice();

        while (circularQueueObj.GetChoice())
        {
            char previousMenuFlag = 'n';
            if (selectedChoice > circularQueueObj.GetMinCase() &&
                selectedChoice < circularQueueObj.GetMaxCase() + 1)
            {
                circularQueueObj.PrintSelectedChoice();
            }

            switch (selectedChoice)
            {
            case 1:
            {
                bool isEmpty = circularQueueObj.IsEmpty();
                if (isEmpty)
                {
                    std::cout << "The queue is empty" << std::endl;
                }
                else
                {
                    std::cout << "The queue is not empty" << std::endl;
                }
                break;
            }
            case 2:
            {
                bool isFull = circularQueueObj.IsFull();
                if (isFull)
                {
                    std::cout << "The queue is full" << std::endl;
                }
                else
                {
                    std::cout << "The queue is not full" << std::endl;
                }
                break;
            }
            case 3:
            {
                circularQueueObj.Display();
                break;
            }
            case 4:
            {
                int numElements = circularQueueObj.NumElements();
                std::cout << "There are " << numElements << " elements in the queue" << std::endl;
                break;
            }
            case 5:
            {
                T element = 0;
                std::cout << "Enter the number you want to insert: ";
                utils::InputNumberFromUser(element);

                bool enqueueRes = circularQueueObj.Enqueue(element);
                if (enqueueRes)
                {
                    std::cout << "The element " << element << " was successfully enqueued" << std::endl;
                }
                else
                {
                    std::cout << "The element was not enqueued" << std::endl;
                }
                break;
            }
            case 6:
            {
                std::optional<T> dequeuedElement = circularQueueObj.Dequeue();

                if (dequeuedElement.has_value())
                {
                    std::cout << "Element " << dequeuedElement.value() << " was successfully dequeued from the queue" << std::endl;
                }
                else
                {
                    std::cout << "Could not perform dequeue operation" << std::endl;
                }
                break;
            }
            case 7:
            {
                std::optional<T> frontElement = circularQueueObj.Front();

                if (frontElement.has_value())
                {
                    std::cout << "Element in front: " << frontElement.value() << std::endl;
                }
                else
                {
                    std::cout << "Could not perform Front() operation" << std::endl;
                }
                break;
            }
            case 8:
            {
                std::optional<T> rearElement = circularQueueObj.Rear();

                if (rearElement.has_value())
                {
                    std::cout << "Element in rear: " << rearElement.value() << std::endl;
                }
                else
                {
                    std::cout << "Could not perform Rear() operation" << std::endl;
                }
                break;
            }
            case 9:
            {
                circularQueueObj.Reset();
                break;
            }
            case 10:
            {
                previousMenuFlag = 'y';
                break;
            }
            case 11:
            {
                exit(0);
            }
            default:
            {
                std::cout << "The selected option is out of bounds!!! "
                          << "Please select appropriate option: " << std::endl;
                break;
            }
            }

            if (previousMenuFlag == 'y')
            {
                break;
            }
            else
            {
                circularQueueObj.PrintMenu();
                circularQueueObj.GetChoiceInputFromUser();
            }
        }
    }

    template <class T>
    void Handle(queue::QueueUsingLinkedList<T>& queueUsingLinkedListObj)
    {
        queueUsingLinkedListObj.PrintMenu();
        queueUsingLinkedListObj.GetChoiceInputFromUser();
        const int& selectedChoice = queueUsingLinkedListObj.GetChoice();

        while (queueUsingLinkedListObj.GetChoice())
        {
            char previousMenuFlag = 'n';
            if (selectedChoice > queueUsingLinkedListObj.GetMinCase() &&
                selectedChoice < queueUsingLinkedListObj.GetMaxCase() + 1)
            {
                queueUsingLinkedListObj.PrintSelectedChoice();
            }

            switch (selectedChoice)
            {
            case 1:
            {
                bool isEmpty = queueUsingLinkedListObj.IsEmpty();
                if (isEmpty)
                {
                    std::cout << "The queue is empty" << std::endl;
                }
                else
                {
                    std::cout << "The queue is not empty" << std::endl;
                }
                break;
            }
            case 2:
            {
                queueUsingLinkedListObj.Display();
                break;
            }
            case 3:
            {
                int numElements = queueUsingLinkedListObj.NumElements();
                std::cout << "There are " << numElements << " elements in the queue" << std::endl;
                break;
            }
            case 4:
            {
                T element = 0;
                std::cout << "Enter the number you want to insert: ";
                utils::InputNumberFromUser(element);

                bool enqueueRes = queueUsingLinkedListObj.Enqueue(element);
                if (enqueueRes)
                {
                    std::cout << "The element " << element << " was successfully enqueued" << std::endl;
                }
                else
                {
                    std::cout << "The element was not enqueued" << std::endl;
                }
                break;
            }
            case 5:
            {
                std::optional<T> dequeuedElement = queueUsingLinkedListObj.Dequeue();

                if (dequeuedElement.has_value())
                {
                    std::cout << "Element " << dequeuedElement.value() << " was successfully dequeued from the queue" << std::endl;
                }
                else
                {
                    std::cout << "Could not perform dequeue operation" << std::endl;
                }
                break;
            }
            case 6:
            {
                std::optional<T> frontElement = queueUsingLinkedListObj.Front();

                if (frontElement.has_value())
                {
                    std::cout << "Element in front: " << frontElement.value() << std::endl;
                }
                else
                {
                    std::cout << "Could not perform Front() operation" << std::endl;
                }
                break;
            }
            case 7:
            {
                std::optional<T> rearElement = queueUsingLinkedListObj.Rear();

                if (rearElement.has_value())
                {
                    std::cout << "Element in rear: " << rearElement.value() << std::endl;
                }
                else
                {
                    std::cout << "Could not perform Rear() operation" << std::endl;
                }
                break;
            }
            case 8:
            {
                queueUsingLinkedListObj.Reset();
                break;
            }
            case 9:
            {
                previousMenuFlag = 'y';
                break;
            }
            case 10:
            {
                exit(0);
            }
            default:
            {
                std::cout << "The selected option is out of bounds!!! "
                          << "Please select appropriate option: " << std::endl;
                break;
            }
            }

            if (previousMenuFlag == 'y')
            {
                break;
            }
            else
            {
                queueUsingLinkedListObj.PrintMenu();
                queueUsingLinkedListObj.GetChoiceInputFromUser();
            }
        }
    }

    template <class T>
    void Handle(queue::DoubleEndedQueue<T>& doubleEndedQueueObj)
    {
        doubleEndedQueueObj.PrintMenu();
        doubleEndedQueueObj.GetChoiceInputFromUser();
        const int& selectedChoice = doubleEndedQueueObj.GetChoice();

        while (doubleEndedQueueObj.GetChoice())
        {
            char previousMenuFlag = 'n';
            if (selectedChoice > doubleEndedQueueObj.GetMinCase() &&
                selectedChoice < doubleEndedQueueObj.GetMaxCase() + 1)
            {
                doubleEndedQueueObj.PrintSelectedChoice();
            }

            switch (selectedChoice)
            {
            case 1:
            {
                bool isEmpty = doubleEndedQueueObj.IsEmpty();
                if (isEmpty)
                {
                    std::cout << "The queue is empty" << std::endl;
                }
                else
                {
                    std::cout << "The queue is not empty" << std::endl;
                }
                break;
            }
            case 2:
            {
                doubleEndedQueueObj.Display();
                break;
            }
            case 3:
            {
                int numElements = doubleEndedQueueObj.NumElements();
                std::cout << "There are " << numElements << " elements in the queue" << std::endl;
                break;
            }
            case 4:
            {
                T element = 0;
                std::cout << "Enter the number you want to insert in front: ";
                utils::InputNumberFromUser(element);

                bool enqueueRes = doubleEndedQueueObj.EnqueueFront(element);
                if (enqueueRes)
                {
                    std::cout << "The element " << element << " was successfully enqueued in front" << std::endl;
                }
                else
                {
                    std::cout << "The element was not enqueued" << std::endl;
                }
                break;
            }
            case 5:
            {
                T element = 0;
                std::cout << "Enter the number you want to insert in rear: ";
                utils::InputNumberFromUser(element);

                bool enqueueRes = doubleEndedQueueObj.EnqueueRear(element);
                if (enqueueRes)
                {
                    std::cout << "The element " << element << " was successfully enqueued in rear" << std::endl;
                }
                else
                {
                    std::cout << "The element was not enqueued" << std::endl;
                }
                break;
            }
            case 6:
            {
                std::optional<T> dequeuedElement = doubleEndedQueueObj.DequeueFront();

                if (dequeuedElement.has_value())
                {
                    std::cout << "Element " << dequeuedElement.value() << " was successfully dequeued from the queue front" << std::endl;
                }
                else
                {
                    std::cout << "Could not perform dequeue operation" << std::endl;
                }
                break;
            }
            case 7:
            {
                std::optional<T> dequeuedElement = doubleEndedQueueObj.DequeueRear();

                if (dequeuedElement.has_value())
                {
                    std::cout << "Element " << dequeuedElement.value() << " was successfully dequeued from the queue rear" << std::endl;
                }
                else
                {
                    std::cout << "Could not perform dequeue operation" << std::endl;
                }
                break;
            }
            case 8:
            {
                std::optional<T> frontElement = doubleEndedQueueObj.Front();

                if (frontElement.has_value())
                {
                    std::cout << "Element in front: " << frontElement.value() << std::endl;
                }
                else
                {
                    std::cout << "Could not perform Front() operation" << std::endl;
                }
                break;
            }
            case 9:
            {
                std::optional<T> rearElement = doubleEndedQueueObj.Rear();

                if (rearElement.has_value())
                {
                    std::cout << "Element in rear: " << rearElement.value() << std::endl;
                }
                else
                {
                    std::cout << "Could not perform Rear() operation" << std::endl;
                }
                break;
            }
            case 10:
            {
                doubleEndedQueueObj.Reset();
                break;
            }
            case 11:
            {
                previousMenuFlag = 'y';
                break;
            }
            case 12:
            {
                exit(0);
            }
            default:
            {
                std::cout << "The selected option is out of bounds!!! "
                          << "Please select appropriate option: " << std::endl;
                break;
            }
            }

            if (previousMenuFlag == 'y')
            {
                break;
            }
            else
            {
                doubleEndedQueueObj.PrintMenu();
                doubleEndedQueueObj.GetChoiceInputFromUser();
            }
        }
    }

    template <class T>
    void Handle(queue::PriorityQueueLimitedSet<T>& priorityQueueLimitedSetObj)
    {
        priorityQueueLimitedSetObj.PrintMenu();
        priorityQueueLimitedSetObj.GetChoiceInputFromUser();
        const int& selectedChoice = priorityQueueLimitedSetObj.GetChoice();

        while (priorityQueueLimitedSetObj.GetChoice())
        {
            char previousMenuFlag = 'n';
            if (selectedChoice > priorityQueueLimitedSetObj.GetMinCase() &&
                selectedChoice < priorityQueueLimitedSetObj.GetMaxCase() + 1)
            {
                priorityQueueLimitedSetObj.PrintSelectedChoice();
            }

            switch (selectedChoice)
            {
            case 1:
            {
                bool isEmpty = priorityQueueLimitedSetObj.IsEmpty();
                if (isEmpty)
                {
                    std::cout << "The queue is empty" << std::endl;
                }
                else
                {
                    std::cout << "The queue is not empty" << std::endl;
                }
                break;
            }
            case 2:
            {
                priorityQueueLimitedSetObj.Display();
                break;
            }
            case 3:
            {
                int numElements = priorityQueueLimitedSetObj.NumElements();
                std::cout << "There are " << numElements << " elements in the queue" << std::endl;
                break;
            }
            case 4:
            {
                T element = 0;
                int priority = 0;
                std::cout << "Enter the number you want to enqueue with its priority: ";
                utils::InputNumberFromUser(element, 1, 10,'n');
                utils::InputNumberFromUser(priority, 1, priorityQueueLimitedSetObj.GetNumPriorities(),'n');

                bool enqueueRes = priorityQueueLimitedSetObj.Enqueue(element, priority);
                if (enqueueRes)
                {
                    std::cout << "The element " << element << " was successfully enqueued in front" << std::endl;
                }
                else
                {
                    std::cout << "The element was not enqueued" << std::endl;
                }
                break;
            }
            case 5:
            {
                std::optional<T> dequeuedElement = priorityQueueLimitedSetObj.Dequeue();

                if (dequeuedElement.has_value())
                {
                    std::cout << "Element " << dequeuedElement.value() << " was successfully dequeued from the queue" << std::endl;
                }
                else
                {
                    std::cout << "Could not perform dequeue operation" << std::endl;
                }
                break;
            }
            case 6:
            {
                std::optional<T> peekFront = priorityQueueLimitedSetObj.PeekFront();

                if (peekFront.has_value())
                {
                    std::cout << "Element " << peekFront.value() << " is present in the front of queue with highest priority" << std::endl;
                }
                else
                {
                    std::cout << "Could not perform Peek front operation" << std::endl;
                }
                break;
            }
            case 7:
            {
                int priority = 0;
                std::cout << "Enter the priority you want to get the front for: ";
                utils::InputNumberFromUser(priority, 1, priorityQueueLimitedSetObj.GetNumPriorities(),'n');
                std::optional<T> peekPriority = priorityQueueLimitedSetObj.PeekPriority(priority);

                if (peekPriority.has_value())
                {
                    std::cout << "Element " << peekPriority.value() << " is present in the front of queue with priority: " << priority << std::endl;
                }
                else
                {
                    std::cout << "Could not perform peek priority operation" << std::endl;
                }
                break;
            }
            case 8:
            {
                priorityQueueLimitedSetObj.Reset();
                break;
            }
            case 9:
            {
                previousMenuFlag = 'y';
                break;
            }
            case 10:
            {
                exit(0);
            }
            default:
            {
                std::cout << "The selected option is out of bounds!!! "
                          << "Please select appropriate option: " << std::endl;
                break;
            }
            }

            if (previousMenuFlag == 'y')
            {
                break;
            }
            else
            {
                priorityQueueLimitedSetObj.PrintMenu();
                priorityQueueLimitedSetObj.GetChoiceInputFromUser();
            }
        }
    }

    template <class T>
    void Handle(queue::PriorityQueueElement<T>& priorityQueueElementObj)
    {
        priorityQueueElementObj.PrintMenu();
        priorityQueueElementObj.GetChoiceInputFromUser();
        const int& selectedChoice = priorityQueueElementObj.GetChoice();

        while (priorityQueueElementObj.GetChoice())
        {
            char previousMenuFlag = 'n';
            if (selectedChoice > priorityQueueElementObj.GetMinCase() &&
                selectedChoice < priorityQueueElementObj.GetMaxCase() + 1)
            {
                priorityQueueElementObj.PrintSelectedChoice();
            }

            switch (selectedChoice)
            {
            case 1:
            {
                bool isEmpty = priorityQueueElementObj.IsEmpty();
                if (isEmpty)
                {
                    std::cout << "The queue is empty" << std::endl;
                }
                else
                {
                    std::cout << "The queue is not empty" << std::endl;
                }
                break;
            }
            case 2:
            {
                priorityQueueElementObj.Display();
                break;
            }
            case 3:
            {
                int numElements = priorityQueueElementObj.NumElements();
                std::cout << "There are " << numElements << " elements in the queue" << std::endl;
                break;
            }
            case 4:
            {
                T element = 0;
                std::cout << "Enter the number you want to enqueue: ";
                utils::InputNumberFromUser(element);

                bool enqueueRes = priorityQueueElementObj.Enqueue(element);
                if (enqueueRes)
                {
                    std::cout << "The element " << element << " was successfully enqueued in the queue" << std::endl;
                }
                else
                {
                    std::cout << "The element was not enqueued" << std::endl;
                }
                break;
            }
            case 5:
            {
                std::optional<T> dequeuedElement = priorityQueueElementObj.Dequeue();

                if (dequeuedElement.has_value())
                {
                    std::cout << "Element " << dequeuedElement.value() << " was successfully dequeued from the queue" << std::endl;
                }
                else
                {
                    std::cout << "Could not perform dequeue operation" << std::endl;
                }
                break;
            }
            case 6:
            {
                std::optional<T> front = priorityQueueElementObj.Front();

                if (front.has_value())
                {
                    std::cout << "Element " << front.value() << " is present in the front of queue" << std::endl;
                }
                else
                {
                    std::cout << "Could not perform front operation" << std::endl;
                }
                break;
            }
            case 7:
            {
                std::optional<T> rear = priorityQueueElementObj.Rear();

                if (rear.has_value())
                {
                    std::cout << "Element " << rear.value() << " is present in the rear of queue" << std::endl;
                }
                else
                {
                    std::cout << "Could not perform rear operation" << std::endl;
                }
                break;
            }
            case 8:
            {
                priorityQueueElementObj.Reset();
                break;
            }
            case 9:
            {
                previousMenuFlag = 'y';
                break;
            }
            case 10:
            {
                exit(0);
            }
            default:
            {
                std::cout << "The selected option is out of bounds!!! "
                          << "Please select appropriate option: " << std::endl;
                break;
            }
            }

            if (previousMenuFlag == 'y')
            {
                break;
            }
            else
            {
                priorityQueueElementObj.PrintMenu();
                priorityQueueElementObj.GetChoiceInputFromUser();
            }
        }
    }

    template <class T>
    void Handle(queue::QueueUsingTwoStacks<T>& queueUsingTwoStacksObj)
    {
        queueUsingTwoStacksObj.PrintMenu();
        queueUsingTwoStacksObj.GetChoiceInputFromUser();
        const int& selectedChoice = queueUsingTwoStacksObj.GetChoice();

        while (queueUsingTwoStacksObj.GetChoice())
        {
            char previousMenuFlag = 'n';
            if (selectedChoice > queueUsingTwoStacksObj.GetMinCase() &&
                selectedChoice < queueUsingTwoStacksObj.GetMaxCase() + 1)
            {
                queueUsingTwoStacksObj.PrintSelectedChoice();
            }

            switch (selectedChoice)
            {
            case 1:
            {
                bool isEmpty = queueUsingTwoStacksObj.IsEmpty();
                if (isEmpty)
                {
                    std::cout << "The queue is empty" << std::endl;
                }
                else
                {
                    std::cout << "The queue is not empty" << std::endl;
                }
                break;
            }
            case 2:
            {
                queueUsingTwoStacksObj.Display();
                break;
            }
            case 3:
            {
                T element = 0;
                std::cout << "Enter the number you want to enqueue: ";
                utils::InputNumberFromUser(element);

                bool enqueueRes = queueUsingTwoStacksObj.Enqueue(element);
                if (enqueueRes)
                {
                    std::cout << "The element " << element << " was successfully enqueued in the queue" << std::endl;
                }
                else
                {
                    std::cout << "The element was not enqueued" << std::endl;
                }
                break;
            }
            case 4:
            {
                std::optional<T> dequeuedElement = queueUsingTwoStacksObj.Dequeue();

                if (dequeuedElement.has_value())
                {
                    std::cout << "Element " << dequeuedElement.value() << " was successfully dequeued from the queue" << std::endl;
                }
                else
                {
                    std::cout << "Could not perform dequeue operation" << std::endl;
                }
                break;
            }
            case 5:
            {
                std::optional<T> front = queueUsingTwoStacksObj.Front();

                if (front.has_value())
                {
                    std::cout << "Element " << front.value() << " is present in the front of queue" << std::endl;
                }
                else
                {
                    std::cout << "Could not perform front operation" << std::endl;
                }
                break;
            }
            case 6:
            {
                std::optional<T> rear = queueUsingTwoStacksObj.Rear();

                if (rear.has_value())
                {
                    std::cout << "Element " << rear.value() << " is present in the rear of queue" << std::endl;
                }
                else
                {
                    std::cout << "Could not perform rear operation" << std::endl;
                }
                break;
            }
            case 7:
            {
                queueUsingTwoStacksObj.Reset();
                break;
            }
            case 8:
            {
                previousMenuFlag = 'y';
                break;
            }
            case 9:
            {
                exit(0);
            }
            default:
            {
                std::cout << "The selected option is out of bounds!!! "
                          << "Please select appropriate option: " << std::endl;
                break;
            }
            }

            if (previousMenuFlag == 'y')
            {
                break;
            }
            else
            {
                queueUsingTwoStacksObj.PrintMenu();
                queueUsingTwoStacksObj.GetChoiceInputFromUser();
            }
        }
    }

    template <class T>
    void Handle(tree::BinaryTreeUsingArray<T>& binaryTreeUsingArrayObj)
    {
        binaryTreeUsingArrayObj.PrintMenu();
        binaryTreeUsingArrayObj.GetChoiceInputFromUser();
        const int& selectedChoice = binaryTreeUsingArrayObj.GetChoice();

        while (binaryTreeUsingArrayObj.GetChoice())
        {
            char previousMenuFlag = 'n';
            if (selectedChoice > binaryTreeUsingArrayObj.GetMinCase() &&
                selectedChoice < binaryTreeUsingArrayObj.GetMaxCase() + 1)
            {
                binaryTreeUsingArrayObj.PrintSelectedChoice();
            }

            switch (selectedChoice)
            {
            case 1:
            {
                bool res = binaryTreeUsingArrayObj.IsExisting();
                
                if (res)
                {
                    std::cout << "The tree exists" << std::endl;
                }
                else
                {
                    std::cout << "The tree does not exist" << std::endl;
                }
                break;
            }
            case 2:
            {
                if (not binaryTreeUsingArrayObj.IsExisting())
                {
                    std::cout << "The tree does not exist" << std::endl;
                }
                else
                {
                    binaryTreeUsingArrayObj.DisplayPreOrderRecursive(1);
                    std::cout << std::endl;
                }
                break;
            }
            case 3:
            {
                if (not binaryTreeUsingArrayObj.IsExisting())
                {
                    std::cout << "The tree does not exist" << std::endl;
                }
                else
                {
                    binaryTreeUsingArrayObj.DisplayInOrderRecursive(1);
                    std::cout << std::endl;
                }
                break;
            }
            case 4:
            {
                if (not binaryTreeUsingArrayObj.IsExisting())
                {
                    std::cout << "The tree does not exist" << std::endl;
                }
                else
                {
                    binaryTreeUsingArrayObj.DisplayPostOrderRecursive(1);
                    std::cout << std::endl;
                }
                break;
            }
            case 5:
            {
                if (not binaryTreeUsingArrayObj.IsExisting())
                {
                    std::cout << "The tree does not exist" << std::endl;
                }
                else
                {
                    binaryTreeUsingArrayObj.DisplayLevelOrderRecursive(1);
                    std::cout << std::endl;
                }
                break;
            }
            case 6:
            {
                if (binaryTreeUsingArrayObj.IsExisting())
                {
                    std::cout << "Tree already exists, cannot generate tree if already exists, reset and try again" << std::endl;
                }
                else
                {
                    binaryTreeUsingArrayObj.GenerateTree();
                }
                break;
            }
            case 7:
            {
                binaryTreeUsingArrayObj.ResetTree();
                break;
            }
            case 8:
            {
                previousMenuFlag = 'y';
                break;
            }
            case 9:
            {
                exit(0);
            }
            default:
            {
                std::cout << "The selected option is out of bounds!!! "
                          << "Please select appropriate option: " << std::endl;
                break;
            }
            }

            if (previousMenuFlag == 'y')
            {
                break;
            }
            else
            {
                binaryTreeUsingArrayObj.PrintMenu();
                binaryTreeUsingArrayObj.GetChoiceInputFromUser();
            }
        }
    }

    template <class T>
    void Handle(tree::BinaryTreeUsingLinkedRepresentation<T>& binaryTreeUsingLinkedRepresentationObj)
    {
        binaryTreeUsingLinkedRepresentationObj.PrintMenu();
        binaryTreeUsingLinkedRepresentationObj.GetChoiceInputFromUser();
        const int& selectedChoice = binaryTreeUsingLinkedRepresentationObj.GetChoice();

        while (binaryTreeUsingLinkedRepresentationObj.GetChoice())
        {
            char previousMenuFlag = 'n';
            if (selectedChoice > binaryTreeUsingLinkedRepresentationObj.GetMinCase() &&
                selectedChoice < binaryTreeUsingLinkedRepresentationObj.GetMaxCase() + 1)
            {
                binaryTreeUsingLinkedRepresentationObj.PrintSelectedChoice();
            }

            switch (selectedChoice)
            {
            case 1:
            {
                bool res = binaryTreeUsingLinkedRepresentationObj.IsExisting();
                
                if (res)
                {
                    std::cout << "The tree exists" << std::endl;
                }
                else
                {
                    std::cout << "The tree does not exist" << std::endl;
                }
                break;
            }
            case 2:
            {
                if (not binaryTreeUsingLinkedRepresentationObj.IsExisting())
                {
                    std::cout << "The tree does not exist" << std::endl;
                }
                else
                {
                    binaryTreeUsingLinkedRepresentationObj.DisplayPreOrderRecursive(binaryTreeUsingLinkedRepresentationObj.GetRootNode());
                    std::cout << std::endl;
                }
                break;
            }
            case 3:
            {
                if (not binaryTreeUsingLinkedRepresentationObj.IsExisting())
                {
                    std::cout << "The tree does not exist" << std::endl;
                }
                else
                {
                    binaryTreeUsingLinkedRepresentationObj.DisplayInOrderRecursive(binaryTreeUsingLinkedRepresentationObj.GetRootNode());
                    std::cout << std::endl;
                }
                break;
            }
            case 4:
            {
                if (not binaryTreeUsingLinkedRepresentationObj.IsExisting())
                {
                    std::cout << "The tree does not exist" << std::endl;
                }
                else
                {
                    binaryTreeUsingLinkedRepresentationObj.DisplayPostOrderRecursive(binaryTreeUsingLinkedRepresentationObj.GetRootNode());
                    std::cout << std::endl;
                }
                break;
            }
            case 5:
            {
                if (not binaryTreeUsingLinkedRepresentationObj.IsExisting())
                {
                    std::cout << "The tree does not exist" << std::endl;
                }
                else
                {
                    binaryTreeUsingLinkedRepresentationObj.DisplayLevelOrderRecursive(binaryTreeUsingLinkedRepresentationObj.GetRootNode());
                    std::cout << std::endl;
                }
                break;
            }
            case 6:
            {
                if (binaryTreeUsingLinkedRepresentationObj.IsExisting())
                {
                    std::cout << "Tree already exists, cannot generate tree if already exists, reset and try again" << std::endl;
                }
                else
                {
                    binaryTreeUsingLinkedRepresentationObj.GenerateTree();
                }
                break;
            }
            case 7:
            {
                binaryTreeUsingLinkedRepresentationObj.ResetTree(binaryTreeUsingLinkedRepresentationObj.GetRootNode());
                break;
            }
            case 8:
            {
                previousMenuFlag = 'y';
                break;
            }
            case 9:
            {
                exit(0);
            }
            default:
            {
                std::cout << "The selected option is out of bounds!!! "
                          << "Please select appropriate option: " << std::endl;
                break;
            }
            }

            if (previousMenuFlag == 'y')
            {
                break;
            }
            else
            {
                binaryTreeUsingLinkedRepresentationObj.PrintMenu();
                binaryTreeUsingLinkedRepresentationObj.GetChoiceInputFromUser();
            }
        }
    }
} // namespace handlers
