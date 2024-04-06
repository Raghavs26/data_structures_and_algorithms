#include <bits/stdc++.h>

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
    void inorder(Node *root, int k, int &count, int &res) {
        if (!root) return;
        inorder(root->left, k, count, res);
        count++;
        if (count == k) {
            res = root->data;
            return;
        }
        inorder(root->right, k, count, res);
    }

   public:
    int KthSmallestElement(Node *root, int k) {
        int count = 0;
        int res = -1;
        inorder(root, k, count, res);
        return res;
    }
};

int main() {
    return 0;
}