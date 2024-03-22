#include <bits/stdc++.h>

#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
   public:
    vector<int> inorderTraversal(TreeNode *root) {
        if (!root) return {};
        stack<TreeNode *> st1;
        vector<int> res;

        while (!st1.empty()) {
            TreeNode *current = st1.top();
            st1.pop();
            res.push_back(current->val);
            if (current->left) st1.push(current->left);
            if (current->right) st1.push(current->right);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

struct Node {
    int data;
    Node *left;
    Node *right;
};
class Solution {
   public:
    vector<int> postOrder(Node *node) {
        if (!node) return {};
        stack<TreeNode *> st1;
        vector<int> res;
        while (!st1.empty()) {
            TreeNode *current = st1.top();
            st1.pop();
            res.push_back(current->val);
            if (current->left) st1.push(current->left);
            if (current->right) st1.push(current->right);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

class Solution {
   private:
    int solve(Node *root, int &maxSum) {
        if (!root) return 0;
        int leftSum = max(0, solve(root->left, maxSum));
        int rightSum = max(0, solve(root->right, maxSum));

        maxSum = max(maxSum, leftSum + rightSum + root->data);

        return root->data + max(leftSum, rightSum);
    }

   public:
    int findMaxSum(Node *root) {
        int maxSum = 0;
        solve(root, maxSum);
        return maxSum;
    }
};