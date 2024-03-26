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

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

// class Solution {
//    private:
//     ListNode *findMiddle(ListNode *head) {
//         if (!head) return head;
//         ListNode *slow = head, *fast = head;
//         while (fast->next && fast->next->next) {
//             slow = slow->next;
//             fast = fast->next->next;
//         }
//         return slow;
//     }

//     vector<int> convertLinkedListToArray(ListNode *head) {
//         ListNode *current = head;
//         vector<int> result;
//         while (current) {
//             result.push_back(current->val);
//             current = current->next;
//         }
//         return result;
//     }

//     TreeNode *buildBST(vector<int> &nums, int left, int right) {
//         if (left > right) return nullptr;
//         int mid = left + (right - left) / 2;
//         TreeNode *root = new TreeNode(nums[mid]);
//         root->left = buildBST(nums, left, mid - 1);
//         root->right = buildBST(nums, mid + 1, right);
//         return root;
//     }

//    public:
//     TreeNode *sortedListToBST(ListNode *head) {
//         if (!head) return nullptr;
//         vector<int> linkedListArray = convertLinkedListToArray(head);
//         return buildBST(linkedListArray, 0, linkedListArray.size() - 1);
//     }
// };

class Solution {
   private:
    ListNode* findMiddle(ListNode* head, ListNode* tail) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != tail && fast->next != tail) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    TreeNode* buildTree(ListNode* head, ListNode* tail) {
        if (head == tail) return nullptr;

        ListNode* midNode = findMiddle(head, tail);
        TreeNode* root = new TreeNode(midNode->val);
        root->left = buildTree(head, midNode);
        root->right = buildTree(midNode->next, tail);
        return root;
    }

   public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (!head) return nullptr;
        return buildTree(head, nullptr);
    }
};

int main() {
    return 0;
}