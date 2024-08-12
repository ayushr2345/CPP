#pragma once

#include <map>
#include <string>

namespace rectangle
{
    class Rectangle
    {
    private:
        unsigned int m_length  { 0 };
        unsigned int m_breadth { 0 };

    public:
        Rectangle();
        Rectangle(unsigned int length, unsigned int breadth);
        Rectangle(Rectangle&);
        ~Rectangle() { std::cout << "Rectangle Destructor called" << std::endl; }
        void               SetLength(unsigned int length) { m_length = length; }
        void               SetBreadth(unsigned int breadth) { m_breadth = breadth; }
        const unsigned int GetLength() const { return m_length; }
        const unsigned int GetBreadth() const { return m_breadth; }
        const unsigned int GetArea() const { return m_length * m_breadth; }
        const unsigned int GetPerimeter() const { return 2 * (m_length + m_breadth); }
        void               Display() { std::cout << "Display of Rectangle" << std::endl; }
    };
} // namespace rectangle
