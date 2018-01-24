#include <iostream>
/* Guide to Scientific Computing in C++
 * Chapter 1 Exercise 1.4
 * Write code that declares four 2 X 2 matrices of double precision 
 * floating point numbers, A, B, C, D and assigns values to the entries 
 * of A and B.  Let C = A + B and D = AB.  Extend your code so that it 
 * calculates the entries of C and D, and then prints the entries of 
 * these matrices to screen. */
 
int main()
{
    double A[2][2] = {{1.9,2.9},{3.9,4.91}}, B[2][2] = {{4.9,5.8}, {6.7,7.6}}, C[2][2], D[2][2];
    // Calculate A + B
    for(int i=0; i<2; i++)
    {
        for(int j=0; j<2; j++)
        {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
    //Calculate AB
    for(int i=0; i< 2; i++)
    {
        for(int j=0; j<2; j++)
        {
            D[i][j] = A[i][0] * B[0][j] + A[i][1] * B[1][j];
        }
    }
    // Output the values of C and D
    std::cout << "Matrix C (= A + B) is \n" ;    
    std::cout << C[0][0] << "  " << C[0][1] << "\n";
    std::cout << C[1][0] << "  " << C[1][1] << "\n";
    
    std::cout << "Matrix D (= A * B) is \n" ;    
    std::cout << D[0][0] << "  " << D[0][1] << "\n";
    std::cout << D[1][0] << "  " << D[1][1] << "\n";
    
    return 0;
}
