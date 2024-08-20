#include <iostream>
#include "TridiagonalMatrix.h"

namespace matrices
{
    TridiagonalMatrix::TridiagonalMatrix(int size):
        m_size { size },
        m_data { nullptr }
    {
        m_size = size;
        m_data = new int[3 * m_size - 2];
    }

    TridiagonalMatrix::~TridiagonalMatrix()
    {
        delete []m_data;
        m_size = 0;
    }

    void TridiagonalMatrix::Set(int i, int j, int x)
    {
        if ((i - j) == 1)
        {
            m_data[i - 2] = x;
        }
        else if ((i - j) == 0)
        {
            m_data[m_size - 1 + i - 1] = x;
        }
        else if ((i - j) == -1)
        {
            m_data[2 * m_size - 1 + i - 1] = x;
        }
        else
        {
            std::cout << "Wrong Index" << std::endl;
        }
    }

    int TridiagonalMatrix::Get(int i, int j)
    {
        if ((i - j) == 1)
        {
            return m_data[i - 2];
        }
        else if ((i - j) == 0)
        {
            return m_data[m_size - 1 + i - 1];
        }
        else if ((i - j) == -1)
        {
            return m_data[2 * m_size - 1 + i - 1];
        }
        return 0;
    }

    void TridiagonalMatrix::Display()
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
