#ifndef STUDENTHEADER
#define STUDENTHEADER

#include <iostream>
#include <string>

class Student
{
private:
    double library_fines;    
public:
    Student();
    Student(std::string name);
    Student(std::string, double lib_fines, double tut_fees);
    std::string student_name;
    double tuition_fees;
    virtual double money_owed() const;
    double GetLibraryFines() const;
    void SetLibraryFines(double fines);
};
#endif
