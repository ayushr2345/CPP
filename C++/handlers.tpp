#pragma once

#include "DSA/ArrayADT/ArrayADT.h"
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
                std::cout << "Enter the element which you want to insert at the end: ";
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
} // namespace handlers
