#include <bits/stdc++.h>

#include <iostream>
using namespace std;

class FreqStack {
   private:
    unordered_map<int, int> freqMap;
    unordered_map<int, stack<int>> freqStack;
    int maxFreq = 0;

   public:
    FreqStack() {}

    void push(int val) {
        int freq = ++freqMap[val];
        maxFreq = max(freq, maxFreq);
        freqStack[freq].push(val);
    }

    int pop() {
        int top = freqStack[maxFreq].top();
        freqStack[maxFreq].pop();
        freqMap[top]--;
        if (freqStack[maxFreq].empty()) maxFreq--;
        return top;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */

int main() {
    return 0;
}