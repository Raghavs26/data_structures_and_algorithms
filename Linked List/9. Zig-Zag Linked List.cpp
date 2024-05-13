#include <bits/stdc++.h>

#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Solution {
   public:
    Node* zigZag(Node* head) {
        if (!head || !head->next) {
            return head;
        }

        bool isLess = true;
        Node* current = head;

        while (current && current->next) {
            bool check1 = isLess && current->data > current->next->data;
            bool check2 = !isLess && current->data < current->next->data;
            if (check1 || check2) {
                swap(current->data, current->next->data);
            }
            current = current->next;
            isLess = !isLess;
        }

        return head;
    }
};

int main() {
    return 0;
}