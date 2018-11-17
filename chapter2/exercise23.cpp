#include <iostream>
/* Guide to Scientific Computing in C++
 * Chapter 2.  Exercise 2.3
 * In this exercise you are asked to write and test a program which 
 * sums a list of numbers which are provided by a user via std::cin.
 * 1.  Write a program that calculates the sum of a collection of 
 * positive integers that are entered by the user from the keyboard.
 * Your program should propmt the user to enter each integer followed by
 * the return key, and to enter "-1" at the end of the list of integers
 * to be added.
 * 2.  Modify your code so that the code terminates if the sum of the 
 * integers entered up to that point exceeds 100.
 * 2.  Modify your code so that, if the user has entered an incorrect 
 * integer, they may enter "-2" to reset the sum to zero and begin 
 * enterng integers again */
  
int main ()
{
    int total= 0 , count = 0, num;
    std::cout << "Enter a list of integers.  Type -1 to end" << "\n";
    do
    {
        std::cin >> num;
        if(num != -1)
        {
            total += num;
            count += 1;
        }
        if(num == -2)
        {
            total = 0;
            count = 0;
            std::cout << "Totals have been reset\n";
        }        
    } while(num != -1  && total <= 100);
    
    std::cout << "The average is: " << (double) total / (double) count << "\n";
    
    return 0;
}
