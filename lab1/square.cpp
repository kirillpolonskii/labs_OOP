#include "square.h"

Square::Square(){
    //std::cout << "Empty constructor was called\n";
    //std::cout << "-----" << std::endl;
    const Point p(0.0, 0.0);
    points.assign(4, p);
}

Square::Square(std::vector<Point> points) : Square(){
    //const Point p(0.0, 0.0);
    //points.assign(8, p);
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

void Square::print(std::ostream& os){
    os << "Square: ";
    for (int i = 0; i < 4; ++i){
        os << points[i] << ' ';
    }
    os << std::endl;
}

double Square::area() {
    double a = points[0].dist(points[1]);
    double s = a * a;
    //std::cout << s << std::endl;
    return s;
}

int Square::getVertexesNumber() {
    return 4;
}