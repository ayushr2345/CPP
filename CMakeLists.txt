cmake_minimum_required(VERSION 3.22)
project(C++)

set (CMAKE_CXX_STANDARD 20)

set(SOURCE_FILES
    C++/main.cpp
    C++/Language/Basics.cpp
    C++/Language/CPPStrings.cpp
    C++/Language/CStyleStrings.cpp
    C++/Language/Functions.cpp
    C++/handlers.cpp
    C++/Language/IOStreams.cpp
    C++/Language/PointersAndReferences.cpp
    C++/Language/Student.cpp
    C++/utils.cpp
    C++/Language/Object\ Oriented\ Programming/Car.cpp
    C++/Language/Object\ Oriented\ Programming/ClassesAndObjects.cpp
    C++/Language/Object\ Oriented\ Programming/Complex.cpp
    C++/Language/Object\ Oriented\ Programming/Cuboid.cpp
    C++/Language/Object\ Oriented\ Programming/Rectangle.cpp
)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
