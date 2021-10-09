#include "octagon.h"
// перед написанием контейнера протестирую каждую функцию
// tested
Octagon::Octagon(){
    std::cout << "Empty constructor was called\n";
    std::cout << "-----" << std::endl;
    const Point p(0.0, 0.0);
    this->points.assign(8, p);
    this->area = 0;
}

std::istream& operator >> (std::istream& is, Octagon& oct){
    const Point p(0.0, 0.0);
    oct.points.assign(8, p);
    std::cout << "Enter the coordinates of octagon: " << std::endl;
    for (int i = 0; i < 8; ++i){
        is >> oct.points[i];
    }
    std::cout << "Out of >>\n";
    return is;
}

Octagon::Octagon(std::vector<Point> points) : Octagon(){
    //const Point p(0.0, 0.0);
    //points.assign(8, p);
    for (int i = 0; i < 8; ++i){
        this->points[i] = points[i];
    }
    for (int i = 1; i < 7; ++i){
        this->area += Octagon::triangleArea(points[0], points[i], points[i + 1]);
    }
}

std::ostream& operator << (std::ostream& os, Octagon& oct){
    os << "Enter in << \n";
    os << "Octagon: ";
    for (int i = 0; i < 8; ++i){
        os << oct.points[i] << ' ';
    }
    os << std::endl;
    return os;
}

bool operator == (Octagon& oct1, Octagon& oct2){
    for (int i = 0; i < Octagon::VERTICES_NUM; ++i){
        if (!(oct1.points[i] == oct2.points[i])){
            return false;
        }
    }
    return true;
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

double Octagon::GetArea() {
    return area;
}

Octagon::~Octagon() {}