#pragma once

#include <map>
#include <string>
#include <iostream>
#include <optional>

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
            SEARCH_NODE                      = 6,
            INSERT_NODE                      = 7,
            DELETE_NODE                      = 8,
            RESET_TREE                       = 9,
            BACK_TO_PREVIOUS_MENU            = 10,
            EXIT_FROM_PROGRAM                = 11,
            MAX_COUNT                        = EXIT_FROM_PROGRAM
        };

        class Node
        {
        public:
            Node* m_m_leftChild = nullptr;
            T     m_m_data;
            Node* m_m_rightChild = nullptr;
            int   m_m_balanceFactor = 0;
        };
        std::map<int, std::string> m_avlTreeMenuMap {};
        Node*                      m_rootNode { nullptr };
    public:
        AVLTree();
        ~AVLTree();
        const int        GetMinCase();
        const int        GetMaxCase();
        const int&       GetChoice();
        void             GetChoiceInputFromUser();
        void             PrintMenu();
        void             PrintSelectedChoice();
        bool             DoesTreeExist();
        void             DisplayPreOrder();
        void             DisplayInOrder();
        void             DisplayPostOrder();
        void             DisplayLevelOrder();
        std::optional<T> SearchNode(const& T);
        bool             InsertNode(const& T);
        std::optional<T> DeleteNode(const& T);
} // namespace tree

# include "BinarySearchTree.tpp"
