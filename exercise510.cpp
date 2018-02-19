#include <iostream>
#include <cmath>
#include <cassert>
// Module to solve the n x n linear system Au = b using Gaussian 
// elimination with pivoting

void SolveLinearSystem(double** A, double* B, double* C, int size);
void SwapRows(double** A, double* B, int size, int row1, int row2);
int  GetMaximumValue(double** A, int row, int size);
void GenerateSwap(double** A, int size, int row1, int row2);
void ReduceRows(double** A, double* B, int size, int rowNumber);
void Multiply(double** A, double** B, double**C, 
              int rowsA, int colsA, int rowsB, int colsB);
void Multiply(double** A, double* B, double* C, 
              int rowsA, int colsA, int rowsB);
void PrintMatrix(double**A, int size);
void PrintVector(double* A, int size);

int main(int argc, char* argv[])
{
    // Test on a 4X4 matrix
    double** test = new double* [4];
    for(int i=0; i<4; i++)
    {
        test[i] = new double[4];
    }
    // Set up values
    test[0][0] = 1.0;
    test[0][1] = -4.0;
    test[0][2] = 4.0;
    test[0][3] = 7.0;
    test[1][0] = 0.0;
    test[1][1] = 2.0;
    test[1][2] = -1.0;
    test[1][3] = 0.0;
    test[2][0] = 2.0;
    test[2][1] = 1.0;
    test[2][2] = 1.0;
    test[2][3] = 4.0;
    test[3][0] = 2.0;
    test[3][1] = -3.0;
    test[3][2] = 2.0;
    test[3][3] = -5.0;
    
    std::cout << "Test matrix is : \n";
    PrintMatrix(test, 4);
    
    double* u = new double[4];
    u[0] = 4.0;
    u[1] = 5.0;
    u[2] = 2.0;
    u[3] = 9.0;
    
    double* answer = new double[4];
    SolveLinearSystem(test, u, answer, 4);
    
    std::cout << "The solution is: " << "\n";
    PrintVector(answer, 4);
    
    // Tidy up
    for(int i=0; i<4; i++)
    {
        delete[] test[i];
    }
    delete[] test;
    delete[] u;
    delete[] answer;
    
    return 0;
}

void SolveLinearSystem(double** A, double* B, double* C, int size)
{
    for(int i=0; i<size -1; i++)
    {
        // Loop through all the rows of the matrix
        // Determine the largest value in position A[n][i]
        int linetoswap = GetMaximumValue(A, i, size); 
        if (linetoswap != i)
        {
            std::cout << "Swap lines " << i << " and " << linetoswap << "\n";
            SwapRows(A, B, size, i, linetoswap);
        }
        std::cout << "Check after swapping\n";
        PrintMatrix(A, size);
        PrintVector(B, size);
        ReduceRows(A, B, size, i);

    }
    std::cout << "After Gaussian elimination \n" ;
    PrintMatrix(A, size);
    PrintVector(B, size);
    
    // Now do back substitution.  Can easily get last value
    C[size-1] = B[size-1] / A[size-1][size-1];
    // Now go backwards through each row 
    for(int i=size - 2; i >= 0; i--)
    {
        double ax = 0.0;
        for(int j=i+1; j<size; j++)
        {
            ax += A[i][j] * C[j];
            
        }
        C[i] = 1.0 / A[i][i] * (B[i] - ax);
    } 
}

void SwapRows(double** A, double* B, int size, int row1, int row2)
{
    // Generate the matrix that will be used to swap the rows
    double** swap = new double* [size];
    double** tempA = new double* [size];
    for(int i=0; i<size; i++)
    {
        swap[i] = new double[size];
        tempA[i] = new double[size];
    }
    GenerateSwap(swap, size, row1, row2);
    double* tempU = new double[size];
    
    // Multiply the swap matrix with matrix and vector
    Multiply(swap, A, tempA, size, size, size, size);
    Multiply(swap, B, tempU, size, size, size);
    
    PrintMatrix(tempA, size);
    
    // Copy the temp values back to tne matrix and vector
    for(int i=0; i<size;i++)
    {
        for(int j=0; j<size;j++)
        {
            A[i][j] = tempA[i][j];
        }
        B[i] = tempU[i];
    }
    // Tidy up
    for(int i=0; i<size; i++)
    {
        delete[] swap[i];
        delete[] tempA[i];
    }
    delete[] swap;
    delete[] tempA;
    delete[] tempU;
}

int GetMaximumValue(double** A, int row, int size)
{
    int rowNumber;
    double largest = 0.0;
    for(int i=row; i<size; i++)
    {
        if(fabs(A[i][row]) > largest)
        {
            largest = fabs(A[i][row]);
            rowNumber = i; 
        }
    }
    std::cout << "Largest number is: " << largest << "\n";
    return rowNumber;
}

void GenerateSwap(double** A, int size, int row1, int row2)
{
    for(int i=0;i<size; i++)
    {
        for(int j=0; j<size; j++)
        {
            if(i==j && (i != row1 && j != row1) && (i != row2 && j != row2))
            {
                A[i][j] = 1;
            }
            else if(i == row1 && j == row2)
            {
                A[i][j] = 1;
            }
            else if(i== row2 && j == row1)
            {
                A[i][j] = 1;
            } 
            else
            {
                A[i][j] = 0;
            }
        }
    }
    PrintMatrix(A, size);
}

void ReduceRows(double** A, double* B, int size, int rowNumber)
{
    for(int i=rowNumber + 1; i<size; i++)
    {
        std::cout << "Here with  - " << A[i][rowNumber] << " and " << A[rowNumber][rowNumber] << "\n";
        double m = A[i][rowNumber] / A[rowNumber][rowNumber];
        std::cout << "Row = " << rowNumber << " top = " << A[i][rowNumber] << " bottom = " << A[rowNumber][rowNumber] << "\n";
        std::cout << "Value of m is: " << m << "\n";
        for(int j=0; j< size; j++)
        {
            if(j< rowNumber)
            {
                A[i][j] = 0;
            }
            else
            {
                A[i][j] = A[i][j] - m * A[rowNumber][j];
            }
        }
        B[i] = B[i] - m * B[rowNumber];
    }
    std::cout << "Matrix after reduce rows \n";
    PrintMatrix(A, size); 
    std::cout << "Vector after reduce rows \n";
    PrintVector(B, size);
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

void Multiply(double** A, double* B, double* C,
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

void PrintMatrix(double** A, int size)
{
    for(int i=0; i<size; i++)
    {
        for(int j=0; j<size; j++)
        {
            std::cout << A[i][j] << "  ";
        }
        std::cout << "\n";
    }
}

void PrintVector(double* A, int size)
{
    for(int i=0; i<size; i++)
    {
        std::cout << A[i] << "\n";
    }
}
