#include <iostream>
#include <cmath>
// Function to calculate the p-norm of a vector:
//     = [Sum_i ( |x_i|**p ) ] ** (1/p
// See "An introduction to Numerical Analysis" by
// Endre Suli and David Mayers, page 60, for definition 
// of the p-norm of  vector
// x is a pointer to the vector which is of size vecSize

double CalculateNorm(double* x, int vecSize, int p = 2)
{
    double sum = 0.0;
    //Loop over elems x_i of x, incrementing sum by |x_i|**p
    for(int i=0; i<vecSize; i++)
    {
        double temp = fabs(x[i]);
        sum += pow(temp, p);
    }
    // Return p-th root of sum
    return pow (sum, 1.0/p);
}

int main(int argc, char* argv[])
{
    double* vec = new double[3];
    vec[0] = 2.0;
    vec[1] = 4.0;
    vec[2] = 3.0;
    
    std::cout << "2-norm for vector is: " << CalculateNorm(vec, 3) << "\n";
    std::cout << "3-norm for vector is: " << CalculateNorm(vec, 3, 3) << "\n";
    std::cout << "4-norm for vector is: " << CalculateNorm(vec, 3, 4) << "\n";
    return 0;
}
