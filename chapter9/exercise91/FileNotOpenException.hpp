#ifndef FILENOTOPENEXCEPTIONDEF
#define FILENOTOPENEXCEPTIONDEF

#include "Exception.hpp"
#include <string>

class FileNotOpenException : public Exception
{
public:
    FileNotOpenException(std::string probString);
};
#endif  //FILENOTOPENEXCEPTIONDEF
