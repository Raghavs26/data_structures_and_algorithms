#include <bits/stdc++.h>

#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Solution {
   private:
    Node* reverseList(Node* head) {
        Node* current = head;
        Node* prev = nullptr;
        while (current) {
            Node* nextNode = current->next;
            current->next = prev;
            prev = current;
            current = nextNode;
        }
        return prev;
    }

   public:
    struct Node* addTwoLists(struct Node* num1, struct Node* num2) {
        Node* dummy = new Node(0);
        Node* tail = dummy;
        int carry = 0;
        Node* l1 = reverseList(num1);
        Node* l2 = reverseList(num2);
        while (l1 || l2 || carry) {
            int val1 = l1 ? l1->data : 0;
            int val2 = l2 ? l2->data : 0;
            int sum = val1 + val2 + carry;

            carry = sum / 10;
            tail->next = new Node(sum % 10);
            tail = tail->next;

            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }

        Node* res = reverseList(dummy->next);
        delete dummy;

        while (res && res->data == 0) {
            Node* temp = res;
            res = res->next;
            delete temp;
        }

        return res;
    }
};

int main() {
    return 0;
}