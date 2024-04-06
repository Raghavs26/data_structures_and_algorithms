#include <bits/stdc++.h>

#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

class Solution {
   public:
    Node* lca(Node* root, int n1, int n2) {
        if (!root) return root;
        if (root->data == n1 || root->data == n2) return root;
        Node* left = lca(root->left, n1, n2);
        Node* right = lca(root->right, n1, n2);
        if (!left) {
            return right;
        } else if (!right) {
            return left;
        } else {
            return root;
        }
    }
};

int main() {
    return 0;
}