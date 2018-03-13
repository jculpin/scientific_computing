#include <iostream>
#include <vector>
#include <algorithm>
#include "ComplexNumber.hpp"

int main(int argc, char* argv[])
{
    std::vector<ComplexNumber> complexvector;
    
    ComplexNumber c1(1.0,2.0);
    ComplexNumber c2(3.0,1.0);
    ComplexNumber c3(-1.0,2.0); 

    complexvector.reserve(6);
    complexvector.push_back(c1);
    complexvector.push_back(c2);
    complexvector.push_back(c3);
    
    for(int i=0; i<3; i++)
    {
        std::cout << complexvector[i] << "\n";
    }
    
    std::cout << "Length of complex vector is " << complexvector.size() << "\n";
    
    std::vector<ComplexNumber>::const_iterator c;
    for (c=complexvector.begin(); c!=complexvector.end(); c++)
    {
        std::cout << *c << "\n";
    }
    
    ComplexNumber c4(-2.0, -2.0);
    complexvector.insert(complexvector.begin() + 1, c4);
    std::cout << "Length of complex vector is " << complexvector.size() << "\n";
    for (c=complexvector.begin(); c!=complexvector.end(); c++)
    {
        std::cout << *c << "\n";
    }
    
    ComplexNumber c5(0.5, 0.5);
    complexvector.insert(complexvector.end() - 1, c5);
    std::cout << "Length of complex vector is " << complexvector.size() << "\n";
    for (c=complexvector.begin(); c!=complexvector.end(); c++)
    {
        std::cout << *c << "\n";
    }
    
    complexvector.erase(complexvector.begin() + 3, complexvector.end());
    std::cout << "Length of complex vector is " << complexvector.size() << "\n";
    for (c=complexvector.begin(); c!=complexvector.end(); c++)
    {
        std::cout << *c << "\n";
    }
        
    return 0;
}
