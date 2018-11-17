#ifndef SQUAREMATRIXHEADER
#define SQUAREMATRIXHEADER

#include <iostream>

class SquareMatrix
{
private:
    double mMatrix[2][2];
public:    
    SquareMatrix();
    SquareMatrix(const SquareMatrix& A);
    SquareMatrix(double first, double second, double third, double forth);
    double Det() const;
    SquareMatrix InverseMatrix() const;
    SquareMatrix& operator=(const SquareMatrix& A);
    SquareMatrix operator-() const;
    SquareMatrix operator+(const SquareMatrix& A) const;
    SquareMatrix operator-(const SquareMatrix& A) const;
    void Multiple(double factor);
    void PrintMatrix() const;
};

#endif
