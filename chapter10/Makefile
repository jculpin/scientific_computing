all: UseVector VectorTestSuite 

### 
UseVector:	UseVector.cpp Exception.o Vector.o 
	g++ -O -o UseVector $^

### The testing framework is a two-step process
# 1. Header to C++ main program via cxxtest generating script
#eg.
#ComplexNumberTestSuite.cpp: 	ComplexNumberTestSuite.hpp
#	cxxtestgen --have-eh --error-printer -o ComplexNumberTestSuite.cpp ComplexNumberTestSuite.hpp
%TestSuite.cpp: %TestSuite.hpp
	cxxtestgen --have-eh --error-printer -o $@ $<

# 2. C++ main program to executable - Then run the executable with -v "verbose trace"
VectorTestSuite:	VectorTestSuite.cpp Exception.o Vector.o
	g++ -g -o VectorTestSuite $^\
	&& ./VectorTestSuite -v

### Instructions for building the classes						
%.o:	%.cpp %.hpp
	g++ -g -c $<

clean:
	rm -f *.o *TestSuite.cpp
