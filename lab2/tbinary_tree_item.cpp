#include "tbinary_tree_item.h"
TBinaryTreeItem::TBinaryTreeItem(const Octagon& oct) {
    std::cout << "In TBItem constructor\n";
    this->octagon = oct;
    this->left = nullptr;
    this->right = nullptr;
    this->counter = 1;
}

TBinaryTreeItem::TBinaryTreeItem(TBinaryTreeItem& other) {
    //if (other != nullptr){
        this->octagon = other.octagon;
        this->left = other.left;
        this->right = other.right;
        this->counter = other.counter;
    //}

}

Octagon& TBinaryTreeItem::GetOctagon() {
    return this->octagon;
}

void TBinaryTreeItem::SetOctagon(const Octagon &oct) {
    this->octagon = oct;
}

TBinaryTreeItem* TBinaryTreeItem::GetLeft() {
    if (this != nullptr){
        return this->left;
    }
    else
        return nullptr;
}

void TBinaryTreeItem::SetLeft(TBinaryTreeItem* tBinTreeItem) {
    if (this != nullptr){
        this->left = tBinTreeItem;
    }
}

TBinaryTreeItem* TBinaryTreeItem::GetRight() {
    if (this != nullptr){
        return this->right;
    }
    else
        return nullptr;
}

void TBinaryTreeItem::SetRight(TBinaryTreeItem* tBinTreeItem) {
    if (this != nullptr){
        this->right = tBinTreeItem;
    }
}

/*double TBinaryTreeItem::GetArea(){
    if (this != nullptr){
        return octagon.GetArea();
    }
}*/

std::ostream& operator << (std::ostream& out, TBinaryTreeItem* treeItem){
    if (treeItem != nullptr){
        out << treeItem->counter << '*' << treeItem->GetOctagon().GetArea();
    }
    else {
        out << "null";
    }
    return out;
}

TBinaryTreeItem::~TBinaryTreeItem() {
    //delete this->left;
    //delete this->right;
    std::cout << "Destructor TBinaryTreeItem was called\n";
}