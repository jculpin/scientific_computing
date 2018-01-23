#include <iostream>
#include <cmath>

int main()
{

    double v1[3] = {1.0,2.0,3.0};
    double v2[3] = {4.1,5.1,6.5};
        
    double scalar_product;
    for(int i=0; i<3;i++)
    {
        scalar_product += v1[i]*v2[i];
    }
    std::cout << "The scalar product is :" << scalar_product << "\n";
    
    float euclidean_norm;
    scalar_product = 0;
    for(int i=0; i<3; i++)
    {
        scalar_product += v1[i]*v1[i];
    }
    euclidean_norm = sqrt(scalar_product);
    std::cout << "Euclidean norm for v1 = " << euclidean_norm << "\n";
    
    scalar_product = 0;
    for(int i=0; i<3; i++)
    {
        scalar_product += v2[i]*v2[i];
    }
    euclidean_norm = sqrt(scalar_product);
    std::cout << "Euclidean norm for v2 = " << euclidean_norm << "\n";
    
    return 0;
}
