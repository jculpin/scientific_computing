#include <iostream>
/* Guide to Scientific Computing in C++
 * Chapter 2.  Exercise 2.4
 * Modify the sample code
 * Define vectors x, y, and z, and matrices C and D, such that
 *          x = u - v,
 *          y = Au,
 *          z = Au - v,
 *          C = 4A - 3B,
 *          D = AB
 */

int main (int argc, char* argv[])
{
    double u[3] = {1.0, 2.0, 3.0};
    double v[3] = {6.0, 5.0, 4.0};
    double A[3][3] = {{1.0, 5.0, 0.0},
                      {7.0, 1.0, 2.0},
                      {0.0, 0.0, 1.0}};
    double B[3][3] = {{-2.0, 0.0, 1.0},
                      {1.0, 0.0, 0.0},
                      {4.0, 1.0, 0.0}};
    double w[3];
    // Five lines below are my solution
    double x[3] = {0.0, 0.0, 0.0};
    double y[3] = {0.0, 0.0, 0.0};
    double z[3] = {0.0, 0.0, 0.0};
    double C[3][3];
    double D[3][3];
    
    for(int i=0; i<3; i++)
    {
        w[i] = u[i] - 3.0*v[i];
    }
    
    // Following code is my solution
    // Calculate x = u - v
    for(int i=0; i<3; i++)
    {
        x[i] = u[i] - v[i];
    }
    
    // Calculate y = Au
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            y[i] += A[i][j] * u[j];
        }
    }
    
    // Calculate z = Au - v i.e. y - v
    for(int i=0; i<3; i++)
    {
        z[i] = y[i] - v[i];
    }
    
    // Calculate C = 4A - 3B
    for (int i=0; i<3; i++)
    {
        for (int j=0; j<3; j++)
        {
            C[i][j] = 4*A[i][j] - 3*B[i][j];
        }
    }
    
    // Calculate D = AB
    for (int i=0; i<3; i++)
    {
        for (int j=0; j<3; j++)
        {
            D[i][j] = A[i][0] * B[0][j] + 
                      A[i][1] * B[1][j] +
                      A[i][2] * B[2][j]  ;
        }
    }
    
    // Print out the results
    std::cout << "Vector w is: \n";
    for(int i=0; i<3; i++)
    {
        std::cout << w[i] << "\n";
    }
    
    std::cout << "Vector x is: \n";
    for(int i=0; i<3; i++)
    {
        std::cout << x[i] << "\n";
    }
    
    std::cout << "Vector y is: \n";
    for(int i=0; i<3; i++)
    {
        std::cout << y[i] << "\n";
    }
    
    std::cout << "Vector z is: \n";
    for(int i=0; i<3; i++)
    {
        std::cout << z[i] << "\n";
    }
    
    std::cout << "Matrix C is:  \n";
    for (int i=0; i<3; i++)
    {
        for (int j=0; j<3; j++)
        {
            std::cout << C[i][j] << " ";
        }
        std::cout << "\n";
    }
    
    std::cout << "Matrix D is:  \n";
    for (int i=0; i<3; i++)
    {
        for (int j=0; j<3; j++)
        {
            std::cout << D[i][j] << " ";
        }
        std::cout << "\n";
    }
    
    return 0;
}


