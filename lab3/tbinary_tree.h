#ifndef LAB3_TBINARY_TREE_H
#define LAB3_TBINARY_TREE_H

#include "tbinary_tree_item.h"

class TBinaryTree {
private:
    std::shared_ptr<TBinaryTreeItem> root;
public:
    TBinaryTree(); // checked
    TBinaryTree(TBinaryTree& otherBinTree); // checked
    void Push(const Octagon& oct); // checked
    void Pop(const Octagon& oct); // added throw, checked
    void Clear(); // checked
    bool Empty(); // checked
    int Count(const Octagon& octagon); // rewrote, checked
    Octagon& GetItemNotLess(double area); // rewrote with throw, checked
    friend std::ostream& operator << (std::ostream &out, TBinaryTree* tree); // checked
    std::shared_ptr<TBinaryTreeItem> GetRoot();
    virtual ~TBinaryTree();

};


#endif //LAB3_TBINARY_TREE_H
