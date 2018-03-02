ComplexNumber.o : ComplexNumber.cpp ComplexNumber.hpp
	g++ -c -g ComplexNumber.cpp

UseComplexNumber : ComplexNumber.o UseComplexNumber.o
	g++ -g -o UseComplexNumber UseComplexNumber.cpp ComplexNumber.o
	
exercise612 : ComplexNumber.o exercise612.o
	g++ -g -o exercise612 exercise612.cpp ComplexNumber.o
