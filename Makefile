ComplexNumber.o : ComplexNumber.cpp ComplexNumber.hpp
	g++ -c -O ComplexNumber.cpp

UseComplexNumber : ComplexNumber.o UseComplexNumber.o
	g++ -O -o UseComplexNumber UseComplexNumber.cpp ComplexNumber.o

