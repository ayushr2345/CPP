#pragma once

#include "utils.h"
#include "Language/Basics.h"
#include "Language/PointersAndReferences.h"
#include "Language/CStyleStrings.h"
#include "Language/CPPStrings.h"
#include "Language/Functions.h"
#include "Language/Object Oriented Programming/ClassesAndObjects.h"
#include "Language/IOStreams.h"
#include "DataStructures/Recursion/Recursions.h"
#include "DataStructures/ArrayADT/ArrayADT.h"
#include "DataStructures/Strings/Strings.h"
#include "DataStructures/Matrices/MatricesMain.h"
#include "DataStructures/LinkedList/LinkedListMain.h"
#include "DataStructures/Stack/StackMain.h"
#include "DataStructures/Queues/QueueMain.h"
#include "DataStructures/Trees/TreeMain.h"
#include "DataStructures/Heaps/HeapMain.h"
#include "Algorithms/SortingAlgorithms/SortingAlgorithmsMain.h"

namespace handlers
{
    // Language Handlers
    void Handle(basics::Basics&);
    void Handle(pointersAndReferences::PointersAndReferences&);
    void Handle(cStyleStrings::CStyleStrings&);
    void Handle(cppStrings::CPPStrings&);
    void Handle(functions::Functions&);
    void Handle(classesAndObjects::ClassesAndObjects&);
    void Handle(iostreams::IOStreams&);

    // DSA Handlers

    // Recursion
    void Handle(recursions::Recursions&);

    // Array ADT
    template<class T>
    void Handle(arrayAdt::ArrayADT<T>&);

    // Strings
    void Handle(strings::Strings&);
    
    // Matrices
    void Handle(matrices::MatricesMain&);
    
    // Linked List
    void Handle(linkedList::LinkedListMain&);

    template<class T>
    void Handle(linkedList::LinearSinglyLinkedList<T>&);

    template<class T>
    void Handle(linkedList::CircularSinglyLinkedList<T>&);

    template<class T>
    void Handle(linkedList::LinearDoublyLinkedList<T>&);

    template<class T>
    void Handle(linkedList::CircularDoublyLinkedList<T>&);

    void Handle(linkedList::SparseMatrix&);

    // Stack
    void Handle(stack::StackMain&);

    template <class T>
    void Handle(stack::StackUsingArray<T>&);

    template <class T>
    void Handle(stack::StackUsingLinkedList<T>&);

    // Queue
    void Handle(queue::QueueMain&);

    template <class T>
    void Handle(queue::QueueUsingArray<T>&);

    template <class T>
    void Handle(queue::CircularQueue<T>&);

    template <class T>
    void Handle(queue::QueueUsingLinkedList<T>&);

    template <class T>
    void Handle(queue::DoubleEndedQueue<T>&);

    template <class T>
    void Handle(queue::PriorityQueueLimitedSet<T>&);

    template <class T>
    void Handle(queue::PriorityQueueElement<T>&);

    template <class T>
    void Handle(queue::QueueUsingTwoStacks<T>&);

    // Trees
    void Handle(tree::TreeMain&);

    template <class T>
    void Handle(tree::BinaryTreeUsingArray<T>&);

    template <class T>
    void Handle(tree::BinaryTreeUsingLinkedRepresentation<T>&);

    template <class T>
    void Handle(tree::BinarySearchTree<T>&);

    template <class T>
    void Handle(tree::AVLTree<T>&);

    // Heaps
    void Handle(heap::HeapMain&);

    template <class T>
    void Handle(heap::MaxHeap<T>&);

    template <class T>
    void Handle(heap::MinHeap<T>&);

    template <class T>
    void Handle(heap::Heapify<T>&);

    template <class T>
    void Handle(heap::PriorityQueuesUsingHeaps<T>&);

    // Sorting Algorithms
    void Handle(sorting_algorithms::SortingAlgorithmsMain&);

    template <class T>
    void Handle(sorting_algorithms::BubbleSort<T>&);

    template <class T>
    void Handle(sorting_algorithms::InsertionSort<T>&);

    template <class T>
    void Handle(sorting_algorithms::SelectionSort<T>&);
} // namespace handlers

#include "handlers_data_structures.tpp"
#include "handlers_algorithms.tpp"
