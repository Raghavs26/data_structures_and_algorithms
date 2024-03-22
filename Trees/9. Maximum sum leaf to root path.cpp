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
        int leftSum = root->data + solve(root->left);
        int rightSum = root->data + solve(root->right);

        return max(leftSum, rightSum);
    }

   public:
    int maxPathSum(Node* root) {
        int maxSum = INT_MIN;
    }
};

int main() {
    return 0;
}