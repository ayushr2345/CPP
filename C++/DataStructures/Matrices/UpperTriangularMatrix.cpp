#include <iostream>
#include "UpperTriangularMatrix.h"

namespace matrices
{
    UpperTriangularMatrix::UpperTriangularMatrix(int size):
        m_size { size },
        m_data { nullptr }
    {
        m_size = size;
        m_data = new int[m_size * (m_size + 1) / 2];
    }

    UpperTriangularMatrix::~UpperTriangularMatrix()
    {
        delete []m_data;
        m_size = 0;
    }

    void UpperTriangularMatrix::Set(int i, int j, int x)
    {
        if (not (i <= j))
        {
            std::cout << "Wrong Index" << std::endl;
        }
        else
        {
            // this is row major mapping, 
            m_data[(m_size * (i - 1)) - ((i - 1) * (i - 2) / 2) + (j - i)] = x;

            // this is column major mapping
            // m_data[(j * (j - 1) / 2) + (i - 1)] = x;
        }
    }

    int UpperTriangularMatrix::Get(int i, int j)
    {
        if (i <= j)
        {
            return m_data[(m_size * (i - 1)) - ((i - 1) * (i - 2) / 2) + (j - i)];
        }
        return 0;
    }

    void UpperTriangularMatrix::Display()
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
