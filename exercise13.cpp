#include <iostream>
#include <cmath>
/* Guide to Scientific Computing in C++
 * Chapter 1 Exercise 1.3
 * Write code that declares two vectors as arrays of double precision 
 * floating point numbers of length three and assigns values to each of 
 * these entries.  Extend the code so that it calculates the scalar 
 * (dot) product of these vectors and prints it to screen.  Finally, 
 * extend the code so that it prints the Euclidean norm of both vectors
 * to the screen */
int main()
{

    double v1[3] = {1.0,2.0,3.0};
    double v2[3] = {4.1,5.1,6.5};
        
    double scalar_product;
    for(int i=0; i<3;i++)
    {
        scalar_product += v1[i]*v2[i];
    }
    std::cout << "The scalar product is :" << scalar_product << "\n";
    
    double euclidean_norm;
    scalar_product = 0;
    for(int i=0; i<3; i++)
    {
        scalar_product += v1[i]*v1[i];
    }
    euclidean_norm = sqrt(scalar_product);
    std::cout << "Euclidean norm for v1 = " << euclidean_norm << "\n";
    
    scalar_product = 0;
    for(int i=0; i<3; i++)
    {
        scalar_product += v2[i]*v2[i];
    }
    euclidean_norm = sqrt(scalar_product);
    std::cout << "Euclidean norm for v2 = " << euclidean_norm << "\n";
    
    return 0;
}
