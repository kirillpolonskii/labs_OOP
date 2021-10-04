#ifndef LAB2_OCTAGON_H
#define LAB2_OCTAGON_H

#include "figure.h"
#include <vector>

class Octagon : public Figure{
private:
    std::vector<Point> points;
    double area;
public:
    Octagon();
    Octagon(std::vector<Point> points);
    Octagon(const Octagon& otherOct);
    friend std::ostream& operator << (std::ostream& os, Octagon& oct);
    friend std::istream& operator >> (std::istream& is, Octagon& oct);
    Octagon& operator= (const Octagon& copiedOct){
        for (int i = 0; i < 8; ++i){
            this->points[i] = copiedOct.points[i];
        }
        for (int i = 1; i < 7; ++i){
            this->area += Octagon::triangleArea(copiedOct.points[0], copiedOct.points[i], copiedOct.points[i + 1]);
        }
        return *this;
    }
    friend bool operator == (Octagon& oct1, Octagon& oct2);
    double Area();
    double triangleArea(Point p1, Point p2, Point p3);
    int VertexesNumber();
    ~Octagon();

    static const int VERTICES_NUM = 3;
};

#endif //LAB2_OCTAGON_H