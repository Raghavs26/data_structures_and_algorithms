#include <bits/stdc++.h>

#include <iostream>
using namespace std;

struct Node {
    char data;
    struct Node* next;

    Node(char x) {
        data = x;
        next = NULL;
    }
};

class Solution {
   private:
    bool isVowel(char c) {
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }

   public:
    struct Node* arrangeCV(Node* head) {
        Node* vowels = new Node('0');
        Node* consonants = new Node('0');
        Node *v = vowels, *c = consonants;
        Node* current = head;
        while (current) {
            char ch = current->data;
            if (isVowel(ch)) {
                v->next = current;
                v = v->next;
            } else {
                c->next = current;
                c = c->next;
            }
            current = current->next;
        }
        v->next = consonants->next;
        c->next = nullptr;
        return vowels->next;
    }
};

int main() {
    return 0;
}