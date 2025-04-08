# pragma once

namespace matrices
{
    class TridiagonalMatrix
    {
    private:
        int  m_size { 0 };
        int* m_data { nullptr };
    public:
        TridiagonalMatrix(int);
        ~TridiagonalMatrix();
        void Set(int, int, int);
        int Get(int, int);
        void Display();
    };
} // namespace matrices
