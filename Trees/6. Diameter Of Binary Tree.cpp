#include <bits/stdc++.h>

#include <iostream>
using namespace std;

template <typename T>
class TreeNode {
   public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

int dfs(TreeNode<int> *root, int &diameter) {
    if (!root) return 0;
    int left = dfs(root->left, diameter);
    int right = dfs(root->right, diameter);
    diameter = max(diameter, left + right);
    return max(left, right) + 1;
}

int diameterOfBinaryTree(TreeNode<int> *root) {
    int diameter = 0;
    dfs(root, diameter);
    return diameter;
}

int main() {
    return 0;
}