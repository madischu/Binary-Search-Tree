#include "binaryTree.h"

// Checks whether the tree is empty
template <class elemType>
bool binaryTreeType<elemType>::isEmpty() const
{
    return (root == nullptr);
}

// Inorder traversal
template <class elemType>
void binaryTreeType<elemType>::inorderTraversal() const
{
    inorder(root);
}

// Preorder traversal
template <class elemType>
void binaryTreeType<elemType>::preorderTraversal() const
{
    preorder(root);
}

// Postorder traversal
template <class elemType>
void binaryTreeType<elemType>::postorderTraversal() const
{
    postorder(root);
}

// Destroys the entire tree
template <class elemType>
void binaryTreeType<elemType>::destroyTree()
{
    destroy(root);
}

// Returns height of tree
template <class elemType>
int binaryTreeType<elemType>::treeHeight() const
{
    return height(root);
}

// Returns total number of nodes
template <class elemType>
int binaryTreeType<elemType>::treeNodeCount() const
{
    return nodeCount(root);
}

// Returns total number of leaves
template <class elemType>
int binaryTreeType<elemType>::treeLeavesCount() const
{
    return leavesCount(root);
}

// Public function to count nodes with exactly one child
template <class elemType>
int binaryTreeType<elemType>::singleParent() const
{
    return singleParent(root);
}

// Recursive helper function for counting single-parent nodes
template <class elemType>
int binaryTreeType<elemType>::singleParent(nodeType<elemType>* p) const
{
    if (p == nullptr)
    {
        return 0;
    }

    int count = 0;

    if ((p->llink != nullptr && p->rlink == nullptr) ||
        (p->llink == nullptr && p->rlink != nullptr))
    {
        count = 1;
    }

    return count + singleParent(p->llink) + singleParent(p->rlink);
}

// Inorder helper
template <class elemType>
void binaryTreeType<elemType>::inorder(nodeType<elemType>* p) const
{
    if (p != nullptr)
    {
        inorder(p->llink);
        cout << p->info << " ";
        inorder(p->rlink);
    }
}

// Preorder helper
template <class elemType>
void binaryTreeType<elemType>::preorder(nodeType<elemType>* p) const
{
    if (p != nullptr)
    {
        cout << p->info << " ";
        preorder(p->llink);
        preorder(p->rlink);
    }
}

// Postorder helper
template <class elemType>
void binaryTreeType<elemType>::postorder(nodeType<elemType>* p) const
{
    if (p != nullptr)
    {
        postorder(p->llink);
        postorder(p->rlink);
        cout << p->info << " ";
    }
}

// Destroy helper
template <class elemType>
void binaryTreeType<elemType>::destroy(nodeType<elemType>*& p)
{
    if (p != nullptr)
    {
        destroy(p->llink);
        destroy(p->rlink);
        delete p;
        p = nullptr;
    }
}

// Height helper
template <class elemType>
int binaryTreeType<elemType>::height(nodeType<elemType>* p) const
{
    if (p == nullptr)
    {
        return 0;
    }
    else
    {
        return 1 + max(height(p->llink), height(p->rlink));
    }
}

// Max helper
template <class elemType>
int binaryTreeType<elemType>::max(int x, int y) const
{
    return (x >= y) ? x : y;
}

// Node count helper
template <class elemType>
int binaryTreeType<elemType>::nodeCount(nodeType<elemType>* p) const
{
    if (p == nullptr)
    {
        return 0;
    }
    else
    {
        return 1 + nodeCount(p->llink) + nodeCount(p->rlink);
    }
}

// Leaves count helper
template <class elemType>
int binaryTreeType<elemType>::leavesCount(nodeType<elemType>* p) const
{
    if (p == nullptr)
    {
        return 0;
    }

    if (p->llink == nullptr && p->rlink == nullptr)
    {
        return 1;
    }

    return leavesCount(p->llink) + leavesCount(p->rlink);
}

// Default constructor
template <class elemType>
binaryTreeType<elemType>::binaryTreeType()
{
    root = nullptr;
}

// Copy constructor
template <class elemType>
binaryTreeType<elemType>::binaryTreeType
                (const binaryTreeType<elemType>& otherTree)
{
    if (otherTree.root == nullptr)
    {
        root = nullptr;
    }
    else
    {
        copyTree(root, otherTree.root);
    }
}

// Destructor
template <class elemType>
binaryTreeType<elemType>::~binaryTreeType()
{
    destroy(root);
}

// Assignment operator
template <class elemType>
const binaryTreeType<elemType>& binaryTreeType<elemType>::operator=
                    (const binaryTreeType<elemType>& otherTree)
{
    if (this != &otherTree)
    {
        if (root != nullptr)
        {
            destroy(root);
        }

        if (otherTree.root == nullptr)
        {
            root = nullptr;
        }
        else
        {
            copyTree(root, otherTree.root);
        }
    }

    return *this;
}

// Copy helper
template <class elemType>
void binaryTreeType<elemType>::copyTree
                  (nodeType<elemType>*& copiedTreeRoot,
                   nodeType<elemType>* otherTreeRoot)
{
    if (otherTreeRoot == nullptr)
    {
        copiedTreeRoot = nullptr;
    }
    else
    {
        copiedTreeRoot = new nodeType<elemType>;
        copiedTreeRoot->info = otherTreeRoot->info;
        copyTree(copiedTreeRoot->llink, otherTreeRoot->llink);
        copyTree(copiedTreeRoot->rlink, otherTreeRoot->rlink);
    }
}

// Explicit template instantiation
template class binaryTreeType<int>;
