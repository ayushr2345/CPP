#pragma once

#include <map>
#include <string>

namespace complex
{
    class Complex
    {
    private:
        int m_real { 0 };
        int m_img  { 0 };

    public:
        Complex(int length, int breadth);
        Complex(Complex&);
        int     GetReal() { return m_real; }
        int     GetImg() { return m_img; }
        void    Display();
        Complex Add(Complex&);
        Complex operator +(Complex&);
        friend Complex operator-(Complex&, Complex&); // cannot be inline
        friend std::ostream& operator<<(std::ostream&, Complex&);
    };
} // namespace complex
