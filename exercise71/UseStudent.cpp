#include <iostream>
#include "Student.hpp"
#include "GraduateStudent.hpp"
#include "PhdStudent.hpp"

int main(int argc, char* argv[])
{
    Student student_1;
    student_1.student_name = "John Culpin";
    Student student_2("Cathy Gilmour", 100.00, 2500.00);
    Student student_3("Dan Lees");
    GraduateStudent student_4;
    std::cout << student_2.student_name << " owes " 
        << student_2.money_owed() << "\n";
    student_4.tuition_fees = 1234.56;
    std::cout << student_4.student_name << " is " << student_4.status 
        << " and owes " << student_4.money_owed() <<"\n";
    
    PhdStudent student_5;
    student_5.SetLibraryFines(123.45);
    std::cout << "Phd student owes " << student_5.money_owed() << "\n";
    
    return 0;
}
