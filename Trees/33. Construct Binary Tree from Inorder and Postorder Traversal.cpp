#include <bits/stdc++.h>

#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
   private:
    TreeNode* solve(vector<int>& postOrder, int& postIndex, vector<int>& inOrder, int inStart, int inEnd) {
        if (inStart > inEnd) {
            return nullptr;
        }
        int rootValue = postOrder[postIndex];
        TreeNode* root = new TreeNode(rootValue);
        int index = inStart;
        while (index <= inEnd) {
            if (inOrder[index] == rootValue)
                break;
            index++;
        }
        postIndex--;
        root->right = solve(postOrder, postIndex, inOrder, index + 1, inEnd);
        root->left = solve(postOrder, postIndex, inOrder, inStart, index - 1);
        return root;
    }

   public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = postorder.size();
        int postIndex = n - 1;
        return solve(postorder, postIndex, inorder, 0, n - 1);
    }
};

int main() {
    return 0;
}