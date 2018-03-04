#include "ComplexArray.hpp"

ComplexArray::ComplexArray()
{
    cArray = new ComplexNumber* [3];
    for(int i =0; i<3; i++)
    {
        cArray[i] = new ComplexNumber[3];
    }
}
    
