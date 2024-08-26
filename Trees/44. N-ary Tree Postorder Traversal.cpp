#include <bits/stdc++.h>
using namespace std;

class Node {
   public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
   private:
    void traversePostOrder(Node* root, vector<int>& res) {
        if (!root) return;

        for (auto cur : root->children) {
            traversePostOrder(cur, res);
        }
        res.push_back(root->val);
    }

   public:
    vector<int> postorder(Node* root) {
        vector<int> res;
        traversePostOrder(root, res);
        return res;
    }
};

int main() {
    return 0;
}