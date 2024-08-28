# pragma once
#include "LinearSinglyLinkedList.h"

namespace linkedList
{
    class SparseMatrix
    {
    private:
        class Element
        {
        public:
            Element() {};
            Element(int i, int j, int x)
            {
                m_m_row     = i;
                m_m_column  = j;
                m_m_element = x;
            }
            int m_m_row     { 0 };
            int m_m_column  { 0 };
            int m_m_element { 0 };
        };

        int                              m_size_row     { 0 };
        int                              m_size_column  { 0 };
        int                              m_num_non_zero { 0 };
        int                              m_data_idx     { 0 };
        LinearSinglyLinkedList<Element>* m_data         { nullptr };
    public:
        SparseMatrix(int, int, int);
        ~SparseMatrix();
        void SetNumNonZero(int);
        void Set(int, int, int);
        int  Get(int, int);
        void Display();

        friend SparseMatrix* operator+(SparseMatrix&, SparseMatrix&);
    };
} // namespace linkedList
