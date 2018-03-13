#include <iostream>

template<class T> T GetAbsolute(T number1, T number2);

int main(int argc, char* argv[])
{
    std::cout << GetAbsolute<int>(-100, 150) << "\n";
    std::cout << GetAbsolute<double>(110.00, -23.34) << "\n";
    
    return 0;
}

template<class T> T GetAbsolute(T number1, T number2)
{
    T result;
    
    if(number1 < 0) number1 = 0 - number1;
    if(number2 < 0) number2 = 0 - number2;
    
    if(number1 < number2)
    {
        result = number2;
    }
    else
    {
        result = number1;
    }
    
    return result;
}
