#include <iostream>
#include "DiagonalMatrix.h"

namespace matrices
{
    DiagonalMatrix::DiagonalMatrix(int size):
        m_size { size },
        m_data { nullptr }
    {
        m_size = size;
        m_data = new int[m_size];
    }

    DiagonalMatrix::~DiagonalMatrix()
    {
        delete []m_data;
        m_size = 0;
    }

    void DiagonalMatrix::Set(int i, int j, int x)
    {
        if (not (i == j))
        {
            std::cout << "Indexes are not equal, not setting anything" << std::endl;
        }
        else
        {
            m_data[i - 1] = x;
        }
    }

    int DiagonalMatrix::Get(int i, int j)
    {
        if (i == j)
        {
            return m_data[i - 1];
        }
        return 0;
    }

    void DiagonalMatrix::Display()
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
