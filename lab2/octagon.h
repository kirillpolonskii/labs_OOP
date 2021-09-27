#ifndef LAB2_OCTAGON_H
#define LAB2_OCTAGON_H

#include "figure.h"
#include <vector>

class Octagon : public Figure{
private:
    std::vector<Point> points;
public:
    Octagon();
    Octagon(std::vector<Point> points);
    Octagon(const Octagon& otherOct);
    friend std::ostream& operator << (std::ostream& os, Octagon& oct);
    friend std::istream& operator >> (std::istream& is, Octagon& oct);
    Octagon& operator= (Octagon& copiedOct){
        for (int i = 0; i < 8; ++i){
            this->points[i] = copiedOct.points[i];
        }
        return *this;
    }
    double Area();
    double triangleArea(Point p1, Point p2, Point p3);
    int VertexesNumber();
    ~Octagon();

    static const int VERTICES_NUM = 3;
};

#endif //LAB2_OCTAGON_H