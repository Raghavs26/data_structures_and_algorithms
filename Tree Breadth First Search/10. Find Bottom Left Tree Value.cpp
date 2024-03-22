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
    int findBottomLeftValue(TreeNode *root) {
        if (!root) return 0;
        queue<pair<TreeNode *, int>> q;
        int res = 0;
        int maxLevel = INT_MIN;
        q.push({root, 0});
        while (!q.empty()) {
            TreeNode *current = q.front().first;
            int level = q.front().second;
            q.pop();
            if (level > maxLevel) {
                maxLevel = level;
                res = current->val;
            }
            if (current->left) q.push({current->left, level + 1});
            if (current->right) q.push({current->right, level + 1});
        }
        return res;
    }
};

int main() {
    return 0;
}