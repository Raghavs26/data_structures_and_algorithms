#include <bits/stdc++.h>

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class Solution {
   public:
    void removeLoop(Node* head) {
        Node* slow = head;
        Node* fast = head;
        bool loopExists = false;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                loopExists = true;
                break;
            }
        }

        if (loopExists) {
            Node* temp = head;
            while (slow != temp) {
                slow = slow->next;
                temp = temp->next;
            }

            while (fast->next != slow) {
                fast = fast->next;
            }
            fast->next = nullptr;
        }
    }
};

int main() {
    return 0;
}