#ifndef ABSTRACTODESOLVERDEF
#define ABSTRACTODESOLVERDEF

class AbstractOdeSolver
{
protected:
    double stepSize;
    double initialTime;
    double finalTime;
    double initialValue;
public:
    void SetStepSize(double h);
    void SetTimeInterval(double t0, double t1);
    void SetInitialValue(double y0);
    double GetStepSize();
    virtual double RightHandSide(double y, double t) = 0;
    virtual double SolveEquation() = 0;
};

void AbstractOdeSolver::SetStepSize(double h)
{
    stepSize = h;
}

void AbstractOdeSolver::SetTimeInterval(double t0, double t1)
{
    initialTime = t0;
    finalTime = t1;
}

void AbstractOdeSolver::SetInitialValue(double y0)
{
    initialValue = y0;
}

double AbstractOdeSolver::GetStepSize()
{
    return stepSize;
}

#endif    
