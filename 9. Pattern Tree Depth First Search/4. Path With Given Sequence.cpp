#include <bits/stdc++.h>
#include <iostream>

using namespace std;

class TreeNode {
public:
  int val;
  TreeNode *left, *right;
  TreeNode(int val) {
    this->val = val;
    this->left = this->right = NULL;
  }
};

class Solution {
public:
  bool solve(TreeNode *root, vector<int> &arr, int idx) {
    if (!root || idx >= arr.size() || root->val != arr[idx]) {
      return false;
    }
    if (idx == arr.size() - 1 and !root->left and !root->right) {
      return true;
    }

    return solve(root->left, arr, idx + 1) || solve(root->right, arr, idx + 1);
  }
  bool isValidSequence(TreeNode *root, vector<int> &arr) {
    return solve(root, arr, 0);
  }
};

int main() { return 0; }