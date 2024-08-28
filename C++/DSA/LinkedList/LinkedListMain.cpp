#include <iostream>
#include <functional>
#include "LinkedListMain.h"
#include "../../utils.h"
#include "../../handlers.h"

namespace linkedList
{
    LinkedListMain::LinkedListMain():
        m_choice                ( 0 ),
        m_linkedListMainMenuMap ( {} )
    {
        m_linkedListMainMenuMap.insert({ m_LinkedListMainMenu(LINEAR_SINGLY_LINKED_LIST), 
                                         std::string("Linear Singly Linked List") });
        m_linkedListMainMenuMap.insert({ m_LinkedListMainMenu(CIRCULAR_SINGLY_LINKED_LIST), 
                                         std::string("Circular Singly Linked List") });
        m_linkedListMainMenuMap.insert({ m_LinkedListMainMenu(LINEAR_DOUBLY_LINKED_LIST), 
                                         std::string("Linear Doubly Linked List") });
        m_linkedListMainMenuMap.insert({ m_LinkedListMainMenu(CIRCULAR_DOUBLY_LINKED_LIST), 
                                         std::string("Circular Doubly Linked List") });
        m_linkedListMainMenuMap.insert({ m_LinkedListMainMenu(SPARSE_MATRIX), 
                                         std::string("Sparse Matrix") });
        m_linkedListMainMenuMap.insert({ m_LinkedListMainMenu(SPARSE_MATRIX_ADDITION), 
                                         std::string("Sparse Matrix Addition") });
        m_linkedListMainMenuMap.insert({ m_LinkedListMainMenu(BACK_TO_PREVIOUS_MENU),
                                         std::string("Back to Previous Menu") });
        m_linkedListMainMenuMap.insert({ m_LinkedListMainMenu(EXIT_FROM_PROGRAM),
                                         std::string("Exit from program") });
    }

    const int LinkedListMain::GetMinCase()
    {
        return m_LinkedListMainMenu::MIN_COUNT;
    }

    const int LinkedListMain::GetMaxCase()
    {
        return m_LinkedListMainMenu::MAX_COUNT;
    }

    const int& LinkedListMain::GetChoice()
    {
        return m_choice;
    }

    void LinkedListMain::GetChoiceInputFromUser()
    {
        utils::InputNumberFromUser(m_choice, 1, static_cast<int>(m_LinkedListMainMenu::MAX_COUNT));
    }

    void LinkedListMain::PrintMenu()
    {
        std::cout << std::endl;
        for (std::map<int, std::string>::iterator it = m_linkedListMainMenuMap.begin();
            it != m_linkedListMainMenuMap.end();
            it++)
        {
            std::cout << it->first << ". " << it->second << std::endl;
        }
        std::cout << "Please enter your choice: ";
    }

    void LinkedListMain::PrintSelectedChoice()
    {
        std::cout << std::endl << std::endl
                  << "You have chosen choice "
                  << m_linkedListMainMenuMap.at(m_choice)
                  << std::endl;
    }

    void LinkedListMain::LinearSinglyLinkedList()
    {
        linkedList::LinearSinglyLinkedList<int> linearSinglyLinkedListObj;
        handlers::Handle(linearSinglyLinkedListObj);
    }

    void LinkedListMain::CircularSinglyLinkedList()
    {
        linkedList::CircularSinglyLinkedList<int> circularSinglyLinkedListObj;
        handlers::Handle(circularSinglyLinkedListObj);
    }

    void LinkedListMain::LinearDoublyLinkedList()
    {
        linkedList::LinearDoublyLinkedList<int> linearDoublyLinkedListObj;
        handlers::Handle(linearDoublyLinkedListObj);
    }

    void LinkedListMain::CircularDoublyLinkedList()
    {
        linkedList::CircularDoublyLinkedList<int> CircularDoublyLinkedListObj;
        handlers::Handle(CircularDoublyLinkedListObj);
    }

    void LinkedListMain::SparseMatrixUsingLinkedList()
    {
        std::cout << "The matrix non-zero elements are very less than number of zero elements" << std::endl;

        int numRows    = { 0 };
        int numColumns = { 0 };
        int numNonZero = { 0 };
        std::cout << "Please enter the number of rows in the matrix: ";
        utils::InputNumberFromUser(numRows, 2, 10);

        std::cout << "Please enter number of columns in the matrix: ";
        utils::InputNumberFromUser(numColumns, 2, 10);

        std::cout << "Please enter the number of non-zero elements in the matrix: ";
        utils::InputNumberFromUser(numNonZero, 2, numRows * numColumns);

        linkedList::SparseMatrix smObj(numRows, numColumns, numNonZero);

        std::cout << "Please enter all the non-zero elements row by row: " << std::endl;

        int row, column, element;
        for (int i = 0; i < numNonZero; i++)
        {
            utils::InputNumberFromUser(row, 1, numRows, 'n');
            utils::InputNumberFromUser(column, 1, numColumns, 'n');
            utils::InputNumberFromUser(element, 1, 9, 'n');
            smObj.Set(row, column, element);
        }

        smObj.Display();
    }

    void LinkedListMain::SparseMatrixAdditionUsingLinkedList()
    {
        int numRows    = { 0 };
        int numColumns = { 0 };
        int numNonZero = { 0 };
        std::cout << "Please enter the number of rows in the matrix: ";
        utils::InputNumberFromUser(numRows, 2, 10);

        std::cout << "Please enter number of columns in the matrix: ";
        utils::InputNumberFromUser(numColumns, 2, 10);

        std::cout << "Please enter the number of non-zero elements in the matrix: ";
        utils::InputNumberFromUser(numNonZero, 2, numRows * numColumns);

        linkedList::SparseMatrix smObj1(numRows, numColumns, numNonZero);

        std::cout << "Please enter all the non-zero elements row by row: " << std::endl;

        int row, column, element;
        for (int i = 0; i < numNonZero; i++)
        {
            utils::InputNumberFromUser(row, 1, numRows, 'n');
            utils::InputNumberFromUser(column, 1, numColumns, 'n');
            utils::InputNumberFromUser(element, 1, 9, 'n');
            smObj1.Set(row, column, element);
        }

        linkedList::SparseMatrix smObj2(numRows, numColumns, numNonZero);
        smObj2.Set(1, 2, 1);
        smObj2.Set(1, 3, 5);
        smObj2.Set(2, 3, 5);
        smObj2.Set(3, 2, 1);
        smObj2.Set(4, 2, 1);

        smObj1.Display();
        std::cout << std::endl;

        smObj2.Display();
        std::cout << std::endl;

        linkedList::SparseMatrix *temp = smObj1 + smObj2;
        temp->Display();

        delete temp;
    }
} // namespace linkedList
