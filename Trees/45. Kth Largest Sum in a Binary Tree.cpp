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
    long long kthLargestLevelSum(TreeNode *root, int k) {
        if (!root) return -1;

        queue<TreeNode *> q;
        priority_queue<long long> pq;

        q.push(root);

        while (!q.empty()) {
            long long sum = 0;
            int size = q.size();

            for (int i = 0; i < size; i++) {
                TreeNode *current = q.front();
                q.pop();
                sum += current->val;
                if (current->left) q.push(current->left);
                if (current->right) q.push(current->right);
            }

            pq.push(sum);
        }

        if (k > pq.size()) {
            return -1;
        }

        for (int i = 1; i < k; i++) {
            pq.pop();
        }

        return pq.top();
    }
};

int main() {
    return 0;
}