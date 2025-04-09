#pragma once

#include "utils.h"


namespace handlers
{
    template <class T>
    void Handle(sorting_algorithms::BubbleSort<T>& bubbleSortObj)
    {
        bubbleSortObj.PrintMenu();
        bubbleSortObj.GetChoiceInputFromUser();
        const int& selectedChoice = bubbleSortObj.GetChoice();

        while (bubbleSortObj.GetChoice())
        {
            char previousMenuFlag = 'n';
            if (selectedChoice > bubbleSortObj.GetMinCase() &&
                selectedChoice < bubbleSortObj.GetMaxCase() + 1)
            {
                bubbleSortObj.PrintSelectedChoice();
            }

            switch (selectedChoice)
            {
            case 1:
            {
                bubbleSortObj.ShowcaseBubbleSort();
                break;
            }
            case 2:
            {
                bubbleSortObj.ShowcaseBubbleSortAction();
                break;
            }
            case 3:
            {
                bubbleSortObj.InsertElements();
                break;
            }
            case 4:
            {
                if (not bubbleSortObj.DoesDataExist())
                {
                    std::cout << "No element present in the array, cannot perform bubble sort" << std::endl;
                }
                bool res = bubbleSortObj.PerformBubbleSort();
                if (res)
                {
                    std::cout << "Successfully performed bubble sort on the array" << std::endl;
                }
                else
                {
                    std::cout << "Could not perform bubble sort on the array" << std::endl;
                }
                break;
            }
            case 5:
            {
                if (not bubbleSortObj.DoesDataExist())
                {
                    std::cout << "No element present in the array, nothing to display" << std::endl;
                }
                else
                {
                    bubbleSortObj.DisplayArray();
                }
                break;
            }
            case 6:
            {
                previousMenuFlag = 'y';
                break;
            }
            case 7:
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
                bubbleSortObj.PrintMenu();
                bubbleSortObj.GetChoiceInputFromUser();
            }
        }
    }

    template <class T>
    void Handle(sorting_algorithms::InsertionSort<T>& insertionSortObj)
    {
        insertionSortObj.PrintMenu();
        insertionSortObj.GetChoiceInputFromUser();
        const int& selectedChoice = insertionSortObj.GetChoice();

        while (insertionSortObj.GetChoice())
        {
            char previousMenuFlag = 'n';
            if (selectedChoice > insertionSortObj.GetMinCase() &&
                selectedChoice < insertionSortObj.GetMaxCase() + 1)
            {
                insertionSortObj.PrintSelectedChoice();
            }

            switch (selectedChoice)
            {
            case 1:
            {
                insertionSortObj.ShowcaseInsertionSort();
                break;
            }
            case 2:
            {
                insertionSortObj.ShowcaseInsertionSortAction();
                break;
            }
            case 3:
            {
                insertionSortObj.InsertElements();
                break;
            }
            case 4:
            {
                if (not insertionSortObj.DoesDataExist())
                {
                    std::cout << "No element present in the array, cannot perform insertion sort" << std::endl;
                }
                bool res = insertionSortObj.PerformInsertionSort();
                if (res)
                {
                    std::cout << "Successfully performed insertion sort on the array" << std::endl;
                }
                else
                {
                    std::cout << "Could not perform insertion sort on the array" << std::endl;
                }
                break;
            }
            case 5:
            {
                if (not insertionSortObj.DoesDataExist())
                {
                    std::cout << "No element present in the array, nothing to display" << std::endl;
                }
                else
                {
                    insertionSortObj.DisplayArray();
                }
                break;
            }
            case 6:
            {
                previousMenuFlag = 'y';
                break;
            }
            case 7:
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
                insertionSortObj.PrintMenu();
                insertionSortObj.GetChoiceInputFromUser();
            }
        }
    }

    template <class T>
    void Handle(sorting_algorithms::SelectionSort<T>& selectionSortObj)
    {
        selectionSortObj.PrintMenu();
        selectionSortObj.GetChoiceInputFromUser();
        const int& selectedChoice = selectionSortObj.GetChoice();

        while (selectionSortObj.GetChoice())
        {
            char previousMenuFlag = 'n';
            if (selectedChoice > selectionSortObj.GetMinCase() &&
                selectedChoice < selectionSortObj.GetMaxCase() + 1)
            {
                selectionSortObj.PrintSelectedChoice();
            }

            switch (selectedChoice)
            {
            case 1:
            {
                selectionSortObj.ShowcaseSelectionSort();
                break;
            }
            case 2:
            {
                selectionSortObj.ShowcaseSelectionSortAction();
                break;
            }
            case 3:
            {
                selectionSortObj.InsertElements();
                break;
            }
            case 4:
            {
                if (not selectionSortObj.DoesDataExist())
                {
                    std::cout << "No element present in the array, cannot perform selection sort" << std::endl;
                }
                bool res = selectionSortObj.PerformSelectionSort();
                if (res)
                {
                    std::cout << "Successfully performed selection sort on the array" << std::endl;
                }
                else
                {
                    std::cout << "Could not perform selection sort on the array" << std::endl;
                }
                break;
            }
            case 5:
            {
                if (not selectionSortObj.DoesDataExist())
                {
                    std::cout << "No element present in the array, nothing to display" << std::endl;
                }
                else
                {
                    selectionSortObj.DisplayArray();
                }
                break;
            }
            case 6:
            {
                previousMenuFlag = 'y';
                break;
            }
            case 7:
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
                selectionSortObj.PrintMenu();
                selectionSortObj.GetChoiceInputFromUser();
            }
        }
    }

    template <class T>
    void Handle(sorting_algorithms::QuickSort<T>& quickSortObj)
    {
        quickSortObj.PrintMenu();
        quickSortObj.GetChoiceInputFromUser();
        const int& selectedChoice = quickSortObj.GetChoice();

        while (quickSortObj.GetChoice())
        {
            char previousMenuFlag = 'n';
            if (selectedChoice > quickSortObj.GetMinCase() &&
                selectedChoice < quickSortObj.GetMaxCase() + 1)
            {
                quickSortObj.PrintSelectedChoice();
            }

            switch (selectedChoice)
            {
            case 1:
            {
                quickSortObj.ShowcaseQuickSort();
                break;
            }
            case 2:
            {
                quickSortObj.ShowcaseQuickSortAction();
                break;
            }
            case 3:
            {
                quickSortObj.InsertElements();
                break;
            }
            case 4:
            {
                if (not quickSortObj.DoesDataExist())
                {
                    std::cout << "No element present in the array, cannot perform quick sort" << std::endl;
                }
                bool res = quickSortObj.PerformQuickSort();
                if (res)
                {
                    std::cout << "Successfully performed quick sort on the array" << std::endl;
                }
                else
                {
                    std::cout << "Could not perform quick sort on the array" << std::endl;
                }
                break;
            }
            case 5:
            {
                if (not quickSortObj.DoesDataExist())
                {
                    std::cout << "No element present in the array, nothing to display" << std::endl;
                }
                else
                {
                    quickSortObj.DisplayArray();
                }
                break;
            }
            case 6:
            {
                previousMenuFlag = 'y';
                break;
            }
            case 7:
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
                quickSortObj.PrintMenu();
                quickSortObj.GetChoiceInputFromUser();
            }
        }
    }
} // namespace handlers