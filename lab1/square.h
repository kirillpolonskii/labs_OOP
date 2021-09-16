#ifndef LAB1_SQUARE_H
#define LAB1_SQUARE_H

#include "figure.h"
#include <vector>

class Square : public Figure{
private:
    std::vector<Point> points;
public:
    Square();
    Square(std::vector<Point> points);
    Square(std::istream& is);
    Square(const Square& otherSquare);
    void print(std::ostream& os);
    double area();
    int getVertexesNumber();
};
#endif //LAB1_SQUARE_H