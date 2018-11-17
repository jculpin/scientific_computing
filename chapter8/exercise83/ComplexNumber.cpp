#include "ComplexNumber.hpp"
#include <cmath>

// Override default constructor
// Set real and imaginary parts to zero
ComplexNumber::ComplexNumber()
{
    mRealPart = 0.0;
    mImaginaryPart = 0.0;
}

// Constructor that sets complex number z=x+iy
ComplexNumber::ComplexNumber(double x, double y)
{
    mRealPart = x;
    mImaginaryPart = y;
}

// Constructor to specify a real number in complex form
ComplexNumber::ComplexNumber(double x)
{
    mRealPart = x;
    mImaginaryPart = 0;
}

// Copy constructor
ComplexNumber::ComplexNumber(const ComplexNumber& z)
{
    mRealPart = RealPart(z);
    mImaginaryPart = ImaginaryPart(z);
}

// Method for computing the modulus of a
// complex number
double ComplexNumber::CalculateModulus() const
{
    return sqrt(mRealPart*mRealPart + 
                mImaginaryPart*mImaginaryPart);
}

// Method for computing the argument of a
// complex number
double ComplexNumber::CalculateArgument() const
{
    return atan2(mImaginaryPart, mRealPart);
}


// Return the real part of the complex number
double ComplexNumber::GetRealPart() const
{
    return mRealPart;
}

// Return imaginary part of complex number
double ComplexNumber::GetImaginaryPart() const
{
    return mImaginaryPart;
}

// Friend method to return real part
double RealPart(const ComplexNumber& z) 
{
    return z.mRealPart;
}

// Friend method to return imaginary part
double ImaginaryPart(const ComplexNumber& z) 
{
    return z.mImaginaryPart;
}

// Method for raising a complex number to the power n
// using De Moivre'ds theorem - first complex
// number must be converted to polar form
ComplexNumber ComplexNumber::CalculatePower(double n) const
{
    double modulus = CalculateModulus();
    double argument = CalculateArgument();
    double mod_of_result = pow(modulus, n);
    double arg_of_result = argument*n;
    double real_part = mod_of_result*cos(arg_of_result);
    double imag_part = mod_of_result*sin(arg_of_result);
    ComplexNumber z(real_part, imag_part);
    return z;
}

// Calculate the conjugate x - iy of complex number x + iy
ComplexNumber ComplexNumber::CalculateConjugate() const
{
    ComplexNumber z(GetRealPart(), -GetImaginaryPart());
    
    return z;
}

//Set the complex number to be it's conjugate
void ComplexNumber::SetConjugate()
{
    mImaginaryPart = -mImaginaryPart;
}

// Overloading the = (assignment) opersator
ComplexNumber& ComplexNumber::operator=(const ComplexNumber& z)
{
    mRealPart = z.mRealPart;
    mImaginaryPart = z.mImaginaryPart;
    return *this;
}

// Overloading the unary - operator
ComplexNumber ComplexNumber::operator-() const
{
    ComplexNumber w;
    w.mRealPart = -mRealPart;
    w.mImaginaryPart = -mImaginaryPart;
    return w;
}

// Overloading the binary + operator
ComplexNumber ComplexNumber::operator+(const ComplexNumber& z) const
{
    ComplexNumber w;
    w.mRealPart = mRealPart + z.mRealPart;
    w.mImaginaryPart = mImaginaryPart + z.mImaginaryPart;
    return w;
}

// Overloading the binary - operator
ComplexNumber ComplexNumber::operator-(const ComplexNumber& z) const
{
    ComplexNumber w;
    w.mRealPart = mRealPart - z.mRealPart;
    w.mImaginaryPart = mImaginaryPart - z.mImaginaryPart;
    return w;
}

// Overload the multiplication operator
ComplexNumber ComplexNumber::operator*(const ComplexNumber& z) const
{
    ComplexNumber w;
    w.mRealPart = mRealPart * z.mRealPart - mImaginaryPart * z.mImaginaryPart;
    w.mImaginaryPart = mRealPart * z.mImaginaryPart + mImaginaryPart * z.mRealPart;
    
    return w;
}

//Overload the * operator for a scalar
ComplexNumber ComplexNumber::operator*(const double factor) const
{
    ComplexNumber w;
    w.mRealPart = factor * mRealPart;
    w.mImaginaryPart = factor * mImaginaryPart;
    
    return w;
}

// Overloading the insertion << operator
std::ostream& operator<<(std::ostream& output, const ComplexNumber& z)
{
    // Format as "(a + bi)" or as "(a - bi)"
    output << "(" << z.mRealPart << " ";
    if(z.mImaginaryPart >= 0.0)
    {
        output << "+ " << z.mImaginaryPart << "i)";
    }
    else
    {
        // z.mImaginary Part < 0.0
        // Replace + with minus sign
        output << "- " << -z.mImaginaryPart << "i)";
    }
    return output;
}

