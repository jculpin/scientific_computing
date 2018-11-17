#include <iostream>
#include <fstream>

/* Guide to Scientific Computing in C++
 * Chapter 3.  Exercise 3.2 */

int main(int argc, char* argv[])
{
    std::ifstream read_file("x_and_y.dat");
    if(!read_file.is_open())
    {
        return 1;
    }
    int number_of_rows = 0;
    while(!read_file.eof())
    {
        double dummy1, dummy2, dummy3, dummy4;
        read_file >> dummy1 >> dummy2;
        read_file >> dummy3 >> dummy4;        
        if(!read_file.eof())
            number_of_rows++;
    }
    std::cout << "number of rows = "
              << number_of_rows << "\n";
    read_file.close();
              
    return 0;
}
          
