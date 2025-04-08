#pragma once

#include "AVLTree.h"
#include "../../utils.h"

namespace tree
{
    /******************************************
    ************* PRIVATE METHODS *************
    *******************************************/

    template <class T>
    void AVLTree<T>::DisplayPreOrder(const Node* node)
    {
        if (node)
        {
            std::cout << node->m_m_data << " ";
            DisplayPreOrder(node->m_m_leftChild);
            DisplayPreOrder(node->m_m_rightChild);
        }
    }

    template <class T>
    void AVLTree<T>::DisplayInOrder(const Node* node)
    {
        if (node)
        {
            DisplayInOrder(node->m_m_leftChild);
            std::cout << node->m_m_data << " ";
            DisplayInOrder(node->m_m_rightChild);
        }
    }

    template <class T>
    void AVLTree<T>::DisplayPostOrder(const Node* node)
    {
        if (node)
        {
            DisplayPostOrder(node->m_m_leftChild);
            DisplayPostOrder(node->m_m_rightChild);
            std::cout << node->m_m_data << " ";
        }
    }

    template <class T>
    void AVLTree<T>::DisplayLevelOrder(const Node* node)
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
            DisplayLevelOrder(node->m_m_leftChild);
            DisplayLevelOrder(node->m_m_rightChild);
        }
    }

    template <class T>
    int AVLTree<T>::CalculateNodeHeight(const Node* node)
    {
        int nodeLeftHeight  = 0;
        int nodeRightHeight = 0;
        if (node->m_m_leftChild)
        {
            nodeLeftHeight = node->m_m_leftChild->m_m_height;
        }
        if (node->m_m_rightChild)
        {
            nodeRightHeight = node->m_m_rightChild->m_m_height;
        }
        return nodeLeftHeight > nodeRightHeight ? nodeLeftHeight : nodeRightHeight;
    }

    template <class T>
    int AVLTree<T>::CalculateBalanceFactor(const Node* node)
    {
        int nodeLeftHeight  = 0;
        int nodeRightHeight = 0;
        if (node->m_m_leftChild)
        {
            nodeLeftHeight = node->m_m_leftChild->m_m_height;
        }
        if (node->m_m_rightChild)
        {
            nodeRightHeight = node->m_m_rightChild->m_m_height;
        }
        return nodeLeftHeight - nodeRightHeight;
    }

    template <class T>
    AVLTree<T>::Node* AVLTree<T>::PerformLLRotation(Node* node)
    {
        Node* nodeLeftChild = node->m_m_leftChild;
        Node* nodeRightOfLeftChild = nodeLeftChild->m_m_rightChild;

        nodeLeftChild->m_m_rightChild = node;
        node->m_m_leftChild = nodeRightOfLeftChild;

        if (node == m_rootNode)
        {
            m_rootNode = nodeLeftChild;
        }

        node->m_m_height = CalculateNodeHeight(node) + 1;
        nodeLeftChild->m_m_height = CalculateNodeHeight(nodeLeftChild) + 1;
        if (nodeRightOfLeftChild)
        {
            nodeRightOfLeftChild->m_m_height = CalculateNodeHeight(nodeRightOfLeftChild) + 1;
        }

        return nodeLeftChild;
    }

    template <class T>
    AVLTree<T>::Node* AVLTree<T>::PerformLRRotation(Node* node)
    {
        Node* nodeLeftChild = node->m_m_leftChild;
        Node* nodeRightOfLeftChild = nodeLeftChild->m_m_rightChild;

        nodeLeftChild->m_m_rightChild = nodeRightOfLeftChild->m_m_leftChild;
        node->m_m_leftChild = nodeRightOfLeftChild->m_m_rightChild;

        nodeRightOfLeftChild->m_m_leftChild = nodeLeftChild;
        nodeRightOfLeftChild->m_m_rightChild = node;

        if (node == m_rootNode)
        {
            m_rootNode = nodeRightOfLeftChild;
        }

        node->m_m_height = CalculateNodeHeight(node) + 1;
        nodeLeftChild->m_m_height = CalculateNodeHeight(nodeLeftChild) + 1;
        if (nodeRightOfLeftChild)
        {
            nodeRightOfLeftChild->m_m_height = CalculateNodeHeight(nodeRightOfLeftChild) + 1;
        }
        return nodeRightOfLeftChild;
    }

    template <class T>
    AVLTree<T>::Node* AVLTree<T>::PerformRLRotation(Node* node)
    {
        Node* nodeRightChild = node->m_m_rightChild;
        Node* nodeLeftOfRightChild = nodeRightChild->m_m_leftChild;

        nodeRightChild->m_m_leftChild = nodeLeftOfRightChild->m_m_rightChild;
        node->m_m_rightChild = nodeLeftOfRightChild->m_m_leftChild;

        nodeLeftOfRightChild->m_m_leftChild = node;
        nodeLeftOfRightChild->m_m_rightChild = nodeRightChild;

        if (node == m_rootNode)
        {
            m_rootNode = nodeLeftOfRightChild;
        }

        node->m_m_height = CalculateNodeHeight(node) + 1;
        nodeRightChild->m_m_height = CalculateNodeHeight(nodeRightChild) + 1;
        if (nodeLeftOfRightChild)
        {
            nodeLeftOfRightChild->m_m_height = CalculateNodeHeight(nodeLeftOfRightChild) + 1;
        }

        return nodeLeftOfRightChild;
    }

    template <class T>
    AVLTree<T>::Node* AVLTree<T>::PerformRRRotation(Node* node)
    {
        Node* nodeRightChild = node->m_m_rightChild;
        Node* nodeLeftOfRightChild = nodeRightChild->m_m_leftChild;

        nodeRightChild->m_m_leftChild = node;
        node->m_m_rightChild = nodeLeftOfRightChild;

        if (node == m_rootNode)
        {
            m_rootNode = nodeRightChild;
        }

        node->m_m_height = CalculateNodeHeight(node) + 1;
        nodeRightChild->m_m_height = CalculateNodeHeight(nodeRightChild) + 1;
        if (nodeLeftOfRightChild)
        {
            nodeLeftOfRightChild->m_m_height = CalculateNodeHeight(nodeLeftOfRightChild) + 1;
        }

        return nodeRightChild;
    }

    template <class T>
    AVLTree<T>::Node* AVLTree<T>::InsertRecursive(Node* node, const T element)
    {
        if (node == nullptr)
        {
            Node* temp = new Node;
            temp->m_m_data = element;
            temp->m_m_leftChild = nullptr;
            temp->m_m_rightChild = nullptr;
            temp->m_m_height = 1;
            if (m_rootNode == nullptr)
            {
                m_rootNode = temp;
            }
            return temp;
        }
        if (element < node->m_m_data)
        {
            node->m_m_leftChild = InsertRecursive(node->m_m_leftChild, element);
        }
        else
        {
            node->m_m_rightChild = InsertRecursive(node->m_m_rightChild, element);
        }

        node->m_m_height = CalculateNodeHeight(node) + 1;
        if (CalculateBalanceFactor(node) == 2 and CalculateBalanceFactor(node->m_m_leftChild) == 1)
        {
            return PerformLLRotation(node);
        }
        else if (CalculateBalanceFactor(node) == 2 and CalculateBalanceFactor(node->m_m_leftChild) == -1)
        {
            return PerformLRRotation(node);
        }
        else if (CalculateBalanceFactor(node) == -2 and CalculateBalanceFactor(node->m_m_rightChild) == 1)
        {
            return PerformRLRotation(node);
        }
        else if (CalculateBalanceFactor(node) == -2 and CalculateBalanceFactor(node->m_m_rightChild) == -1)
        {
            return PerformRRRotation(node);
        }
        return node;
    }

    template <class T>
    const AVLTree<T>::Node* AVLTree<T>::SearchRecursive(const Node* node, const T element)
    {
        if (node == nullptr)
        {
            return nullptr;
        }

        if (element == node->m_m_data)
        {
            return node;
        }

        if (element < node->m_m_data)
        {
            return SearchRecursive(node->m_m_leftChild, element);
        }
        else
        {
            return SearchRecursive(node->m_m_rightChild, element);
        }
    }

    template <class T>
    AVLTree<T>::Node* AVLTree<T>::InOrderPredecessor(Node* node)
    {
        if (node and node->m_m_rightChild)
        {
            node = node->m_m_rightChild;
        }
        return node;
    }

    template <class T>
    AVLTree<T>::Node* AVLTree<T>::InOrderSuccessor(Node* node)
    {
        if (node and node->m_m_leftChild)
        {
            node = node->m_m_leftChild;
        }
        return node;
    }

    template <class T>
    int AVLTree<T>::GetDegOfNode(const Node* node)
    {
        if (node->m_m_leftChild and node->m_m_rightChild)
        {
            return 2;
        }
        else if ( (node->m_m_leftChild and not node->m_m_rightChild) or
                  (not node->m_m_leftChild and node->m_m_rightChild) )
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    template <class T>
    AVLTree<T>::Node* AVLTree<T>::DeleteRecursive(Node* node, const T element)
    {
        if (node == nullptr)
        {
            return nullptr;
        }

        if (GetDegOfNode(node) == 0)
        {
            if (node == m_rootNode)
            {
                m_rootNode = nullptr;
            }
            delete node;
            return nullptr;
        }

        if (element < node->m_m_data)
        {
            node->m_m_leftChild = DeleteRecursive(node->m_m_leftChild, element);
        }
        else if (element > node->m_m_data)
        {
            node->m_m_rightChild = DeleteRecursive(node->m_m_rightChild, element);
        }
        else
        {
            if (CalculateNodeHeight(node->m_m_leftChild) > CalculateNodeHeight(node->m_m_rightChild))
            {
                Node* inOrderPredecessorNode = InOrderPredecessor(node->m_m_leftChild);
                node->m_m_data = inOrderPredecessorNode->m_m_data;
                DeleteRecursive(node->m_m_leftChild, inOrderPredecessorNode->m_m_data);
            }
            else
            {
                Node* inOrderSuccessorNode = InOrderSuccessor(node->m_m_rightChild);
                node->m_m_data = inOrderSuccessorNode->m_m_data;
                DeleteRecursive(node->m_m_rightChild, inOrderSuccessorNode->m_m_data);
            }
        }

        node->m_m_height = CalculateNodeHeight(node) + 1;
        if (CalculateBalanceFactor(node) == 2 and CalculateBalanceFactor(node->m_m_leftChild) == 1)
        {
            // L1 rotation
            return PerformLLRotation(node);
        }
        else if (CalculateBalanceFactor(node) == 2 and CalculateBalanceFactor(node->m_m_leftChild) == -1)
        {
            // L-1 rotation
            return PerformLRRotation(node);
        }
        else if (CalculateBalanceFactor(node) == 2 and CalculateBalanceFactor(node->m_m_leftChild) == 0)
        {
            // L0 rotation
            return PerformLLRotation(node); // or can also perform LR rotation
        }
        else if (CalculateBalanceFactor(node) == -2 and CalculateBalanceFactor(node->m_m_leftChild) == 1)
        {
            // R1 rotation
            return PerformRRRotation(node);
        }
        else if (CalculateBalanceFactor(node) == -2 and CalculateBalanceFactor(node->m_m_leftChild) == -1)
        {
            // R-1 rotation
            return PerformRLRotation(node);
        }
        else if (CalculateBalanceFactor(node) == -2 and CalculateBalanceFactor(node->m_m_leftChild) == 0)
        {
            // R0 rotation
            return PerformRRRotation(node); // or can also perform RL rotation
        }
        return node;
    }

    template <class T>
    void AVLTree<T>::ResetTree(Node* node)
    {
        if (node)
        {
            Node* leftChild = node->m_m_leftChild;
            Node* rightChild = node->m_m_rightChild;
            if (node == m_rootNode)
            {
                m_rootNode = nullptr;
            }
            delete node;
            ResetTree(leftChild);
            ResetTree(rightChild);
        }
    }

    /******************************************
    *********** PRIVATE METHODS END ***********
    *******************************************/

    template <class T>
    AVLTree<T>::AVLTree():
        m_choice                  ( 0 ),
        m_avlTreeMenuMap ( {} )
    {
        m_avlTreeMenuMap.insert({ m_AVLTreeMenu(DOES_TREE_EXIST),
                                  std::string("Check if the tree exists") });
        m_avlTreeMenuMap.insert({ m_AVLTreeMenu(DISPLAY_PREORDER),
                                  std::string("Display Pre Order Traversal") });
        m_avlTreeMenuMap.insert({ m_AVLTreeMenu(DISPLAY_INORDER),
                                  std::string("Display In Order Traversal") });
        m_avlTreeMenuMap.insert({ m_AVLTreeMenu(DISPLAY_POSTORDER),
                                  std::string("Display Post Order Traversal") });
        m_avlTreeMenuMap.insert({ m_AVLTreeMenu(DISPLAY_LEVELORDER),
                                  std::string("Display Level Order Traversal") });
        m_avlTreeMenuMap.insert({ m_AVLTreeMenu(SEARCH_NODE_RECURSIVE),
                                  std::string("Search Node Recursive") });
        m_avlTreeMenuMap.insert({ m_AVLTreeMenu(INSERT_NODE_RECURSIVE),
                                  std::string("Insert Node Recursive") });
        m_avlTreeMenuMap.insert({ m_AVLTreeMenu(DELETE_NODE_RECURSIVE),
                                  std::string("Delete Node Recursive") });
        m_avlTreeMenuMap.insert({ m_AVLTreeMenu(RESET_TREE),
                                  std::string("Reset Tree") });
        m_avlTreeMenuMap.insert({ m_AVLTreeMenu(BACK_TO_PREVIOUS_MENU),
                                  std::string("Back to Previous Menu") });
        m_avlTreeMenuMap.insert({ m_AVLTreeMenu(EXIT_FROM_PROGRAM),
                                  std::string("Exit from program") });
    }

    template <class T>
    AVLTree<T>::~AVLTree()
    {
        ResetTree(m_rootNode);
    }
    
    template <class T>
    const int AVLTree<T>::GetMinCase()
    {
        return m_AVLTreeMenu::MIN_COUNT;
    }

    template <class T>
    const int AVLTree<T>::GetMaxCase()
    {
        return m_AVLTreeMenu::MAX_COUNT;
    }

    template <class T>
    const int& AVLTree<T>::GetChoice()
    {
        return m_choice;
    }

    template <class T>
    void AVLTree<T>::GetChoiceInputFromUser()
    {
        utils::InputNumberFromUser(m_choice, 1, static_cast<int>(m_AVLTreeMenu::MAX_COUNT));
    }

    template <class T>
    void AVLTree<T>::PrintMenu()
    {
        std::cout << std::endl;
        for (std::map<int, std::string>::iterator it = m_avlTreeMenuMap.begin();
            it != m_avlTreeMenuMap.end();
            it++)
        {
            std::cout << it->first << ". " << it->second << std::endl;
        }
        std::cout << "Please enter your choice: ";
    }

    template <class T>
    void AVLTree<T>::PrintSelectedChoice()
    {
        std::cout << std::endl << std::endl
                << "You have chosen choice "
                << m_avlTreeMenuMap.at(m_choice)
                << std::endl;
    }

    template <class T>
    bool AVLTree<T>::DoesTreeExist()
    {
        return m_rootNode ? true : false;
    }

    template <class T>
    void AVLTree<T>::DisplayPreOrder()
    {
        if (not DoesTreeExist())
        {
            std::cout << "The tree does not exist" << std::endl;
        }
        else
        {
            DisplayPreOrder(m_rootNode);
        }
    }

    template <class T>
    void AVLTree<T>::DisplayInOrder()
    {
        if (not DoesTreeExist())
        {
            std::cout << "The tree does not exist" << std::endl;
        }
        else
        {
            DisplayInOrder(m_rootNode);
        }
    }

    template <class T>
    void AVLTree<T>::DisplayPostOrder()
    {
        if (not DoesTreeExist())
        {
            std::cout << "The tree does not exist" << std::endl;
        }
        else
        {
            DisplayPostOrder(m_rootNode);
        }
    }

    template <class T>
    void AVLTree<T>::DisplayLevelOrder()
    {
        if (not DoesTreeExist())
        {
            std::cout << "The tree does not exist" << std::endl;
        }
        else
        {
            DisplayLevelOrder(m_rootNode);
        }
    }

    template <class T>
    bool AVLTree<T>::SearchRecursive(const T element)
    {
        return SearchRecursive(m_rootNode, element) ? true : false;
    }

    template <class T>
    bool AVLTree<T>::InsertRecursive(const T element)
    {
        if (SearchRecursive(element))
        {
            std::cout << "Cannot insert as same element present in the tree" << std::endl;
            return false;
        }
        return InsertRecursive(m_rootNode, element) ? true : false;
    }

    template <class T>
    bool AVLTree<T>::DeleteRecursive(const T element)
    {
        if (not SearchRecursive(element))
        {
            std::cout << "The element to be deleted is not present in the tree" << std::endl;
            return false;
        }
        return DeleteRecursive(m_rootNode, element) ? true : false;
    }

    template <class T>
    void AVLTree<T>::ResetTree()
    {
        ResetTree(m_rootNode);
    }
} //namespace tree
