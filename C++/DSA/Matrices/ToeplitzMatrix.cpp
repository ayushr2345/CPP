#include <iostream>
#include "ToeplitzMatrix.h"

namespace matrices
{
    ToeplitzMatrix::ToeplitzMatrix(int size):
        m_size { size },
        m_data { nullptr }
    {
        m_size = size;
        m_data = new int[2 * m_size - 1];
    }

    ToeplitzMatrix::~ToeplitzMatrix()
    {
        delete []m_data;
        m_size = 0;
    }

    void ToeplitzMatrix::Set(int i, int j, int x)
    {
        if (i <= j)
        {
            m_data[j - 1] = x;
        }
        else if (i > j)
        {
            m_data[m_size + i - j - 1] = x;
        }
        else
        {
            std::cout << "Wrong Index" << std::endl;
        }
    }

    int ToeplitzMatrix::Get(int i, int j)
    {
        if (i <= j)
        {
            return m_data[j - i];
        }
        else if (i > j)
        {
            return m_data[m_size + i - j - 1];
        }
        return 0;
    }

    void ToeplitzMatrix::Display()
    {
        for (int i = 1; i <= m_size; i++)
        {
            for (int j = 1; j <= m_size; j++)
            {
                std::cout << Get(i, j) << " ";
            }
            std::cout << std::endl;
        }
    }
} // namespace matrices
