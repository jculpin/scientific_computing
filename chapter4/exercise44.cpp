#include <iostream>
/* Guide to Scientific Computing in C++
 * Chapter 4.  Exercise 4.4 */

int main(int argc, char* argv[])
{
    for(int i=0; i<1000000000; i++)
    {
        // Dynamically define three 2 X 2 matrices of
        // double precision floating point numbers
        double** A;
        double** B;
        double** C;
    
        A = new double* [2];
        B = new double* [2];
        C = new double* [2];
        for(int i=0; i<2; i++)
        {
            A[i] = new double[2];
            B[i] = new double[2];
            C[i] = new double[2];
        }
        
        // Assign values to A and B
        A[0][0] = 2.0;
        A[0][1] = 1.0;
        A[1][0] = 0.0;
        A[1][1] = -2.0;
        B[0][0] = -1.0;
        B[0][1] = 0.0;
        B[1][0] = 2.0;
        B[1][1] = -2.0;
    
        // Let C = A + B
        for (int i=0; i<2; i++)
        {
            for(int j=0; j<2; j++)
            {
                C[i][j] = A[i][j] + B[i][j];
            }
        }
    
        // Print values of C to screen
        /*
        std::cout << "The natrix C is: \n";
        for (int i=0; i<2; i++)
        {
            std::cout << C[i][0] << " " << C[i][1] << "\n";
        }
        */
        for (int i=0; i<2; i++)
        {
            delete[] A[i];
            delete[] B[i];
            delete[] C[i];
        }
        delete[] A;
        delete[] B;
        delete[] C;
    }
    
    return 0;
}
