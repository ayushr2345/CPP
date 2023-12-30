#pragma once

#include <iostream>
#include <map>
#include <string>
#include "Cuboid.h"

namespace rectangle
{
    Cuboid::Cuboid(unsigned int length, unsigned int breadth, unsigned int height) :
        m_height { height }
    {
        SetLength(length);
        SetBreadth(breadth);
        SetHeight(height);
        std::cout << "Parameterized constructor of Cuboid class is called" << std::endl;
    }
} // namespace rectangle
