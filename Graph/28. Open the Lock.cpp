#include <bits/stdc++.h>

#include <iostream>
using namespace std;

class Solution {
   public:
    int openLock(vector<string>& deadends, string target) {
        queue<string> q;
        unordered_set<string> dead(deadends.begin(), deadends.end());
        unordered_set<string> visited;
        q.push("0000");
        visited.insert("0000");
        int steps = 0;
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                string current = q.front();
                q.pop();
                if (current == target) return steps;
                if (dead.find(current) != dead.end()) continue;

                for (int i = 0; i < 4; i++) {
                    char c = current[i];
                    string next = current;
                    next[i] = c == '9' ? '0' : c + 1;
                    if (visited.find(next) == visited.end() && dead.find(next) == dead.end()) {
                        q.push(next);
                        visited.insert(next);
                    }
                    next[i] = c == '0' ? '9' : c - 1;
                    if (visited.find(next) == visited.end() && dead.find(next) == dead.end()) {
                        q.push(next);
                        visited.insert(next);
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};

int main() {
    return 0;
}
