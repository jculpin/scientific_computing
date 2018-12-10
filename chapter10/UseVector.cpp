#include <cmath>
#include <iostream>
#include <cassert>
#include "Vector.hpp"

int main(int argc, char* argv[])
{
    int vector_size = 3;
    //std::cout << "Before creation of v" << "\n";
    Vector v(vector_size);    
    //std::cout << "After creation of v" << "\n";
    v[0] = 2.3;
    v[1] = 4.5;
    v(3) = 5.5;
    std::cout << "First test = " << v[0] << "\n";
    std::cout << "Second test = " << v(1) << "\n";
    std::cout << "Third test = " << v(2) << "\n";
    std::cout << "Fourth test = " << v(3) << "\n";
    std::cout << "Fifth test = " << v.Read(3) << "\n";
    std::cout << "Fail test " << v(4) << "\n";
    return 0;
}
