#include "Student.hpp"
#include <cassert>

Student::Student()
{
    student_name = "";
    library_fines = 0.0;
    tuition_fees = 0.0;
}

Student::Student(std::string name)
{
    student_name = name;
}

Student::Student(std::string name, double lib_fines, double tut_fees)
{
    student_name = name;
    library_fines = lib_fines;
    tuition_fees = tut_fees;
}

double Student::money_owed() const
{
    return library_fines + tuition_fees;
}

double Student::GetLibraryFines() const
{
    return library_fines;
}

void Student::SetLibraryFines(double fines)
{
    assert(fines > 0);
    
    library_fines = fines;
}
