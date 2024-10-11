#pragma once

#include "AVLTree.h"
#include "../../utils.h"

namespace tree
{
    template <class T>
    AVLTree<T>::AVLTree():
        m_choice         ( 0 ),
        m_avlTreeMenuMap ( {} ),
        m_rootNode       { nullptr }
    {
        m_avlTreeMenuMap.insert({ m_AVLTreeMenu(DOES_TREE_EXIST),
                                  std::string("Check if the tree exists") });
        m_avlTreeMenuMap.insert({ m_AVLTreeMenu(DISPLAY_PREORDER),
                                  std::string("Display Preorder") });
        m_avlTreeMenuMap.insert({ m_AVLTreeMenu(DISPLAY_INORDER),
                                  std::string("Display Inorder") });
        m_avlTreeMenuMap.insert({ m_AVLTreeMenu(DISPLAY_POSTORDER),
                                  std::string("Display Postorder") });
        m_avlTreeMenuMap.insert({ m_AVLTreeMenu(DISPLAY_LEVELORDER),
                                  std::string("Display Level order") });
        m_avlTreeMenuMap.insert({ m_AVLTreeMenu(RESET_TREE),
                                  std::string("Reset Tree") });
        m_avlTreeMenuMap.insert({ m_AVLTreeMenu(BACK_TO_PREVIOUS_MENU),
                                  std::string("Back to Previous Menu") });
        m_avlTreeMenuMap.insert({ m_AVLTreeMenu(EXIT_FROM_PROGRAM),
                                  std::string("Exit from program") });
    }

    template <class T>
    AVLTree<T>::~AVLTree()
    {
        ResetTree(m_rootNode);
    }
    
    template <class T>
    const int AVLTree<T>::GetMinCase()
    {
        return m_AVLTreeMenu::MIN_COUNT;
    }

    template <class T>
    const int AVLTree<T>::GetMaxCase()
    {
        return m_AVLTreeMenu::MAX_COUNT;
    }

    template <class T>
    const int& AVLTree<T>::GetChoice()
    {
        return m_choice;
    }

    template <class T>
    void AVLTree<T>::GetChoiceInputFromUser()
    {
        utils::InputNumberFromUser(m_choice, 1, static_cast<int>(m_AVLTreeMenu::MAX_COUNT));
    }

    template <class T>
    void AVLTree<T>::PrintMenu()
    {
        std::cout << std::endl;
        for (std::map<int, std::string>::iterator it = m_avlTreeMenuMap.begin();
            it != m_avlTreeMenuMap.end();
            it++)
        {
            std::cout << it->first << ". " << it->second << std::endl;
        }
        std::cout << "Please enter your choice: ";
    }

    template <class T>
    void AVLTree<T>::PrintSelectedChoice()
    {
        std::cout << std::endl << std::endl
                << "You have chosen choice "
                << m_avlTreeMenuMap.at(m_choice)
                << std::endl;
    }

    template <class T>
    bool AVLTree<T>::DoesTreeExist()
    {
        return m_rootNode ? true : false;
    }

    // Private methods
    template <class T>
    void AVLTree<T>::DisplayPreOrder(const Node* node)
    {
        if (node)
        {
            std::cout << node->m_m_data << " ";
            DisplayPreOrder(node->m_m_leftChild);
            DisplayPreOrder(node->m_m_rightChild);
        }
    }

    template <class T>
    void AVLTree<T>::DisplayInOrder(const Node* node)
    {
        if (node)
        {
            DisplayInOrder(node->m_m_leftChild);
            std::cout << node->m_m_data << " ";
            DisplayInOrder(node->m_m_rightChild);
        }
    }

    template <class T>
    void AVLTree<T>::DisplayPostOrder(const Node* node)
    {
        if (node)
        {
            DisplayPostOrder(node->m_m_leftChild);
            DisplayPostOrder(node->m_m_rightChild);
            std::cout << node->m_m_data << " ";
        }
    }

    template <class T>
    void AVLTree<T>::DisplayLevelOrder(const Node* node)
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
            DisplayLevelOrder(node->m_m_leftChild);
            DisplayLevelOrder(node->m_m_rightChild);
        }
    }

    template <class T>
    void AVLTree<T>::ResetTree(const Node* node)
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
} //namespace tree
