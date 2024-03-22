#include <bits/stdc++.h>

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
};

class Solution {
   public:
    vector<int> verticalSum(Node *root) {
        map<int, int> mp;
        vector<int> res;
        queue<pair<Node *, int>> q;
        q.push({root, 0});
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                Node *current = q.front().first;
                int level = q.front().second;
                q.pop();
                mp[level] += current->data;
                if (current->left) q.push({current->left, level - 1});
                if (current->right) q.push({current->right, level + 1});
            }
        }

        for (auto it : mp) {
            int levelSum = it.second;
            res.push_back(levelSum);
        }
        return res;
    }
};

int main() {
    return 0;
}