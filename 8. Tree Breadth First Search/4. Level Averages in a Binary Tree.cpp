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
  vector<double> averageOfLevels(TreeNode *root) {
    if (!root)
      return {};
    vector<double> res;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty()) {
      int sum = 0;
      int size = q.size();
      for (int i = 0; i < size; i++) {
        TreeNode *current = q.front();
        q.pop();
        sum += current->val;
        if (!current->left)
          q.push(current->left);
        if (!current->right)
          q.push(current->right);
      }
      double avg = sum / size;
      res.push_back(avg);
    }
    return res;
  }
};

int main() { return 0; }