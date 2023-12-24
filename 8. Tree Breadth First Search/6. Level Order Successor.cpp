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
  TreeNode *findSuccessor(TreeNode *root, int key) {
    TreeNode *res = nullptr;
    if (!root)
      return res;
    queue<TreeNode *> q;
    while (!q.empty()) {
      TreeNode *current = q.front();
      q.pop();
      if (current->left) {
        q.push(current->left);
      }
      if (current->right) {
        q.push(current->right);
      }
      if (current->val == key) {
        break;
      }
    }
    return q.front();
  }
};

int main() { return 0; }