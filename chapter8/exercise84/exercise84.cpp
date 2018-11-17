#include <set>
#include <iostream>
#include "Point2d.hpp"

int main(int argc, char* argv[])
{
    std::set<Point2d> points;
    Point2d origin(0.0,0.0);
    points.insert(origin);
    points.insert(Point2d(-2.00000001,1.1));
    points.insert(Point2d(-2.0,-5.0));
    points.insert(Point2d(0.0,0.0));
    
    std::cout << "Number of points in set = "
              << points.size() << "\n";
    std::set<Point2d>::const_iterator c;
    for(c=points.begin(); c!=points.end(); c++)
    {
        std::cout << c->x << " " << c->y << "\n";
    }
        
    return 0;
}
