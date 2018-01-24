#include <iostream>
/* Guide to Scientific Computing in C++
 * Chapter 1 Exercise 1.2
 * Write code that asks a user to enter two integers from the keyboard
 * and then writes the product of these integers to the screen */
 
int main()
{
    int first, second;
    
    std::cout << "Enter two integers : " << "\n";
    std::cin >> first >> second ;
    std::cout << "The product of the two numbers is: " << first * second << "\n";
    
    return 0;
}
