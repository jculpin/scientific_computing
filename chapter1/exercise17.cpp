#include <iostream>
/* Guide to Scientific Computing in C++
 * Chapter 1 Exercise 1.7
 * Investigate the use of the compiler error warning flags discussed in 
 * section 1.3.3.  For example,: (i) declare an integer as a constant 
 * variable and then attempt to chnage the value later in the code; and
 * (ii) attempt to set an integer variable ot the value 3.2 */
 
int main()
{
    int my_int, result;
    double const my_double = 13.445;
    double answer;
    
    my_int = 3.2123 + 2.456;
    result = my_int * 3;
    // my_double = 12.34 * 3;
    answer = my_double * 3;
    
    return answer + result;
}
