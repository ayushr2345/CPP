#include <iostream>
#include "SparseMatrix.h"

namespace linkedList
{
    SparseMatrix::SparseMatrix(int rows, int columns, int numNonZero):
        m_size_row     { rows },
        m_size_column  { columns },
        m_num_non_zero { numNonZero },
        m_data_idx     { 0 },
        m_data         { nullptr }
    {
        m_data = new LinearSinglyLinkedList<Element>;
    }

    SparseMatrix::~SparseMatrix()
    {
        delete m_data;
        m_size_row     = 0;
        m_size_column  = 0;
        m_num_non_zero = 0;
    }

    void SparseMatrix::SetNumNonZero(int num)
    {
        m_num_non_zero = num;
    }

    void SparseMatrix::Set(int i, int j, int x)
    {
        m_data->Insert(m_data_idx, Element(i, j, x));
        m_data_idx++;
    }

    int SparseMatrix::Get(int i, int j)
    {
        auto temp = m_data->MoveToIndex(0);
        for (int a = 0; a < m_num_non_zero; a++)
        {            
            if ((temp->m_m_data).m_m_row == i and (temp->m_m_data).m_m_column == j)
            {
                return (temp->m_m_data).m_m_element;
            }
            temp = temp->m_m_next;
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

            while (i < smObj1.m_num_non_zero and j < smObj2.m_num_non_zero)
            {
                auto getA = smObj1.m_data->Get(i);
                auto getB = smObj2.m_data->Get(j);

                if (getA->m_m_row < getB->m_m_row)
                {
                    temp->Set(getA->m_m_row, getA->m_m_column, getA->m_m_element);
                    i++;
                }
                else if (getA->m_m_row > getB->m_m_row)
                {
                    temp->Set(getB->m_m_row, getB->m_m_column, getB->m_m_element);
                    j++;
                }
                else
                {
                    if (getA->m_m_column < getB->m_m_column)
                    {
                        temp->Set(getA->m_m_row, getA->m_m_column, getA->m_m_element);
                        i++;
                    }
                    else if (getA->m_m_column > getB->m_m_column)
                    {
                        temp->Set(getB->m_m_row, getB->m_m_column, getB->m_m_element);
                        j++;
                    }
                    else
                    {
                        temp->Set(getA->m_m_row, getA->m_m_column, getA->m_m_element + getB->m_m_element);
                        i++;
                        j++;
                    }
                }
            }

            while (i < smObj1.m_num_non_zero)
            {
                auto getA = smObj1.m_data->Get(i);
                temp->Set(getA->m_m_row, getA->m_m_column, getA->m_m_element);
                i++;
            }

            while (j < smObj2.m_num_non_zero)
            {
                auto getB = smObj2.m_data->Get(j);
                temp->Set(getB->m_m_row, getB->m_m_column, getB->m_m_element);
                j++;
            }
            temp->SetNumNonZero(temp->m_data->GetSize());
            return temp;
        }
        else
        {
            std::cout << "The sizes of the two sparse matrix are not equal, cannot add" << std::endl;
            return nullptr;
        }
    }
} // namespace linkedList
