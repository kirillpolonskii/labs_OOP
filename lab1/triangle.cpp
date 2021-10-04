#include "triangle.h"

Triangle::Triangle(){
    const Point p(0.0, 0.0);
    points.assign(3, p);
}

Triangle::Triangle(std::vector<Point> points) : Triangle(){
    for (int i = 0; i < 3; ++i){
        this->points[i] = points[i];
    }
}

Triangle::Triangle(std::istream& is) : Triangle(){
    std::cout << "Enter the coordinates of triangle: " << std::endl;
    for (int i = 0; i < 3; ++i){
        is >> points[i];
    }
}

Triangle::Triangle(const Triangle& otherTriangle) : Triangle(otherTriangle.points){
    for (int i = 0; i < 3; ++i){
        this->points[i] = otherTriangle.points[i];
    }
}

void Triangle::Print(std::ostream& os){
    os << "Triangle: ";
    for (int i = 0; i < 3; ++i){
        os << points[i] << ' ';
    }
    os << std::endl;
}

double Triangle::Area() {
    double a = points[0].dist(points[1]);
    double b = points[1].dist(points[2]);
    double c = points[0].dist(points[2]);
    double p = (a + b + c) / 2.0;
    double s = sqrt(p * (p - a) * (p - b) * (p - c));
    return s;
}

int Triangle::VertexesNumber() {
    return 3;
}

Triangle::~Triangle() {
    std::cout << "Triangle was deleted" << std::endl;
}
