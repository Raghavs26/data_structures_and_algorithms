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
   private:
    void solve(Node* root, vector<int>& path, vector<vector<int>>& res) {
        if (!root) return;
        path.push_back(root->data);
        if (!root->left && !root->right) {
            res.push_back(path);
            return;
        }
        solve(root->left, path, res);
        solve(root->right, path, res);
        path.pop_back();
    }

   public:
    vector<vector<int>> Paths(Node* root) {
        vector<vector<int>> res;
        vector<int> path;
        solve(root, path, res);
        return res;
    }
};

int main() {
    return 0;
}
