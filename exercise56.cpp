#include <iostream>
#include <cassert>

// Multiply two matrices
void Multiply(double** A, double** B, double** C, 
                  int rowsA, int colsA,
                  int rowsB, int colsB);

//Multiply a vector and a matrix
void Multiply(double* A, double**B, double* C,
                int colsA, int rowsB, int colsB);
                                
// Multiply a matrix and a vector
void Multiply(double** A, double* B, double* C,
                int rowsA, int colsA, int rowsB);
                                
// Multiply a scalar and a matrix
void Multiply(double x,  double** A, double** C,
              int rowsA, int colsA);

// Multiply a matrix and a scalar
void Multiply(double** A, double x, double** B,
              int rowsA, int colsA);
                                
int main(int argc, char* argv[])
{
    // test function on a 3X3 matrix
    double** W = new double* [3];
    double** X = new double* [3];
    double** Y = new double* [3];
    double** Z = new double* [3];
    for(int i=0; i<3; i++)
    {
        W[i] = new double[3];
        X[i] = new double[3];
        Y[i] = new double[3];
        Z[i] = new double[3];
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
        
    Multiply(X, Y, Z, 3, 3, 3, 3);
    
    std::cout << "X multiplied by Y gives\n";
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            std::cout << Z[i][j] << "  " ;
        }
        std::cout << "\n";
    }
        
    // Test multiplication of vector and matrix
    double* u = new double[3];
    u[0] = 2.0;
    u[1] = 4.0;
    u[2] = 10.0;
    
    double* v = new double[3];
    Multiply(u, X, v, 3, 3, 3);
    std::cout << "\n" << "u multiplied by X gives\n"; 
    for(int i=0; i<3; i++)
    {
        std::cout << v[i] << "  " ;
    }
    std::cout << "\n";
    delete[] v;
    
    // Test multiplication of matrix and vector
    double* w = new double[3];
    Multiply(X, u, w, 3, 3, 3);
    std::cout << "\n" << "X multiplied by A gives\n"; 
    for(int i=0; i<3; i++)
    {
        std::cout << w[i] << "  " ;
    }
    std::cout << "\n";
    delete[] w;
    
    // Test multiplication of scalar and matrix
    Multiply(X, 2.0, W, 3, 3);
    std::cout << "\nX multiplied by 2.0 gives\n";
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            std::cout << W[i][j] << "  " ;
        }
        std::cout << "\n";
    }
    
    // Test multiplication of matrix and scalar    
    Multiply(Y, 3.0, W, 3, 3);
    std::cout << "\n3.0 multiplied by Y gives\n";
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            std::cout << W[i][j] << "  " ;
        }
        std::cout << "\n";
    }
    
    // tidy up
    for(int loop=0; loop<3; loop++)
    {
        delete[] W[loop];
        delete[] X[loop];
        delete[] Y[loop];
        delete[] Z[loop];
    }
    delete[] W;
    delete[] X;
    delete[] Y;
    delete[] Z;
    delete[] u;
    
    return 0;
}

void Multiply(double** A, double** B, double** C,
                  int rowsA, int colsA,
                  int rowsB, int colsB)
{
    assert(colsA == rowsB);
    
    for(int i=0; i<rowsA; i++)
    {
        for(int j=0; j<colsB; j++)
        {
            {
                C[i][j] = 0.0;
                for(int loop=0; loop<colsA; loop++)
                {
                    C[i][j] += A[i][loop] * B[loop][j];
                }
            }
        }            
    }                     
}

void Multiply(double* A, double**B, double* C,
                int colsA, int rowsB, int colsB)
{
    assert (colsA == rowsB);
    
    for(int i=0; i<colsB; i++)
    {
        C[i] = 0.0;
        for(int loop=0; loop<colsA; loop++)
        {
            C[i] += A[loop] * B[loop][i];
        }
    }
}

void Multiply(double** A, double* B, double* C,
                int rowsA, int colsA, int rowsB)
{
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

// Multiply a scalar and a matrix
void Multiply(double x, double** A, double** C,
              int rowsA, int colsA)
{    
    for(int i=0; i<rowsA; i++)
    {
        for(int j=0; j<colsA; j++)
        {
            C[i][j] = A[i][j] * x;
        }
    }
}
        

// Multiply a matrix and a scalar
void Multiply(double** A, double x, double** B,
              int rowsA, int colsA)
{    
    for(int i=0; i<rowsA; i++)
    {
        for(int j=0; j<colsA; j++)
        {
            B[i][j] = A[i][j] * x;
        }
    }
}
        
