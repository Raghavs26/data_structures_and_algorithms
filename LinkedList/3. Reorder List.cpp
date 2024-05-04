#include <bits/stdc++.h>

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
   public:
    void reorderList(ListNode *head) {
        if (!head) return;

        ListNode *slow = head, *fast = head;
        while (fast->next and fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *current = slow->next, *prev = nullptr;
        while (current) {
            ListNode *nextNode = current->next;
            current->next = prev;
            prev = current;
            current = nextNode;
        }
        slow->next = nullptr;
        ListNode *h1 = head, *h2 = prev;
        while (h2) {
            auto next = h1->next;
            h1->next = h2;
            h1 = h2;
            h2 = next;
        }
    }
};

int main() {
    return 0;
}