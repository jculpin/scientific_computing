#include <iostream>
#include <cmath>
#include <cassert>
// Module to solve linear system Ax = b for 3X3 matrix A

double CalculateDeterminant (double** A, int size);
double** MatrixOfMinors (double** A, int size);
void MatrixOfCofactors (double** A, int size);
double** CalculateAdjugate(double** A, int size);
double** InverseMatrix(double** A, int size);
double** Multiply(double x,  double** A, int rowsA, int colsA);
// Multiply two matrices
double** Multiply(double** A, double** B, 
                  int rowsA, int colsA,
                  int rowsB, int colsB);
void printMatrix(double** A, int size); 
                 
double** Multiply(double** A, double** B,
                  int rowsA, int colsA,
                  int rowsB, int colsB)
{
    assert(colsA == rowsB);
     
    double** mult = new double* [colsA];
    for(int i=0; i<rowsA; i++)
    {
        mult[i] = new double[colsB];
    }
    
    for(int i=0; i<rowsA; i++)
    {
        for(int j=0; j<colsB; j++)
        {
            {
                mult[i][j] = 0.0;
                for(int loop=0; loop<colsA; loop++)
                {
                    mult[i][j] += A[i][loop] * B[loop][j];
                }
            }
        }            
    }
    return mult;
                     
}
                  
double** Multiply(double x, double** A, int rowsA, int colsA)
{

    double** mult = new double* [rowsA];
    for(int i=0; i<rowsA; i++)
    {
        mult[i] = new double[colsA];
    }
    
    for(int i=0; i<rowsA; i++)
    {
        for(int j=0; j<colsA; j++)
        {
            mult[i][j] = A[i][j] * x;
        }
    }
    
    return mult;
}

double** InverseMatrix(double** A, int size)
{
    double** Inv = new double* [size];
    for(int loop=0; loop < size; loop++)
    {
        Inv[loop] = new double[size];
    }    

    Inv = MatrixOfMinors(A, size);
    printMatrix(Inv, 3);
    MatrixOfCofactors(Inv, size);
    printMatrix(Inv, 3);
    Inv = CalculateAdjugate(Inv, size);
    printMatrix(Inv, 3);
    double det = CalculateDeterminant(A, size);
    Inv = Multiply(1.0 / det, Inv, size, size);
     
    return Inv;
}

double** CalculateAdjugate(double** A, int size)
{
    double** Adj = new double* [size];
    for(int loop=0; loop < size; loop++)
    {
        Adj[loop] = new double[size];
    }    

    for (int rows=0; rows < size; rows++)
    {
        for(int cols=0; cols < size; cols++)
        {
            Adj[rows][cols] = A[cols][rows];
        }
    }
    
    return Adj;
}

void MatrixOfCofactors(double** A, int size)
{
    // Change the signs on alternate cells
    for(int rows=0; rows<size; rows++)
    {
        for(int cols=0; cols<size; cols++)
        {
            A[rows][cols] = pow(-1, cols) * pow(-1, rows) * A[rows][cols];            
        }
    }
}

double** MatrixOfMinors (double** A, int size)
{
    double** MoM = new double* [size];
    for(int loop=0; loop < size; loop++)
    {
        MoM[loop] = new double[size];
    }    
    
    double** Ahat = new double* [size - 1];
    for(int loop=0; loop < size -1; loop++)
    {
        Ahat[loop] = new double[size - 1];
    }
        
    for(int rows=0; rows < size; rows++)
    {
        for(int cols=0; cols< size; cols++)
        {
            // need to set values in Ahat determinant
            for(int i=0; i < size - 1; i++)
            {
                for(int j=0; j < size - 1 ; j++)
                {
                    int colElement = 0;
                    int rowElement = 0;
                    if(i < rows) rowElement = i;
                    if(i >= rows) rowElement = i + 1;
                    if(j < cols) colElement = j;
                    if(j >= cols) colElement = j + 1; 
                    Ahat[i][j] = A[rowElement][colElement];
                }
                MoM[rows][cols] = CalculateDeterminant(Ahat, size - 1); 
            }
        }
    }
        
    return MoM;
}

double CalculateDeterminant (double** A, int size)
{
    double det = 0;
    if(size == 1)
    {
        det = A[0][0];
    }
    else 
    {
        double** Ahat = new double* [size - 1];
        for(int loop=0; loop < size -1; loop++)
        {
            Ahat[loop] = new double[size - 1];
        }
        
        for(int loop=0; loop< size; loop++)
        {
            // need to set values in Ahat determinant
            for(int i=0; i < size - 1; i++)
            {
                for(int j=0; j < size - 1 ; j++)
                {
                    int rowElement = 0;
                    if(j < loop) rowElement = j;
                    if(j >= loop) rowElement = j + 1; 
                    Ahat[i][j] = A[i+1][rowElement];
                }
            }
            // now calculate the determinant value
            det += pow(-1, loop) * A[0][loop] * CalculateDeterminant(Ahat, size - 1);
        }
    }
    return det;
}

int main (int argc, char* argv[])
{
    //  Test on a 3X3 matrix
    double** X = new double* [3];
    for(int loop=0; loop < 3; loop++)
    {
        X[loop] = new double[3];
    }
    X[0][0] = 2;
    X[0][1] = 1;
    X[0][2] = 3;
    X[1][0] = 2;
    X[1][1] = -1;
    X[1][2] = 1;
    X[2][0] = 5;
    X[2][1] = -4;
    X[2][2] = -6;
    
    std::cout << "Determinant X = \n";
    for(int i = 0; i<3; i++)
    {
        for(int j = 0; j< 3; j++)
        {
            std::cout << X[i][j] << " " ;
        }
        std::cout << "\n";
    }
    
    double** Xinv = new double* [3];
    for(int loop=0; loop < 3; loop++)
    {
        Xinv[loop] = new double[3];
    }
    Xinv = InverseMatrix(X, 3);
    std::cout << "Inverse = \n";
    for(int i = 0; i<3; i++)
    {
        for(int j = 0; j< 3; j++)
        {
            std::cout << Xinv[i][j] << " " ;
        }
        std::cout << "\n";
    }
    
    double** test = new double* [3];
    for(int loop=0; loop < 3; loop++)
    {
        test[loop] = new double[3];
    }
    test = Multiply(X, Xinv, 3, 3, 3, 3);
    std::cout << "Check = " << "\n";
    for(int i = 0; i<3; i++)
    {
        for(int j = 0; j< 3; j++)
        {
            std::cout << test[i][j] << " " ;
        }
        std::cout << "\n";
    }

    return 0;
}

void printMatrix(double** A, int size)
{
    std::cout << "The matrix is \n";
    for(int rows=0; rows < size; rows++)
    {
        for(int cols=0; cols < size; cols++)
        {
            std::cout << A[rows][cols] << "  ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}
