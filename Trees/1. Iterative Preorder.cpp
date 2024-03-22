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
    vector<int> preorderTraversal(TreeNode *root) {
        if (!root) return {};
        stack<TreeNode *> st;
        vector<int> res;
        st.push(root);
        while (!st.empty()) {
            auto current = st.top();
            st.pop();
            res.push_back(current->val);
            if (current->left) st.push(current->left);
            if (current->right) st.push(current->right);
        }
        return res;
    }
};

int main() {
    return 0;
}