#ifndef LAB2_TBINARY_TREE_ITEM_H
#define LAB2_TBINARY_TREE_ITEM_H

#include "octagon.h"

class TBinaryTreeItem {
private:
    Octagon octagon;
    TBinaryTreeItem* left;
    TBinaryTreeItem* right;

public:
    TBinaryTreeItem(const Octagon& oct);
    TBinaryTreeItem(TBinaryTreeItem& other);
    Octagon& GetOctagon();
    void SetOctagon(const Octagon& oct);
    TBinaryTreeItem* GetLeft();
    void SetLeft(TBinaryTreeItem* tBinTreeItem);
    TBinaryTreeItem* GetRight();
    void SetRight(TBinaryTreeItem* tBinTreeItem);
    friend std::ostream& operator << (std::ostream& out, TBinaryTreeItem* treeItem);
    virtual ~TBinaryTreeItem();

    int counter;
    static Octagon& NULL_OCT;
};


#endif //LAB2_TBINARY_TREE_ITEM_H
