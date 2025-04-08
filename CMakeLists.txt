cmake_minimum_required(VERSION 3.22)
project(Cpp)

set (CMAKE_CXX_STANDARD 20)

set(SOURCE_FILES
    C++/main.cpp
    C++/handlers.cpp
    C++/utils.cpp
    C++/Language/Basics.cpp
    C++/Language/CPPStrings.cpp
    C++/Language/CStyleStrings.cpp
    C++/Language/Functions.cpp
    C++/Language/IOStreams.cpp
    C++/Language/PointersAndReferences.cpp
    C++/Language/Student.cpp
    C++/Language/Object\ Oriented\ Programming/Car.cpp
    C++/Language/Object\ Oriented\ Programming/ClassesAndObjects.cpp
    C++/Language/Object\ Oriented\ Programming/Complex.cpp
    C++/Language/Object\ Oriented\ Programming/Cuboid.cpp
    C++/Language/Object\ Oriented\ Programming/Rectangle.cpp
    C++/DataStructures/Recursion/Recursions.cpp
    C++/DataStructures/Strings/Strings.cpp
    C++/DataStructures/Matrices/MatricesMain.cpp
    C++/DataStructures/Matrices/LowerTriangularMatrix.cpp
    C++/DataStructures/Matrices/UpperTriangularMatrix.cpp
    C++/DataStructures/Matrices/DiagonalMatrix.cpp
    C++/DataStructures/Matrices/TridiagonalMatrix.cpp
    C++/DataStructures/Matrices/ToeplitzMatrix.cpp
    C++/DataStructures/Matrices/SparseMatrix.cpp
    C++/DataStructures/Matrices/PolynomialRepresentation.cpp
    C++/DataStructures/LinkedList/LinkedListMain.cpp
    C++/DataStructures/LinkedList/SparseMatrix.cpp
    C++/DataStructures/LinkedList/PolynomialRepresentation.cpp
    C++/DataStructures/Stack/StackMain.cpp
    C++/DataStructures/Queues/QueueMain.cpp
    C++/DataStructures/Trees/TreeMain.cpp
    C++/DataStructures/Heaps/HeapMain.cpp
    C++/Algorithms/SortingAlgorithms/SortingAlgorithmsMain.cpp
)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
