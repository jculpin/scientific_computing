#ifndef EXCEPTIONDEF
#define EXCEPTIONDEF

#include <string>

class Exception
{
protected:
    std::string mTag, mProblem;
public:
    Exception();
    Exception(const Exception& otherException);
    Exception(std::string tagString, std::string probString);
    void PrintDebug() const;
    std::string getType() const;
};
#endif  //EXCEPTIONDEF
