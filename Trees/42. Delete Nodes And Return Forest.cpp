#include <bits/stdc++.h>
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
    vector<TreeNode *> delNodes(TreeNode *root, vector<int> &to_delete) {
        if (!root) return {};
        vector<TreeNode *> res;
        unordered_set<int> st(to_delete.begin(), to_delete.end());
        if (st.find(root->val) == st.end()) res.push_back(root);
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            auto cur = q.front();
            q.pop();
            if (cur->left) q.push(cur->left);
            if (cur->right) q.push(cur->right);

            if (cur->left && st.find(cur->left->val) != st.end()) cur->left = nullptr;
            if (cur->right && st.find(cur->right->val) != st.end()) cur->right = nullptr;

            if (st.find(cur->val) != st.end()) {
                if (cur->left) res.push_back(cur->left);
                if (cur->right) res.push_back(cur->right);
            }
        }
        return res;
    }
};

int main() {
    return 0;
}