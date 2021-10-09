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

void reverseCount(double minArea, double maxArea, TBinaryTreeItem* curItem, int& ans){
    if (curItem != nullptr){
        reverseCount(minArea, maxArea, curItem->GetLeft(), ans);
        reverseCount(minArea, maxArea, curItem->GetRight(), ans);
        if (minArea <= curItem->GetOctagon().GetArea() && curItem->GetOctagon().GetArea() < maxArea){
            ++ans;
        }
    }
}

int TBinaryTree::Count(double minArea, double maxArea){
    int ans = 0;
    //TBinaryTreeItem* curItem = root;
    reverseCount(minArea, maxArea, root, ans);
    return ans;
}

//void reverseClear(TBinaryTreeItem* parent, TBinaryTreeItem* curItem){
void reverseClear(TBinaryTreeItem* curItem){
    //if ((parent->GetLeft()->GetLeft() != nullptr || parent->GetLeft()->GetRight() != nullptr) ||
    //    (parent->GetRight()->GetLeft() != nullptr || parent->GetRight()->GetRight() != nullptr)){
    if (curItem != nullptr){
        reverseClear(curItem->GetLeft());
        reverseClear(curItem->GetRight());
        //if (curItem->GetLeft() != nullptr){
            delete curItem;
            curItem = nullptr;
        //}
    }
}

void TBinaryTree::Clear(){
    reverseClear(root);
    delete root;
    root = nullptr;
}

bool TBinaryTree::Empty(){
    return root == nullptr;
}


TBinaryTree::~TBinaryTree() {

}

