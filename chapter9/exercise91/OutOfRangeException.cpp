#include <iostream>
#include "OutOfRangeException.hpp"

//Constructor
OutOfRangeException::OutOfRangeException(std::string probString)
{
    mTag = "OUTOFRANGE";
    mProblem = probString;
}
