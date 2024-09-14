#include <iostream>
#include <string>
#include <functional>
#include "TreeMain.h"
#include "../../utils.h"
#include "../../handlers.h"

namespace tree
{
    TreeMain::TreeMain():
        m_choice          ( 0 ),
        m_treeMainMenuMap ( {} )
    {
        m_treeMainMenuMap.insert({ m_TreeMainMenu(BINARY_TREE_USING_ARRAY),
                                   std::string("Binary Tree using Array") });
        m_treeMainMenuMap.insert({ m_TreeMainMenu(BINARY_TREE_USING_LINKED_REPRESENTATION),
                                   std::string("Binary Tree using Linked Representation") });
        m_treeMainMenuMap.insert({ m_TreeMainMenu(BACK_TO_PREVIOUS_MENU),
                                   std::string("Back to Previous Menu") });
        m_treeMainMenuMap.insert({ m_TreeMainMenu(EXIT_FROM_PROGRAM),
                                   std::string("Exit from program") });
    }

    const int TreeMain::GetMinCase()
    {
        return m_TreeMainMenu::MIN_COUNT;
    }

    const int TreeMain::GetMaxCase()
    {
        return m_TreeMainMenu::MAX_COUNT;
    }

    const int& TreeMain::GetChoice()
    {
        return m_choice;
    }

    void TreeMain::GetChoiceInputFromUser()
    {
        utils::InputNumberFromUser(m_choice, 1, static_cast<int>(m_TreeMainMenu::MAX_COUNT));
    }

    void TreeMain::PrintMenu()
    {
        std::cout << std::endl;
        for (std::map<int, std::string>::iterator it = m_treeMainMenuMap.begin();
            it != m_treeMainMenuMap.end();
            it++)
        {
            std::cout << it->first << ". " << it->second << std::endl;
        }
        std::cout << "Please enter your choice: ";
    }

    void TreeMain::PrintSelectedChoice()
    {
        std::cout << std::endl << std::endl
                  << "You have chosen choice "
                  << m_treeMainMenuMap.at(m_choice)
                  << std::endl;
    }

    void TreeMain::BinaryTreeUsingArray()
    {
        std::cout << "Please enter the height of the binary tree: ";
        int height;
        utils::InputNumberFromUser(height, 0, 5);
        int maxNodes = std::pow(2, (height + 1)) - 1;
        std::cout << "MAX NODES: " << maxNodes << std::endl;
        tree::BinaryTreeUsingArray<int> binaryTreeUsingArrayObj(maxNodes + 1);
        handlers::Handle(binaryTreeUsingArrayObj);
    }

    void TreeMain::BinaryTreeUsingLinkedRepresentation()
    {
        tree::BinaryTreeUsingLinkedRepresentation<int> binaryTreeUsingLinkedRepresentationObj;
        handlers::Handle(binaryTreeUsingLinkedRepresentationObj);
    }
} // namespace tree
