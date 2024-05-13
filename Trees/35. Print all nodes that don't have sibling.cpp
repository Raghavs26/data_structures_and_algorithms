#include <bits/stdc++.h>

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
};

vector<int> noSibling(Node* node) {
    vector<int> ans;
    if (!node) {
        ans.push_back(-1);
        return ans;
    }

    queue<Node*> q;
    q.push(node);
    while (!q.empty()) {
        Node* front = q.front();
        q.pop();

        if (front->left) q.push(front->left);
        if (front->right) q.push(front->right);

        if (front->left && !front->right) ans.push_back(front->left->data);
        if (front->right && !front->left) ans.push_back(front->right->data);
    }

    if (ans.empty()) {
        ans.push_back(-1);
    } else {
        sort(ans.begin(), ans.end());
    }

    return ans;
};

int main() {
    return 0;
}