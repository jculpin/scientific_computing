#include <iostream>

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
