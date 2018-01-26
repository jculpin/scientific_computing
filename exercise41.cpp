#include <iostream>
/* Guide to Scientific Computing in C++
 * Chapter 4.  Exercise 4.1 */

int main(int argc, char* argv[])
{
    int i = 5;
    int* p_j;
    // Store the address of i in p_a
    p_j = &i;
    // Multiply a by 5 using only pointer variables
    std::cout << "Mulitply by 5: " << *p_j * 5 << "\n";
    std::cout << "5 times i = " << *p_j << "\n";
    int* p_k = new int;
    // Store the content of i in p_k
    *p_k = i;
    std::cout << "New pointer: " << *p_k << "\n";
     
    return 0;
}
