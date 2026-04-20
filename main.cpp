#include <iostream>
#include "binarySearchTree.h"

using namespace std;

void runTest(const int values[], int size, int testNumber)
{
    bSearchTreeType<int> tree;

    for (int i = 0; i < size; i++)
    {
        tree.insert(values[i]);
    }

    cout << "Test Case " << testNumber << ": ";
    for (int i = 0; i < size; i++)
    {
        cout << values[i];
        if (i < size - 1)
        {
            cout << ", ";
        }
    }
    cout << endl;

    cout << "Inorder Traversal: ";
    tree.inorderTraversal();
    cout << endl;

    cout << "Nodes with exactly one child: "
         << tree.singleParent() << endl;

    cout << endl;
}

int main()
{
    int test1[] = {50, 30, 70, 20, 40, 60, 80};
    int test2[] = {50, 30, 70, 20, 60};
    int test3[] = {10, 20, 30, 40};

    runTest(test1, 7, 1);
    runTest(test2, 5, 2);
    runTest(test3, 4, 3);

    return 0;
}
