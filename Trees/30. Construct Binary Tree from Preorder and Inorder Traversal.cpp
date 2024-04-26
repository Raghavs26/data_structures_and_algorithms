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
    TreeNode* buildTreeHelper(vector<int>& preorder, int preStart, int preEnd,
                              vector<int>& inorder, int inStart, int inEnd,
                              unordered_map<int, int>& indexMap) {
        if (preStart > preEnd || inStart > inEnd) return nullptr;
        int rootValue = preorder[preStart];
        TreeNode* root = new TreeNode(rootValue);

        int rootIndex = indexMap[rootValue];
        int leftSubTreeSize = rootIndex - inStart;

        root->left = buildTreeHelper(preorder, preStart + 1, preStart + leftSubTreeSize,
                                     inorder, inStart, rootIndex - 1, indexMap);
        root->right = buildTreeHelper(preorder, preStart + leftSubTreeSize + 1, preEnd,
                                      inorder, rootIndex + 1, inEnd, indexMap);
    }

   public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> indexMap;
        int n = inorder.size();
        for (int i = 0; i < n; i++) {
            indexMap[inorder[i]] = i;
        }
        return buildTreeHelper(preorder, 0, n - 1, inorder, 0, n - 1, indexMap);
    }
};

int main() {
    return 0;
}