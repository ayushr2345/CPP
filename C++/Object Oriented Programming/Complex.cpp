#include <iostream>
#include <map>
#include <string>
#include "Complex.h"

namespace complex
{
    Complex::Complex(int real, int img) :
        m_real { real },
        m_img  { img }
    {
        std::cout << "Parameterized constructor is called" << std::endl;
    }

    Complex::Complex(Complex& comp)
    {
        m_real = comp.GetReal();
        m_img  = comp.GetImg();
    }

    Complex Complex::Add(Complex& comp)
    {
        Complex temp(0, 0);
        temp.m_real = this->m_real + comp.GetReal();
        temp.m_img  = this->m_img + comp.GetImg();
        return temp;
    }

    void Complex::Display()
    {
        std::cout << m_real << " + " << m_img << "i" << std::endl;
    }

    Complex Complex::operator+(Complex& comp)
    {
        std::cout << "Normal overloaded '+' called" << std::endl;
        Complex temp(0, 0);
        temp.m_real = this->m_real + comp.GetReal();
        temp.m_img = this->m_img + comp.GetImg();
        return temp;
    }

    // shouldn't use access specifier here as it is a friend function
    // friend function does not belong to class
    Complex operator-(Complex& comp1, Complex& comp2)
    {
        std::cout << "Friend overloaded '-' called" << std::endl;

        // can access pvt members here as this is a friend function
        Complex temp(0, 0);
        temp.m_real = comp1.m_real - comp2.GetReal();
        temp.m_img = comp1.m_img - comp2.GetImg();
        return temp;
    }

    std::ostream& operator<<(std::ostream& os, Complex& comp)
    {
        os << comp.GetReal() << " + " << comp.GetImg() << "i" << std::endl;
        // if we dont return os and make the function return void, we won't be able to do std::cout << comp << "hi";
        return os;
    }
} // namespace complex
