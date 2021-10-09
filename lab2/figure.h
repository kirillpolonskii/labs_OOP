#ifndef LAB2_FIGURE_H
#define LAB2_FIGURE_H

#include "point.h"

class Figure {
private:
    double area;
public :
    virtual double Area() = 0;
    virtual int VertexesNumber() = 0;

    //virtual ~Figure();
};

#endif
