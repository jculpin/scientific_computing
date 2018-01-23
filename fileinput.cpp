#include <iostream>
#include <fstream>
#include <cassert>

int main()
{
    float x;
    int cnt = 1;
    
    std::ifstream read_file ("Output.dat");
    assert(read_file.is_open());
    
    while(!read_file.eof())
    {
        cnt += 1;
        read_file >> x;
        std::cout << x << ", " << cnt <<"\n";
    }
    
    read_file.close();
    
    return 0;
}
