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
        stack<TreeNode *> st;
        vector<int> res;
        while (true) {
            if (root) {
                st.push(root);
                root = root->left;
            } else {
                if (st.empty()) break;
                auto current = st.top();
                st.pop();
                res.push_back(current->val);
                current = current->right;
            }
        }
        return res;
    }
};

int main() {
    return 0;
}