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

// time complexity :O(Min(N1,N2))
class Solution {
   public:
    TreeNode *replaceValueInTree(TreeNode *root) {
        if (!root) return root;

        queue<TreeNode *> q;
        q.push(root);
        int levelSum = root->val;

        while (!q.empty()) {
            int size = q.size();
            int nextLevelSum = 0;

            for (int i = 0; i < size; i++) {
                TreeNode *current = q.front();
                q.pop();

                current->val = levelSum - current->val;

                int siblingSum = (current->left ? current->left->val : 0);
                siblingSum += (current->right ? current->right->val : 0);

                if (current->left) {
                    nextLevelSum += current->left->val;
                    current->left->val = siblingSum;
                    q.push(current->left);
                }

                if (current->right) {
                    nextLevelSum += current->right->val;
                    current->right->val = siblingSum;
                    q.push(current->right);
                }
            }
            levelSum = nextLevelSum;
        }

        return root;
    }
};
int main() {
    return 0;
}