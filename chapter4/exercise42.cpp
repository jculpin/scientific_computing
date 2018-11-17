#include <iostream>
/* Guide to Scientific Computing in C++
 * Chapter 4.  Exercise 4.2 */

int main(int argc, char* argv[])
{
    int x, y;
    x = 10;
    y = 234;
    
    std::cout << "Before the swap \n";
    std::cout << "x = " << x << " y = " << y << "\n";
    
    int* p_x;
    int* p_y;
    
    p_x = &x;
    p_y = &y;
    
    // swap the values using pointers 
    int* p_temp = new int;
    *p_temp = *p_x;
    x = *p_y;
    y = *p_temp;
    
    std::cout << "After the swap \n";
    std::cout << "x = " << x << " y = " << y << "\n";
    
    return 0;
}
