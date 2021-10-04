#include <iostream>
#include "octagon.h"
int main() {
// 1.0 0.0 1.0 0.0 1.0 0.0 1.0 0.0 1.0 0.0 1.0 0.0 1.0 0.0 1.0 0.0
    Octagon oct1;
    Octagon oct2;
    std::cin >> oct2;
    std::cout << "Before << oct1\n";
    std::cout << oct1 << std::endl;
    std::cout << "After << oct1\n";
    std::cout << oct2;


    return 0;
}
