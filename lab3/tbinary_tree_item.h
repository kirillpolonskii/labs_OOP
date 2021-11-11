#ifndef LAB3_TBINARY_TREE_ITEM_H
#define LAB3_TBINARY_TREE_ITEM_H

#include "octagon.h" // checked

class TBinaryTreeItem {
private:
    Octagon octagon;
    std::shared_ptr<TBinaryTreeItem> left;
    std::shared_ptr<TBinaryTreeItem> right;

public:
    TBinaryTreeItem(const Octagon& oct);
    TBinaryTreeItem(std::shared_ptr<TBinaryTreeItem>& other);
    Octagon& GetOctagon();
    void SetOctagon(const Octagon& oct);
    std::shared_ptr<TBinaryTreeItem> GetLeft();
    void SetLeft(std::shared_ptr<TBinaryTreeItem> tBinTreeItem);
    std::shared_ptr<TBinaryTreeItem> GetRight();
    void SetRight(std::shared_ptr<TBinaryTreeItem> tBinTreeItem);
    friend std::ostream& operator << (std::ostream& out, std::shared_ptr<TBinaryTreeItem> treeItem);
    virtual ~TBinaryTreeItem();

    int counter;
};


#endif //LAB3_TBINARY_TREE_ITEM_H
