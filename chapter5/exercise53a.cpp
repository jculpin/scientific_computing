#include <iostream>

void swap_numbers (double* a, double* b);

int main(int argc, char* argv[])
{
    double a = 12.34;
    double b = 98.76;
        
    swap_numbers(&a, &b);
    std::cout << "a = " << a << " b = " << b << "\n";
     
    return 0;
}

void swap_numbers(double* a, double* b)
{
    double temp;
    
    temp = *b;
    *b = *a;
    *a = temp;
}
