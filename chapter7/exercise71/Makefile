Student.o : Student.cpp Student.hpp
	g++ -c Student.cpp

GraduateStudent.o : GraduateStudent.hpp GraduateStudent.cpp 
	g++ -c GraduateStudent.cpp

PhdStudent.o : PhdStudent.hpp PhdStudent.cpp
	g++ -c PhdStudent.cpp

UseStudent.o : UseStudent.cpp Student.hpp GraduateStudent.hpp
	g++ -c  UseStudent.cpp

UseStudent : Student.o GraduateStudent.o UseStudent.o PhdStudent.o
	g++ -o UseStudent Student.o GraduateStudent.o UseStudent.o PhdStudent.o
