#include <iostream>
#include <cmath>
#include <cassert>

int main ()
{
    int i, j;
    i = 10;
    j = 0;
    std::cout << "The value of j is " << j << "\n";
    if(j == 0)
    {
        std::cerr << "Cannot divide by zero" << "\n";
    }
    assert(j > 0);
    
    return 0;
}
