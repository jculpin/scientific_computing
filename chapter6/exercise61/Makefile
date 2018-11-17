ComplexNumber.o : ComplexNumber.cpp ComplexNumber.hpp
	g++ -Wall -O -c -g ComplexNumber.cpp

UseComplexNumber : ComplexNumber.o UseComplexNumber.o
	g++ -Wall -O -g -o UseComplexNumber UseComplexNumber.cpp ComplexNumber.o
	
exercise612 : ComplexNumber.o exercise612.o
	g++ -Wall -O -g -o exercise612 exercise612.cpp ComplexNumber.o
