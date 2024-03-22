#include <bits/stdc++.h>

#include <iostream>
using namespace std;

template <typename T>

class BinaryTreeNode {
   public:
    T data;
    BinaryTreeNode<T>* left;
    BinaryTreeNode<T>* right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

bool identicalTrees(BinaryTreeNode<int>* root1, BinaryTreeNode<int>* root2) {
    if (!root1 && !root2) return true;
    if (!root1 || !root2) return false;
    if (root1->data != root2->data) return false;
    return identicalTrees(root1->left, root2->left) && identicalTrees(root1->right, root2->right);
}

int main() {
    return 0;
}