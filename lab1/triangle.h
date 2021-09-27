#ifndef LAB1_TRIANGLE_H
#define LAB1_TRIANGLE_H
#include "figure.h"
#include <vector>

class Triangle : public Figure{
private:
    std::vector<Point> points;
public:
    Triangle();
    Triangle(std::vector<Point> points);
    Triangle(std::istream& is);
    Triangle(const Triangle& otherTriangle);
    void Print(std::ostream& os);
    double Area();
    int VertexesNumber();
    ~Triangle();
};

#endif //LAB1_TRIANGLE_H