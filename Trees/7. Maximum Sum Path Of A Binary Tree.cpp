#include <bits/stdc++.h>

#include <iostream>
using namespace std;

template <typename T>
class BinaryTreeNode {
   public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

int solve(BinaryTreeNode<int> *root, int &maxSum) {
    if (!root) return 0;
    int leftSum = max(0, solve(root->left, maxSum));
    int rightSum = max(0, solve(root->right, maxSum));

    maxSum = max(maxSum, leftSum + rightSum + root->data);

    return root->data + max(leftSum, rightSum);
}

int maxPathSum(BinaryTreeNode<int> *root) {
    int maxSum = INT_MIN;
    solve(root, maxSum);
    return maxSum;
}

int main() {
    return 0;
}