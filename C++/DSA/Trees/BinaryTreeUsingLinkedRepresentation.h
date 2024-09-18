#pragma once

#include <map>
#include <string>
#include <optional>
#include <iostream>
#include "../Queues/QueueUsingLinkedList.h"

namespace tree
{
    template <class T>
    class BinaryTreeUsingLinkedRepresentation
    {
    private:
        enum m_BinaryTreeUsingLinkedRepresentationMenu
        {
            MIN_COUNT                    = 0,
            DOES_TREE_EXIST              = 1,
            DISPLAY_PREORDER_RECURSIVE   = 2,
            DISPLAY_INORDER_RECURSIVE    = 3,
            DISPLAY_POSTORDER_RECURSIVE  = 4,
            DISPLAY_LEVELORDER_RECURSIVE = 5,
            GENERATE_TREE                = 6,
            RESET_TREE                   = 7,
            BACK_TO_PREVIOUS_MENU        = 8,
            EXIT_FROM_PROGRAM            = 9,
            MAX_COUNT                    = EXIT_FROM_PROGRAM
        };

        class Node
        {
        public:
            Node* m_m_leftChild = { nullptr };
            T     m_m_data;
            Node* m_m_rightChild = { nullptr };
        };
        int                        m_choice                                     { 0 };
        std::map<int, std::string> m_binaryTreeUsingLinkedRepresentationMenuMap {};
        Node*                      m_rootNode                                   {};
    public:
        BinaryTreeUsingLinkedRepresentation();
        ~BinaryTreeUsingLinkedRepresentation();
        const int        GetMinCase();
        const int        GetMaxCase();
        const int&       GetChoice();
        void             GetChoiceInputFromUser();
        void	         PrintMenu();
        void             PrintSelectedChoice();
        const Node*      GetRootNode();
        bool             IsExisting();
        void             DisplayPreOrderRecursive(const Node*);
        void             DisplayInOrderRecursive(const Node*);
        void             DisplayPostOrderRecursive(const Node*);
        void             DisplayLevelOrderRecursive(const Node*);
        void             GenerateTree();
        void             ResetTree(const Node*);
    };
} // namespace tree

# include "BinaryTreeUsingLinkedRepresentation.tpp"
