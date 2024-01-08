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
  int minDepth(TreeNode *root) {
    if (!root)
      return 0;
    int res = 0;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty()) {
      int size = q.size();
      res += 1;
      for (int i = 0; i < size; i++) {
        TreeNode *current = q.front();
        q.pop();
        if (!current->left and !current->right)
          return res;
        if (current->left)
          q.push(current->left);
        if (current->right)
          q.push(current->right);
      }
    }
    return res;
  }
};

int main() { return 0; }