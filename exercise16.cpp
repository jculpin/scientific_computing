#include <iostream>
/* Guide to Scientific Computing in C++
 * Chapter 1 Exercise 1.6
 * I want to record the number of cars that drive past my house each day
 * for five consecutive days, and calculate the average of these 
 * numbers.  Create an integer array to store these five numbers, and 
 * then write code to calculate the average of these numbers.  Execute
 * your code using the sample data 34, 58, 57, 32, 43.  Verify that you 
 * get the correct answer 44.8 */  
 
int main ()
{
    int cars[5];
    
    std::cout << "Enter the number of cars for each of the five days \n";
    std::cin >> cars[0] >> cars[1] >> cars[2] >> cars[3] >> cars[4];
    
    double average;
    for(int i=0; i<5; i++)
    {
        average += (double) cars[i];
    }
    average /= 5.0;
    
    std::cout << "The avaerage number of cars that passed is " << average << "\n";
        
    return 0;
}
