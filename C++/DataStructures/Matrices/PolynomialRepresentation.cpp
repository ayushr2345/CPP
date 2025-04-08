#include <iostream>
#include <cmath>
#include "PolynomialRepresentation.h"

namespace matrices
{
    PolynomialRepresentation::PolynomialRepresentation(int numTerms):
        m_num_terms { numTerms },
        m_data_idx  { 0 },
        m_data      { nullptr }
    {
        m_data = new Term[m_num_terms];
    }

    PolynomialRepresentation::~PolynomialRepresentation()
    {
        delete []m_data;
        m_num_terms = 0;
    }

    void PolynomialRepresentation::Set(int coefficient, int exponent)
    {
        (m_data + m_data_idx)->m_m_coefficient = coefficient;
        (m_data + m_data_idx)->m_m_exponent    = exponent;
        m_data_idx++;
    }

    void PolynomialRepresentation::Display()
    {
        for (int i = 0; i < m_num_terms; i++)
        {
            std::cout << m_data[i].m_m_coefficient << " * pow(x, " << m_data[i].m_m_exponent << ")";
            if (i != m_num_terms - 1) 
            {
                std::cout << " + ";
            }
        }
        std::cout << std::endl;
    }

    double PolynomialRepresentation::Evaluate(int x)
    {
        double sum = 0;
        for (int i = 0; i < m_num_terms; i++)
        {
            sum += m_data[i].m_m_coefficient * pow(x, m_data[i].m_m_exponent);
        }
        return sum;
    }

    PolynomialRepresentation* operator+(PolynomialRepresentation &prObj1, PolynomialRepresentation &prObj2)
    {
        PolynomialRepresentation *temp = new PolynomialRepresentation(prObj1.m_num_terms + prObj2.m_num_terms);

        int i = 0;
        int j = 0;

        while (i < prObj1.m_num_terms or j < prObj2.m_num_terms)
        {
            if (prObj1.m_data[i].m_m_exponent < prObj2.m_data[j].m_m_exponent)
            {
                temp->Set(prObj2.m_data[j].m_m_coefficient, prObj2.m_data[j].m_m_exponent);
                j++;
            }
            else if (prObj1.m_data[i].m_m_exponent > prObj2.m_data[j].m_m_exponent)
            {
                temp->Set(prObj1.m_data[i].m_m_coefficient, prObj1.m_data[i].m_m_exponent);
                i++;
            }
            else
            {
                temp->Set(prObj1.m_data[i].m_m_coefficient + prObj2.m_data[j].m_m_coefficient, prObj1.m_data[i].m_m_exponent);
                i++;
                j++;
            }
        }

        while (i < prObj1.m_num_terms)
        {
            temp->Set(prObj1.m_data[i].m_m_coefficient, prObj1.m_data[i].m_m_exponent);
            i++;
        }

        while (j < prObj2.m_num_terms)
        {
            temp->Set(prObj2.m_data[j].m_m_coefficient, prObj2.m_data[j].m_m_exponent);
            j++;
        }
        return temp;
    }
} // namespace matrices
