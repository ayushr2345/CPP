# pragma once

namespace matrices
{
    class PolynomialRepresentation
    {
    private:
        class Term
        {
        public:
            int m_m_coefficient { 0 };
            int m_m_exponent    { 0 };
        };
        int   m_num_terms { 0 };
        int   m_data_idx  { 0 };
        Term* m_data      { nullptr };
    public:
        PolynomialRepresentation(int);
        ~PolynomialRepresentation();
        void   Set(int, int);
        void   Display();
        double Evaluate(int);
        friend PolynomialRepresentation* operator+(PolynomialRepresentation&, PolynomialRepresentation&);
    };
} // namespace matrices
