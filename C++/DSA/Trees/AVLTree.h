#pragma once

#include <map>
#include <string>
#include <iostream>
#include <vector>

namespace tree
{
    template <class T>
    class AVLTree
    {
    private:
        enum m_AVLTreeMenu
        {
            MIN_COUNT                        = 0,
            DOES_TREE_EXIST                  = 1,
            DISPLAY_PREORDER                 = 2,
            DISPLAY_INORDER                  = 3,
            DISPLAY_POSTORDER                = 4,
            DISPLAY_LEVELORDER               = 5,
            SEARCH_NODE_RECURSIVE            = 6,
            INSERT_NODE_RECURSIVE            = 7,
            DELETE_NODE_RECURSIVE            = 8,
            RESET_TREE                       = 9,
            BACK_TO_PREVIOUS_MENU            = 10,
            EXIT_FROM_PROGRAM                = 11,
            MAX_COUNT                        = EXIT_FROM_PROGRAM
        };

        class Node
        {
        public:
            Node* m_m_leftChild  = { nullptr };
            T     m_m_data       = {};
            int   m_m_height     = 0;
            Node* m_m_rightChild = { nullptr };
        };

        int                        m_choice         { 0 };
        std::map<int, std::string> m_avlTreeMenuMap {};
        Node*                      m_rootNode       { nullptr };
        void                       DisplayPreOrder(const Node*);
        void                       DisplayInOrder(const Node*);
        void                       DisplayPostOrder(const Node*);
        void                       DisplayLevelOrder(const Node*);
        int                        CalculateNodeHeight(const Node*);
        int                        CalculateBalanceFactor(const Node*);
        Node*                      PerformLLRotation(Node*);
        Node*                      PerformLRRotation(Node*);
        Node*                      PerformRLRotation(Node*);
        Node*                      PerformRRRotation(Node*);
        Node*                      InsertRecursive(Node*, const T);
        const Node*                SearchRecursive(const Node*, const T);
        Node*                      InOrderPredecessor(Node*);
        Node*                      InOrderSuccessor(Node*);
        int                        GetDegOfNode(const Node*);
        Node*                      DeleteRecursive(Node*, const T);
        bool                       IsAVLTree();
        bool                       IsSortedAndUnique(const std::vector<T>);
        void                       ResetTree(Node*);
    public:
        AVLTree();
        ~AVLTree();
        const int        GetMinCase();
        const int        GetMaxCase();
        const int&       GetChoice();
        void             GetChoiceInputFromUser();
        void	         PrintMenu();
        void             PrintSelectedChoice();
        bool             DoesTreeExist();
        void             DisplayPreOrder();
        void             DisplayInOrder();
        void             DisplayPostOrder();
        void             DisplayLevelOrder();
        bool             SearchRecursive(const T);
        bool             InsertRecursive(const T);
        bool             DeleteRecursive(const T);
        void             ResetTree();
    };
} // namespace tree

# include "AVLTree.tpp"