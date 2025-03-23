#pragma once

#include <map>
#include <cmath>
#include <string>
#include <optional>
#include <iostream>
#include "BinaryTreeUsingArray.h"
#include "BinaryTreeUsingLinkedRepresentation.h"
#include "BinarySearchTree.h"
#include "AVLTree.h"

namespace tree
{
    class TreeMain
    {
    private:
        enum m_TreeMainMenu
        {
            MIN_COUNT                               = 0,
            BINARY_TREE_USING_ARRAY                 = 1,
            BINARY_TREE_USING_LINKED_REPRESENTATION = 2,
            BINARY_SEARCH_TREE                      = 3,
            AVL_TREE                                = 4,
            BACK_TO_PREVIOUS_MENU                   = 5,
            EXIT_FROM_PROGRAM                       = 6,
            MAX_COUNT                               = EXIT_FROM_PROGRAM
        };
        int                        m_choice          { 0 };
        std::map<int, std::string> m_treeMainMenuMap { };

    public:
        TreeMain();
        const int   GetMinCase();
        const int   GetMaxCase();
        const int&  GetChoice();
        void        GetChoiceInputFromUser();
        void	    PrintMenu();
        void        PrintSelectedChoice();
        void        BinaryTreeUsingArray();
        void        BinaryTreeUsingLinkedRepresentation();
        void        BinarySearchTree();
        void        AVLTree();
    };
} // namespace tree
