#include "tbinary_tree.h"
#include "string"

TBinaryTree::TBinaryTree() {
    root = nullptr;
}

/*void recursiveCopying(TBinaryTreeItem* curItem, TBinaryTreeItem* otherItem){
    if (otherItem != nullptr){
        curItem = new TBinaryTreeItem(*otherItem);
        recursiveCopying(cur)
    }
}*/

TBinaryTree::TBinaryTree(TBinaryTree& otherBinTree) : TBinaryTree(){
    root = new TBinaryTreeItem(*otherBinTree.root);
}

void TBinaryTree::Push(const Octagon& oct){
    if (root == nullptr){
        root = new TBinaryTreeItem(oct);
    }
    else if (root->GetOctagon() == oct){
        ++root->counter;
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
                ++curItem->counter;
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

void TBinaryTree::Pop(const Octagon& oct){
    TBinaryTreeItem* deletedItem = root;
    if (root != nullptr) {
        while (deletedItem != nullptr && !(deletedItem->GetOctagon() == oct)) {
            if (oct.GetArea() < deletedItem->GetOctagon().GetArea()) {
                deletedItem = deletedItem->GetLeft();
            } else {
                deletedItem = deletedItem->GetRight();
            }
        }
        if (deletedItem == nullptr) {
            std::cout << "There isn't such octagon in tree.\n";
        }
        else { //
            if (deletedItem->GetLeft() != nullptr){
                TBinaryTreeItem* largestChild = deletedItem->GetLeft();
                if (largestChild->GetRight() != nullptr) { // if he isn't the largest child himself
                    TBinaryTreeItem *parent = largestChild;
                    largestChild = parent->GetRight();
                    while (largestChild->GetRight() != nullptr) {
                        parent = largestChild;
                        largestChild = largestChild->GetRight();
                    }
                    // here we swap the values in deleted item and largest child and change pointers to children
                    //int tmpCounter;
                    //tmpCounter = deletedItem->counter;
                    deletedItem->counter = largestChild->counter;
                    //largestChild->counter = tmpCounter;
                    deletedItem->SetOctagon(largestChild->GetOctagon());
                    // in fact, we don't delete deletedItem, we delete the largest child and put his values to deletedItem
                    parent->SetRight(largestChild->GetLeft());
                    delete largestChild;

                }
                else{ // if he is the largest child himself
                    //int tmpCounter;
                    //tmpCounter = deletedItem->counter;
                    deletedItem->counter = largestChild->counter;
                    //largestChild->counter = tmpCounter;
                    deletedItem->SetOctagon(largestChild->GetOctagon());
                    deletedItem->SetLeft(largestChild->GetLeft());
                    delete largestChild;
                }
            }
            else if (deletedItem->GetRight() != nullptr){ // if there is right child
                TBinaryTreeItem* leastChild = deletedItem->GetLeft();
                if (leastChild->GetLeft() != nullptr) { // if he isn't the least child himself
                    TBinaryTreeItem *parent = leastChild;
                    leastChild = parent->GetLeft();
                    while (leastChild->GetLeft() != nullptr) {
                        parent = leastChild;
                        leastChild = leastChild->GetLeft();
                    }
                    // here we swap the values in deleted item and largest child and change pointers to children
                    //int tmpCounter;
                    //tmpCounter = deletedItem->counter;
                    deletedItem->counter = leastChild->counter;
                    //leastChild->counter = tmpCounter;
                    deletedItem->SetOctagon(leastChild->GetOctagon());
                    // in fact, we don't delete deletedItem, we delete the largest child and put his values to deletedItem
                    parent->SetLeft(leastChild->GetRight());
                    delete leastChild;

                }
                else{ // if he is the least child himself
                    //int tmpCounter;
                    //tmpCounter = deletedItem->counter;
                    deletedItem->counter = leastChild->counter;
                    //leastChild->counter = tmpCounter;
                    deletedItem->SetOctagon(leastChild->GetOctagon());
                    deletedItem->SetRight(leastChild->GetRight());
                    delete leastChild;
                }
            }
            else{ // if deleted item is a leaf
                delete deletedItem;
                deletedItem = nullptr;
            }
        }
    }
    else {
        std::cout << "Tree is empty!\n";
    }

}

void recursiveCount(double minArea, double maxArea, TBinaryTreeItem* curItem, int& ans){
    if (curItem != nullptr){
        recursiveCount(minArea, maxArea, curItem->GetLeft(), ans);
        recursiveCount(minArea, maxArea, curItem->GetRight(), ans);
        if (minArea <= curItem->GetOctagon().GetArea() && curItem->GetOctagon().GetArea() < maxArea){
            ++ans;
        }
    }
}

int TBinaryTree::Count(double minArea, double maxArea){
    int ans = 0;
    //TBinaryTreeItem* curItem = root;
    recursiveCount(minArea, maxArea, root, ans);
    return ans;
}

//void reverseClear(TBinaryTreeItem* parent, TBinaryTreeItem* curItem){
void recursiveClear(TBinaryTreeItem* curItem){
    //if ((parent->GetLeft()->GetLeft() != nullptr || parent->GetLeft()->GetRight() != nullptr) ||
    //    (parent->GetRight()->GetLeft() != nullptr || parent->GetRight()->GetRight() != nullptr)){
    if (curItem != nullptr){
        recursiveClear(curItem->GetLeft());
        recursiveClear(curItem->GetRight());
        //if (curItem->GetLeft() != nullptr){
            delete curItem;
            curItem = nullptr;
        //}
    }
}

void TBinaryTree::Clear(){
    recursiveClear(root);
    delete root;
    root = nullptr;
}

bool TBinaryTree::Empty(){
    return root == nullptr;
}

Octagon& TBinaryTree::GetItemNotLess(double area) {
    TBinaryTreeItem* curItem = root;
    while (curItem != nullptr){
        if (curItem->GetOctagon().GetArea() >= area){
            return curItem->GetOctagon();
        }
        else {
            curItem = curItem->GetRight();
        }
    }
    return TBinaryTreeItem::NULL_OCT;

}

void recursivePrint(TBinaryTreeItem* curItem, bool isLeftChild, int& closeBracketAmount, std::string& resStr){
    if (curItem != nullptr){
        resStr += std::to_string(curItem->counter) + "*" + std::to_string(curItem->GetOctagon().GetArea());
        if (curItem->GetLeft() != nullptr || curItem->GetRight() != nullptr){
            resStr += ": [";
        }
        recursivePrint(curItem->GetLeft(), true, closeBracketAmount, resStr);
        if (curItem->GetRight() != nullptr){
            resStr += ", ";
        }
        ++closeBracketAmount;
        recursivePrint(curItem->GetRight(), false, closeBracketAmount, resStr);
        while (closeBracketAmount > 0){
            resStr += "]";
            --closeBracketAmount;
        }
    }
    else if (!isLeftChild){
        --closeBracketAmount;
    }
}

std::ostream& operator << (std::ostream& out, TBinaryTree* tree){
    if (tree == nullptr){
        out << "null" << std::endl;
    }
    else if (tree->root == nullptr){
        out << '\n';
    }
    else{
        std::string resStr;
        int closeBracketAmount = 0;
        recursivePrint(tree->root, true, closeBracketAmount, resStr);
    }
}

TBinaryTree::~TBinaryTree() {

}

