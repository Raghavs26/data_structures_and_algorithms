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

class FindElements {
   private:
    unordered_set<int> st;
    void dfs(TreeNode *root, int val) {
        if (!root) return;
        st.insert(val);
        if (root->left) dfs(root->left, 2 * val + 1);
        if (root->right) dfs(root->right, 2 * val + 2);
    }

   public:
    FindElements(TreeNode *root) {
        dfs(root, 0);
    }

    bool find(int target) {
        return st.find(target) != st.end();
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */

int main() {
    return 0;
}