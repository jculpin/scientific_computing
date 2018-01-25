#include <iostream>
#include <cmath>
/* Guide to Scientific Computing in C++
 * Chapter 2.  Exercise 2.6 */

int main ()
{
    //float x[100];
    float x_next = 0, x_prev = 0;
    //x[0] = 0;
    // Use Newton-Raphson to solve e^x + x^3 - 5 = 0
    //for (int i=0; i<100; i++)
    do{
        //x[i+1] = x[i] - ((exp(x[i]) + pow(x[i],3) - 5.0) / (exp(x[i]) + 3.0 * pow(x[i],2)));
        //std::cout << "Iteration: " << i << "  Value: " << x[i+1] << "\n";
        //std::cout << "Termination check: " << x[i+1]- x[i] << "\n";
        x_prev = x_next;
        x_next = x_prev - ((exp(x_prev) + pow(x_prev,3) - 5.0) / (exp(x_prev) + 3.0 * pow(x_prev,2)));
        //std::cout << "Iteration: " << i << "  Value: " << x_next << "\n";
        
        // Check the value to see if it is cloise to zero 
        std::cout << "Check: " << exp(x_next) + pow(x_next,3) - 5 << "\n";
        std::cout << "Value: " << x_next << "\n";        
    }while(fabs(x_next - x_prev) > 1e-3);
    
    return 0;
}
