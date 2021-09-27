#ifndef LAB1_FIGURE_H
#define LAB1_FIGURE_H

#include "point.h"

class Figure {
    virtual void Print(std::ostream& os) = 0;
    virtual double Area() = 0;
    virtual int VertexesNumber() = 0;
    virtual ~Figure();
};

#endif