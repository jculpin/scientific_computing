#include "ComplexNumber.hpp"

int main(int argc, char* argv[])
{
    ComplexNumber z1(4.0, 3.0);
    
    std::cout << "z1 = " << z1 << "\n";
    std::cout << "Modulus z1 = "
              << z1.CalculateModulus() << "\n";
    std::cout << "Argument z1 = "
              << z1.CalculateArgument() << "\n";
              
    ComplexNumber z2;
    z2 = z1.CalculatePower(3);
    std::cout << "z2 = z1*z1*z1 = " << z2 << "\n";
    
    ComplexNumber z3;
    z3 = -z2;
    std::cout << "z3 = -z2 = " << z3 << "\n";
    
    ComplexNumber z4;
    z4 = z1 + z2;
    std::cout << "z1 + z2 = " << z4 << "\n";
    
    ComplexNumber zs[2];
    zs[0] = z1;
    zs[1] = z2;
    std::cout << "Second element of zs = "
              << zs[1] << "\n";
              
    std::cout << "Real part of z2 = ";
    std::cout << z2.GetRealPart() << "\n"; 
    std::cout << "Imaginary part of z2 = ";
    std::cout << z2.GetImaginaryPart() << "\n";
             
    std::cout << "Real part of z3 = ";
    std::cout << RealPart(z3) << "\n"; 
    std::cout << "Imaginary part of z3 = ";
    std::cout << ImaginaryPart(z3) << "\n";
                 
    ComplexNumber copy(z2);
    std::cout << "Copy of z2 " << copy << "\n";
    
    ComplexNumber justreal(-12.3);
    std::cout << "Test real number in complex form = " << justreal << "\n";
    
    ComplexNumber conj = z1.CalculateConjugate();
    std::cout << "Conjugate of z1 = " << conj << "\n";
    
    conj.SetConjugate();
    std::cout << "After setting conj to be it's own conjugate " << conj << "\n";
        
    return 0;
}


