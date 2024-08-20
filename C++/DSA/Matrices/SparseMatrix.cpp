#include <iostream>
#include "SparseMatrix.h"

namespace matrices
{
    SparseMatrix::SparseMatrix(int rows, int columns, int numNonZero):
        m_size_row     { rows },
        m_size_column  { columns },
        m_num_non_zero { numNonZero },
        m_data_idx     { 0 },
        m_data         { nullptr }
    {
        m_data = new Element[m_num_non_zero];
    }

    SparseMatrix::~SparseMatrix()
    {
        delete []m_data;
        m_size_row     = 0;
        m_size_column  = 0;
        m_num_non_zero = 0;
    }

    void SparseMatrix::Set(int i, int j, int x)
    {
        (m_data + m_data_idx)->m_m_row     = i;
        (m_data + m_data_idx)->m_m_column  = j;
        (m_data + m_data_idx)->m_m_element = x;
        m_data_idx++;
    }

    int SparseMatrix::Get(int i, int j)
    {
        for (int a = 0; a < m_num_non_zero; a++)
        {
            if ((m_data + a)->m_m_row == i and (m_data + a)->m_m_column == j)
            {
                return (m_data + a)->m_m_element;
            }
        }
        return 0;
    }

    void SparseMatrix::Display()
    {
        for (int i = 1; i <= m_size_row; i++)
        {
            for (int j = 1; j <= m_size_column; j++)
            {
                std::cout << Get(i, j) << " ";
            }
            std::cout << std::endl;
        }
    }

    SparseMatrix* operator+(SparseMatrix &smObj1, SparseMatrix &smObj2)
    {
        if (smObj1.m_size_row == smObj2.m_size_row and
            smObj1.m_size_column == smObj2.m_size_column)
        {
            SparseMatrix *temp = new SparseMatrix(
                smObj1.m_size_row,
                smObj1.m_size_column,
                smObj1.m_num_non_zero + smObj2.m_num_non_zero
            );

            int i = 0;
            int j = 0;
            int k = 0;

            while (i < smObj1.m_num_non_zero or j < smObj2.m_num_non_zero)
            {
                if (smObj1.m_data[i].m_m_row < smObj2.m_data[j].m_m_row)
                {
                    temp->m_data[k++] = smObj1.m_data[i++];
                }
                else if (smObj1.m_data[i].m_m_row > smObj2.m_data[j].m_m_row)
                {
                    temp->m_data[k++] = smObj2.m_data[j++];
                }
                else
                {
                    if (smObj1.m_data[i].m_m_column < smObj2.m_data[j].m_m_column)
                    {
                        temp->m_data[k++] = smObj1.m_data[i++];
                    }
                    else if (smObj1.m_data[i].m_m_column > smObj2.m_data[j].m_m_column)
                    {
                        temp->m_data[k++] = smObj2.m_data[j++];
                    }
                    else
                    {
                        temp->m_data[k] = smObj1.m_data[i++];
                        temp->m_data[k++].m_m_element += smObj2.m_data[j++].m_m_element;
                    }
                }
            }
            return temp;
        }
        else
        {
            std::cout << "The sizes of the two matrices are not equal, cannot add" << std::endl;
            return nullptr;
        }
    }
} // namespace matrices
