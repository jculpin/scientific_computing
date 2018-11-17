SquareMatrix.o : SquareMatrix.cpp SquareMatrix.hpp
	g++ -c -g SquareMatrix.cpp

UseSquareMatrix : SquareMatrix.o UseSquareMatrix.o
	g++ -g -o UseSquareMatrix UseSquareMatrix.cpp SquareMatrix.o

