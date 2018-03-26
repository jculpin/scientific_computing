#include "AbstractOdeSolver.hpp"
#include <iostream>
#include <fstream>
#include "Exception.hpp"

class ForwardEulerSolver : public AbstractOdeSolver
{
public:
    double RightHandSide(double y, double t);
    double SolveEquation();
};

double ForwardEulerSolver::RightHandSide(double y, double t)
{
    return -100.0 * y;
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
    std::cout << "initial value = " << y << "\n";
    int i, interval;
    interval = (int) (finalTime - initialTime) / stepSize;
    for(int i=1; i < interval + 1; i++)
    {
        try
        {
            y = y + stepSize * RightHandSide(y, i*stepSize);  
            output_file  << y << "      " << i*stepSize << "\n";
            if(y < 0.0)
            {
                if(y > -1.0e-6)
                {
                    throw (Exception("Type1", "Solution within acceptable tolerance level"));
                }
                else
                {
                    throw (Exception("Type2", "Solution outside acceptable tolerance level"));
                }
            }
            else if(y > 1.0)
            {
                if (y < 1.0 + 1.0e-6)
                {
                    throw (Exception("Type1", "Solution within acceptable tolerance level"));
                }
                else
                {
                    (Exception("Type2", "Solution outside acceptable tolerance level"));
                }
            }
        }   // try
        catch (Exception& error)
        {
            if (error.getType() == "Type1")
            {
                std::cout << "Type1\n";
            }
            else if (error.getType() == "Type2")
            {  
                std::cout << "Type2\n";
                //stepSize = 0.5 * stepSize;
                //solve->SolveEquation();          
            }
            else if (error.getType() == "Type3")
            {
                std::cout << "Type3\n";
            }
        }            
    } 
    
    output_file.flush();
    output_file.close();
    
    return y;
}

int main(int argc, char* argv[])
{
    AbstractOdeSolver* solve= new ForwardEulerSolver;
    double solution;
    solve->SetStepSize(0.01);
    solve->SetTimeInterval(0.0, 100.0);
    solve->SetInitialValue(0.8);
    solution = solve->SolveEquation();
    
    std::cout << "The solution is " << solution << "\n";
    
    delete solve;
    
    return 0;
}
