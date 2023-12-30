#pragma once

#include <map>
#include <string>
#include "Rectangle.h"

namespace rectangle
{
    class Cuboid: public Rectangle
    {
    private:
        unsigned int m_height { 0 };

    public:
        Cuboid(unsigned int, unsigned int, unsigned int);
        void               SetHeight(unsigned int height) { m_height = height; }
        const unsigned int GetHeight() const { return m_height; }
        const unsigned int GetVolume() const { return GetArea() * m_height; }
        virtual void       Display() { std::cout << "Display of Cuboid" << std::endl; }
    };
} // namespace rectangle
