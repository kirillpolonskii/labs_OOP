#include "tbinary_tree.h"

TBinaryTree::TBinaryTree() {
    this->root = nullptr;
}

TBinaryTree::TBinaryTree(const TBinaryTree& otherBinTree) : TBinaryTree(){
    // for now it's empty
}

void TBinaryTree::Push(Octagon& oct){
    if (root == nullptr){
        root = new TBinaryTreeItem(oct);
    }
    else if (root->GetOctagon() == oct){
        root->IncCounter();
    }
    else{
        TBinaryTreeItem* parent = root;
        TBinaryTreeItem* curItem;
        bool childInLeft = true;
        if (oct.GetArea() < parent->GetOctagon().GetArea()) {
            curItem = root->GetLeft();
        }
        else {
            curItem = root->GetRight();
            childInLeft = false;
        }
        while (curItem != nullptr){ // while we are not in needed place in tree
            if (curItem->GetOctagon() == oct){ // if all points are same
                curItem->IncCounter();
            }
            else { // compare with area
                if (oct.GetArea() < curItem->GetOctagon().GetArea()){ // go to left child
                    parent = curItem;
                    curItem = parent->GetLeft();
                    childInLeft = true;
                }
                else { // go to right child
                    parent = curItem;
                    curItem = parent->GetRight();
                    childInLeft = false;
                }
            }
        }
        curItem = new TBinaryTreeItem(oct);
        if (childInLeft){ // set the pointers
            parent->SetLeft(curItem);
        }
        else{
            parent->SetRight(curItem);
        }
    }

}


bool TBinaryTree::Empty(){
    return root == nullptr;
}


TBinaryTree::~TBinaryTree() {

}

