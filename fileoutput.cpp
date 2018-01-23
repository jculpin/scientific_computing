#include <iostream>
#include <fstream>
#include <cassert>

int main()
{
    float x = 1.23456789;
    
    std::ofstream write_output ("Output.dat", std::ios::app);
    assert(write_output.is_open());
    
    write_output.precision(6);
    write_output << x << "\n";
    
    write_output.flush();
    write_output.close();
    
    return 0;
}
