#include "GraduateStudent.hpp"

GraduateStudent::GraduateStudent() : Student()
{
    student_name = "No name entered";
    status = "Full-time";
}

double GraduateStudent::money_owed() const
{
    return Student::GetLibraryFines();
}
