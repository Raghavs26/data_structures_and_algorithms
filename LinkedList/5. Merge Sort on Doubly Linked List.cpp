#include <bits/stdc++.h>

#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node *next, *prev;
    Node(int x) {
        data = x;
        next = prev = NULL;
    }
};

class Solution {
   private:
    Node* getMid(Node* head) {
        Node* fast = head;
        Node* slow = head;
        while (fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        Node* secondHalf = slow->next;
        slow->next = nullptr;
        if (secondHalf)
            secondHalf->prev = nullptr;
        return secondHalf;
    }

    Node* mergeSort(Node* first, Node* second) {
        if (!first) return second;

        if (!second) return first;

        Node* mergedList = nullptr;
        if (first->data < second->data) {
            mergedList = first;
            mergedList->next = mergeSort(first->next, second);
            if (mergedList->next) mergedList->next->prev = mergedList;
            mergedList->prev = nullptr;
        } else {
            mergedList = second;
            mergedList->next = mergeSort(first, second->next);
            if (mergedList->next) mergedList->next->prev = mergedList;
            mergedList->prev = nullptr;
        }
        return mergedList;
    }

   public:
    struct Node* sortDoubly(struct Node* head) {
        if (!head || !head->next) {
            return head;
        }

        Node* secondHalf = getMid(head);

        head = sortDoubly(head);
        secondHalf = sortDoubly(secondHalf);

        return mergeSort(head, secondHalf);
    }
};

int main() {
    return 0;
}
