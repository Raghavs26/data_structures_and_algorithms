#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    string repeatLimitedString(string s, int repeatLimit) {
        unordered_map<char, int> mp;
        for (char c : s) mp[c]++;

        priority_queue<pair<char, int>> pq;
        for (auto [c, count] : mp) pq.push({c, count});

        string res;
        while (!pq.empty()) {
            auto [currentChar, currentCount] = pq.top();
            pq.pop();

            int use = min(repeatLimit, currentCount);
            res.append(use, currentChar);
            currentCount -= use;

            if (currentCount > 0) {
                if (pq.empty()) break;
                auto [nextChar, nextCount] = pq.top();
                pq.pop();

                res.push_back(nextChar);
                nextCount--;

                if (nextCount > 0) pq.push({nextChar, nextCount});
                pq.push({currentChar, currentCount});
            }
        }

        return res;
    }
};

int main() {
    Solution sol;
    string s = "cczazcc";
    int repeatLimit = 2;
    cout << sol.repeatLimitedString(s, repeatLimit) << endl;
    return 0;
}
