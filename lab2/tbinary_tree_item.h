#ifndef LAB2_TBINARY_TREE_ITEM_H
#define LAB2_TBINARY_TREE_ITEM_H

#include "octagon.h"

class TBinaryTreeItem {
private:
    Octagon octagon;
    TBinaryTreeItem* left;
    TBinaryTreeItem* right;
    int counter;
public:
    TBinaryTreeItem(const Octagon& oct);
    TBinaryTreeItem(const TBinaryTreeItem& other);
    Octagon& GetOctagon();
    void SetOctagon(const Octagon& oct);
    TBinaryTreeItem* GetLeft();
    void SetLeft(TBinaryTreeItem* tBinTreeItem);
    TBinaryTreeItem* GetRight();
    void SetRight(TBinaryTreeItem* tBinTreeItem);
    //double GetArea();
    void IncCounter();
    virtual ~TBinaryTreeItem();

};


#endif //LAB2_TBINARY_TREE_ITEM_H
