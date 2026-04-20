#ifndef H_binarySearchTree
#define H_binarySearchTree

#include "binaryTree.h"

template <class elemType>
class bSearchTreeType: public binaryTreeType<elemType>
{
public:
    bool search(const elemType& searchItem) const;
    void insert(const elemType& insertItem);
    void deleteNode(const elemType& deleteItem);
};

#endif
