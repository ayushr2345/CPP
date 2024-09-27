#pragma once

#include "BinarySearchTree.h"
#include "../../utils.h"

namespace tree
{

    template <class T>
    BinaryTree<T>::BinaryTree():
        m_rootNode               { nullptr },
        m_inOrderTraversalVector {}
    {
    }

    template <class T>
    BinaryTree<T>::~BinaryTree()
    {
        ResetTree();
    }

    template <class T>
    bool BinaryTree<T>::IsExisting()
    {
        return m_rootNode ? true : false;
    }

    // private methods
    template <class T>
    void BinaryTree<T>::DisplayPreOrderRecursive(const Node* node)
    {
        if (node)
        {
            std::cout << node->m_m_data << " ";
            DisplayPreOrderRecursive(node->m_m_leftChild);
            DisplayPreOrderRecursive(node->m_m_rightChild);
        }
    }

    template <class T>
    void BinaryTree<T>::DisplayInOrderRecursive(const Node* node)
    {
        if (node)
        {
            DisplayInOrderRecursive(node->m_m_leftChild);
            std::cout << node->m_m_data << " ";
            DisplayInOrderRecursive(node->m_m_rightChild);
        }
    }

    template <class T>
    void BinaryTree<T>::DisplayPostOrderRecursive(const Node* node)
    {
        if (node)
        {
            DisplayPostOrderRecursive(node->m_m_leftChild);
            DisplayPostOrderRecursive(node->m_m_rightChild);
            std::cout << node->m_m_data << " ";
        }
    }

    template <class T>
    void BinaryTree<T>::DisplayLevelOrderRecursive(const Node* node)
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
    int BinaryTree<T>::CalculateDeg0NodesOfTree(const Node* node)
    {
        if (node)
        {
            int x = CalculateDeg0NodesOfTree(node->m_m_leftChild);
            int y = CalculateDeg0NodesOfTree(node->m_m_rightChild);
            if (not node->m_m_leftChild and not node->m_m_rightChild)
            {
                return x + y + 1;
            }
            return x + y;
        }
        return 0;
    }
    
    template <class T>
    int BinaryTree<T>::CalculateDeg1NodesOfTree(const Node* node)
    {
        if (node)
        {
            int x = CalculateDeg1NodesOfTree(node->m_m_leftChild);
            int y = CalculateDeg1NodesOfTree(node->m_m_rightChild);
            if ((not node->m_m_leftChild and node->m_m_rightChild) or
                (node->m_m_leftChild and not node->m_m_rightChild))
            {
                return x + y + 1;
            }
            return x + y;
        }
        return 0;
    }
    
    template <class T>
    int BinaryTree<T>::CalculateDeg2NodesOfTree(const Node* node)
    {
        if (node)
        {
            int x = CalculateDeg2NodesOfTree(node->m_m_leftChild);
            int y = CalculateDeg2NodesOfTree(node->m_m_rightChild);
            if (node->m_m_leftChild and node->m_m_rightChild)
            {
                return x + y + 1;
            }
            return x + y;
        }
        return 0;
    }
    
    template <class T>
    int BinaryTree<T>::CalculateInternalNodesOfTree(const Node* node)
    {
        if (node)
        {
            int x = CalculateInternalNodesOfTree(node->m_m_leftChild);
            int y = CalculateInternalNodesOfTree(node->m_m_rightChild);
            if (node->m_m_leftChild or node->m_m_rightChild)
            {
                return x + y + 1;
            }
            return x + y;
        }
        return 0;
    }
    
    template <class T>
    int BinaryTree<T>::CalculateExternalNodesOfTree(const Node* node)
    {
        if (node)
        {
            int x = CalculateExternalNodesOfTree(node->m_m_leftChild);
            int y = CalculateExternalNodesOfTree(node->m_m_rightChild);
            if (not node->m_m_leftChild and not node->m_m_rightChild)
            {
                return x + y + 1;
            }
            return x + y;
        }
        return 0;
    }
    
    template <class T>
    int BinaryTree<T>::CalculateNoNodesOfTree(const Node* node)
    {
        if (node)
        {
            int x = CalculateNoNodesOfTree(node->m_m_leftChild);
            int y = CalculateNoNodesOfTree(node->m_m_rightChild);
            return x + y + 1;
        }
        return 0;
    }
    
    template <class T>
    int BinaryTree<T>::CalculateHeightOfTree(const Node* node)
    {
        if (node)
        {
            int x = CalculateHeightOfTree(node->m_m_leftChild);
            int y = CalculateHeightOfTree(node->m_m_rightChild);
            if (x > y)
            {
                return x + 1;
            }
            else
            {
                return y + 1;
            }
        }
        return -1;
    }

    template <class T>
    void BinaryTree<T>::ResetTree(const Node* node)
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

    template <class T>
    BinaryTree<T>::Node* BinaryTree<T>::SearchNodeRecursive(const Node* temp, const T element)
    {
        if (temp == nullptr)
        {
            return nullptr;
        }
        if (temp->m_m_data == element)
        {
            return const_cast<BinaryTree<T>::Node*>(temp);
        }

        if (element > temp->m_m_data)
        {
            return SearchNodeRecursive(temp->m_m_rightChild, element);
        }
        else
        {
            return SearchNodeRecursive(temp->m_m_leftChild, element);
        }
    }

    template <class T>
    BinaryTree<T>::Node* BinaryTree<T>::InsertNodeRecursive(Node* temp, const T element)
    {
        if (temp == nullptr)
        {
            Node* newNode = new Node;
            newNode->m_m_data = element;
            newNode->m_m_leftChild = nullptr;
            newNode->m_m_rightChild = nullptr;
            return newNode;
        }
        else if (element > temp->m_m_data)
        {
            temp->m_m_rightChild = InsertNodeRecursive(temp->m_m_rightChild, element);
        }
        else
        {
            temp->m_m_leftChild = InsertNodeRecursive(temp->m_m_leftChild, element);
        }
        return temp;
    }

    template <class T>
    int BinaryTree<T>::GetDegOfNode(const Node* temp)
    {
        if (not temp)
        {
            return -1;
        }
        if(temp->m_m_leftChild and temp->m_m_rightChild)
        {
            return 2;
        }

        if ((temp->m_m_leftChild and not temp->m_m_rightChild) or
            (temp->m_m_rightChild and not temp->m_m_leftChild))
        {
            return 1;
        }

        return 0;
    }

    template <class T>
    BinaryTree<T>::Node* BinaryTree<T>::InOrderPredecessor(Node* temp)
    {
        while (temp and temp->m_m_rightChild)
        {
            temp = temp->m_m_rightChild;
        }
        return temp;
    }
    
    template <class T>
    BinaryTree<T>::Node* BinaryTree<T>::InOrderSuccessor(Node* temp)
    {
        while (temp and temp->m_m_leftChild)
        {
            temp = temp->m_m_leftChild;
        }
        return temp;
    }

    template <class T>
    BinaryTree<T>::Node* BinaryTree<T>::DeleteNodeRecursive(Node* temp, const T element)
    {
        if (temp == nullptr)
        {
            return nullptr;
        }

        if (GetDegOfNode(temp) == 0)
        {
            if (temp == m_rootNode)
            {
                m_rootNode = nullptr;
            }
            delete temp;
            return nullptr;
        }

        if (element > temp->m_m_data)
        {
            temp->m_m_rightChild = DeleteNodeRecursive(temp->m_m_rightChild, element);
        }
        else if (element < temp->m_m_data)
        {
            temp->m_m_leftChild = DeleteNodeRecursive(temp->m_m_leftChild, element);
        }
        else
        {
            FillInOrderTraversalVector(m_rootNode);
            if (CalculateHeightOfTree(temp->m_m_leftChild) > CalculateHeightOfTree(temp->m_m_rightChild))
            {
                Node* inOrderPredecessorNode = InOrderPredecessor(temp->m_m_leftChild);
                temp->m_m_data = inOrderPredecessorNode->m_m_data; 
                temp->m_m_leftChild = DeleteNodeRecursive(temp->m_m_leftChild, inOrderPredecessorNode->m_m_data);
            }
            else
            {
                Node* inOrderSuccessorNode = InOrderSuccessor(temp->m_m_rightChild);
                temp->m_m_data = inOrderSuccessorNode->m_m_data; 
                temp->m_m_rightChild = DeleteNodeRecursive(temp->m_m_rightChild, inOrderSuccessorNode->m_m_data);
            }
        }
        return temp;
    }
    // private methods end

    template <class T>
    void BinaryTree<T>::DisplayPreOrderRecursive()
    {
        DisplayPreOrderRecursive(m_rootNode);
    }

    template <class T>
    void BinaryTree<T>::DisplayInOrderRecursive()
    {
        DisplayInOrderRecursive(m_rootNode);
    }

    template <class T>
    void BinaryTree<T>::DisplayPostOrderRecursive()
    {
        DisplayPostOrderRecursive(m_rootNode);
    }

    template <class T>
    void BinaryTree<T>::DisplayLevelOrderRecursive()
    {
        DisplayLevelOrderRecursive(m_rootNode);
    }

    template <class T>
    void BinaryTree<T>::DisplayPreOrderIterative()
    {
        std::stack<Node*> treeStack;

        Node* temp = m_rootNode;
        while (temp or treeStack.size())
        {
            if (temp)
            {
                std::cout << temp->m_m_data << " ";
                treeStack.push(temp);
                temp = temp->m_m_leftChild;
            }
            else
            {
                Node* poppedValue = treeStack.pop();
                temp = poppedValue->m_m_rightChild;
            }
        }
    }

    template <class T>
    void BinaryTree<T>::DisplayInOrderIterative()
    {
        std::stack<Node*> treeStack;

        Node* temp = m_rootNode;
        while (temp or treeStack.size())
        {
            if (temp)
            {
                treeStack.push(temp);
                temp = temp->m_m_leftChild;
            }
            else
            {
                Node* poppedValue = treeStack.pop();
                std::cout << temp->m_m_data << " ";
                temp = poppedValue->m_m_rightChild;
            }
        }
    }

    template <class T>
    void BinaryTree<T>::DisplayPostOrderIterative()
    {
        std::stack<Node*> treeStack;

        Node* temp = m_rootNode;
        while (temp or treeStack.size())
        {
            if (temp)
            {
                treeStack.push(temp);
                temp = temp->m_m_leftChild;
            }
            else
            {
                Node* poppedValue = treeStack.pop();
                if (poppedValue < 0)
                {
                    poppedValue = -1 * poppedValue;
                    std::cout << poppedValue->m_m_data << " ";
                }
                else
                {
                    treeStack.push(-temp);
                    temp = poppedValue->m_m_rightChild;
                }
            }
        }
    }

    template <class T>
    void BinaryTree<T>::DisplayLevelOrderIterative()
    {
        std::queue<Node*> treeQueue;

        Node* temp = m_rootNode;
        treeQueue.push(temp);
        std::cout << temp->m_m_data << " ";
        while (treeQueue.size())
        {
            temp = treeQueue.pop();
            if (temp->m_m_leftChild)
            {
                std::cout << temp->m_m_leftChild->m_m_data << " ";
                treeQueue.push(temp->m_m_leftChild);
            }
            else
            {
                std::cout << temp->m_m_rightChild->m_m_data << " ";
                treeQueue.push(temp->m_m_rightChild);
            }
        }
    }

    template <class T>
    int  BinaryTree<T>::GetNoDeg0Nodes()
    {
        return CalculateDeg0NodesOfTree(m_rootNode);
    }

    template <class T>
    int  BinaryTree<T>::GetNoDeg1Nodes()
    {
        return CalculateDeg1NodesOfTree(m_rootNode);
    }

    template <class T>
    int  BinaryTree<T>::GetNoDeg2Nodes()
    {
        return CalculateDeg2NodesOfTree(m_rootNode);
    }

    template <class T>
    int  BinaryTree<T>::GetNoInternalNodes()
    {
        return CalculateInternalNodesOfTree(m_rootNode);
    }

    template <class T>
    int  BinaryTree<T>::GetNoExternalNodes()
    {
        return CalculateExternalNodesOfTree(m_rootNode);
    }

    template <class T>
    int  BinaryTree<T>::GetTotalNoNodes()
    {
        return CalculateNoNodesOfTree(m_rootNode);
    }

    template <class T>
    int  BinaryTree<T>::GetHeightOfTree()
    {
        return CalculateHeightOfTree(m_rootNode);
    }

    template <class T>
    void BinaryTree<T>::GenerateTree()
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
    void BinaryTree<T>::ResetTree()
    {
        ResetTree(m_rootNode);
    }

    template <class T>
    void BinaryTree<T>::FillInOrderTraversalVector(const Node* node)
    {
        if (node)
        {
            FillInOrderTraversalVector(node->m_m_leftChild);
            m_inOrderTraversalVector.push_back(node->m_m_data);
            FillInOrderTraversalVector(node->m_m_rightChild);
        }
    }

    template <class T>
    std::vector<T> BinaryTree<T>::GetInOrderTraversal()
    {
        m_inOrderTraversalVector.clear();
        FillInOrderTraversalVector(m_rootNode);
        return m_inOrderTraversalVector; 
    }

    template <class T>
    BinaryTree<T>::Node* BinaryTree<T>::SearchNodeRecursive(const T element)
    {
        return SearchNodeRecursive(m_rootNode, element);
    }

    template <class T>
    BinaryTree<T>::Node* BinaryTree<T>::SearchNodeIterative(const T element)
    {
        Node* temp = m_rootNode;
        while (temp)
        {
            if (temp->m_m_data == element)
            {
                return temp;
            }
            else if (temp->m_m_data < element)
            {
                temp = temp->m_m_rightChild;
            }
            else
            {
                temp = temp->m_m_leftChild;
            }
        }
        return nullptr;
    }

    template <class T>
    bool BinaryTree<T>::InsertNodeRecursive(const T element)
    {
        Node* searchRes = SearchNodeRecursive(element);

        if (searchRes)
        {
            return false;
        }
        InsertNodeRecursive(m_rootNode, element);
        return true;
    }

    template <class T>
    bool BinaryTree<T>::InsertNodeIterative(const T element)
    {
        Node* searchRes = SearchNodeIterative(element);

        if (searchRes)
        {
            return false;
        }
        
        Node* prevTemp = nullptr;
        Node* temp = m_rootNode;

        while (temp)
        {
            prevTemp = temp;
            if (element > temp->m_m_data)
            {
                temp = temp->m_m_rightChild;
            }
            else
            {
                temp = temp->m_m_leftChild;
            }
        }

        Node* newNode = new Node;
        newNode->m_m_data = element;
        newNode->m_m_leftChild = nullptr;
        newNode->m_m_rightChild = nullptr;

        if (newNode->m_m_data > prevTemp->m_m_data)
        {
            prevTemp->m_m_rightChild = newNode;
        }
        else
        {
            prevTemp->m_m_leftChild = newNode;
        }
        return true;
    }

    template <class T>
    bool BinaryTree<T>::DeleteNodeRecursive(const T element)
    {
        Node* searchRes = SearchNodeRecursive(element);
        if (not searchRes)
        {
            return false;
        }
        DeleteNodeRecursive(m_rootNode, element);
        return true;
    }

    template <class T>
    void BinaryTree<T>::GenerateTreeFromPreOrder(const std::vector<T>& preOrder)
    {
        if (IsExisting())
        {
            std::cout << "The tree already exists, resetting the tree" << std::endl;
            ResetTree(m_rootNode);
        }

        m_rootNode = new Node;
        m_rootNode->m_m_data = preOrder[0];
        m_rootNode->m_m_leftChild = nullptr;
        m_rootNode->m_m_rightChild = nullptr;

        Node* temp = m_rootNode;
        int i = 1;
        int numNodes = preOrder.size();

        std::stack<Node*> treeStack;
        treeStack.push(m_rootNode);

        while (i < numNodes)
        {
            Node* newNode = new Node;
            newNode->m_m_data = preOrder[i];
            newNode->m_m_leftChild = nullptr;
            newNode->m_m_rightChild = nullptr;

            if (preOrder[i] < temp->m_m_data)
            {
                // Add as left child
                temp->m_m_leftChild = newNode;
                treeStack.push(temp);  // Push current node before descending
                temp = temp->m_m_leftChild;
            }
            else
            {
                // Pop nodes from the stack until we find the correct parent
                while (!treeStack.empty() && preOrder[i] > treeStack.top()->m_m_data)
                {
                    temp = treeStack.top();
                    treeStack.pop();
                }

                // Add as right child
                temp->m_m_rightChild = newNode;
                temp = temp->m_m_rightChild;
            }
            i++;
        }
    }

    //
    //   BINARY SEARCH TREE
    //

    template <class T>
    BinarySearchTree<T>::BinarySearchTree():
        m_choice                  ( 0 ),
        m_binarySearchTreeMenuMap ( {} )
    {
        m_binarySearchTreeMenuMap.insert({ m_BinarySearchTreeMenu(DOES_TREE_EXIST),
                                           std::string("Check if the tree exists") });
        m_binarySearchTreeMenuMap.insert({ m_BinarySearchTreeMenu(GENERATE_TREE),
                                           std::string("Generate Tree") });
        m_binarySearchTreeMenuMap.insert({ m_BinarySearchTreeMenu(DISPLAY_PREORDER),
                                           std::string("Display Pre Order Traversal") });
        m_binarySearchTreeMenuMap.insert({ m_BinarySearchTreeMenu(DISPLAY_INORDER),
                                           std::string("Display In Order Traversal") });
        m_binarySearchTreeMenuMap.insert({ m_BinarySearchTreeMenu(DISPLAY_POSTORDER),
                                           std::string("Display Post Order Traversal") });
        m_binarySearchTreeMenuMap.insert({ m_BinarySearchTreeMenu(DISPLAY_LEVELORDER),
                                           std::string("Display Level Order Traversal") });
        m_binarySearchTreeMenuMap.insert({ m_BinarySearchTreeMenu(SEARCH_NODE_RECURSIVE),
                                           std::string("Search Node Recursive") });
        m_binarySearchTreeMenuMap.insert({ m_BinarySearchTreeMenu(SEARCH_NODE_ITERATIVE),
                                           std::string("Search Node Iterative") });
        m_binarySearchTreeMenuMap.insert({ m_BinarySearchTreeMenu(INSERT_NODE_RECURSIVE),
                                           std::string("Insert Node Recursive") });
        m_binarySearchTreeMenuMap.insert({ m_BinarySearchTreeMenu(INSERT_NODE_ITERATIVE),
                                           std::string("Insert Node Iterative") });
        m_binarySearchTreeMenuMap.insert({ m_BinarySearchTreeMenu(DELETE_NODE_RECURSIVE),
                                           std::string("Delete Node Recursive") });
        m_binarySearchTreeMenuMap.insert({ m_BinarySearchTreeMenu(GENERATE_TREE_FROM_PREORDER),
                                           std::string("Generate Tree From Preorder Traversal") });
        m_binarySearchTreeMenuMap.insert({ m_BinarySearchTreeMenu(RESET_TREE),
                                           std::string("Reset Tree") });
        m_binarySearchTreeMenuMap.insert({ m_BinarySearchTreeMenu(BACK_TO_PREVIOUS_MENU),
                                           std::string("Back to Previous Menu") });
        m_binarySearchTreeMenuMap.insert({ m_BinarySearchTreeMenu(EXIT_FROM_PROGRAM),
                                           std::string("Exit from program") });
    }

    template <class T>
    BinarySearchTree<T>::~BinarySearchTree()
    {
        m_binaryTree.ResetTree();
    }

    template <class T>
    bool BinarySearchTree<T>::IsSortedAndUnique(const std::vector<T> inOrderTraversalVector)
    {
        int vectorSize = inOrderTraversalVector.size();
        for (int i = 0; i < vectorSize - 1; i++)
        {
            if (inOrderTraversalVector[i] >= inOrderTraversalVector[i + 1])
            {
                return false;
            }
        }
        return true;
    }

    template <class T>
    bool BinarySearchTree<T>::IsBST()
    {
        std::vector<T> inOrderTraversalVector = m_binaryTree.GetInOrderTraversal();
        return IsSortedAndUnique(inOrderTraversalVector);
    }
    
    template <class T>
    const int BinarySearchTree<T>::GetMinCase()
    {
        return m_BinarySearchTreeMenu::MIN_COUNT;
    }

    template <class T>
    const int BinarySearchTree<T>::GetMaxCase()
    {
        return m_BinarySearchTreeMenu::MAX_COUNT;
    }

    template <class T>
    const int& BinarySearchTree<T>::GetChoice()
    {
        return m_choice;
    }

    template <class T>
    void BinarySearchTree<T>::GetChoiceInputFromUser()
    {
        utils::InputNumberFromUser(m_choice, 1, static_cast<int>(m_BinarySearchTreeMenu::MAX_COUNT));
    }

    template <class T>
    void BinarySearchTree<T>::PrintMenu()
    {
        std::cout << std::endl;
        for (std::map<int, std::string>::iterator it = m_binarySearchTreeMenuMap.begin();
            it != m_binarySearchTreeMenuMap.end();
            it++)
        {
            std::cout << it->first << ". " << it->second << std::endl;
        }
        std::cout << "Please enter your choice: ";
    }

    template <class T>
    void BinarySearchTree<T>::PrintSelectedChoice()
    {
        std::cout << std::endl << std::endl
                << "You have chosen choice "
                << m_binarySearchTreeMenuMap.at(m_choice)
                << std::endl;
    }

    template <class T>
    bool BinarySearchTree<T>::DoesTreeExist()
    {
        return m_binaryTree.IsExisting();
    }
    
    template <class T>
    void BinarySearchTree<T>::GenerateTree()
    {
        m_binaryTree.GenerateTree();
        bool isBst = IsBST();
        if (not isBst)
        {
            std::cout << "The entered tree is not a BST. Resetting the tree" << std::endl;
            m_binaryTree.DisplayInOrderRecursive();
            ResetTree();
        }
    }
    
    template <class T>
    void BinarySearchTree<T>::DisplayPreOrder()
    {
        if (not DoesTreeExist())
        {
            std::cout << "The tree does not exist" << std::endl;
        }
        else
        {
            m_binaryTree.DisplayPreOrderRecursive();
        }
    }
    
    template <class T>
    void BinarySearchTree<T>::DisplayInOrder()
    {
        if (not DoesTreeExist())
        {
            std::cout << "The tree does not exist" << std::endl;
        }
        else
        {
            m_binaryTree.DisplayInOrderRecursive();
        }
    }
    
    template <class T>
    void BinarySearchTree<T>::DisplayPostOrder()
    {
        if (not DoesTreeExist())
        {
            std::cout << "The tree does not exist" << std::endl;
        }
        else
        {
            m_binaryTree.DisplayPostOrderRecursive();
        }
    }
    
    template <class T>
    void BinarySearchTree<T>::DisplayLevelOrder()
    {
        if (not DoesTreeExist())
        {
            std::cout << "The tree does not exist" << std::endl;
        }
        else
        {
            m_binaryTree.DisplayLevelOrderRecursive();
        }
    }

    template <class T>
    bool BinarySearchTree<T>::InsertRecursive(const T element)
    {
        return m_binaryTree.InsertNodeRecursive(element);
    }

    template <class T>
    bool BinarySearchTree<T>::InsertIterative(const T element)
    {
        return m_binaryTree.InsertNodeIterative(element);
    }

    template <class T>
    bool BinarySearchTree<T>::SearchRecursive(const T element)
    {
        return m_binaryTree.SearchNodeRecursive(element);
    }

    template <class T>
    bool BinarySearchTree<T>::SearchIterative(const T element)
    {
        return m_binaryTree.SearchNodeIterative(element);
    }

    template <class T>
    bool BinarySearchTree<T>::DeleteRecursive(const T element)
    {
        return m_binaryTree.DeleteNodeRecursive(element);
    }

    template <class T>
    void BinarySearchTree<T>::GenerateTreeFromPreOrder(const std::vector<T>& preOrder)
    {
        return m_binaryTree.GenerateTreeFromPreOrder(preOrder);
    }

    template <class T>
    void BinarySearchTree<T>::ResetTree()
    {
        m_binaryTree.ResetTree();
    }
} //namespace tree
