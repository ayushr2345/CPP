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
} // namespace linkedList
