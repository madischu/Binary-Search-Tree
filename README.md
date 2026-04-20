# Binary-Search-Tree

## Program Description
This program adds a function named `singleParent` to the `binaryTreeType` class. The purpose of this function is to return the number of nodes in a binary tree that have exactly one child. 

A node is counted as a single-parent node if:
- it has a left child but no right child, or
- it has a right child but no left child

The program uses a binary search tree to test the function with the required test cases. 

## Inputs 
The program inserts a sequence of integer values into a binary search tree. 

## Outputs 
The program displays:
- the values inserted into the tree
- the number of nodes that have exactly one child

## Compile and Run Instructions
**Using g++**

*g++ main.cpp binaryTree.cpp binarySearchTree.cpp -o bstSingleParent*

*./bstSingleParent*

## Design Documentation
**Detailed Psuedocode**

```
MAIN PROGRAM
    Create three binary search tree objects

    For test case 1:
        Insert 50, 30, 70, 20, 40, 60, 80 into tree1
        Display the inserted values
        Call singleParent()
        Display the result

    For test case 2:
        Insert 50, 30, 70, 20, 60 into tree2
        Display the inserted values
        Call singleParent()
        Display the result

    For test case 3:
        Insert 10, 20, 30, 40 into tree3
        Display the inserted values
        Call singleParent()
        Display the result

END MAIN PROGRAM


FUNCTION singleParent()
    Return singleParent(root)
END FUNCTION


RECURSIVE FUNCTION singleParent(node)
    If node is NULL
        Return 0

    Set countLeftRight to 0

    If node has a left child and no right child
        Set countLeftRight to 1
    Else if node has a right child and no left child
        Set countLeftRight to 1

    Return countLeftRight
           + singleParent(node->llink)
           + singleParent(node->rlink)
END FUNCTION


FUNCTION insert(node, value)
    If node is NULL
        Create a new node
        Store value in the node
        Set left and right links to NULL
    Else if value is less than node info
        Insert into left subtree
    Else if value is greater than node info
        Insert into right subtree
END FUNCTION
```

## UML Class Diagrams
<img width="338" height="177" alt="image" src="https://github.com/user-attachments/assets/07867dc4-6528-474a-b780-8f1a1dae57b3" />
<img width="337" height="278" alt="image" src="https://github.com/user-attachments/assets/555ab345-7753-46eb-ad65-9a0fd72cc2cf" />
<img width="337" height="198" alt="image" src="https://github.com/user-attachments/assets/d03b7102-25e3-480c-889f-969ad9572242" />

## Use Case Diagram
<img width="362" height="911" alt="image" src="https://github.com/user-attachments/assets/12355d5c-b79d-4270-91d3-74ecc84a1999" />

## Program Execution Evidence
<img width="424" height="240" alt="image" src="https://github.com/user-attachments/assets/aacaa8d0-120d-4e91-9f51-f7e72e9c0ee7" />
