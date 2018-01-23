#include <iostream>

int main ()
{

    int* p_i;
    
    p_i = new int;
    *p_i = 12;
    *p_i += 1;
    std::cout << *p_i << "\n";
    std::cout << &p_i << "\n";    
    delete p_i;
    
    double* x;
    x = new double [10];
    std::cout << x << "\n";
    std::cout << x + 1 << "\n";
    std::cout << &x[0] << "\n";    
    std::cout << &x[1] << "\n";    
    delete[] x;
    
    int rows = 5, cols = 3;
    double** A;
    A = new double* [rows];
    for(int i=0; i<rows; i++)
    {
        A[i] = new double [cols];
    }
    
    A[0][0] = 3.0;
    std::cout << &A << "\n";
    for (int i=0; i<rows; i++)
    {
        delete[] A[i];
    }
    delete[] A;
    
    int** irreg;
    irreg = new int* [1000];
    for (int i=0; i<1000; i++)
    {
        irreg[i] = new int[i+1];
    }
    
    irreg[0][0] = 12;
    
    for(int i=0; i<rows; i++)
    {
        delete[] irreg[i];
    }
    delete[] irreg;
    
    
    
    return 0;
}
