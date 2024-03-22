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

    ~TreeNode() {
        if (left) delete left;
        if (right) delete right;
    }
};

void traverseLeft(TreeNode<int> *root, vector<int> &res) {
    if (!root or (!root->left && !root->right)) return;
    res.push_back(root->data);
    if (root->left) traverseLeft(root->left, res);
    else traverseLeft(root->right, res);
}
void traverseRight(TreeNode<int> *root, vector<int> &res) {
    if (!root or (!root->left && !root->right)) return;
    if (root->right) traverseRight(root->right, res);
    else traverseRight(root->left, res);
    res.push_back(root->data);
}
void traverseLeafNodes(TreeNode<int> *root, vector<int> &res) {
    if (!root) return;
    if (!root->left && !root->right) {
        res.push_back(root->data);
        return;
    }
    traverseLeafNodes(root->left, res);
    traverseLeafNodes(root->right, res);
}

vector<int> traverseBoundary(TreeNode<int> *root) {
    if (!root) return {};
    vector<int> res;
    res.push_back(root->data);
    traverseLeft(root->left, res);
    traverseLeafNodes(root->left, res);
    traverseLeafNodes(root->right, res);
    traverseRight(root->right, res);
    return res;
}

int main() {
    return 0;
}