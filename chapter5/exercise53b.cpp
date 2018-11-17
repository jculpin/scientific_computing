#include <iostream>

void swap_numbers (double& a, double& b);

int main(int argc, char* argv[])
{
    double a;
    double b;
    
    a = 123.456;
    b = 987.654;
    swap_numbers(a, b);
    std::cout << "a = " << a << " b = " << b << "\n";
     
    return 0;
}

void swap_numbers(double& a, double& b)
{
    double temp;
    
    temp = b;
    b = a;
    a = temp;
}
