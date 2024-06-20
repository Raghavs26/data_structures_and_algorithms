#include <bits/stdc++.h>

#include <iostream>
using namespace std;

class Solution {
   public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        priority_queue<int> maxPQ;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minPQ;
        for (int i = 0; i < n; i++) {
            minPQ.push({capital[i], i});
        }
        int availableCapital = w;
        for (int i = 0; i < k; i++) {
            while (!minPQ.empty() && minPQ.top().first <= availableCapital) {
                int idx = minPQ.top().second;
                minPQ.pop();
                maxPQ.push(profits[idx]);
            }
            if (maxPQ.empty()) break;

            availableCapital += maxPQ.top();
            maxPQ.pop();
        }
        return availableCapital;
    }
};

int main() {
    return 0;
}