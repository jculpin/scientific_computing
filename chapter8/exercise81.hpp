#include <cassert>
#include <iostream>

template<unsigned int DIM> class ProbabilityArray
{
private:
    double mProbability[DIM];
public:
    double& operator[](unsigned int index)
    {
        std::cout << index << "\n";
        assert(index < DIM);
        assert(index > -1);

        assert(mProbability[index] > -10e-6);
        assert(mProbability[index] < 1 + 10e-6);
        if(mProbability[index] < 0)
        {   
            mProbability[index] = 0.0;
        }
        else if(mProbability[index] > 1)
        {
            mProbability[index]= 1.0;
        }
        
        return(mProbability[index]);

    }
};
