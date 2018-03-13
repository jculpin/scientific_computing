#include <iostream>
#include "exercise81.hpp"


int main(int argc, char* argv[])
{
    ProbabilityArray<7> chanceOfRain;
    
    //chanceOfRain.testSetup();
    chanceOfRain[0] = 1.000001;
    std::cout << chanceOfRain[10] << "\n";

}
