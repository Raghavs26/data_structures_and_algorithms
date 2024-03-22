#include <bits/stdc++.h>

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
};

class Solution {
   private:
    int solve(Node* root) {
        if (!root) return 0;

        if (!root->left && !root->right) {
            return root->data;
        }

        int leftSum = solve(root->left);
        int rightSum = solve(root->right);

        if (root->data != leftSum + rightSum || leftSum == -1 || rightSum == -1) {
            return -1;
        }

        return root->data + (leftSum + rightSum);
    }

   public:
    bool isSumTree(Node* root) {
        return solve(root) != -1;
    }
};

int main() {
    return 0;
}