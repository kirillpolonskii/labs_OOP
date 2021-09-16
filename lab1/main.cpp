#include "octagon.h"
#include "triangle.h"
#include "square.h"

int main() {
    Octagon oct1;
    std::vector<Point> points;
    const Point p(0.0, 0.0);
    points.assign(8, p);
    for (int i = 0; i < 8; ++i){
        Point p(0.0, 0.0);
        points[i] = p;
    }
    Octagon oct2(points);
    Octagon oct3(std::cin);
    Octagon* copiedOct = new Octagon(oct2);
    oct1.print(std::cout);
    std::cout << "His area is " << oct1.area() << "\n";
    oct2.print(std::cout);
    std::cout << "His area is " << oct2.area() << "\n";
    oct3.print(std::cout);
    std::cout << "His area is " << oct3.area() << "\n";
    copiedOct->print(std::cout);
    std::cout << "His area is " << copiedOct->area() << "\n";

    Triangle tr1(std::cin);
    tr1.print(std::cout);
    std::cout << "His area is " << tr1.area() << "\n";

    Square sq1(std::cin);
    sq1.print(std::cout);
    std::cout << "His area is " << sq1.area() << "\n";


    return 0;
}