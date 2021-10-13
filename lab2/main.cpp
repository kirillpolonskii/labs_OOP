#include <iostream>
#include "tbinary_tree.h"
int main() {
// 1.0 0.0 1.0 0.0 1.0 0.0 1.0 0.0 1.0 0.0 1.0 0.0 1.0 0.0 1.0 0.0
// 3.0 4.0 5.0 3.0 6.0 0.0 4.0 -4.0 1.0 -4.0 -2.0 -1.0 -2.0 2.0 0.0 4.0  --  area=50.0
// 3.0 0.0 5.0 2.0 4.0 4.0 2.0 5.0 0.0 4.0 0.0 2.0 1.0 1.0 2.5 0.0  --  area=16.75
// 3.0 0.0 5.0 2.0 4.0 4.0 2.0 5.0 -1.0 3.0 -1.0 1.0 0.0 0.0 1.5 -1.0  --  area=23.0
    Octagon oct1;
    //Octagon oct2;
    std::cin >> oct1;
    //oct2 = oct1;
    //std::cout << oct1;
    //std::cout << oct1.Area() << std::endl;
    //std::cout << oct1.GetArea();
    std::cout << "In main: before creating tree\n";
    TBinaryTree* tree = new TBinaryTree();
    std::cout << "root in main = " << tree->GetRoot();
    std::cout << tree;
    //TBinaryTreeItem* item1 = new TBinaryTreeItem(oct1);
    tree->Push(oct1);
    std::cout << tree->Empty() << std::endl;
    tree->Push(oct1);
    std::cout << tree;
    Octagon oct2;
    std::cin >> oct2;
    tree->Push(oct2);
    Octagon oct3 = oct2;
    tree->Push(oct3);
    std::cout << tree;
    Octagon oct4;
    std::cin >> oct4;
    tree->Push(oct4);
    std::cout << tree;
    return 0;
}
