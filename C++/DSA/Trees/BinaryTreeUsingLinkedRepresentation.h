#pragma once

#include <cstdint>
#include <map>
#include <string>
#include <optional>
#include <iostream>
#include "../Queues/QueueUsingLinkedList.h"
#include "../Stack/StackUsingLinkedList.h"

namespace tree
{
    template <class T>
    class BinaryTreeUsingLinkedRepresentation
    {
    private:
        enum m_BinaryTreeUsingLinkedRepresentationMenu
        {
            MIN_COUNT                        = 0,
            DOES_TREE_EXIST                  = 1,
            DISPLAY_PREORDER_RECURSIVE       = 2,
            DISPLAY_INORDER_RECURSIVE        = 3,
            DISPLAY_POSTORDER_RECURSIVE      = 4,
            DISPLAY_LEVELORDER_RECURSIVE     = 5,
            DISPLAY_PREORDER_ITERATIVE       = 6,
            DISPLAY_INORDER_ITERATIVE        = 7,
            DISPLAY_POSTORDER_ITERATIVE      = 8,
            DISPLAY_LEVELORDER_ITERATIVE     = 9,
            CALCULATE_DEG0_NODES_OF_TREE     = 10,
            CALCULATE_DEG1_NODES_OF_TREE     = 11,
            CALCULATE_DEG2_NODES_OF_TREE     = 12,
            CALCULATE_INTERNAL_NODES_OF_TREE = 13,
            CALCULATE_EXTERNAL_NODES_OF_TREE = 14,
            CALCULATE_NO_NODES_OF_TREE       = 15,
            CALCULATE_HEIGHT_OF_TREE         = 16,
            GENERATE_TREE                    = 17,
            RESET_TREE                       = 18,
            BACK_TO_PREVIOUS_MENU            = 19,
            EXIT_FROM_PROGRAM                = 20,
            MAX_COUNT                        = EXIT_FROM_PROGRAM
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
        void             DisplayPreOrderIterative();
        void             DisplayInOrderIterative();
        void             DisplayPostOrderIterative();
        void             DisplayLevelOrderIterative();
        int              CalculateDeg0NodesOfTree(const Node*);
        int              CalculateDeg1NodesOfTree(const Node*);
        int              CalculateDeg2NodesOfTree(const Node*);
        int              CalculateInternalNodesOfTree();
        int              CalculateExternalNodesOfTree();
        int              CalculateNoNodesOfTree();
        int              CalculateHeightOfTree(const Node*);
        void             GenerateTree();
        void             ResetTree(const Node*);
    };
} // namespace tree

# include "BinaryTreeUsingLinkedRepresentation.tpp"
