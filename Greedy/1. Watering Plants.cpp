#include <bits/stdc++.h>

#include <iostream>
using namespace std;

class Solution {
   public:
    int min_sprinklers(int gallery[], int n) {
        vector<pair<int, int>> range;

        for (int i = 0; i < n; i++) {
            if (gallery[i] == -1) continue;

            int left = max(0, i - gallery[i]);
            int right = min(n - 1, i + gallery[i]);

            range.push_back({left, right});
        }

        sort(range.begin(), range.end());

        int count = 0, target = 0;
        int i = 0;
        while (target < n) {
            int nextTarget = -1;
            while (i < range.size()) {
                if (range[i].first > target) break;

                nextTarget = max(nextTarget, range[i].second);
                i++;
            }
            if (nextTarget < target) return -1;
            count++;
            target = nextTarget + 1;
        }
        return count;
    }
};

int main() {
    return 0;
}