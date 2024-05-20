cmake_minimum_required(VERSION 3.22)
project(C++)

set (CMAKE_CXX_STANDARD 20)

set(SOURCE_FILES
    C++/main.cpp
    C++/Basics.cpp
    C++/CPPStrings.cpp
    C++/CStyleStrings.cpp
    C++/Functions.cpp
    C++/handlers.cpp
    C++/IOStreams.cpp
    C++/PointersAndReferences.cpp
    C++/Student.cpp
    C++/utils.cpp
    C++/Object\ Oriented\ Programming/Car.cpp
    C++/Object\ Oriented\ Programming/ClassesAndObjects.cpp
    C++/Object\ Oriented\ Programming/Complex.cpp
    C++/Object\ Oriented\ Programming/Cuboid.cpp
    C++/Object\ Oriented\ Programming/Rectangle.cpp
)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})