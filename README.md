# C++ Learning and Practice Project

This repository is a hands-on C++ study project designed to explore the core building blocks of the language, object-oriented programming, common data structures, and classic algorithms through interactive console-based examples. It is organized as a menu-driven application that lets you navigate through different topics without needing to compile or run each example separately.

## Overview

The project serves as both a learning resource and a reference implementation. It demonstrates how to structure small C++ programs, organize source files cleanly, and implement common computer science concepts in a practical way.

## What the project covers

### Language fundamentals
The project includes examples and exercises for:
- Variables, operators, and control flow
- Functions and modular program design
- Pointers and references
- C-style strings and C++ string handling
- Input and output streams
- Object-oriented programming concepts using classes and objects

### Data structures
The repository includes implementations and demonstrations for:
- Recursion
- Arrays and array-based data structures
- Strings
- Matrices and special matrix representations
- Linked lists
- Stacks
- Queues
- Trees
- Heaps and priority queue concepts

### Algorithms
The project also explores common algorithmic topics such as:
- Sorting algorithms including bubble sort, selection sort, insertion sort, quick sort, and heap sort

## Project structure

The codebase is organized into a few main areas:
- [C++/main.cpp](C++/main.cpp) – Entry point and interactive menu system
- [C++/handlers.cpp](C++/handlers.cpp) and [C++/handlers.h](C++/handlers.h) – Centralized handling logic for examples
- [C++/utils.cpp](C++/utils.cpp) and [C++/utils.h](C++/utils.h) – Shared utility functions for input, menus, and console output
- [C++/Language](C++/Language) – Basic C++ language topics and OOP examples
- [C++/DataStructures](C++/DataStructures) – Data structure implementations and demos
- [C++/Algorithms](C++/Algorithms) – Algorithm-focused examples
- [CMakeLists.txt](CMakeLists.txt) – Build configuration for the project

## Build and run

This project uses CMake and requires a modern C++ compiler with C++20 support.

### Prerequisites
- CMake 3.22 or newer
- A C++ compiler supporting C++20

### Build instructions

From the repository root, run:

```bash
cmake -S . -B build
cmake --build build
```

### Run the program

On Linux or macOS:

```bash
./build/Cpp
```

On Windows:

```powershell
.\build\Cpp.exe
```

## How to use it

When the program starts, you will be presented with a menu that lets you choose between:
- Language topics
- Data structures
- Algorithms

Each option opens a submenu with related examples, and many sections prompt you for input to demonstrate behavior interactively.

## Notes

This is primarily an educational repository rather than a production-grade application. The focus is on clarity, experimentation, and understanding core concepts in C++.

## Intended audience

This project is especially useful for:
- Beginners learning C++
- Students practicing data structures and algorithms
- Developers preparing for interviews
- Anyone who wants a compact, menu-driven C++ reference project
