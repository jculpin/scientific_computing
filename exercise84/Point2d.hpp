#include <cmath>

class Point2d
{
public:
    double x, y;
    Point2d(double a, double b)
    {
        x = a;
        y = b;
    }
    bool operator<(const Point2d& other) const
    {
        if(x < other.x && fabs(x - other.x) > 1.0e-8)
        {
            return true;
        }
        else if(x > other.x && fabs(x - other.x) > 1.0e-8)
        {
            return false;
        }
        else if (y < other.y && fabs(y - other.y) > 1.0e-8)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
            
        
