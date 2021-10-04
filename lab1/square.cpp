#include "square.h"

Square::Square(){
    const Point p(0.0, 0.0);
    points.assign(4, p);
}

Square::Square(std::vector<Point> points) : Square(){
    for (int i = 0; i < 4; ++i){
        this->points[i] = points[i];
    }
}

Square::Square(std::istream& is) : Square(){
    std::cout << "Enter the coordinates of square: " << std::endl;
    for (int i = 0; i < 4; ++i){
        is >> points[i];
    }
}

Square::Square(const Square& otherSquare) : Square(otherSquare.points){
    for (int i = 0; i < 4; ++i){
        this->points[i] = otherSquare.points[i];
    }
}

void Square::Print(std::ostream& os){
    os << "Square: ";
    for (int i = 0; i < 4; ++i){
        os << points[i] << ' ';
    }
    os << std::endl;
}

double Square::Area() {
    double a = points[0].dist(points[1]);
    double s = a * a;
    return s;
}

int Square::VertexesNumber() {
    return 4;
}

Square::~Square() {std::cout << "Square was deleted" << std::endl;}