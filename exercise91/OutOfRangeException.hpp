#ifndef OUTOFRANGEEXCEPTIONDEF
#define OUTOFRANGEEXCEPTIONDEF

#include "Exception.hpp"
#include <string>

class OutOfRangeException : public Exception
{
public:
    OutOfRangeException(std::string probString);
};
#endif  //OUTOFRANGEEXCEPTIONDEF
