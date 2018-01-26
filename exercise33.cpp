#include <iostream>
#include <cassert>
#include <fstream>
#include <cstdlib>

/* Guide to Scientific Computing in C++
 * Chapter 3.  Exercise 3.2 */

int main (int argc, char* argv[])
{
    int N = atoi(argv[1]);  // Grid size entered on command line
    assert(N > 1);
    
    float x_prev = 1, x_next = 1;
    float h = 1.0/N;   // the step size
    std::cout << h << "\n";
    std::ofstream write_file("xy.dat");
    assert(write_file.is_open());
    write_file.precision(5);
    
    for(int i=0; i<N; i++)
    {
        x_prev = x_next;
        x_next = x_prev - (h * x_prev);
        write_file << (float) i * h << "  " << x_next << "\n";
    }
    
    write_file.close();
    return 0;
}
