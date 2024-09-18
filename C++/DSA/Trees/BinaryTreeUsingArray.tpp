#pragma once

#include "BinaryTreeUsingArray.h"
#include "../../utils.h"

namespace tree
{
    template <class T>
    BinaryTreeUsingArray<T>::BinaryTreeUsingArray(int size):
        m_choice                      ( 0 ),
        m_binaryTreeUsingArrayMenuMap ( {} ),
        m_size                        ( size ),
        m_numNodes                    ( 0 ),
        m_data                        { nullptr }
    {
        m_binaryTreeUsingArrayMenuMap.insert({ m_BinaryTreeUsingArrayMenu(DOES_TREE_EXIST),
                                               std::string("Check if the tree exists") });
        m_binaryTreeUsingArrayMenuMap.insert({ m_BinaryTreeUsingArrayMenu(DISPLAY_PREORDER_RECURSIVE),
                                               std::string("Display Preorder Recursive") });
        m_binaryTreeUsingArrayMenuMap.insert({ m_BinaryTreeUsingArrayMenu(DISPLAY_INORDER_RECURSIVE),
                                               std::string("Display Inorder Recursive") });
        m_binaryTreeUsingArrayMenuMap.insert({ m_BinaryTreeUsingArrayMenu(DISPLAY_POSTORDER_RECURSIVE),
                                               std::string("Display Postorder Recursive") });
        m_binaryTreeUsingArrayMenuMap.insert({ m_BinaryTreeUsingArrayMenu(DISPLAY_LEVELORDER_RECURSIVE),
                                               std::string("Display Level order Recursive") });
        m_binaryTreeUsingArrayMenuMap.insert({ m_BinaryTreeUsingArrayMenu(DISPLAY_PREORDER_ITERATIVE),
                                               std::string("Display Preorder Iterative") });
        m_binaryTreeUsingArrayMenuMap.insert({ m_BinaryTreeUsingArrayMenu(DISPLAY_INORDER_ITERATIVE),
                                               std::string("Display Inorder Iterative") });
        m_binaryTreeUsingArrayMenuMap.insert({ m_BinaryTreeUsingArrayMenu(DISPLAY_POSTORDER_ITERATIVE),
                                               std::string("Display Postorder Iterative") });
        m_binaryTreeUsingArrayMenuMap.insert({ m_BinaryTreeUsingArrayMenu(DISPLAY_LEVELORDER_ITERATIVE),
                                               std::string("Display Level order Iterative") });
        m_binaryTreeUsingArrayMenuMap.insert({ m_BinaryTreeUsingArrayMenu(GENERATE_TREE),
                                               std::string("Generate Tree") });
        m_binaryTreeUsingArrayMenuMap.insert({ m_BinaryTreeUsingArrayMenu(RESET_TREE),
                                               std::string("Reset Tree") });
        m_binaryTreeUsingArrayMenuMap.insert({ m_BinaryTreeUsingArrayMenu(BACK_TO_PREVIOUS_MENU),
                                               std::string("Back to Previous Menu") });
        m_binaryTreeUsingArrayMenuMap.insert({ m_BinaryTreeUsingArrayMenu(EXIT_FROM_PROGRAM),
                                               std::string("Exit from program") });
        m_data = new T[m_size];
    }

    template <class T>
    BinaryTreeUsingArray<T>::~BinaryTreeUsingArray()
    {
        ResetTree();
    }
    
    template <class T>
    const int BinaryTreeUsingArray<T>::GetMinCase()
    {
        return m_BinaryTreeUsingArrayMenu::MIN_COUNT;
    }

    template <class T>
    const int BinaryTreeUsingArray<T>::GetMaxCase()
    {
        return m_BinaryTreeUsingArrayMenu::MAX_COUNT;
    }

    template <class T>
    const int& BinaryTreeUsingArray<T>::GetChoice()
    {
        return m_choice;
    }

    template <class T>
    void BinaryTreeUsingArray<T>::GetChoiceInputFromUser()
    {
        utils::InputNumberFromUser(m_choice, 1, static_cast<int>(m_BinaryTreeUsingArrayMenu::MAX_COUNT));
    }

    template <class T>
    void BinaryTreeUsingArray<T>::PrintMenu()
    {
        std::cout << std::endl;
        for (std::map<int, std::string>::iterator it = m_binaryTreeUsingArrayMenuMap.begin();
            it != m_binaryTreeUsingArrayMenuMap.end();
            it++)
        {
            std::cout << it->first << ". " << it->second << std::endl;
        }
        std::cout << "Please enter your choice: ";
    }

    template <class T>
    void BinaryTreeUsingArray<T>::PrintSelectedChoice()
    {
        std::cout << std::endl << std::endl
                << "You have chosen choice "
                << m_binaryTreeUsingArrayMenuMap.at(m_choice)
                << std::endl;
    }

    template <class T>
    std::optional<T> BinaryTreeUsingArray<T>::GetRootNode()
    {
        return m_data[1];
    }

    template <class T>
    bool BinaryTreeUsingArray<T>::IsExisting()
    {
        return m_numNodes ? true : false;
    }

    template <class T>
    void BinaryTreeUsingArray<T>::DisplayPreOrderRecursive(const int node)
    {
        if (node <= m_numNodes)
        {
            std::cout << m_data[node] << " ";
            DisplayPreOrderRecursive(2 * node);
            DisplayPreOrderRecursive(2 * node + 1);
        }
    }

    template <class T>
    void BinaryTreeUsingArray<T>::DisplayInOrderRecursive(const int node)
    {
        if (node <= m_numNodes)
        {
            DisplayInOrderRecursive(2 * node);
            std::cout << m_data[node] << " ";
            DisplayInOrderRecursive(2 * node + 1);
        }
    }

    template <class T>
    void BinaryTreeUsingArray<T>::DisplayPostOrderRecursive(const int node)
    {
        if (node <= m_numNodes)
        {
            DisplayPostOrderRecursive(2 * node);
            DisplayPostOrderRecursive(2 * node + 1);
            std::cout << m_data[node] << " ";
        }
    }

    template <class T>
    void BinaryTreeUsingArray<T>::DisplayLevelOrderRecursive(const int node)
    {
        if (node == 1)
        {
            std::cout << m_data[node] << " ";
        }
        if (node <= m_numNodes)
        {
            if ((2 * node) <= m_numNodes)
            {
                std::cout << m_data[2 * node] << " ";
            }
            if ((2 * node + 1) <= m_numNodes)
            {
                std::cout << m_data[2 * node + 1] << " ";
            }
            DisplayLevelOrderRecursive(2 * node);
            DisplayLevelOrderRecursive(2 * node + 1);
        }
    }

    template <class T>
    void BinaryTreeUsingArray<T>::DisplayPreOrderIterative()
    {
        stack::StackUsingLinkedList<int> treeStack;

        int temp = 1;
        while (not treeStack.IsEmpty() or temp <= m_numNodes)
        {
            if (temp <= m_numNodes)
            {
                std::cout << m_data[temp] << " ";
                treeStack.Push(temp);
                temp = 2 * temp;
            }
            else
            {
                std::optional<int> poppedNode = treeStack.Pop();
                temp = 2 * poppedNode.value() + 1;
            }
        }
    }

    template <class T>
    void BinaryTreeUsingArray<T>::DisplayInOrderIterative()
    {
        stack::StackUsingLinkedList<int> treeStack;

        int temp = 1;
        while (not treeStack.IsEmpty() or temp <= m_numNodes)
        {
            if (temp <= m_numNodes)
            {
                treeStack.Push(temp);
                temp = 2 * temp;
            }
            else
            {
                std::optional<int> poppedNode = treeStack.Pop();
                std::cout << m_data[poppedNode.value()] << " ";
                temp = 2 * poppedNode.value() + 1;
            }
        }
    }

    template <class T>
    void BinaryTreeUsingArray<T>::DisplayPostOrderIterative()
    {
        stack::StackUsingLinkedList<int> treeStack;

        int temp = 1;
        while (not treeStack.IsEmpty() or temp <= m_numNodes)
        {
            if (temp <= m_numNodes)
            {
                treeStack.Push(temp);
                temp = 2 * temp;
            }
            else
            {
                std::optional<int> poppedNode = treeStack.Pop();
                if (poppedNode.value() < 0)
                {
                    std::cout << m_data[abs(poppedNode.value())] << " ";
                }
                else
                {
                    treeStack.Push(-poppedNode.value());
                    temp = 2 * poppedNode.value() + 1;
                }
            }
        }
    }

    template <class T>
    void BinaryTreeUsingArray<T>::DisplayLevelOrderIterative()
    {
        queue::QueueUsingLinkedList<int> treeQueue;

        int temp = 1;
        treeQueue.Enqueue(temp);
        std::cout << m_data[temp] << " ";
        while (not treeQueue.IsEmpty())
        {
            temp = treeQueue.Dequeue().value();
            if ((2 * temp) <= m_numNodes)
            {
                std::cout << m_data[2 * temp] << " ";
                treeQueue.Enqueue(2 * temp);
            }
            if ((2 * temp + 1) <= m_numNodes)
            {
                std::cout << m_data[2 * temp + 1] << " ";
                treeQueue.Enqueue(2 * temp + 1);
            }
        }
    }

    template <class T>
    void BinaryTreeUsingArray<T>::GenerateTree()
    {
        std::cout << "Enter the root node of the tree: ";
        utils::InputNumberFromUser(m_data[1]);
        m_numNodes++;

        int currentNode = 1;
        while (currentNode < m_size)
        {
            // getting the left child
            std::cout << "Current Node: " << m_data[currentNode] << std::endl;
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
                std::cout << "Enter the left child of the node " << m_data[currentNode] << ": ";
                utils::InputNumberFromUser(m_data[2 * currentNode]);
                m_numNodes++;
            }

            // getting the right child
            std::cout << "Current Node: " << m_data[currentNode] << std::endl;
            std::cout << "Does this node has a right child (y/n): ";
            std::cin >> ch;

            while (ch != 'y' and ch != 'Y' and ch != 'n' and ch != 'N')
            {
                std::cout << "Wrong Input, please enter again: ";
                std::cin >> ch;
            }

            if (ch == 'y' or ch == 'Y')
            {
                std::cout << "Enter the right child of the node " << m_data[currentNode] << ": ";
                utils::InputNumberFromUser(m_data[2 * currentNode + 1]);
                m_numNodes++;
            }
            currentNode++;
        }

    }

    template <class T>
    void BinaryTreeUsingArray<T>::ResetTree()
    {
        delete []m_data;
        m_data = nullptr;
        m_numNodes = 0;
    }
} //namespace tree
