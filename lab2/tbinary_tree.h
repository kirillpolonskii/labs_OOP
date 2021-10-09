#ifndef LAB2_TBINARY_TREE_H
#define LAB2_TBINARY_TREE_H

#include "tbinary_tree_item.h"

class TBinaryTree {
private:
    TBinaryTreeItem* root;
public:
    TBinaryTree();
    TBinaryTree(const TBinaryTree& otherBinTree);
    void Push(Octagon& oct);
    void Pop(Octagon& oct);
    void Clear();
    bool Empty();
    int  Count(double minArea, double maxArea);
    //void reverseCount(double minArea, double maxAre, TBinaryTreeItem* curItem, int& ans);
    virtual ~TBinaryTree();
    
};


#endif //LAB2_TBINARY_TREE_H
