cmake_minimum_required(VERSION 3.22)
project(C++)

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
    C++/DSA/Recursion/Recursions.cpp
    C++/DSA/Strings/Strings.cpp
    C++/DSA/Matrices/MatricesMain.cpp
    C++/DSA/Matrices/LowerTriangularMatrix.cpp
    C++/DSA/Matrices/UpperTriangularMatrix.cpp
    C++/DSA/Matrices/DiagonalMatrix.cpp
    C++/DSA/Matrices/TridiagonalMatrix.cpp
    C++/DSA/Matrices/ToeplitzMatrix.cpp
    C++/DSA/Matrices/SparseMatrix.cpp
    C++/DSA/Matrices/PolynomialRepresentation.cpp
    C++/DSA/LinkedList/LinkedListMain.cpp
    C++/DSA/LinkedList/SparseMatrix.cpp
)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
