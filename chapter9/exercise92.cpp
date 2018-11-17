#include<iostream>

int main(int argc, char* argv[])
{

    double* p_x;
    try
    {
        p_x = new double[1000000000];
    }
    catch (std::bad_alloc& e)
    {
        std::cout << "Caught allocation exception\n";
        std::cout << e.what() << "\n";
        return 1;
    }

    //std::cout << "here\n";

    delete p_x;
    return 0;
}
