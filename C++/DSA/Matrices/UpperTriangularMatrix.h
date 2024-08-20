# pragma once

namespace matrices
{
    class UpperTriangularMatrix
    {
    private:
        int  m_size { 0 };
        int* m_data { nullptr };
    public:
        UpperTriangularMatrix(int);
        ~UpperTriangularMatrix();
        void Set(int, int, int);
        int Get(int, int);
        void Display();
    };
} // namespace matrices
