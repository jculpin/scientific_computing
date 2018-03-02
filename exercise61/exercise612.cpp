#include "ComplexNumber.hpp"

void MultiplyMatrix(ComplexNumber** A, ComplexNumber** B, 
                    ComplexNumber** C, int size);
void PrintMatrix(ComplexNumber** A, int size);
void MultiplyMatrix(ComplexNumber** A, ComplexNumber** B, 
                    double factor, int size);
ComplexNumber** CreateComplexMatrix (int size);
void DeleteComplexArray(ComplexNumber** A, int size);
void CopyArray(ComplexNumber** A, ComplexNumber** B, int size);
void AddMatrices(ComplexNumber** A, ComplexNumber** B, int size);
int Factorial (int num);

int main(int argc, char* argv[])
{
    // Create a 3X3 array of complex numbers
    ComplexNumber** complexArray = CreateComplexMatrix(3);
    ComplexNumber** tempArray = CreateComplexMatrix(3);
    ComplexNumber** expMatrix = CreateComplexMatrix(3);
    ComplexNumber** powerMatrix = CreateComplexMatrix(3);
    ComplexNumber** identity = CreateComplexMatrix(3);
    
    // Initialise matrix
    //ComplexNumber c0(1,2);
    //ComplexNumber c1(-1,1);
    //ComplexNumber c2(0,-1);
    //ComplexNumber c3(1,1);
    //ComplexNumber c4(2,2);
    //ComplexNumber c5(0,-1);
    //ComplexNumber c6(2,0);
    //ComplexNumber c7(1,2);
    //ComplexNumber c8(-1,-2);
    ComplexNumber c0(1);
    ComplexNumber c1(-1);
    ComplexNumber c2(0);
    ComplexNumber c3(1);
    ComplexNumber c4(2);
    ComplexNumber c5(0);
    ComplexNumber c6(2);
    ComplexNumber c7(1);
    ComplexNumber c8(-1);
    complexArray[0][0] = c0;
    complexArray[0][1] = c1;
    complexArray[0][2] = c2;
    complexArray[1][0] = c3;
    complexArray[1][1] = c4;
    complexArray[1][2] = c5;
    complexArray[2][0] = c6;
    complexArray[2][1] = c7;
    complexArray[2][2] = c8;
    
    // Create the identity matrix
    ComplexNumber ones(1,0);
    ComplexNumber zeros(0,0);
    identity[0][0] = ones;
    identity[0][1] = zeros;
    identity[0][2] = zeros;
    identity[1][0] = zeros;
    identity[1][1] = ones;
    identity[1][2] = zeros;
    identity[2][0] = zeros;
    identity[2][1] = zeros;
    identity[2][2] = ones;
    
    std::cout << "The array is: \n";
    PrintMatrix(complexArray,3);
    
    CopyArray(identity, powerMatrix, 3);
    
    CopyArray(identity, expMatrix, 3);
    // Loop a "suitable" number of times
    for(int i=1; i<10; i++)
    {
        double factor = 1.0 / double(Factorial(i));
        MultiplyMatrix(complexArray, powerMatrix, tempArray, 3);
        std::cout << factor << "\n";
        //PrintMatrix(tempArray,3);
        // Copy the temp array to powerMatrix
        CopyArray(tempArray,powerMatrix, 3);
        //PrintMatrix(powerMatrix,3);
        MultiplyMatrix(powerMatrix, tempArray, factor, 3);
        //PrintMatrix(tempArray,3);
        AddMatrices(tempArray, expMatrix, 3);
    }
    std::cout << "The exponential matrix is: \n";
    PrintMatrix(expMatrix, 3);
    
    // Tidy up
    DeleteComplexArray(complexArray, 3);
    DeleteComplexArray(tempArray, 3);
    DeleteComplexArray(expMatrix, 3);
    DeleteComplexArray(powerMatrix, 3);
    DeleteComplexArray(identity, 3);
    return 0;
}

int Factorial (int num)
{
    int fact;
    if(num == 1) fact = 1;
    else fact = Factorial(num - 1) * num;
    
    return fact;
}

void AddMatrices(ComplexNumber** A, ComplexNumber** B, int size)
{
    for(int i=0; i<size; i++)
    {
        for(int j=0; j<size; j++)
        {
            B[i][j] = A[i][j] + B[i][j];
        }
    }
}
            
    
void CopyArray(ComplexNumber** A, ComplexNumber** B, int size)
{
    for (int i=0; i<size; i++)
    {
        for(int j=0; j<size; j++)
        {
            B[i][j] = A[i][j];
        }
    }
}

ComplexNumber** CreateComplexMatrix (int size)
{
    ComplexNumber** complexArray = new ComplexNumber*[size];
    for(int i =0; i<size; i++)
    {
        complexArray[i] = new ComplexNumber[size];
    }
    
    return complexArray;
}
    
void DeleteComplexArray(ComplexNumber** A, int size)
{
    for(int i=0; i<size; i++)
    {
        delete[] A[i];
    }
    delete[] A;
}
        
void MultiplyMatrix(ComplexNumber** A, ComplexNumber** B, 
                    ComplexNumber** C, int size)
{
    for(int i=0; i<size; i++)
    {
        for(int j=0; j<size; j++)
        {
            ComplexNumber temp(0,0);
            for(int cols=0; cols<size; cols++)
            {
                temp = temp + A[i][cols] * B[cols][j];
            }
            C[i][j] = temp;
        }
    }
}

void MultiplyMatrix(ComplexNumber** A, ComplexNumber** B, 
                    double factor, int size)
{
    // ComplexNumber complexFactor(factor, 0);
    
    for(int i=0; i<size; i++)
    {
        for(int j=0; j<size; j++)
        {
            B[i][j] = A[i][j] * factor;
        }
    }
}

void PrintMatrix(ComplexNumber** A, int size)
{
    for(int i=0; i<size; i++)
    {
        for(int j=0; j<size; j++)
        {
            std::cout << A[i][j] << " ";
        }
        std::cout << "\n";
    }
}
