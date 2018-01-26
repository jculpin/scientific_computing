#include <iostream>
/* Guide to Scientific Computing in C++
 * Chapter 4.  Exercise 4.3 */
 
 int main(int argc, char* argv[])
 {
    double* a;
    double* b;
     
    for(int loop=0; loop<1000000000; loop++)
    {
        a = new double[3];
        b = new double[3];
     
        a[0] = 1.0;
        a[1] = 2.0;
        a[2] = 0.0;
        b[0] = 2.0;
        b[1] = 1.0;
        b[2] = 1.0;
     
        /*
        std::cout << "Vector a = \n";
        for(int i=0; i<3; i++)
        {
            std::cout << a[i] << " ";
        }
        std::cout << "\n";

        std::cout << "Vector b = \n";
        for(int i=0; i<3; i++)
        {
            std::cout << b[i] << " ";
        }
        std::cout << "\n";
        */
        double dot_product = 0;
        // calculate dot product and print it out 
        for(int i=0; i<3; i++)
        {
            dot_product += a[i] * b[i];
        }
     
        //std::cout << "Dot product is " << dot_product << "\n";
     
        delete[] a;
        delete[] b;
    }
    return 0;
 }
