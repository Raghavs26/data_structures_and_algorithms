#include <bits/stdc++.h>
#include <iostream>

using namespace std;

class Node {
public:
  int val = 0;
  Node *left;
  Node *right;
  Node *next;

  Node(int x) {
    val = x;
    left = right = next = nullptr;
  }

  virtual void print() {
    Node *current = this;
    cout << "Traversal using 'next' pointer: ";
    while (current) {
      cout << current->val << " ";
      current = current->next;
    }
  }
};

class Solution {
public:
  static void connect(Node *root) {
    if (!root)
      return;
    queue<Node *> q;
    q.push(root);
    while (!q.empty()) {
      int size = q.size();
      Node *prev = nullptr;
      for (int i = 0; i < size; i++) {
        Node *current = q.front();
        q.pop();
        if (prev) {
          prev->next = current;
        }
        prev = current;
        if (current->left) {
          q.push(current->left);
        }

        if (current->right) {
          q.push(current->right);
        }
      }
    }
  }
};

int main() {
  Node *root = new Node(12);
  root->left = new Node(7);
  root->right = new Node(1);
  root->left->left = new Node(9);
  root->right->left = new Node(10);
  root->right->right = new Node(5);

  Solution::connect(root);
  root->print();

  return 0;
}
