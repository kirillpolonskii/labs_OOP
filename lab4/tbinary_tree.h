#ifndef LAB3_TBINARY_TREE_H
#define LAB3_TBINARY_TREE_H

#include "tbinary_tree_item.h"

template<class T> class TBinaryTree {
private:
    std::shared_ptr<TBinaryTreeItem<T>> root;
public:
    TBinaryTree<T>(); // checked
    TBinaryTree(TBinaryTree<T>& otherBinTree); // checked
    void Push(const std::shared_ptr<T>& data); // checked
    void Pop(const std::shared_ptr<T>& data); // added throw, checked
    void Clear(); // checked
    bool Empty(); // checked
    int Count(const std::shared_ptr<T>& data); // rewrote, checked
    std::shared_ptr<T> GetItemNotLess(double area); // rewrote with throw, checked
    template<class A> friend std::ostream& operator << (std::ostream &out, TBinaryTree<A>* tree); // checked
    std::shared_ptr<TBinaryTreeItem<T>> GetRoot();
    virtual ~TBinaryTree();

};


#endif //LAB3_TBINARY_TREE_H
