#include <bits/stdc++.h>

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
};

class Solution {
   private:
    void inorderTraversal(Node *root, int &prevValue, int &minAbsDiff) {
        if (root == nullptr) return;

        inorderTraversal(root->left, prevValue, minAbsDiff);
        if (prevValue != INT_MAX) {
            minAbsDiff = min(minAbsDiff, abs(root->data - prevValue));
        }
        prevValue = root->data;
        inorderTraversal(root->right, prevValue, minAbsDiff);
    }

   public:
    int absolute_diff(Node *root) {
        int prevValue = INT_MAX;
        int minAbsDiff = INT_MAX;

        inorderTraversal(root, prevValue, minAbsDiff);

        return minAbsDiff;
    }
};

int main() {
    return 0;
}