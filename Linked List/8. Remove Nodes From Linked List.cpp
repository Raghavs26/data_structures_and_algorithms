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
    ListNode* removeNodes(ListNode* head) {
        stack<ListNode*> st;
        ListNode* current = head;
        while (current != nullptr) {
            while (!st.empty() && st.top()->val < current->val) {
                st.pop();
            }
            st.push(current);
            current = current->next;
        }
        if (st.empty()) {
            return nullptr;
        }
        ListNode* res = nullptr;
        while (!st.empty()) {
            ListNode* node = st.top();
            st.pop();
            node->next = res;
            res = node;
        }
        return res;
    }
};

int main() {
    return 0;
}