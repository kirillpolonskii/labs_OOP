#include "tbinary_tree_item.h"

TBinaryTreeItem::TBinaryTreeItem(const Octagon& oct) {
    this->octagon = oct;
    this->left = nullptr;
    this->right = nullptr;
}

TBinaryTreeItem::TBinaryTreeItem(const TBinaryTreeItem& other) {
    this->octagon = other.octagon;
    this->left = other.left;
    this->right = other.right;
}

Octagon& TBinaryTreeItem::GetOctagon() {
    if (this != nullptr){
        return this->octagon;
    }
}

void TBinaryTreeItem::SetOctagon(const Octagon &oct) {
    this->octagon = oct;
}

TBinaryTreeItem* TBinaryTreeItem::GetLeft() {
    if (this != nullptr){
        return this->left;
    }
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
}

void TBinaryTreeItem::SetRight(TBinaryTreeItem* tBinTreeItem) {
    if (this != nullptr){
        this->right = tBinTreeItem;
    }
}

TBinaryTreeItem::~TBinaryTreeItem() {
    delete this->left;
    delete this->right;
}