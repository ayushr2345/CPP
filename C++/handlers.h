#pragma once

#include "utils.h"
#include "Language/Basics.h"
#include "Language/PointersAndReferences.h"
#include "Language/CStyleStrings.h"
#include "Language/CPPStrings.h"
#include "Language/Functions.h"
#include "Language/Object Oriented Programming/ClassesAndObjects.h"
#include "Language/IOStreams.h"
#include "DSA/Recursion/Recursions.h"
#include "DSA/ArrayADT/ArrayADT.h"
#include "DSA/Strings/Strings.h"
#include "DSA/Matrices/MatricesMain.h"
#include "DSA/LinkedList/LinkedListMain.h"
#include "DSA/Stack/StackMain.h"

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
} // namespace handlers

#include "handlers.tpp"
