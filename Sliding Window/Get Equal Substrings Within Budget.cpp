#include <bits/stdc++.h>

#include <iostream>
using namespace std;

class Solution {
   public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.size();
        int res = 0, currentCost = 0;
        int windowStart = 0, windowEnd = 0;
        while (windowEnd < n) {
            currentCost += abs(s[windowEnd] - t[windowEnd]);
            while (currentCost > maxCost) {
                currentCost -= abs(s[windowStart] - t[windowStart]);
                windowStart++;
            }

            res = max(res, windowEnd - windowStart + 1);
            windowEnd++;
        }
        return res;
    }
};

int main() {
    return 0;
}
