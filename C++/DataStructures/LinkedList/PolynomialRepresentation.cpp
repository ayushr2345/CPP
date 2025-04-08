#include <iostream>
#include <cmath>
#include "PolynomialRepresentation.h"

namespace linkedList
{
    PolynomialRepresentation::PolynomialRepresentation(int numTerms):
        m_num_terms { numTerms },
        m_data_idx  { 0 },
        m_data      { nullptr }
    {
        m_data = new LinearSinglyLinkedList<Term>;
    }

    PolynomialRepresentation::~PolynomialRepresentation()
    {
        delete m_data;
        m_num_terms = 0;
    }

    void PolynomialRepresentation::SetNumTerms(int num)
    {
        m_num_terms = num;
    }

    void PolynomialRepresentation::Set(int coefficient, int exponent)
    {
        m_data->Insert(m_data_idx, Term(coefficient, exponent));
        m_data_idx++;
    }

    void PolynomialRepresentation::Display()
    {
        auto temp = m_data->MoveToIndex(0);
        for (int i = 0; i < m_num_terms; i++)
        {
            std::cout << temp->m_m_data.m_m_coefficient << " * pow(x, " << temp->m_m_data.m_m_exponent << ")";
            if (i != m_num_terms - 1) 
            {
                std::cout << " + ";
            }
            temp = temp->m_m_next;
        }
        std::cout << std::endl;
    }

    double PolynomialRepresentation::Evaluate(int x)
    {
        auto temp = m_data->MoveToIndex(0);
        double sum = 0;
        for (int i = 0; i < m_num_terms; i++)
        {
            sum += temp->m_m_data.m_m_coefficient * pow(x, temp->m_m_data.m_m_exponent);
            temp = temp->m_m_next;
        }
        return sum;
    }

    PolynomialRepresentation* operator+(PolynomialRepresentation &prObj1, PolynomialRepresentation &prObj2)
    {
        PolynomialRepresentation *temp = new PolynomialRepresentation(prObj1.m_num_terms + prObj2.m_num_terms);

        int i = 0;
        int j = 0;

        while (i < prObj1.m_num_terms and j < prObj2.m_num_terms)
        {
            auto getA = prObj1.m_data->Get(i);
            auto getB = prObj2.m_data->Get(j);

            if (getA->m_m_exponent < getB->m_m_exponent)
            {
                temp->Set(getB->m_m_coefficient, getB->m_m_exponent);
                j++;
            }
            else if (getA->m_m_exponent > getB->m_m_exponent)
            {
                temp->Set(getA->m_m_coefficient, getA->m_m_exponent);
                i++;
            }
            else
            {
                temp->Set(getA->m_m_coefficient + getB->m_m_coefficient, getA->m_m_exponent);
                i++;
                j++;
            }
        }

        while (i < prObj1.m_num_terms)
        {
            auto getA = prObj1.m_data->Get(i);
            temp->Set(getA->m_m_coefficient, getA->m_m_exponent);
            i++;
        }

        while (j < prObj2.m_num_terms)
        {
            auto getB = prObj2.m_data->Get(j);
            temp->Set(getB->m_m_coefficient, getB->m_m_exponent);
            j++;
        }

        temp->SetNumTerms(temp->m_data->GetSize());
        return temp;
    }
} // namespace linkedList
