#pragma once

#include "BinaryTreeUsingLinkedRepresentation.h"
#include "../../utils.h"

namespace tree
{
    template <class T>
    BinaryTreeUsingLinkedRepresentation<T>::BinaryTreeUsingLinkedRepresentation():
        m_choice                                     ( 0 ),
        m_binaryTreeUsingLinkedRepresentationMenuMap ( {} ),
        m_rootNode                                   { nullptr }
    {
        m_binaryTreeUsingLinkedRepresentationMenuMap.insert({ m_BinaryTreeUsingLinkedRepresentationMenu(DOES_TREE_EXIST),
                                                              std::string("Check if the tree exists") });
        m_binaryTreeUsingLinkedRepresentationMenuMap.insert({ m_BinaryTreeUsingLinkedRepresentationMenu(DISPLAY_PREORDER_RECURSIVE),
                                                              std::string("Display Preorder Recursive") });
        m_binaryTreeUsingLinkedRepresentationMenuMap.insert({ m_BinaryTreeUsingLinkedRepresentationMenu(DISPLAY_INORDER_RECURSIVE),
                                                              std::string("Display Inorder Recursive") });
        m_binaryTreeUsingLinkedRepresentationMenuMap.insert({ m_BinaryTreeUsingLinkedRepresentationMenu(DISPLAY_POSTORDER_RECURSIVE),
                                                              std::string("Display Postorder Recursive") });
        m_binaryTreeUsingLinkedRepresentationMenuMap.insert({ m_BinaryTreeUsingLinkedRepresentationMenu(DISPLAY_LEVELORDER_RECURSIVE),
                                                              std::string("Display Level order Recursive") });
        m_binaryTreeUsingLinkedRepresentationMenuMap.insert({ m_BinaryTreeUsingLinkedRepresentationMenu(DISPLAY_PREORDER_ITERATIVE),
                                                              std::string("Display Preorder Iterative") });
        m_binaryTreeUsingLinkedRepresentationMenuMap.insert({ m_BinaryTreeUsingLinkedRepresentationMenu(DISPLAY_INORDER_ITERATIVE),
                                                              std::string("Display Inorder Iterative") });
        m_binaryTreeUsingLinkedRepresentationMenuMap.insert({ m_BinaryTreeUsingLinkedRepresentationMenu(DISPLAY_POSTORDER_ITERATIVE),
                                                              std::string("Display Postorder Iterative") });
        m_binaryTreeUsingLinkedRepresentationMenuMap.insert({ m_BinaryTreeUsingLinkedRepresentationMenu(DISPLAY_LEVELORDER_ITERATIVE),
                                                              std::string("Display Level order Iterative") });
        m_binaryTreeUsingLinkedRepresentationMenuMap.insert({ m_BinaryTreeUsingLinkedRepresentationMenu(GENERATE_TREE),
                                                              std::string("Generate Tree") });
        m_binaryTreeUsingLinkedRepresentationMenuMap.insert({ m_BinaryTreeUsingLinkedRepresentationMenu(RESET_TREE),
                                                              std::string("Reset Tree") });
        m_binaryTreeUsingLinkedRepresentationMenuMap.insert({ m_BinaryTreeUsingLinkedRepresentationMenu(BACK_TO_PREVIOUS_MENU),
                                                              std::string("Back to Previous Menu") });
        m_binaryTreeUsingLinkedRepresentationMenuMap.insert({ m_BinaryTreeUsingLinkedRepresentationMenu(EXIT_FROM_PROGRAM),
                                                              std::string("Exit from program") });
    }

    template <class T>
    BinaryTreeUsingLinkedRepresentation<T>::~BinaryTreeUsingLinkedRepresentation()
    {
        ResetTree(m_rootNode);
    }
    
    template <class T>
    const int BinaryTreeUsingLinkedRepresentation<T>::GetMinCase()
    {
        return m_BinaryTreeUsingLinkedRepresentationMenu::MIN_COUNT;
    }

    template <class T>
    const int BinaryTreeUsingLinkedRepresentation<T>::GetMaxCase()
    {
        return m_BinaryTreeUsingLinkedRepresentationMenu::MAX_COUNT;
    }

    template <class T>
    const int& BinaryTreeUsingLinkedRepresentation<T>::GetChoice()
    {
        return m_choice;
    }

    template <class T>
    void BinaryTreeUsingLinkedRepresentation<T>::GetChoiceInputFromUser()
    {
        utils::InputNumberFromUser(m_choice, 1, static_cast<int>(m_BinaryTreeUsingLinkedRepresentationMenu::MAX_COUNT));
    }

    template <class T>
    void BinaryTreeUsingLinkedRepresentation<T>::PrintMenu()
    {
        std::cout << std::endl;
        for (std::map<int, std::string>::iterator it = m_binaryTreeUsingLinkedRepresentationMenuMap.begin();
            it != m_binaryTreeUsingLinkedRepresentationMenuMap.end();
            it++)
        {
            std::cout << it->first << ". " << it->second << std::endl;
        }
        std::cout << "Please enter your choice: ";
    }

    template <class T>
    void BinaryTreeUsingLinkedRepresentation<T>::PrintSelectedChoice()
    {
        std::cout << std::endl << std::endl
                << "You have chosen choice "
                << m_binaryTreeUsingLinkedRepresentationMenuMap.at(m_choice)
                << std::endl;
    }

    template <class T>
    const BinaryTreeUsingLinkedRepresentation<T>::Node* BinaryTreeUsingLinkedRepresentation<T>::GetRootNode()
    {
        return m_rootNode;
    }

    template <class T>
    bool BinaryTreeUsingLinkedRepresentation<T>::IsExisting()
    {
        return m_rootNode ? true : false;
    }

    template <class T>
    void BinaryTreeUsingLinkedRepresentation<T>::DisplayPreOrderRecursive(const Node* node)
    {
        if (node)
        {
            std::cout << node->m_m_data << " ";
            DisplayPreOrderRecursive(node->m_m_leftChild);
            DisplayPreOrderRecursive(node->m_m_rightChild);
        }
    }

    template <class T>
    void BinaryTreeUsingLinkedRepresentation<T>::DisplayInOrderRecursive(const Node* node)
    {
        if (node)
        {
            DisplayInOrderRecursive(node->m_m_leftChild);
            std::cout << node->m_m_data << " ";
            DisplayInOrderRecursive(node->m_m_rightChild);
        }
    }

    template <class T>
    void BinaryTreeUsingLinkedRepresentation<T>::DisplayPostOrderRecursive(const Node* node)
    {
        if (node)
        {
            DisplayPostOrderRecursive(node->m_m_leftChild);
            DisplayPostOrderRecursive(node->m_m_rightChild);
            std::cout << node->m_m_data << " ";
        }
    }

    template <class T>
    void BinaryTreeUsingLinkedRepresentation<T>::DisplayLevelOrderRecursive(const Node* node)
    {
        if (node == m_rootNode)
        {
            std::cout << node->m_m_data << " ";
        }
        if (node)
        {
            if (node->m_m_leftChild)
            {
                std::cout << node->m_m_leftChild->m_m_data << " ";
            }
            if (node->m_m_rightChild)
            {
                std::cout << node->m_m_rightChild->m_m_data << " ";
            }
            DisplayLevelOrderRecursive(node->m_m_leftChild);
            DisplayLevelOrderRecursive(node->m_m_rightChild);
        }
    }

    template <class T>
    void BinaryTreeUsingLinkedRepresentation<T>::DisplayPreOrderIterative()
    {
        stack::StackUsingLinkedList<Node*> treeStack;

        Node* temp = m_rootNode;
        while (not treeStack.IsEmpty() or temp != nullptr)
        {
            if (temp)
            {
                std::cout << temp->m_m_data << " ";
                treeStack.Push(temp);
                temp = temp->m_m_leftChild;
            }
            else
            {
                std::optional<Node*> poppedNode = treeStack.Pop();
                temp = poppedNode.value()->m_m_rightChild;
            }
        }
    }

    template <class T>
    void BinaryTreeUsingLinkedRepresentation<T>::DisplayInOrderIterative()
    {
        stack::StackUsingLinkedList<Node*> treeStack;

        Node* temp = m_rootNode;
        while (not treeStack.IsEmpty() or temp != nullptr)
        {
            if (temp)
            {
                treeStack.Push(temp);
                temp = temp->m_m_leftChild;
            }
            else
            {
                std::optional<Node*> poppedNode = treeStack.Pop();
                std::cout << poppedNode.value()->m_m_data << " ";
                temp = poppedNode.value()->m_m_rightChild;
            }
        }
    }

    template <class T>
    void BinaryTreeUsingLinkedRepresentation<T>::DisplayPostOrderIterative()
    {
        stack::StackUsingLinkedList<Node*> treeStack;

        Node* temp = m_rootNode;
        while (not treeStack.IsEmpty() or temp != nullptr)
        {
            if (temp)
            {
                treeStack.Push(temp);
                temp = temp->m_m_leftChild;
            }
            else
            {
                std::optional<Node*> poppedNode = treeStack.Pop();
                // Check if the LSB is 1
                bool isTagged = reinterpret_cast<intptr_t>(poppedNode.value()) & 1;
                if (isTagged)
                {
                    // untag the node address (remove the LSB)
                    Node* taggedNode = reinterpret_cast<Node*>(reinterpret_cast<intptr_t>(poppedNode.value()) & ~1);
                    std::cout << taggedNode->m_m_data << " ";
                }
                else
                {
                    temp = poppedNode.value()->m_m_rightChild;
                    // Set the LSB to 1
                    treeStack.Push(reinterpret_cast<Node*>(reinterpret_cast<intptr_t>(poppedNode.value()) | 1));
                }
            }
        }
    }

    template <class T>
    void BinaryTreeUsingLinkedRepresentation<T>::DisplayLevelOrderIterative()
    {
        queue::QueueUsingLinkedList<Node*> treeQueue;

        Node* temp = m_rootNode;
        treeQueue.Enqueue(temp);
        std::cout << temp->m_m_data << " ";
        while (not treeQueue.IsEmpty())
        {
            temp = treeQueue.Dequeue().value();
            if (temp->m_m_leftChild)
            {
                std::cout << temp->m_m_leftChild->m_m_data << " ";
                treeQueue.Enqueue(temp->m_m_leftChild);
            }
            if (temp->m_m_rightChild)
            {
                std::cout << temp->m_m_rightChild->m_m_data << " ";
                treeQueue.Enqueue(temp->m_m_rightChild);
            }
        }
    }

    template <class T>
    void BinaryTreeUsingLinkedRepresentation<T>::GenerateTree()
    {
        std::cout << "Enter the root node of the tree: ";
        
        Node* temp = new Node;
        temp->m_m_leftChild = nullptr;
        temp->m_m_rightChild = nullptr;

        utils::InputNumberFromUser(temp->m_m_data);
        m_rootNode = temp;

        queue::QueueUsingLinkedList<Node*> treeQueue;
        treeQueue.Enqueue(m_rootNode);

        while (not treeQueue.IsEmpty())
        {
            std::optional<Node*> poppedNode = treeQueue.Dequeue();
            if (not poppedNode.has_value())
            {
                std::cout << "Breaking as this condition should never exist" << std::endl;
                break;
            }

            // getting the left child
            std::cout << "Current Node: " << poppedNode.value()->m_m_data << std::endl;
            std::cout << "Does this node has a left child (y/n): ";
            char ch;
            std::cin >> ch;

            while (ch != 'y' and ch != 'Y' and ch != 'n' and ch != 'N')
            {
                std::cout << "Wrong Input, please enter again: ";
                std::cin >> ch;
            }

            if (ch == 'y' or ch == 'Y')
            {
                Node* temp = new Node;
                std::cout << "Enter the left child of the node " << poppedNode.value()->m_m_data << ": ";
                utils::InputNumberFromUser(temp->m_m_data);
                temp->m_m_leftChild = nullptr;
                temp->m_m_rightChild = nullptr;

                poppedNode.value()->m_m_leftChild = temp;
                treeQueue.Enqueue(temp);
            }

            // getting the right child
            std::cout << "Current Node: " << poppedNode.value()->m_m_data << std::endl;
            std::cout << "Does this node has a right child (y/n): ";
            std::cin >> ch;

            while (ch != 'y' and ch != 'Y' and ch != 'n' and ch != 'N')
            {
                std::cout << "Wrong Input, please enter again: ";
                std::cin >> ch;
            }

            if (ch == 'y' or ch == 'Y')
            {
                Node* temp = new Node;
                std::cout << "Enter the right child of the node " << poppedNode.value()->m_m_data << ": ";
                utils::InputNumberFromUser(temp->m_m_data);
                temp->m_m_leftChild = nullptr;
                temp->m_m_rightChild = nullptr;

                poppedNode.value()->m_m_rightChild = temp;
                treeQueue.Enqueue(temp);
            }
        }
    }

    template <class T>
    void BinaryTreeUsingLinkedRepresentation<T>::ResetTree(const Node* node)
    {
        if (node)
        {
            Node* leftNode = node->m_m_leftChild;
            Node* rightNode = node->m_m_rightChild;
            delete node;
            if (node == m_rootNode)
            {
                m_rootNode = nullptr;
            }
            ResetTree(leftNode);
            ResetTree(rightNode);
        }
    }
} //namespace tree
