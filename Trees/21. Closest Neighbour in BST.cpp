#include <bits/stdc++.h>

#include <iostream>
using namespace std;

struct Node {
    int key;
    Node *left, *right;
};

class Solution {
   public:
    int findMaxForN(Node* root, int n) {
        int result = -1;

        Node* current = root;

        while (current) {
            if (current->key <= n) {
                result = current->key;
                current = current->right;
            } else {
                current = current->left;
            }
        }

        return result;
    }
};

int main() {
    return 0;
}