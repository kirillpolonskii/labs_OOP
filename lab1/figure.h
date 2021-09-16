#ifndef LAB1_FIGURE_H
#define LAB1_FIGURE_H

#include "point.h"

class Figure {
    virtual void print(std::ostream& os) = 0;
    virtual double area() = 0;
    virtual int getVertexesNumber() = 0;
};

#endif