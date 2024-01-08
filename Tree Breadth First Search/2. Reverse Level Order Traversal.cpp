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
  vector<vector<int>> levelOrderBottom(TreeNode *root) {
    if (!root)
      return {};
    vector<vector<int>> res;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty()) {
      vector<int> temp;
      int size = q.size();
      for (int i = 0; i < size; i++) {
        TreeNode *current = q.front();
        q.pop();
        temp.push_back(current->val);
        if (current->left)
          q.push(current->left);
        if (current->right)
          q.push(current->right);
      }
      res.push_back(temp);
    }
    reverse(res.begin(), res.end());
    return res;
  }
};

int main() { return 0; }