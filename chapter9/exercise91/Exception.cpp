#include <iostream>
#include "Exception.hpp"

//Constructor
Exception::Exception(std::string tagString,
                     std::string probString)
{
    mTag = tagString;
    mProblem = probString;
}
// Default constructor 
Exception::Exception()
{
    mTag = "undefined";
    mProblem = "undefined";
}

// Copy constructor    
Exception::Exception(const Exception& otherException)
{
    mTag = otherException.mTag;
    mProblem = otherException.mProblem;
}

void Exception::PrintDebug() const
{
        std::cerr << "** Error (" << mTag << ") **\n";
        std::cerr << "Problem: " << mProblem << "\n\n";
}

std::string Exception::getType() const
{
    return mTag;
}
