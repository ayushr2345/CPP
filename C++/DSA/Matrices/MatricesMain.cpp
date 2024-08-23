#include <iostream>
#include <functional>
#include "MatricesMain.h"
#include "../../utils.h"

namespace matrices
{
    MatricesMain::MatricesMain():
        m_choice              ( 0 ),
        m_matricesMainMenuMap ( {} )
    {
        m_matricesMainMenuMap.insert({ m_MatricesMainMenu(LOWER_TRIANGULAR_MATRIX), 
                                     std::string("Lower Triangular Matrix") });
        m_matricesMainMenuMap.insert({ m_MatricesMainMenu(UPPER_TRIANGULAR_MATRIX), 
                                     std::string("Upper Triangular Matrix") });
        m_matricesMainMenuMap.insert({ m_MatricesMainMenu(DIAGONAL_MATRIX), 
                                     std::string("Diagonal Matrix") });
        m_matricesMainMenuMap.insert({ m_MatricesMainMenu(TRIDIAGONAL_MATRIX), 
                                     std::string("Tridiagonal Matrix") });
        m_matricesMainMenuMap.insert({ m_MatricesMainMenu(TOEPLITZ_MATRIX), 
                                     std::string("Toeplitz Matrix") });
        m_matricesMainMenuMap.insert({ m_MatricesMainMenu(SPARSE_MATRIX), 
                                     std::string("Sparse Matrix") });
        m_matricesMainMenuMap.insert({ m_MatricesMainMenu(SPARSE_MATRIX_ADDITION), 
                                     std::string("Sparse Matrix Addition") });
        m_matricesMainMenuMap.insert({ m_MatricesMainMenu(POLYNOMIAL_REPRESENTATION), 
                                     std::string("Polynomial Representation") });
        m_matricesMainMenuMap.insert({ m_MatricesMainMenu(POLYNOMIAL_EVALUATION), 
                                     std::string("Polynomial Evaluation") });
        m_matricesMainMenuMap.insert({ m_MatricesMainMenu(POLYNOMIAL_ADDITION), 
                                     std::string("Polynomial Addition") });
        m_matricesMainMenuMap.insert({ m_MatricesMainMenu(BACK_TO_PREVIOUS_MENU),
                                      std::string("Back to Previous Menu") });
        m_matricesMainMenuMap.insert({ m_MatricesMainMenu(EXIT_FROM_PROGRAM),
                                      std::string("Exit from program") });
    }

    const int MatricesMain::GetMinCase()
    {
        return m_MatricesMainMenu::MIN_COUNT;
    }

    const int MatricesMain::GetMaxCase()
    {
        return m_MatricesMainMenu::MAX_COUNT;
    }

    const int& MatricesMain::GetChoice()
    {
        return m_choice;
    }

    void MatricesMain::GetChoiceInputFromUser()
    {
        utils::InputNumberFromUser(m_choice, 1, static_cast<int>(m_MatricesMainMenu::MAX_COUNT));
    }

    void MatricesMain::PrintMenu()
    {
        std::cout << std::endl;
        for (std::map<int, std::string>::iterator it = m_matricesMainMenuMap.begin();
            it != m_matricesMainMenuMap.end();
            it++)
        {
            std::cout << it->first << ". " << it->second << std::endl;
        }
        std::cout << "Please enter your choice: ";
    }

    void MatricesMain::PrintSelectedChoice()
    {
        std::cout << std::endl << std::endl
                  << "You have chosen choice "
                  << m_matricesMainMenuMap.at(m_choice)
                  << std::endl;
    }

    void MatricesMain::LowerTriangularMatrix()
    {
        std::cout << "The matrix where only elements are present in the lower half of the matrix" << std::endl;

        int size;
        std::cout << "Please enter the size of the matrix: ";
        utils::InputNumberFromUser(size, 2, 10);

        matrices::LowerTriangularMatrix ltmObj(size);

        std::cout << "Please enter all the non-zero elements row by row: " << std::endl;

        int row, column, element;
        for (int i = 0; i < (size * (size + 1) / 2); i++)
        {
            utils::InputNumberFromUser(row, 1, size, 'n');
            utils::InputNumberFromUser(column, 1, size, 'n');
            utils::InputNumberFromUser(element, 1, 9, 'n');
            ltmObj.Set(row, column, element);
        }

        ltmObj.Display();
    }

    void MatricesMain::UpperTriangularMatrix()
    {
        std::cout << "The matrix where only elements are present in the upper half of the matrix" << std::endl;

        int size;
        std::cout << "Please enter the size of the matrix: ";
        utils::InputNumberFromUser(size, 2, 10);

        matrices::UpperTriangularMatrix utmObj(size);

        std::cout << "Please enter all the non-zero elements row by row: " << std::endl;

        int row, column, element;
        for (int i = 0; i < (size * (size + 1) / 2); i++)
        {
            utils::InputNumberFromUser(row, 1, size, 'n');
            utils::InputNumberFromUser(column, 1, size, 'n');
            utils::InputNumberFromUser(element, 1, 9, 'n');
            utmObj.Set(row, column, element);
        }

        utmObj.Display();
    }

    void MatricesMain::DiagonalMatrix()
    {
        std::cout << "The matrix where only elements are present in the diagonal of the matrix" << std::endl;

        int size;
        std::cout << "Please enter the size of the matrix: ";
        utils::InputNumberFromUser(size, 2, 10);

        matrices::DiagonalMatrix dmObj(size);

        std::cout << "Please enter all the non-zero elements row by row: " << std::endl;

        int row, column, element;
        for (int i = 0; i < size; i++)
        {
            utils::InputNumberFromUser(row, 1, size, 'n');
            utils::InputNumberFromUser(column, 1, size, 'n');
            utils::InputNumberFromUser(element, 1, 9, 'n');
            dmObj.Set(row, column, element);
        }

        dmObj.Display();
    }

    void MatricesMain::TridiagonalMatrix()
    {
        std::cout << "The matrix where only elements are present in the main, upper and lower diagonal of the matrix" << std::endl;

        int size;
        std::cout << "Please enter the size of the matrix: ";
        utils::InputNumberFromUser(size, 2, 10);

        matrices::TridiagonalMatrix tdmObj(size);

        std::cout << "Please enter all the non-zero elements row by row: " << std::endl;

        int row, column, element;
        for (int i = 0; i < (3 * size - 2); i++)
        {
            utils::InputNumberFromUser(row, 1, size, 'n');
            utils::InputNumberFromUser(column, 1, size, 'n');
            utils::InputNumberFromUser(element, 1, 9, 'n');
            tdmObj.Set(row, column, element);
        }

        tdmObj.Display();
    }

    void MatricesMain::ToeplitzMatrix()
    {
        std::cout << "The matrix where M[I, J] = M[I - 1, J - 1]" << std::endl;

        int size;
        std::cout << "Please enter the size of the matrix: ";
        utils::InputNumberFromUser(size, 2, 10);

        matrices::ToeplitzMatrix tmObj(size);

        std::cout << "Please enter all the non-zero elements row by row: " << std::endl;

        int row, column, element;
        for (int i = 0; i < (2 * size - 1); i++)
        {
            utils::InputNumberFromUser(row, 1, size, 'n');
            utils::InputNumberFromUser(column, 1, size, 'n');
            utils::InputNumberFromUser(element, 1, 9, 'n');
            tmObj.Set(row, column, element);
        }

        tmObj.Display();
    }

    void MatricesMain::SparseMatrix()
    {
        std::cout << "The matrix non-zero elements are very less than number of zero elements" << std::endl;

        int numRows    = { 0 };
        int numColumns = { 0 };
        int numNonZero = { 0 };
        std::cout << "Please enter the number of rows in the matrix: ";
        utils::InputNumberFromUser(numRows, 2, 10);

        std::cout << "Please enter number of columns in the matrix: ";
        utils::InputNumberFromUser(numColumns, 2, 10);

        std::cout << "Please enter the number of non-zero elements in the matrix: ";
        utils::InputNumberFromUser(numNonZero, 2, numRows * numColumns);

        matrices::SparseMatrix smObj(numRows, numColumns, numNonZero);

        std::cout << "Please enter all the non-zero elements row by row: " << std::endl;

        int row, column, element;
        for (int i = 0; i < numNonZero; i++)
        {
            utils::InputNumberFromUser(row, 1, numRows, 'n');
            utils::InputNumberFromUser(column, 1, numColumns, 'n');
            utils::InputNumberFromUser(element, 1, 9, 'n');
            smObj.Set(row, column, element);
        }

        smObj.Display();
    }

    void MatricesMain::SparseMatrixAddition()
    {
        int numRows    = { 0 };
        int numColumns = { 0 };
        int numNonZero = { 0 };
        std::cout << "Please enter the number of rows in the matrix: ";
        utils::InputNumberFromUser(numRows, 2, 10);

        std::cout << "Please enter number of columns in the matrix: ";
        utils::InputNumberFromUser(numColumns, 2, 10);

        std::cout << "Please enter the number of non-zero elements in the matrix: ";
        utils::InputNumberFromUser(numNonZero, 2, numRows * numColumns);

        matrices::SparseMatrix smObj1(numRows, numColumns, numNonZero);

        std::cout << "Please enter all the non-zero elements row by row: " << std::endl;

        int row, column, element;
        for (int i = 0; i < numNonZero; i++)
        {
            utils::InputNumberFromUser(row, 1, numRows, 'n');
            utils::InputNumberFromUser(column, 1, numColumns, 'n');
            utils::InputNumberFromUser(element, 1, 9, 'n');
            smObj1.Set(row, column, element);
        }

        matrices::SparseMatrix smObj2(numRows, numColumns, numNonZero);
        smObj2.Set(1, 2, 1);
        smObj2.Set(1, 3, 5);
        smObj2.Set(2, 3, 5);
        smObj2.Set(3, 2, 1);
        smObj2.Set(4, 2, 1);

        smObj1.Display();
        std::cout << std::endl;

        smObj2.Display();
        std::cout << std::endl;

        matrices::SparseMatrix *temp = smObj1 + smObj2;
        temp->Display();

        delete temp;
    }

    void MatricesMain::PolynomialRepresentation()
    {
        std::cout << "Polynomials can be represented by storing the number of terms and their respective coefficients and exponents" << std::endl;

        int numTerms = 0;
        std::cout << "Enter the number of terms for the polynomial: ";
        utils::InputNumberFromUser(numTerms, 1, 10);

        matrices::PolynomialRepresentation prObj(numTerms);

        std::cout << "Please enter the coefficients and exponents in descending order: " << std::endl;

        int coefficient = 0;
        int exponent    = 0;
        for (int i = 0; i < numTerms; i++)
        {
            utils::InputNumberFromUser(coefficient, 0, 10, 'n');
            utils::InputNumberFromUser(exponent, 0, 10, 'n');
            prObj.Set(coefficient, exponent);
        }

        prObj.Display();
    }

    void MatricesMain::PolynomialEvaluation()
    {
        int numTerms = 0;
        std::cout << "Enter the number of terms for the polynomial: ";
        utils::InputNumberFromUser(numTerms, 1, 10);

        matrices::PolynomialRepresentation prObj(numTerms);

        std::cout << "Please enter the coefficients and exponents in descending order: " << std::endl;

        int coefficient = 0;
        int exponent    = 0;
        for (int i = 0; i < numTerms; i++)
        {
            utils::InputNumberFromUser(coefficient, 0, 10, 'n');
            utils::InputNumberFromUser(exponent, 0, 10, 'n');
            prObj.Set(coefficient, exponent);
        }
        
        int x = 0;
        std::cout << "Please enter the value of x: ";
        utils::InputNumberFromUser(x, 1, 10);

        prObj.Display();
        double result = prObj.Evaluate(x);

        std::cout << "The result of the evaluation is: " << result << std::endl;
    }

    void MatricesMain::PolynomialAddition()
    {
        int numTerms = 0;
        std::cout << "Enter the number of terms for the polynomial 1: ";
        utils::InputNumberFromUser(numTerms, 1, 10);

        matrices::PolynomialRepresentation prObj1(numTerms);

        std::cout << "Please enter the coefficients and exponents in descending order: " << std::endl;

        int coefficient = 0;
        int exponent    = 0;
        for (int i = 0; i < numTerms; i++)
        {
            utils::InputNumberFromUser(coefficient, 0, 10, 'n');
            utils::InputNumberFromUser(exponent, 0, 10, 'n');
            prObj1.Set(coefficient, exponent);
        }
        
        prObj1.Display();


        std::cout << "Enter the number of terms for the polynomial 2: ";
        utils::InputNumberFromUser(numTerms, 1, 10);

        matrices::PolynomialRepresentation prObj2(numTerms);

        std::cout << "Please enter the coefficients and exponents in descending order: " << std::endl;

        for (int i = 0; i < numTerms; i++)
        {
            utils::InputNumberFromUser(coefficient, 0, 10, 'n');
            utils::InputNumberFromUser(exponent, 0, 10, 'n');
            prObj2.Set(coefficient, exponent);
        }
        
        prObj2.Display();

        matrices::PolynomialRepresentation* temp = prObj1 + prObj2;
        temp->Display();
        delete temp;
    }
} // namespace matrices
