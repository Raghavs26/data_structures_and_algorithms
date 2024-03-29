#include <bits/stdc++.h>

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
   public:
    ListNode* reverseList(ListNode* head) {
        ListNode *prev = nullptr, *current = head;
        while (current) {
            auto nextNode = current->next;
            current->next = prev;
            prev = current;
            current = current->next;
        }
        return prev;
    }
};

int main() {
    return 0;
}