#pragma once

#include <map>
#include <string>
#include <optional>
#include <iostream>
#include "LowerTriangularMatrix.h"
#include "UpperTriangularMatrix.h"
#include "DiagonalMatrix.h"
#include "TridiagonalMatrix.h"
#include "ToeplitzMatrix.h"
#include "SparseMatrix.h"
#include "PolynomialRepresentation.h"

namespace matrices
{
    class MatricesMain
    {
    private:
        enum m_MatricesMainMenu
        {
            MIN_COUNT                 = 0,
            LOWER_TRIANGULAR_MATRIX   = 1,
            UPPER_TRIANGULAR_MATRIX   = 2,
            DIAGONAL_MATRIX           = 3,
            TRIDIAGONAL_MATRIX        = 4,
            TOEPLITZ_MATRIX           = 5,
            SPARSE_MATRIX             = 6,
            SPARSE_MATRIX_ADDITION    = 7,
            POLYNOMIAL_REPRESENTATION = 8,
            POLYNOMIAL_EVALUATION     = 9,
            POLYNOMIAL_ADDITION       = 10,
            BACK_TO_PREVIOUS_MENU     = 11,
            EXIT_FROM_PROGRAM         = 12,
            MAX_COUNT                 = EXIT_FROM_PROGRAM
        };
        int                        m_choice              { 0 };
        std::map<int, std::string> m_matricesMainMenuMap {};

    public:
        MatricesMain();
        const int  GetMinCase();
        const int  GetMaxCase();
        const int& GetChoice();
        void       GetChoiceInputFromUser();
        void	   PrintMenu();
        void       PrintSelectedChoice();
        void       LowerTriangularMatrix();
        void       UpperTriangularMatrix();
        void       DiagonalMatrix();
        void       TridiagonalMatrix();
        void       ToeplitzMatrix();
        void       SparseMatrix();
        void       SparseMatrixAddition();
        void       PolynomialRepresentation();
        void       PolynomialEvaluation();
        void       PolynomialAddition();
    };
} // namespace matrices
