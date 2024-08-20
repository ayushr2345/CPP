# pragma once

namespace matrices
{
    class LowerTriangularMatrix
    {
    private:
        int  m_size { 0 };
        int* m_data { nullptr };
    public:
        LowerTriangularMatrix(int);
        ~LowerTriangularMatrix();
        void Set(int, int, int);
        int Get(int, int);
        void Display();
    };
} // namespace matrices
