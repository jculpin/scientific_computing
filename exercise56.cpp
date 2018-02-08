#include <iostream>
#include <cassert>

// Multiply two matrices
double** Multiply(double** A, double** B, 
                  int rowsA, int colsA,
                  int rowsB, int colsB);

//Multiply a vector and a matrix
double* Multiply(double* A, double**B,
                int colsA, int rowsB, int colsB);
                                
// Multiply a matrix and a vector
double* Multiply(double** A, double*B,
                int rowsA, int colsA, int rowsB);
                                
// Multiply a scalar and a matrix
double** Multiply(double x,  double** A, int rowsA, int colsA);

// Multiply a matrix and a scalar
double** Multiply(double** A, double x, int rowsA, int colsA);
                                
int main(int argc, char* argv[])
{
    // test function on a 3X3 matrix
    double** X = new double* [3];
    double** Y = new double* [3];
    for(int i=0; i<3; i++)
    {
        X[i] = new double[3];
        Y[i] = new double[3];
    }
    
    X[0][0] = 1.0;
    X[0][1] = 2.0;
    X[0][2] = 3.0;
    X[1][0] = 3.0;
    X[1][1] = 2.0;
    X[1][2] = 1.0;
    X[2][0] = 2.0;
    X[2][1] = 1.0;
    X[2][2] = 3.0;
    Y[0][0] = 4.0;
    Y[0][1] = 6.0;
    Y[0][2] = 1.0;
    Y[1][0] = 7.0;
    Y[1][1] = 4.0;
    Y[1][2] = 2.0;
    Y[2][0] = 3.0;
    Y[2][1] = 8.0;
    Y[2][2] = 4.0;
        
    double** answ = Multiply(X, Y, 3, 3, 3, 3);
    
    std::cout << "X multiplied by Y gives\n";
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            std::cout << answ[i][j] << "  " ;
        }
        std::cout << "\n";
    }
        
    // Test multiplication of vector and matrix
    double* A = new double[3];
    A[0] = 2.0;
    A[1] = 4.0;
    A[2] = 10.0;
    
    double* answ2 = Multiply(A, X, 3, 3, 3);
    std::cout << "\n" << "A multiplied by X gives\n"; 
    for(int i=0; i<3; i++)
    {
        std::cout << answ2[i] << "  " ;
    }
    std::cout << "\n";
 
    // Test multiplication of matrix and vector
    double* answ3 = Multiply(X, A, 3, 3, 3);
    std::cout << "\n" << "X multiplied by A gives\n"; 
    for(int i=0; i<3; i++)
    {
        std::cout << answ3[i] << "  " ;
    }
    std::cout << "\n";

    // Test multiplication of scalar and matrix
    double** answ4 = Multiply(X, 2.0, 3, 3);
    std::cout << "\nX multiplied by 2.0 gives\n";
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            std::cout << answ4[i][j] << "  " ;
        }
        std::cout << "\n";
    }
    
    // Test multiplication of matrix and scalar
    double** answ5 = Multiply(Y, 3.0, 3, 3);
    std::cout << "\n3.0 multiplied by Y gives\n";
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            std::cout << answ5[i][j] << "  " ;
        }
        std::cout << "\n";
    }
    
    return 0;
}

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

double* Multiply(double* A, double**B,
                int colsA, int rowsB, int colsB)
{
    assert (colsA == rowsB);
    
    double* mult = new double[colsB];
    for(int i=0; i<colsB; i++)
    {
        mult[i] = 0.0;
        for(int loop=0; loop<colsA; loop++)
        {
            mult[i] += A[loop] * B[loop][i];
        }
    }
    
    return mult;
}

double* Multiply(double** A, double*B,
                int rowsA, int colsA, int rowsB)
{
    assert (colsA == rowsB);
    
    double* mult = new double[rowsB];
    for(int i=0; i<rowsA; i++)
    {
        mult[i] = 0.0;
        for(int loop=0; loop<colsA; loop++)
        {
            mult[i] += A[i][loop] * B[loop];
        }
    }
    
    return mult;
}

// Multiply a scalar and a matrix
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
        

// Multiply a matrix and a scalar
double** Multiply(double** A, double x, int rowsA, int colsA)
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
        
