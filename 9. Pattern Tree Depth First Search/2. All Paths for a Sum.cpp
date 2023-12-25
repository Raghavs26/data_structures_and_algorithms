#include <bits/stdc++.h>
#include <iostream>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};



class Solution {
public:
  void solve(TreeNode *root, int targetSum, vector<vector<int>> &res,
             vector<int> &temp) {
    if (!root) {
      return;
    }
    if (!root->left and !root->right and targetSum - root->val == 0) {
      res.push_back(temp);
      return;
    }
    temp.push_back(root->val);
    solve(root->left, targetSum - root->val, res, temp);
    solve(root->right, targetSum - root->val, res, temp);
    temp.pop_back();
  }
  vector<vector<int>> pathSum(TreeNode *root, int targetSum) {
    vector<vector<int>> res;
    vector<int> temp;
    solve(root, targetSum, res, temp);
    return res;
  }
};

int main() { return 0; }