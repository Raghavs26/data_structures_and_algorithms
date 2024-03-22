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

vector<int> zigZagTraversal(BinaryTreeNode<int> *root) {
    if (!root) return {};
    vector<int> res;
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    bool toReverse = false;
    while (!q.empty()) {
        int size = q.size();
        vector<int> temp;
        for (int i = 0; i < size; i++) {
            BinaryTreeNode<int> *current = q.front();
            q.pop();
            temp.push_back(current->data);
            if (current->left) q.push(current->left);
            if (current->right) q.push(current->right);
        }

        for (int i = 0; i < size; i++) {
            if (toReverse) {
                res.push_back(temp[size - i - 1]);
            } else {
                res.push_back(temp[i]);
            }
        }
        toReverse = !toReverse;
    }
    return res;
}

int main() {
    return 0;
}