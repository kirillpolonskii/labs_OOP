#ifndef LAB2_POINT_H
#define LAB2_POINT_H

#include <iostream>
#include <iomanip>
#include <cmath>
class Point {

private:
    double x,y;
public:
    Point();
    Point(double x, double y);
    Point(std::istream& is);

    double dist(const Point& other);

    friend std::istream& operator >> (std::istream& is, Point& point);
    friend std::ostream& operator << (std::ostream& os, Point& point);

};

#endif