#ifndef LAB2_TBINARY_TREE_ITEM_H
#define LAB2_TBINARY_TREE_ITEM_H

#include "octagon.h"

class TBinaryTreeItem {
private:
    Octagon octagon;
    TBinaryTreeItem* left;
    TBinaryTreeItem* right;

public:
    TBinaryTreeItem(const Octagon& oct); // checked
    TBinaryTreeItem(TBinaryTreeItem& other);
    Octagon& GetOctagon(); // checked
    void SetOctagon(const Octagon& oct);
    TBinaryTreeItem* GetLeft(); // checked
    void SetLeft(TBinaryTreeItem* tBinTreeItem); // checked
    TBinaryTreeItem* GetRight(); // checked
    void SetRight(TBinaryTreeItem* tBinTreeItem); // checked
    friend std::ostream& operator << (std::ostream& out, TBinaryTreeItem* treeItem);
    virtual ~TBinaryTreeItem();

    int counter;
};


#endif //LAB2_TBINARY_TREE_ITEM_H
