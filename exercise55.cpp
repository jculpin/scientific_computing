#include <iostream>
#include <cassert>

double** Multiply(double** A, double** B, 
                  int rowsA, int colsA,
                  int rowsB, int colsB);
                 
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
    
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            std::cout << answ[i][j] << "  " ;
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
