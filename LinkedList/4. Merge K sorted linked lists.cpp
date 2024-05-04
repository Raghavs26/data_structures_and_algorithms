#include <bits/stdc++.h>

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Compare {
    bool operator()(const Node* n1, const Node* n2) const {
        return n1->data > n2->data;
    }
};

class Solution {
   public:
    Node* mergeKLists(Node* arr[], int k) {
        priority_queue<Node*, vector<Node*>, Compare> pq;
        for (int i = 0; i < k; i++) {
            if (arr[i]) pq.push(arr[i]);
        }
        if (pq.empty()) return NULL;
        Node* dummy = new Node(0);
        Node* tail = dummy;
        while (!pq.empty()) {
            Node* minNode = pq.top();
            pq.pop();
            tail->next = minNode;
            tail = tail->next;
            if (minNode->next != NULL) {
                pq.push(minNode->next);
            }
        }
        return dummy->next;
    }
};

int main() {
    return 0;
}