#pragma once

#include <map>
#include <string>
#include <optional>
#include <iostream>
#include "../Queues/QueueUsingLinkedList.h"
#include "../Stack/StackUsingLinkedList.h"

namespace tree
{
    template <class T>
    class BinaryTreeUsingArray
    {
    private:
        enum m_BinaryTreeUsingArrayMenu
        {
            MIN_COUNT                    = 0,
            DOES_TREE_EXIST              = 1,
            DISPLAY_PREORDER_RECURSIVE   = 2,
            DISPLAY_INORDER_RECURSIVE    = 3,
            DISPLAY_POSTORDER_RECURSIVE  = 4,
            DISPLAY_LEVELORDER_RECURSIVE = 5,
            DISPLAY_PREORDER_ITERATIVE   = 6,
            DISPLAY_INORDER_ITERATIVE    = 7,
            DISPLAY_POSTORDER_ITERATIVE  = 8,
            DISPLAY_LEVELORDER_ITERATIVE = 9,
            GENERATE_TREE                = 10,
            RESET_TREE                   = 11,
            BACK_TO_PREVIOUS_MENU        = 12,
            EXIT_FROM_PROGRAM            = 13,
            MAX_COUNT                    = EXIT_FROM_PROGRAM
        };

        int                        m_choice                      { 0 };
        std::map<int, std::string> m_binaryTreeUsingArrayMenuMap {};
        int                        m_size                        { 0 };
        int                        m_numNodes                    { 0 };
        T*                         m_data                        { nullptr };
    public:
        BinaryTreeUsingArray(int);
        ~BinaryTreeUsingArray();
        const int        GetMinCase();
        const int        GetMaxCase();
        const int&       GetChoice();
        void             GetChoiceInputFromUser();
        void	         PrintMenu();
        void             PrintSelectedChoice();
        std::optional<T> GetRootNode();
        bool             IsExisting();
        void             DisplayPreOrderRecursive(const int);
        void             DisplayInOrderRecursive(const int);
        void             DisplayPostOrderRecursive(const int);
        void             DisplayLevelOrderRecursive(const int);
        void             DisplayPreOrderIterative();
        void             DisplayInOrderIterative();
        void             DisplayPostOrderIterative();
        void             DisplayLevelOrderIterative();
        void             GenerateTree();
        void             ResetTree();
    };
} // namespace tree

# include "BinaryTreeUsingArray.tpp"
