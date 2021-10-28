#include "tbinary_tree.h"
#include "string"

TBinaryTree::TBinaryTree() {
    this->root = nullptr;
    //std::cout << "In TBTree: in constructor before NULL_OCT\n";
}

void recursiveCopying(TBinaryTreeItem* parItem, TBinaryTreeItem* curItem, TBinaryTreeItem* otherItem, bool isLeftChild){
    if (otherItem != nullptr){
        curItem = new TBinaryTreeItem(*otherItem);
        if (isLeftChild){
            parItem->SetLeft(curItem);
        }
        else{
            parItem->SetRight(curItem);
        }
        recursiveCopying(curItem, curItem->GetLeft(), otherItem->GetLeft(), true);
        recursiveCopying(curItem, curItem->GetRight(), otherItem->GetRight(), false);
    }
}

TBinaryTree::TBinaryTree(TBinaryTree& otherBinTree){
    this->root = new TBinaryTreeItem(*otherBinTree.root);
    recursiveCopying(this->root, this->root->GetLeft(), otherBinTree.root->GetLeft(), true);
    recursiveCopying(this->root, this->root->GetRight(), otherBinTree.root->GetRight(), false);
}

void TBinaryTree::Push(const Octagon& oct){
    if (this->root == nullptr){
        this->root = new TBinaryTreeItem(oct);
    }
    else if (this->root->GetOctagon() == oct){
        ++this->root->counter;
    }
    else{
        TBinaryTreeItem* parent = this->root;
        TBinaryTreeItem* curItem;
        bool childInLeft = true;
        if (oct.GetArea() < parent->GetOctagon().GetArea()) {
            curItem = this->root->GetLeft();
        }
        else {
            curItem = this->root->GetRight();
            childInLeft = false;
        }
        while (curItem != nullptr){ // while we are not in needed place in tree
            if (curItem->GetOctagon() == oct){ // if all points are same
                ++curItem->counter;
                return;
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
    if (root != nullptr) { // if tree isn't empty
        TBinaryTreeItem *parentDelItem = root;
        bool isLeftLeaf = true; // will need this var in delete leaf
        while (deletedItem != nullptr && !(deletedItem->GetOctagon() == oct)) {
            if (deletedItem != root){
                parentDelItem = deletedItem;
            }
            if (oct.GetArea() < deletedItem->GetOctagon().GetArea()) {
                deletedItem = deletedItem->GetLeft();
                isLeftLeaf = true;
            } else {
                deletedItem = deletedItem->GetRight();
                isLeftLeaf = false;
            }

        }
        if (deletedItem == nullptr) {
            throw std::invalid_argument("There isn't such octagon in tree!");
        }
        if (deletedItem->counter > 1){
            --deletedItem->counter;
            return;
        }
        else {
            if (deletedItem->GetLeft() != nullptr){ // check left subtree
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
                    largestChild = nullptr;
                }
                else{ // if he is the largest child himself. Parent is unnecessary
                    //int tmpCounter;
                    //tmpCounter = deletedItem->counter;
                    deletedItem->counter = largestChild->counter;
                    //largestChild->counter = tmpCounter;
                    deletedItem->SetOctagon(largestChild->GetOctagon());
                    deletedItem->SetLeft(largestChild->GetLeft());
                    delete largestChild;
                    largestChild = nullptr;
                }
            }
            else if (deletedItem->GetRight() != nullptr){ // check right subtree
                TBinaryTreeItem* leastChild = deletedItem->GetRight();
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
                    leastChild = nullptr;
                }
                else{ // if he is the least child himself
                    //int tmpCounter;
                    //tmpCounter = deletedItem->counter;
                    deletedItem->counter = leastChild->counter;
                    //leastChild->counter = tmpCounter;
                    deletedItem->SetOctagon(leastChild->GetOctagon());
                    deletedItem->SetRight(leastChild->GetRight());
                    delete leastChild;
                    leastChild = nullptr;
                }
            }
            else{ // if deleted item is a leaf
                if (deletedItem == root) {
                    root = nullptr;
                    delete root;
                }
                else {
                    deletedItem = nullptr;
                    delete deletedItem;
                    if (isLeftLeaf)
                        parentDelItem->SetLeft(nullptr);
                    else
                        parentDelItem->SetRight(nullptr);
                    //deletedItem = nullptr;
                }
            }
        }
    }
    else {
        std::cout << "Tree is empty!\n";
    }
}

void recursiveCount(const Octagon& octagon, TBinaryTreeItem* curItem, int& ans){
    if (curItem != nullptr){
        recursiveCount(octagon, curItem->GetLeft(), ans);
        recursiveCount(octagon, curItem->GetRight(), ans);
        if (curItem->GetOctagon() == octagon){
            ans += curItem->counter;
        }
    }
}

int TBinaryTree::Count(const Octagon& octagon){
    int ans = 0;
    recursiveCount(octagon, root, ans);
    return ans;
}

void recursiveClear(TBinaryTreeItem* curItem){
    if (curItem != nullptr){
        recursiveClear(curItem->GetLeft());
        recursiveClear(curItem->GetRight());
        delete curItem;
        curItem = nullptr;
    }
}

void TBinaryTree::Clear(){
    recursiveClear(root);
    //delete root;
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
    throw std::out_of_range("Passed area is bigger then maximum in tree!");

}

void recursivePrint(TBinaryTreeItem* curItem, int& closeBracketAmount, std::string& resStr){
    if (curItem != nullptr){
        resStr += std::to_string(curItem->counter) + "*" + std::to_string(curItem->GetOctagon().GetArea());
        if (curItem->GetLeft() != nullptr || curItem->GetRight() != nullptr){
            resStr += ": [";
        }

        recursivePrint(curItem->GetLeft(), closeBracketAmount, resStr);

        if (curItem->GetLeft() != nullptr && curItem->GetRight() != nullptr){
            resStr += ", ";
        }
        recursivePrint(curItem->GetRight(), closeBracketAmount, resStr);
        if (curItem->GetLeft() != nullptr || curItem->GetRight() != nullptr)
            resStr += "]";
    }
    else {
        --closeBracketAmount;
    }
}

std::ostream& operator << (std::ostream& out, TBinaryTree* tree){
    if (tree == nullptr){
        out << "Tree is null" << std::endl;
    }
    else if (tree->root == nullptr){
        out << "Tree is empty\n";
    }
    else{
        std::string resStr;
        int closeBracketAmount = 0;
        recursivePrint(tree->root, closeBracketAmount, resStr);
        out << resStr << std::endl;
    }
    return out;
}

TBinaryTreeItem* TBinaryTree::GetRoot(){
    return root;
}

TBinaryTree::~TBinaryTree() {
    std::cout << "Destructor TBinaryTree was called\n";
    Clear();
}

