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
   private:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* current = head;
        while (current != nullptr) {
            ListNode* next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        return prev;
    }

   public:
    ListNode* doubleIt(ListNode* head) {
        head = reverseList(head);
        ListNode* current = head;
        int carry = 0;
        while (current != nullptr) {
            int sum = current->val * 2 + carry;
            current->val = sum % 10;
            carry = sum / 10;
            if (current->next == nullptr && carry > 0) {
                current->next = new ListNode(carry);
                break;
            }
            current = current->next;
        }

        return reverseList(head);
    }
};

int main() {
    return 0;
}