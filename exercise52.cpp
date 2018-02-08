#include <iostream>

void print_value(int* x);
void change_value(int* x);

int main(int argc, char* argv[])
{
    int x = 123;
    change_value(&x);
    print_value(&x);
    
    return 0;
}

void print_value(int* x)
{
    std::cout << "The value is: " << *x << "\n";
}

void change_value(int* x)
{
    *x = 321;
}
