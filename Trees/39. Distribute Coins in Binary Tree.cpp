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
    int dfs(TreeNode *root, int &moves) {
        if (!root) return 0;
        int leftExcess = dfs(root->left, moves);
        int rightExcess = dfs(root->right, moves);

        int excess = root->val + leftExcess + rightExcess - 1;
        moves += abs(excess);
        return excess;
    }

   public:
    int distributeCoins(TreeNode *root) {
        int moves = 0;
        dfs(root, moves);
        return moves;
    }
};

int main() {
    return 0;
}