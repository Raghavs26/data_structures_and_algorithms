#include <bits/stdc++.h>

#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node *left, *right;
};

class Solution {
   private:
    // this method will for work for both bst and binary tree
    bool pathToTarget(Node *currentNode, int targetValue, vector<int> &path) {
        if (currentNode) return false;

        path.push_back(currentNode->data);

        if (currentNode->data == targetValue) return true;

        if (pathToTarget(currentNode->left, targetValue, path)) return true;
        if (pathToTarget(currentNode->right, targetValue, path)) return true;

        path.pop_back();
        return false;
    }

    // only works for bst
    void path(Node *root, int x, vector<int> &res) {
        if (!root) return;
        res.push_back(root->data);
        if (x == root->data) return;
        if (root->data > x) {
            path(root->left, x, res);
        } else {
            path(root->right, x, res);
        }
    }

   public:
    int kthCommonAncestor(Node *root, int k, int x, int y) {
        vector<int> p, q;
        // pathToTarget(root, x, p);
        // pathToTarget(root, y, q);
        path(root, x, p);
        path(root, y, q);
        vector<int> common;
        for (int i = 0; i < min(p.size(), q.size()); i++) {
            if (p[i] == q[i]) {
                common.push_back(p[i]);
            } else {
                break;
            }
        }
        reverse(common.begin(), common.end());
        if (k <= common.size()) return common[k - 1];
        return -1;
    }
};

int main() {
    return 0;
}