#include "octagon.h"

Octagon::Octagon(){
    //std::cout << "Empty constructor was called\n";
    //std::cout << "-----" << std::endl;
    const Point p(0.0, 0.0);
    points.assign(8, p);
}

std::istream& operator >> (std::istream& is, Octagon& oct){
    //const Point p(0.0, 0.0);
    //points.assign(8, p);
    std::cout << "Enter the coordinates of octagon: " << std::endl;
    for (int i = 0; i < 8; ++i){
        is >> oct.points[i];
    }
}

Octagon::Octagon(std::vector<Point> points) : Octagon(){
    //const Point p(0.0, 0.0);
    //points.assign(8, p);
    for (int i = 0; i < 8; ++i){
        this->points[i] = points[i];
    }
}



Octagon::Octagon(const Octagon& otherOct) : Octagon(otherOct.points){
    for (int i = 0; i < 8; ++i){
        this->points[i] = otherOct.points[i];
    }
}

std::ostream& operator << (std::ostream& os, Octagon& oct){
    os << "Octagon: ";
    for (int i = 0; i < 8; ++i){
        os << oct.points[i] << ' ';
    }
    os << std::endl;
}

double Octagon::triangleArea(Point p1, Point p2, Point p3) {
    double a = p1.dist(p2);
    double b = p2.dist(p3);
    double c = p1.dist(p3);
    double p = (a + b + c) / 2.0;
    double s = sqrt(p * (p - a) * (p - b) * (p - c));
    //std::cout << s << std::endl;
    return s;
}

double Octagon::Area() {
    double s = 0.0;
    for (int i = 1; i < 7; ++i){
        s += Octagon::triangleArea(points[0], points[i], points[i + 1]);
    }
    return s;
}

int Octagon::VertexesNumber() {
    return Octagon::VERTICES_NUM;
}

Octagon::~Octagon() {}