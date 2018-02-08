#include <iostream>
#include <cmath>

void calculate_sd(double* x, int len);

int main(int argc, char* argv[])
{
    double* p_x;
    p_x = new double[5];
    
    p_x[0] = 12.0;
    p_x[1] = 33.0;
    p_x[2] = 90.0;
    p_x[3] = 42.0;
    p_x[4] = 22.0;
    
    calculate_sd(p_x, 5);
    
    return 0;
}

void calculate_sd(double* x, int len)
{
    double summ = 0.0;
    for(int i=0; i<len; i++)
    {
        summ += x[i];
    }
    double mean = summ / len;
    std::cout << "The mean is " << mean << "\n";
    
    double sd_numerator = 0.0;
    for(int i=0; i<len; i++)
    {
        sd_numerator += pow((x[i] - mean),2);
    }
    double standard_deviation = sqrt(sd_numerator / (len -1));
    
    std::cout << "THe standard deviation is " << standard_deviation << "\n"; 
}
