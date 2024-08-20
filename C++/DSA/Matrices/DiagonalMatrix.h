# pragma once

namespace matrices
{
    class DiagonalMatrix
    {
    private:
        int  m_size { 0 };
        int* m_data { nullptr };
    public:
        DiagonalMatrix(int);
        ~DiagonalMatrix();
        void Set(int, int, int);
        int Get(int, int);
        void Display();
    };
} // namespace matrices
