#include "AbstractOdeSolver.hpp"
#include <iostream>
#include <fstream>

class ForwardEulerSolver : public AbstractOdeSolver
{
public:
    double RightHandSide(double y, double t);
    double SolveEquation();
};

double ForwardEulerSolver::RightHandSide(double y, double t)
{
    return 1 + t;
}

double ForwardEulerSolver::SolveEquation()
{
    std::ofstream output_file("ForwardEuler.txt");
    if(!output_file.is_open())
    {
        return -1;
    }
    output_file.precision(5);
    output_file  << "Forward Euler Solver" << "\n";
    output_file  << "y" << "        " << "t" << "\n";
    
    double y = initialValue;
    int interval;
    interval = (int) (finalTime - initialTime) / stepSize;
    for(int i=1; i < interval + 1; i++)
    {
        y = y + stepSize * RightHandSide(y, i*stepSize);        
        output_file  << y << "      " << i*stepSize << "\n";
    }
    output_file.flush();
    output_file.close();
    return 0;
}

int main(int argc, char* argv[])
{
    AbstractOdeSolver* solve= new ForwardEulerSolver;
    solve->SetStepSize(0.01);
    solve->SetTimeInterval(0.0, 1.0);
    solve->SetInitialValue(2.0);
    solve->SolveEquation();
    delete solve;
    
    return 0;
}
