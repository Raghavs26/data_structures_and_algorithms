#include <bits/stdc++.h>

#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

class Solution {
   public:
    vector<int> zigZagTraversal(Node *root) {
        queue<Node *> q;
        vector<int> ans;
        q.push(root);
        bool order = true;
        while (!q.empty()) {
            int n = q.size();
            vector<int> temp;

            for (int i = 0; i < n; i++) {
                auto current = q.front();
                q.pop();
                temp.push_back(current->data);

                if (current->left) q.push(current->left);
                if (current->right) q.push(current->right);
            }
            for (int i = 0; i < n; i++) {
                if (order) {
                    ans.push_back(temp[i]);
                } else {
                    ans.push_back(temp[n - i - 1]);
                }
            }
            order = !order;
        }
        return ans;
    }
};
int main() {
    return 0;
}