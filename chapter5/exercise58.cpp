#include <iostream>
#include <cmath>
// Recursive program to calulate the determinant of a matrix

double CalculateDeterminant (double** A, int size);

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
    std::cout << "Determinant = \n";
    double detX = CalculateDeterminant(X, 3);
    std::cout << detX << "\n";
    
    return 0;
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
