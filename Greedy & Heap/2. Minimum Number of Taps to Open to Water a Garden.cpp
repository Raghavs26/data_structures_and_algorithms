#include <bits/stdc++.h>

#include <iostream>
using namespace std;

class Solution {
   public:
    int minTaps(int n, vector<int>& ranges) {
        vector<pair<int, int>> v;
        for (int i = 0; i <= n; i++) {
            int left = max(0, i - ranges[i]);
            int right = min(n, i + ranges[i]);
            if (left == right) continue;  // Skip taps with zero coverage
            v.push_back({left, right});
        }
        sort(v.begin(), v.end());
        int count = 0, target = 0, i = 0;
        while (target < n) {
            int nextTarget = target;
            while (i < v.size() && v[i].first <= target) {
                nextTarget = max(nextTarget, v[i].second);
                i++;
            }
            if (nextTarget == target) return -1;
            count++;
            target = nextTarget;
        }
        return count;
    }
};

int main() {
    return 0;
}