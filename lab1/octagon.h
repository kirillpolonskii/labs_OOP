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
    void print(std::ostream& os);
    double area();
    double triangleArea(Point p1, Point p2, Point p3);
    int getVertexesNumber();
};

#endif //LAB1_OCTAGON_H