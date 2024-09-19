#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// time complexity - O(N)
// space complexity - O(N)
class Solution {
   public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> st(nums.begin(), nums.end());
        ListNode* res = new ListNode(0);
        ListNode *prev = res, *current = head;

        res->next = head;

        while (current) {
            if (st.find(current->val) != st.end()) {
                prev->next = current->next;
            } else {
                prev = current;
            }
            current = current->next;
        }
        return res->next;
    }
};

int main() {
    return 0;
}