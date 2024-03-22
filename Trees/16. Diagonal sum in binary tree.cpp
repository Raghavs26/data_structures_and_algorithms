#include <bits/stdc++.h>

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
};

class Solution {
   public:
    vector<int> diagonalSum(Node* root) {
        if (!root) return {};
        int sum = 0;
        vector<int> res;
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                Node* current = q.front();
                q.pop();
                while (current) {
                    if (current->left) q.push(current->left);
                    sum += current->data;
                    current = current->right;
                }
            }
            res.push_back(sum);
            sum = 0;
        }
        return res;
    }
};

int main() {
    return 0;
}