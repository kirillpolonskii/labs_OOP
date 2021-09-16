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
    void print(std::ostream& os);
    double area();
    int getVertexesNumber();
};

#endif //LAB1_TRIANGLE_H