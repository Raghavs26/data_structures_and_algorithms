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
    // we can use map to optimise the code but it work if there are duplicates
   private:
    TreeNode *solve(vector<int> preOrder, int &preIndex, vector<int> inOrder, int inStart, int inEnd) {
        if (inStart > inEnd) {
            return nullptr;
        }
        int rootValue = preOrder[preIndex];
        TreeNode *root = new TreeNode(rootValue);
        int index = inStart;
        while (index <= inEnd) {
            if (inOrder[index] == rootValue)
                break;
            index++;
        }

        preIndex++;
        root->left = solve(preOrder, preIndex, inOrder, inStart, index - 1);
        root->right = solve(preOrder, preIndex, inOrder, index + 1, inEnd);
        return root;
    }

   public:
   public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        int n = inorder.size();
        int preIndex = 0;
        return solve(preorder, preIndex, inorder, 0, n - 1);
    }
};

int main() {
    return 0;
}