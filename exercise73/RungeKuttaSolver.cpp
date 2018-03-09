#include "AbstractOdeSolver.hpp"
#include <iostream>
#include <fstream>

class RungeKuttaSolver : public AbstractOdeSolver
{
public:
    double RightHandSide(double y, double t);
    double SolveEquation();
};

double RungeKuttaSolver::RightHandSide(double y, double t)
{
    return 1 + t;
}

double RungeKuttaSolver::SolveEquation()
{
    std::ofstream output_file("RungeKutta.txt");
    if(!output_file.is_open())
    {
        return -1;
    }
    output_file.precision(5);
    output_file  << "Fourth Order Runge-Kutta Solver" << "\n";
    output_file  << "y" << "        " << "t" << "\n";
    double y = initialValue;
    int interval;
    interval = (int) (finalTime - initialTime) / stepSize;
    for(int i=1; i < interval + 1; i++)
    {
        double k1 = stepSize * RightHandSide(y,(i-1)*stepSize);
        double k2 = stepSize * RightHandSide(y + 0.5 * k1,
                               (i-1)*stepSize + 0.5 * stepSize);
        double k3 = stepSize * RightHandSide(y + 0.5 * k2,
                               (i-1)*stepSize + 0.5 * stepSize);
        double k4 = stepSize * RightHandSide(y + k3,
                               (i-1) * stepSize + stepSize);
        y = y + (1.0 / 6.0) * (k1 + 2 * k2 + 2* k3 + k4);
        output_file  << y << "      " << i*stepSize << "\n";                                                                                                                  
    }
    
    output_file.flush();
    output_file.close();
    return 0;
}

int main(int argc, char* argv[])
{
    AbstractOdeSolver* solve= new RungeKuttaSolver;
    solve->SetStepSize(0.01);
    solve->SetTimeInterval(0.0, 1.0);
    solve->SetInitialValue(2.0);
    solve->SolveEquation();
    delete solve;
    
    return 0;
}
