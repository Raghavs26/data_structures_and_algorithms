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
   private:
    ListNode *reverseList(ListNode *head) {
        ListNode *prev = nullptr;
        ListNode *curr = head;
        while (curr) {
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

   public:
    bool isPalindrome(ListNode *head) {
        if (!head || !head->next) return true;

        ListNode *fast = head, *slow = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        slow = reverseList(slow);

        ListNode *temp = head;
        while (slow) {
            if (temp->val != slow->val) return false;
            temp = temp->next;
            slow = slow->next;
        }
        return true;
    }
};

int main() {
    return 0;
}