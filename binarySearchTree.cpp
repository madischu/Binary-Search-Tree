#include "binarySearchTree.h"

// Searches for a value in the BST
template <class elemType>
bool bSearchTreeType<elemType>::search(const elemType& searchItem) const
{
    nodeType<elemType>* current = this->root;

    while (current != nullptr)
    {
        if (current->info == searchItem)
        {
            return true;
        }
        else if (searchItem < current->info)
        {
            current = current->llink;
        }
        else
        {
            current = current->rlink;
        }
    }

    return false;
}

// Inserts a value into the BST
template <class elemType>
void bSearchTreeType<elemType>::insert(const elemType& insertItem)
{
    nodeType<elemType>* current;
    nodeType<elemType>* trailCurrent = nullptr;
    nodeType<elemType>* newNode;

    newNode = new nodeType<elemType>;
    newNode->info = insertItem;
    newNode->llink = nullptr;
    newNode->rlink = nullptr;

    if (this->root == nullptr)
    {
        this->root = newNode;
    }
    else
    {
        current = this->root;

        while (current != nullptr)
        {
            trailCurrent = current;

            if (current->info == insertItem)
            {
                delete newNode;
                return;
            }
            else if (insertItem < current->info)
            {
                current = current->llink;
            }
            else
            {
                current = current->rlink;
            }
        }

        if (insertItem < trailCurrent->info)
        {
            trailCurrent->llink = newNode;
        }
        else
        {
            trailCurrent->rlink = newNode;
        }
    }
}

// Delete not required for this project
template <class elemType>
void bSearchTreeType<elemType>::deleteNode(const elemType& deleteItem)
{
}

// Explicit template instantiation
template class bSearchTreeType<int>;
