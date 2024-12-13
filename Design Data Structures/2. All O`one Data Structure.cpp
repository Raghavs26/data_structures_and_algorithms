#include <bits/stdc++.h>
using namespace std;

class Node {
   public:
    int count;
    list<string> keys;
    Node* prev;
    Node* next;

    Node(int count) {
        this->count = count;
        this->prev = nullptr;
        this->next = nullptr;
    }
};

class AllOne {
   private:
    unordered_map<string, Node*> mp;
    Node *head, *tail;

   public:
    AllOne() {
        head = new Node(0);
        tail = new Node(0);
        head->next = tail;
        tail->prev = head;
    }

    void addNode(Node* prevNode, int newCount) {
        Node* newNode = new Node(newCount);
        newNode->next = prevNode->next;
        newNode->prev = prevNode;
        prevNode->next->prev = newNode;
        prevNode->next = newNode;
    }

    void removeNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        delete node;
    }

    void inc(string key) {
        if (mp.find(key) == mp.end()) {
            if (head->next == tail || head->next->count != 1) {
                addNode(head, 1);
            }
            head->next->keys.push_back(key);
            mp[key] = head->next;
        } else {
            Node* currentNode = mp[key];
            int currentCount = currentNode->count;
            Node* nextNode = currentNode->next;

            if (nextNode == tail || nextNode->count != currentCount + 1) {
                addNode(currentNode, currentCount + 1);
                nextNode = currentNode->next;
            }
            nextNode->keys.push_back(key);
            mp[key] = nextNode;

            currentNode->keys.remove(key);
            if (currentNode->keys.empty()) {
                removeNode(currentNode);
            }
        }
    }

    void dec(string key) {
        if (mp.find(key) == mp.end()) return;

        Node* currentNode = mp[key];
        int currentCount = currentNode->count;

        if (currentCount == 1) {
            mp.erase(key);
            currentNode->keys.remove(key);
            if (currentNode->keys.empty()) {
                removeNode(currentNode);
            }
        } else {
            Node* prevNode = currentNode->prev;
            if (prevNode == head || prevNode->count != currentCount - 1) {
                addNode(prevNode, currentCount - 1);
                prevNode = currentNode->prev;
            }
            prevNode->keys.push_back(key);
            mp[key] = prevNode;

            currentNode->keys.remove(key);
            if (currentNode->keys.empty()) {
                removeNode(currentNode);
            }
        }
    }

    string getMaxKey() {
        if (tail->prev == head) return "";
        return tail->prev->keys.front();
    }

    string getMinKey() {
        if (head->next == tail) return "";
        return head->next->keys.front();
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */

int main() {
    return 0;
}