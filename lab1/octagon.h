#ifndef LAB1_OCTAGON_H
#define LAB1_OCTAGON_H

#include "figure.h"
#include <vector>

class Octagon : public Figure{
private:
    std::vector<Point> points;
public:
    Octagon();
    Octagon(std::vector<Point> points);
    Octagon(std::istream& is);
    Octagon(const Octagon& otherOct);
    void Print(std::ostream& os);
    double Area();
    double triangleArea(Point p1, Point p2, Point p3);
    int VerticesNumber();
};

#endif //LAB1_OCTAGON_H