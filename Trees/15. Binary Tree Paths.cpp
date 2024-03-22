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
   private:
    void solve(TreeNode *root, vector<string> &res, string path) {
        if (!root) return;
        if (!root->left && !root->right) {
            res.push_back(path + to_string(root->val));
            return;
        }
        solve(root->left, res, path + to_string(root->val) + "->");
        solve(root->right, res, path + to_string(root->val) + "->");
    }

   public:
    vector<string> binaryTreePaths(TreeNode *root) {
        string path{""};
        vector<string> res;
        solve(root, res, path);
        return res;
    }
};

int main() {
    return 0;
}