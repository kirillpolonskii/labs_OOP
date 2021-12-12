#include <iostream>
#include "tbinary_tree.h"
// 1.0 0.0 1.0 0.0 1.0 0.0 1.0 0.0 1.0 0.0 1.0 0.0 1.0 0.0 1.0 0.0
// 3.0 4.0 5.0 3.0 6.0 0.0 4.0 -4.0 1.0 -4.0 -2.0 -1.0 -2.0 2.0 0.0 4.0  --  area=50.0
// 3.0 0.0 5.0 2.0 4.0 4.0 2.0 5.0 0.0 4.0 0.0 2.0 1.0 1.0 2.5 0.0  --  area=16.75
// 3.0 0.0 5.0 2.0 4.0 4.0 2.0 5.0 -1.0 3.0 -1.0 1.0 0.0 0.0 1.5 -1.0  --  area=23.0
// 4.0 1.0 6.0 3.0 5.0 5.0 3.0 6.0 0.0 4.0 0.0 2.0 1.0 1.0 2.5 0.0  --  area=23.0
// 3.0 0.0 5.0 2.0 4.0 4.0 2.0 7.0 -1.0 3.0 -1.0 1.0 0.0 -1.0 2.0 -1.0  --  area=29.5
int main() {
    int command;
    std::vector<std::shared_ptr<Octagon>> addedOctagons;
    TBinaryTree<Octagon>* tree = nullptr;
    int numOfItem = 0;
    while(true){
        std::cout << "----------------MENU----------------\n";
        std::cout << "0 : Exit the program" << "\n"; // checked
        std::cout << "1 : Add octagon in tree\n"; // checked
        std::cout << "2 : Get first item with area not less than entered\n"; // checked
        std::cout << "3 : Get number of entries of octagon by the queue number of your input\n"; // checked
        std::cout << "4 : Get the first item with area not less entered and delete it\n"; // checked
        std::cout << "5 : Clear tree\n"; // checked
        std::cout << "6 : Create tree from another tree\n"; // checked
        std::cout << "7 : Print tree\n"; // checked
        std::cout << "8 : Create tree\n"; // checked
        std::cout << "9 : Delete tree\n"; // checked
        std::cout << "10 : Use iterators\n";
        std::cin >> command;

        switch (command) {
            case 0:{
                delete tree;
                return 0;
            }
            case 1:{
                std::cout << numOfItem + 1 << ".\n";
                std::shared_ptr<Octagon> oct = std::make_shared<Octagon>();
                std::cin >> *oct;
                std::cout << oct->GetArea() << std::endl;
                addedOctagons.push_back(oct);
                ++numOfItem;
                tree->Push(oct);
                break;
            }
            case 2:{
                double area;
                std::cout << "Enter the area:\n";
                std::cin >> area;
                try{
                    std::shared_ptr<Octagon> oct = tree->GetItemNotLess(area);
                    std::cout << *oct << "(its area = " << std::setprecision(5) << oct->GetArea() << ")" << std::endl;
                }
                catch(std::exception& ex){
                    std::cout << ex.what() << std::endl;
                }
                break;
            }
            case 3:{
                int num;
                std::cout << "Enter the index number of entered items:\n";
                std::cin >> num;
                std::cout << *addedOctagons[num - 1] << "with area = " << std::setprecision(4) <<
                          addedOctagons[num - 1]->GetArea() << " meets " <<
                          tree->Count(addedOctagons[num - 1]) << " times in tree\n";
                break;
            }
            case 4:{
                double area;
                std::cout << "Enter the area:\n";
                std::cin >> area;
                try{
                    std::shared_ptr<Octagon> deletedOct = tree->GetItemNotLess(area);
                    tree->Pop(deletedOct);
                }
                catch(std::exception& ex){
                    std::cout << ex.what() << std::endl;
                }
                break;
            }
            case 5:{
                tree->Clear();
                numOfItem = 0;
                break;
            }
            case 6:{
                TBinaryTree<Octagon>* otherTree = new TBinaryTree(*tree);
                std::cout << "Copied: " << otherTree;
                delete otherTree;
                break;
            }
            case 7:{
                std::cout << tree;
                break;
            }
            case 8:{
                tree = new TBinaryTree<Octagon>();
                break;
            }
            case 9:{
                delete tree;
                tree = nullptr;
                numOfItem = 0;
                break;
            }
            case 10:{
                TIterator<TBinaryTreeItem<Octagon>, Octagon> iterator(tree->GetRoot());
                std:: cout << "Iterator points on octagon: " << *iterator << std:: endl;
                iterator.GoToLeft();
                std:: cout << "Its left descendant: ";
                std:: cout << *iterator << std:: endl;
                iterator.GoToRight();
                std:: cout << "Its right descendant: " << *iterator << std:: endl;
                TIterator<TBinaryTreeItem<Octagon>, Octagon> iterA(tree->GetRoot()->GetLeft());
                TIterator<TBinaryTreeItem<Octagon>, Octagon> iterB(tree->GetRoot()->GetLeft());
                if (iterA == iterB) {
                    std:: cout << "Comparison of iterators is working: 1" << std::endl;
                }
                TIterator<TBinaryTreeItem<Octagon>, Octagon> iterC(tree->GetRoot()->GetRight());
                if (iterC != iterA) {
                    std:: cout << "Comparison of iterators is working: 2" << std::endl;
                }
                break;
            }
        }
    }
}
