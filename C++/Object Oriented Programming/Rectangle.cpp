#pragma once

#include <iostream>
#include <map>
#include <string>
#include "Rectangle.h"

namespace rectangle
{
    Rectangle::Rectangle()
    {
        std::cout << "Non-parameterized constructor is called" << std::endl;
    }

    Rectangle::Rectangle(unsigned int length, unsigned int breadth) :
        m_length  { length },
        m_breadth { breadth }
    {
        std::cout << "Parameterized constructor is called" << std::endl;
    }

    Rectangle::Rectangle(Rectangle& rect)
    {
        std::cout << "Copy constructor is called" << std::endl;
        m_length  = rect.GetLength();
        m_breadth = rect.GetBreadth();
    }
} // namespace rectangle
