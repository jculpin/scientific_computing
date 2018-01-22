#include <iostream>
#include <cmath>

using namespace std;

int main ()
{
    double x = 7.8, y = 1.65, u = -1.4, z;
    
    cout << sqrt(10) << "\n";
    cout << pow ( 2, 4) << "\n";
    cout << exp (12) << "\n";
    cout << M_PI << "\n";
    
    z = fmod(x, y);
    cout << z << "\n";
    z = atan2(y, x);
    cout << z << "\n";
    z = fabs(u);
    cout << z << "\n";
}
