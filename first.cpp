#include <iostream>
#include <cmath>

int main ()
{
    double x = 7.8, y = 1.65, u = -1.4, z;
    
    std::cout << sqrt(10) << "\n";
    std::cout << pow ( 2, 4) << "\n";
    std::cout << exp (12) << "\n";
    std::cout << M_PI << "\n";
    
    z = fmod(x, y);
    std::cout << z << "\n";
    z = atan2(y, x);
    std::cout << z << "\n";
    z = fabs(u);
    std::cout << z << "\n";
}
