#pragma once

#include <map>
#include <string>
#include <optional>
#include <iostream>
#include <stack>
#include <queue>
#include <vector>

namespace tree
{
    template <class T>
    class BinaryTree
    {
    private:
        class Node
        {
        public:
            Node* m_m_leftChild  = { nullptr };
            T     m_m_data;
            Node* m_m_rightChild = { nullptr };
        };
        Node*          m_rootNode               { nullptr };
        std::vector<T> m_inOrderTraversalVector {};

        void      DisplayPreOrderRecursive(const Node*);
        void      DisplayInOrderRecursive(const Node*);
        void      DisplayPostOrderRecursive(const Node*);
        void      DisplayLevelOrderRecursive(const Node*);
        int       CalculateDeg0NodesOfTree(const Node*);
        int       CalculateDeg1NodesOfTree(const Node*);
        int       CalculateDeg2NodesOfTree(const Node*);
        int       CalculateInternalNodesOfTree(const Node*);
        int       CalculateExternalNodesOfTree(const Node*);
        int       CalculateNoNodesOfTree(const Node*);
        int       CalculateHeightOfTree(const Node*);
        void      ResetTree(const Node*);
        void      FillInOrderTraversalVector(const Node*);
        Node*     SearchNodeRecursive(const Node*, const T);
    public:
        BinaryTree();
        ~BinaryTree();
        bool           IsExisting();
        void           DisplayPreOrderRecursive();
        void           DisplayInOrderRecursive();
        void           DisplayPostOrderRecursive();
        void           DisplayLevelOrderRecursive();
        void           DisplayPreOrderIterative();
        void           DisplayInOrderIterative();
        void           DisplayPostOrderIterative();
        void           DisplayLevelOrderIterative();
        int            GetNoDeg0Nodes();
        int            GetNoDeg1Nodes();
        int            GetNoDeg2Nodes();
        int            GetNoInternalNodes();
        int            GetNoExternalNodes();
        int            GetTotalNoNodes();
        int            GetHeightOfTree();
        void           GenerateTree();
        void           ResetTree();
        std::vector<T> GetInOrderTraversal();
    };

    template <class T>
    class BinarySearchTree
    {
    private:
        enum m_BinarySearchTreeMenu
        {
            MIN_COUNT                        = 0,
            DOES_TREE_EXIST                  = 1,
            GENERATE_TREE                    = 2,
            DISPLAY_PREORDER                 = 3,
            DISPLAY_INORDER                  = 4,
            DISPLAY_POSTORDER                = 5,
            DISPLAY_LEVELORDER               = 6,
            SEARCH_NODE_RECURSIVE            = 7,
            SEARCH_NODE_ITERATIVE            = 8,
            INSERT_NODE_RECURSIVE            = 9,
            INSERT_NODE_ITERATIVE            = 10,
            DELETE_NODE_RECURSIVE            = 11,
            DELETE_NODE_ITERATIVE            = 12,
            RESET_TREE                       = 13,
            BACK_TO_PREVIOUS_MENU            = 14,
            EXIT_FROM_PROGRAM                = 15,
            MAX_COUNT                        = EXIT_FROM_PROGRAM
        };
        int                        m_choice                  { 0 };
        std::map<int, std::string> m_binarySearchTreeMenuMap {};
        BinaryTree<T>              m_binaryTree              {};
        bool                       IsBST();
        bool                       IsSortedAndUnique(const std::vector<T>);
        void                       SearchNodeRecursive(const Node*, const T);
    public:
        BinarySearchTree();
        ~BinarySearchTree();
        const int        GetMinCase();
        const int        GetMaxCase();
        const int&       GetChoice();
        void             GetChoiceInputFromUser();
        void	         PrintMenu();
        void             PrintSelectedChoice();
        bool             DoesTreeExist();
        void             GenerateTree();
        void             DisplayPreOrder();
        void             DisplayInOrder();
        void             DisplayPostOrder();
        void             DisplayLevelOrder();

        
        void             SearchNodeIterative(const T);
        void             InsertNodeRecursive(const T);
        void             InsertNodeIterative(const T);
        void             DeleteNodeRecursive(const T);
        void             DeleteNodeIterative(const T);
        void             ResetTree();
    };
} // namespace tree

# include "BinarySearchTree.tpp"
x