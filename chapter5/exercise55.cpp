#include <iostream>
#include <cassert>

void Multiply(double** A, double** B, double** C,
                  int rowsA, int colsA,
                  int rowsB, int colsB);
                 
int main(int argc, char* argv[])
{
    // test function on a 3X3 matrix
    double** X = new double* [3];
    double** Y = new double* [3];
    double** Z = new double* [3];
    for(int i=0; i<3; i++)
    {
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
    
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            std::cout << Z[i][j] << "  " ;
        }
        std::cout << "\n";
    }
        
    // tidy up
    for(int loop = 0; loop < 3; loop++)
    {
        delete[] X[loop];
        delete[] Y[loop];
        delete[] Z[loop];
    }
    delete[] X;    
    delete[] Y;
    delete[] Z;
    
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
                C[i][j] = 0;
                for(int loop=0; loop<colsA; loop++)
                {
                    C[i][j] += A[i][loop] * B[loop][j];
                }
            }
        }            
    }
}
