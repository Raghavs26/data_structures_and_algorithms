#include <bits/stdc++.h>

#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
   private:
    vector<string> split(string str, char delim) {
        vector<string> res;
        string token;
        istringstream ss(str);
        while (getline(ss, token, delim)) {
            res.push_back(token);
        }
        return res;
    }

   public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "";
        queue<TreeNode*> q;
        string res{""};
        q.push(root);
        while (!q.empty()) {
            TreeNode* current = q.front();
            q.pop();
            if (!current) {
                res += "# ";
                continue;
            }
            res += to_string(current->val) + " ";
            q.push(current->left);
            q.push(current->right);
        }
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) return nullptr;
        vector<string> values = split(data, ' ');
        queue<TreeNode*> q;
        TreeNode* root = new TreeNode(stoi(values[0]));
        q.push(root);
        int n = values.size();
        for (int i = 1; i < n; i += 2) {
            TreeNode* parent = q.front();
            q.pop();
            if (values[i] != "#") {
                TreeNode* left = new TreeNode(stoi(values[i]));
                parent->left = left;
                q.push(left);
            }
            if (i + 1 < n && values[i + 1] != "#") {
                TreeNode* right = new TreeNode(stoi(values[i + 1]));
                parent->right = right;
                q.push(right);
            }
        }
        return root;
    }
};

int main() {
    return 0;
}