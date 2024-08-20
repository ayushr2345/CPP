# pragma once

namespace matrices
{
    class ToeplitzMatrix
    {
    private:
        int  m_size { 0 };
        int* m_data { nullptr };
    public:
        ToeplitzMatrix(int);
        ~ToeplitzMatrix();
        void Set(int, int, int);
        int Get(int, int);
        void Display();
    };
} // namespace matrices
