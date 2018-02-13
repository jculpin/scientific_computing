#include <iostream>
#include <cmath>
#include <cassert>
// Module to solve linear system Ax = b for 3X3 matrix A

double* SolveLinearSystem(double** A, double* u, int size);
void InverseMatrix(double** A, double** B, int size);
void CalculateAdjugate(double** A, int size);
void MatrixOfCofactors (double** A, int size);
void MatrixOfMinors (double** A, int size);
double CalculateDeterminant (double** A, int size);
void Multiply(double** A, double** B, double** C, 
              int rowsA, int colsA,
              int rowsB, int colsB);
void Multiply(double x,  double** A, double** B,
              int rowsA, int colsA);
void Multiply(double** A, double* B, double* C,
              int rowsA, int colsA, int rowsB);
void printMatrix(double** A, int size); 
void printVector(double* A, int size); 
                 
int main (int argc, char* argv[])
{
    //  Test on a 3X3 matrix
    double** X = new double* [3];
    for(int loop=0; loop < 3; loop++)
    {
        X[loop] = new double[3];
    }
    // Set up the matrix values
    X[0][0] = 2;
    X[0][1] = 1;
    X[0][2] = 3;
    X[1][0] = 2;
    X[1][1] = -1;
    X[1][2] = 1;
    X[2][0] = 5;
    X[2][1] = -4;
    X[2][2] = -6;
    // Create a vector and set the values
    double* u = new double [3];
    u[0] = 7.0;
    u[1] = -3.0;
    u[2] = 10.0;
    
    std::cout << "Matrix X: \n";
    printMatrix(X, 3);
    
    // Now solve the system
    // Create a new matrix to store the answer
    double* answer;
    answer = SolveLinearSystem(X, u, 3);
    
    std::cout << "The answer is: \n";
    printVector(answer, 3);
    
    // Tidy up
    // delete vectors u and answer
    delete[] u;
    delete[] answer;
    
    for(int i=0; i<3; i++)
    {
        delete[] X[i];
    }
    delete[] X;
        
    return 0;
}

double* SolveLinearSystem(double** A, double* u, int size)
{
    double** solve = new double* [3];
    for(int loop=0; loop < 3; loop++)
    {
        solve[loop] = new double[3];
    }
    
    InverseMatrix(A, solve, size);
    std::cout << "Solve matrix is \n";
    printMatrix(solve,3);
    double* answer = new double[size];
    Multiply(solve, u, answer, 3, 3, 3);
    
    for(int i=0; i<size; i++)
    {
        delete[] solve[i];
    }
    delete[] solve;
    
    return answer;
}                 

void InverseMatrix(double** A, double** B, int size)
{
    // Calculate the inverse of a matrix of given size
    double det = CalculateDeterminant(A, size);
    double** temp = new double* [3];
    for(int loop=0; loop < 3; loop++)
    {
        temp[loop] = new double[3];
    }
    // Copy values from A to temp
    for(int i=0; i<size;i++)
    {
        for(int j=0; j<size;j++)
        {
            temp[i][j] = A[i][j];
        }
    }

    MatrixOfMinors(temp, size);
    std::cout << "Matrix of Minors is:\n";
    printMatrix(temp, 3);
    MatrixOfCofactors(temp, size);
    std::cout << "Matrix of Cofactors is:\n";
    printMatrix(temp, 3);
    CalculateAdjugate(temp, size);
    std::cout << "Adjugate is:\n";
    printMatrix(temp, 3);
    Multiply(1.0 / det, temp, B, size, size);
    std::cout << "Inverse is \n";
    printMatrix(B,3); 
    
    // tidy up
    for(int loop=0; loop < size; loop++)
    {
        delete[] temp[loop];
    }
    delete[] temp;
}

void CalculateAdjugate(double** A, int size)
{
    // Calculate the adjugate i.e the transpose
    double** Adj = new double* [size];
    for(int loop=0; loop < size; loop++)
    {
        Adj[loop] = new double[size];
    }    
    // Save a copy of A 
    for (int rows=0; rows < size; rows++)
    {
        for(int cols=0; cols < size; cols++)
        {
            Adj[rows][cols] = A[rows][cols];
        }
    }
    // Now swap rows and columns
    for (int rows=0; rows < size; rows++)
    {
        for(int cols=0; cols < size; cols++)
        {
            A[cols][rows] = Adj[rows][cols];
        }
    }
    
    // tidy up
    for(int i=0; i<size; i++)
    {
        delete[] Adj[i];
    }
    delete[] Adj;
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

void MatrixOfMinors (double** A, int size)
{
    // For each element of the matrix, ignore the values in the current 
    // row and column and calculate the determinant of the remaining
    // values
    double** MoM = new double* [size];
    for(int loop=0; loop < size; loop++)
    {
        MoM[loop] = new double[size];
    }    
    
    // Save a copy of the matrix A
    for(int i=0; i<size; i++)
    {
        for(int j=0; j<size; j++)
        {
            MoM[i][j] = A[i][j];
        }
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
                    Ahat[i][j] = MoM[rowElement][colElement];
                }
                A[rows][cols] = CalculateDeterminant(Ahat, size - 1); 
            }
        }
    }
    
    // Tidy up
    for(int i=0; i<size - 1; i++)
    {
        delete[] Ahat[i];
    }
    for(int i=0; i<size; i++)
    {
        delete[] MoM[i];
    }
    delete[] Ahat;
    delete[] MoM;
}

double CalculateDeterminant (double** A, int size)
{
    // Calculate the determinant using a recursive functiom
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
        // Tidy up
        for(int i=0; i<size - 1; i++)
        {
            delete[] Ahat[i];
        }
        delete[] Ahat;
    }
    
    return det;
}

void Multiply(double** A, double** B, double** C,
              int rowsA, int colsA,
              int rowsB, int colsB)
{
    // Multiply two matrices
    assert(colsA == rowsB);
         
    for(int i=0; i<rowsA; i++)
    {
        for(int j=0; j<colsB; j++)
        {
            C[i][j] = 0.0;
            for(int loop=0; loop<colsA; loop++)
            {
                C[i][j] += A[i][loop] * B[loop][j];
            }
        }            
    }
}
                  
void Multiply(double x, double** A, double** B, 
              int rowsA, int colsA)
{
    // Multiply a scalar by a matrix
    for(int i=0; i<rowsA; i++)
    {
        for(int j=0; j<colsA; j++)
        {
            B[i][j] = A[i][j] * x;
        }
    }
}

void Multiply(double** A, double*B, double* C,
              int rowsA, int colsA, int rowsB)
{
    // Multiply a matrix and a vector
    assert (colsA == rowsB);
    
    for(int i=0; i<rowsA; i++)
    {
        C[i] = 0.0;
        for(int loop=0; loop<colsA; loop++)
        {
            C[i] += A[i][loop] * B[loop];
        }
    }
}

void printMatrix(double** A, int size)
{
    // Print out a given matrix
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

void printVector(double* A, int size)
{
    // Print out a given vector
    for(int rows=0; rows<size; rows++)
    {
        std::cout << A[rows] << "\n";
    }
}
