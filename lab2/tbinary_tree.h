#ifndef LAB2_TBINARY_TREE_H
#define LAB2_TBINARY_TREE_H

#include "tbinary_tree_item.h"

class TBinaryTree {
private:
    TBinaryTreeItem* root;
    Octagon* NULL_OCT;
public:
    TBinaryTree(); // checked
    TBinaryTree(TBinaryTree& otherBinTree);
    void Push(const Octagon& oct); // checked
    void Pop(const Octagon& oct);
    void Clear();
    bool Empty(); // checked
    int  Count(double minArea, double maxArea);
    Octagon& GetItemNotLess(double area); // returns an element not less than the given area
    friend std::ostream& operator << (std::ostream &out, TBinaryTree* tree); // checked 2/3
    TBinaryTreeItem* GetRoot();
    virtual ~TBinaryTree();
    
};


#endif //LAB2_TBINARY_TREE_H
