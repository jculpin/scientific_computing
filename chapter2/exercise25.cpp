#include <iostream>
#include <cassert>
#include <fstream>
/* Guide to Scientific Computing in C++
 * Chapter 2.  Exercise 2.5
 * 1. Write code to calculate the inverse of a matrix given by
 * A =  4  10
 *      1  1
 * 2. Check that the inverse calculated is correct by printing out the 
 * entries of the inverse and comparing with direct calculation
 * 3. Modify your code to include an assert statement that checks that 
 * the determinant of the matrix is non-zero */
 
 int main()
 {
     double A[2][2] = {{4,10},{1,1}};
     double invA[2][2];
     
     // Calculate the determinant
     double det = 1 / (A[0][0] * A[1][1] - A[0][1] * A[1][0]);
     
     // Check that the determinant is not 0
     assert (det != 0.0);
     
     // Calculate the inverse
     invA[0][0] = det * A[1][1];
     invA[0][1] = det * A[0][1] * -1;
     invA[1][0] = det * A[1][0] * -1;
     invA[1][1] = det * A[0][0];
     
     // Print out the inverse
     std::cout << "The inverse of the matrix is: \n";
     for(int i=0; i<2; i++)
     {
         std::cout << invA[i][0] << "  " << invA[i][1] << "\n";
     }
     return 0;
 }
