#include <iostream>
#include "LowerTriangularMatrix.h"

namespace matrices
{
    LowerTriangularMatrix::LowerTriangularMatrix(int size):
        m_size { size },
        m_data { nullptr }
    {
        m_size = size;
        m_data = new int[m_size * (m_size + 1) / 2];
    }

    LowerTriangularMatrix::~LowerTriangularMatrix()
    {
        delete []m_data;
        m_size = 0;
    }

    void LowerTriangularMatrix::Set(int i, int j, int x)
    {
        if (not (i >= j))
        {
            std::cout << "Wrong Index" << std::endl;
        }
        else
        {
            // this is row major mapping
            m_data[(i * (i - 1) / 2) + (j - 1)] = x;

            // for column major mapping, 
            // m_data[(m_size * (j - 1)) - ((j - 1) * (j - 2) / 2) + (i - j)] = x;
        }
    }

    int LowerTriangularMatrix::Get(int i, int j)
    {
        if (i >= j)
        {
            return m_data[(i * (i - 1) / 2) + (j - 1)];
        }
        return 0;
    }

    void LowerTriangularMatrix::Display()
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
