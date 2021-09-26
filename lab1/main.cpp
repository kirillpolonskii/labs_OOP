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
    oct1.Print(std::cout);
    std::cout << "His Area is " << oct1.Area() << "\n";
    oct2.Print(std::cout);
    std::cout << "His Area is " << oct2.Area() << "\n";
    oct3.Print(std::cout);
    std::cout << "His Area is " << oct3.Area() << "\n";
    copiedOct->Print(std::cout);
    std::cout << "His Area is " << copiedOct->Area() << "\n";

    Triangle tr1(std::cin);
    tr1.Print(std::cout);
    std::cout << "His Area is " << tr1.Area() << "\n";

    Square sq1(std::cin);
    sq1.Print(std::cout);
    std::cout << "His Area is " << sq1.Area() << "\n";


    return 0;
}