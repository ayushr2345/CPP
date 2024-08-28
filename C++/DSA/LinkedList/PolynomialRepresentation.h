# pragma once
#include "LinearSinglyLinkedList.h"

namespace linkedList
{
    class PolynomialRepresentation
    {
    private:
        class Term
        {
        public:
            Term() {};
            Term(int c, int e)
            {
                m_m_coefficient = c;
                m_m_exponent    = e;
            }
            int m_m_coefficient { 0 };
            int m_m_exponent    { 0 };
        };
        int                                       m_num_terms { 0 };
        int                                       m_data_idx  { 0 };
        linkedList::LinearSinglyLinkedList<Term>* m_data      { nullptr };
    public:
        PolynomialRepresentation(int);
        ~PolynomialRepresentation();
        void   SetNumTerms(int);
        void   Set(int, int);
        void   Display();
        double Evaluate(int);
        friend PolynomialRepresentation* operator+(PolynomialRepresentation&, PolynomialRepresentation&);
    };
} // namespace linkedList
