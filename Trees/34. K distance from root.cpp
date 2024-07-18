#include <bits/stdc++.h>

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

class Solution {
   public:
    vector<int> Kdistance(struct Node* root, int k) {
        if (k == 0) return {root->data};

        vector<int> res;
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            if (k < 0) break;
            while (size--) {
                Node* current = q.front();
                q.pop();
                if (k == 0) {
                    res.push_back(current->data);
                }
                if (current->left) q.push(current->left);
                if (current->right) q.push(current->right);
            }
            k--;
        }
        return res;
    }
};

int main() {
    return 0;
}