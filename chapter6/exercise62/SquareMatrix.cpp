#include "SquareMatrix.hpp"
#include <cassert>

// Override default constructor
// Set all elements to zero
SquareMatrix::SquareMatrix()
{
    for(int i =0; i<2; i++)
    {
        for(int j=0; j<2; j++)
        {
            mMatrix[i][j] = 0.0;
        }
    }
}

// Copy constructor
SquareMatrix::SquareMatrix(const SquareMatrix& A)
{
    for(int i =0; i<2; i++)
    {
        for(int j=0; j<2; j++)
        {
            mMatrix[i][j] = A.mMatrix[i][j];
        }
    }
}

// Constructor that accepts four entries 
SquareMatrix::SquareMatrix(double first, double second, 
                           double third, double forth)
{
    mMatrix[0][0] = first;
    mMatrix[0][1] = second;
    mMatrix[1][0] = third;
    mMatrix[1][1] = forth;
}
    
// Return the determinant
double SquareMatrix::Det() const
{
    double calc = mMatrix[0][0] * mMatrix[1][1] - mMatrix[0][1] * mMatrix[1][0];
    
    return calc;
}

// Return the inverse of a mtrix
SquareMatrix SquareMatrix::InverseMatrix() const
{
    assert(Det() != 0);
    double first, second, third, forth;
    double determ = Det();
    
    first = (1.0 / determ) * mMatrix[1][1];
    second = -(1.0 / determ) * mMatrix[1][0];
    third = -(1.0 / determ) * mMatrix[0][1];
    forth = (1.0 / determ) * mMatrix[0][0]; 
    
    SquareMatrix Inv(first, second, third, forth);
    
    return Inv;
}

// Overload the assignment operator = 
SquareMatrix& SquareMatrix::operator=(const SquareMatrix& A) 
{
    for(int i=0; i<2; i++)
    {
        for(int j=0; j<2; j++)
        {
            mMatrix[i][j] = A.mMatrix[i][j];
        }
    }
    return *this;
}

// Overloading the unary - operator
SquareMatrix SquareMatrix::operator-() const
{
    SquareMatrix neg(-mMatrix[0][0], -mMatrix[0][1], -mMatrix[1][0], -mMatrix[1][1]);

    return neg;
}

// Overloading the binary + operator
SquareMatrix SquareMatrix::operator+(const SquareMatrix& A) const
{
    SquareMatrix sum(mMatrix[0][0] + A.mMatrix[0][0],
                     mMatrix[0][1] + A.mMatrix[0][1],
                     mMatrix[1][0] + A.mMatrix[1][0],
                     mMatrix[1][1] + A.mMatrix[1][1]);

    return sum;
}

// Overloading the binary - operator
SquareMatrix SquareMatrix::operator-(const SquareMatrix& A) const
{
    SquareMatrix diff(mMatrix[0][0] - A.mMatrix[0][0],
                      mMatrix[0][1] - A.mMatrix[0][1],
                      mMatrix[1][0] - A.mMatrix[1][0],
                      mMatrix[1][1] - A.mMatrix[1][1]);
    return diff;
}

//  Multiply a matrix by the specified variable
void SquareMatrix::Multiple(double factor) 
{
    for(int i=0; i<2; i++)
    {
        for(int j=0; j<2; j++)
        {
            mMatrix[i][j] = factor * mMatrix[i][j];
        }
    }
}

void SquareMatrix::PrintMatrix() const
{
    for(int i=0; i<2; i++)
    {
        for(int j=0; j<2; j++)
        {
            std::cout<< mMatrix[i][j] << "   ";
        }
        std::cout << "\n";
    }
}
