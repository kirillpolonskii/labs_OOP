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
    friend std::ostream& operator << (std::ostream& os, Octagon& oct); // checked
    friend std::istream& operator >> (std::istream& is, Octagon& oct); // checked
    Octagon& operator= (const Octagon& copiedOct){ // checked
        for (int i = 0; i < 8; ++i){
            this->points[i] = copiedOct.points[i];
        }
        for (int i = 1; i < 7; ++i){
            this->area += Octagon::triangleArea(copiedOct.points[0], copiedOct.points[i], copiedOct.points[i + 1]);
        }
        return *this;
    }
    friend bool operator == (const Octagon& oct1, const Octagon& oct2); // checked
    double Area();
    double GetArea() const;
    double triangleArea(Point p1, Point p2, Point p3);
    int VertexesNumber();
    ~Octagon();

    static const int VERTICES_NUM = 8;
};

#endif //LAB2_OCTAGON_H