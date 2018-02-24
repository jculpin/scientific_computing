#include "SquareMatrix.hpp"

int main(int argc, char* argv[])
{
    SquareMatrix newMatrix(2.0, -3.0, 1.0, 5.0);
    
    newMatrix.PrintMatrix();
    
    SquareMatrix neg = -newMatrix;
    
    neg.PrintMatrix();
    
    SquareMatrix copy(newMatrix);
    
    copy.PrintMatrix();
    
    double d1 = copy.Det();
    
    std::cout << "Determinant = " << d1 << "\n";
    
    SquareMatrix inv = copy.InverseMatrix();
    std::cout << "Inverse of copy matrix is " << "\n";
    inv.PrintMatrix();
    
    neg = copy;
    neg.PrintMatrix();
    
    neg.Multiple(-6);
    neg.PrintMatrix();
    
    SquareMatrix summ = newMatrix + neg;
    summ.PrintMatrix();
    
    summ = newMatrix - neg;
    summ.PrintMatrix();
    
    SquareMatrix zero;
    zero.PrintMatrix();
    
    return 0;
}
