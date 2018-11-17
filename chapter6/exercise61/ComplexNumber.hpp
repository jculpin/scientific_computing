#ifndef COMPLEXNUMBERHEADER
#define COMPLEXNUMBERHEADER

#include <iostream>

class ComplexNumber
{
private:
    double mRealPart;
    double mImaginaryPart;
public:
    ComplexNumber();
    ComplexNumber(double x, double y);
    ComplexNumber(double x);
    ComplexNumber(const ComplexNumber& z);
    double CalculateModulus() const;
    double CalculateArgument() const;
    double GetRealPart() const;
    double GetImaginaryPart() const;
    ComplexNumber CalculatePower(double n) const;
    ComplexNumber CalculateConjugate() const;
    void SetConjugate();
    ComplexNumber& operator=(const ComplexNumber& z);
    ComplexNumber operator-() const;
    ComplexNumber operator+(const ComplexNumber& z) const;
    ComplexNumber operator-(const ComplexNumber& z) const;
    ComplexNumber operator*(const ComplexNumber& z) const;
    ComplexNumber operator*(const double factor) const;
    friend ComplexNumber** CreateComplexArray();
    friend void DeleteComplexArray(ComplexNumber** A);
    friend double RealPart(const ComplexNumber& z);
    friend double ImaginaryPart(const ComplexNumber& z);
    friend std::ostream& operator<<(std::ostream& output,
                             const ComplexNumber& z);
                                   
};

#endif
    
