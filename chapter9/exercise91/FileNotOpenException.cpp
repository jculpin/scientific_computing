#include <iostream>
#include "FileNotOpenException.hpp"

//Constructor
FileNotOpenException::FileNotOpenException(std::string probString) 
{
    mTag = "FILENOTOPEN";
    mProblem = probString;
}

