#ifndef GRADUATESTUDENTHEADER
#define GRADUATESTUDENTHEADER

#include "Student.hpp"
#include <string>

class GraduateStudent: public Student
{
public:
    GraduateStudent();
    std::string status;
    double money_owed() const;
};

#endif     
