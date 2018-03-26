AbstractOdeSolver.o : AbstractOdeSolver.hpp
	g++ -c -g AbstractOdeSolver.hpp

ForwardEulerSolver : AbstractOdeSolver.hpp ForwardEulerSolver.cpp 
	g++ -o ForwardEulerSolver Exception.o ForwardEulerSolver.cpp

RungeKuttaSolver : AbstractOdeSolver.hpp RungeKuttaSolver.cpp 
	g++ -o RungeKuttaSolver RungeKuttaSolver.cpp
