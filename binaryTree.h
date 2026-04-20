#ifndef H_binaryTree
#define H_binaryTree

#include <iostream>
#include <cassert>

using namespace std;

template <class elemType>
struct nodeType
{
    elemType info;
    nodeType<elemType>* llink;
    nodeType<elemType>* rlink;
};

template <class elemType>
class binaryTreeType
{
public:
    const binaryTreeType<elemType>& operator=
                        (const binaryTreeType<elemType>&);
    bool isEmpty() const;
    void inorderTraversal() const;
    void preorderTraversal() const;
    void postorderTraversal() const;
    int treeHeight() const;
    int treeNodeCount() const;
    int treeLeavesCount() const;
    void destroyTree();

    // Required function
    int singleParent() const;

    binaryTreeType(const binaryTreeType<elemType>& otherTree);
    binaryTreeType();
    ~binaryTreeType();

protected:
    nodeType<elemType>* root;

private:
    void copyTree(nodeType<elemType>*& copiedTreeRoot,
                  nodeType<elemType>* otherTreeRoot);
    void destroy(nodeType<elemType>*& p);
    void inorder(nodeType<elemType>* p) const;
    void preorder(nodeType<elemType>* p) const;
    void postorder(nodeType<elemType>* p) const;
    int height(nodeType<elemType>* p) const;
    int max(int x, int y) const;
    int nodeCount(nodeType<elemType>* p) const;
    int leavesCount(nodeType<elemType>* p) const;

    // Helper for singleParent
    int singleParent(nodeType<elemType>* p) const;
};

#endif
