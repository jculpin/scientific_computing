#include <iostream>

int main()
{
    double A[2][2] = {{1.9,2.9},{3.9,4.91}}, B[2][2] = {{4.9,5.8}, {6.7,7.6}}, C[2][2], D[2][2];
    
    for(int i=0; i<2; i++)
    {
        for(int j=0; j<2; j++)
        {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
    
    for(int i=0; i< 2; i++)
    {
        for(int j=0; j<2; j++)
        {
            D[i][j] = A[i][0] * B[0][j] + A[i][1] * B[1][j];
        }
    }
    
    std::cout << "Matrix C (= A + B) is \n" ;    
    std::cout << C[0][0] << "  " << C[0][1] << "\n";
    std::cout << C[1][0] << "  " << C[1][1] << "\n";
    
    std::cout << "Matrix D (= A * B) is \n" ;    
    std::cout << D[0][0] << "  " << D[0][1] << "\n";
    std::cout << D[1][0] << "  " << D[1][1] << "\n";
    
    return 0;
}
