#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int minimumPushes(string word) {
        unordered_map<char, int> mp;
        for (char c : word) {
            mp[c]++;
        }

        priority_queue<int> pq;
        for (auto [c, count] : mp) {
            pq.push(count);
        }

        int res = 0;
        int distinct = 0;
        while (!pq.empty()) {
            int count = pq.top();
            pq.pop();
            res += count;
            distinct += 1;
        }

        res += (distinct - 1) / 8;

        return res;
    }
};
int main() {
    return 0;
}