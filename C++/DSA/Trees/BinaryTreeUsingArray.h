#pragma once

#include <map>
#include <string>
#include <optional>
#include <iostream>
#include "../Queues/QueueUsingLinkedList.h"

namespace tree
{
    template <class T>
    class BinaryTreeUsingArray
    {
    private:
        enum m_BinaryTreeUsingArrayMenu
        {
            MIN_COUNT                   = 0,
            DOES_TREE_EXIST             = 1,
            DISPLAY_PREORDER_RECURSIVE  = 2,
            DISPLAY_INORDER_RECURSIVE   = 3,
            DISPLAY_POSTORDER_RECURSIVE = 4,
            GENERATE_TREE               = 5,
            RESET_TREE                  = 6,
            BACK_TO_PREVIOUS_MENU       = 7,
            EXIT_FROM_PROGRAM           = 8,
            MAX_COUNT                   = EXIT_FROM_PROGRAM
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
        void             GenerateTree();
        void             ResetTree();
    };
} // namespace tree

# include "BinaryTreeUsingArray.tpp"
