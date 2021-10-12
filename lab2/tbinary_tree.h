#ifndef LAB2_TBINARY_TREE_H
#define LAB2_TBINARY_TREE_H

#include "tbinary_tree_item.h"

class TBinaryTree {
private:
    TBinaryTreeItem* root;
public:
    TBinaryTree();
    TBinaryTree(TBinaryTree& otherBinTree);
    void Push(const Octagon& oct);
    void Pop(const Octagon& oct);
    void Clear();
    bool Empty();
    int  Count(double minArea, double maxArea);
    Octagon& GetItemNotLess(double area); // returns an element not less than the given area
    friend std::ostream& operator << (std::ostream &out, TBinaryTree* tree);
    virtual ~TBinaryTree();
    
};


#endif //LAB2_TBINARY_TREE_H
