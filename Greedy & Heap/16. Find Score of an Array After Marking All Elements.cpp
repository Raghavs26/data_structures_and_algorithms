#include <bits/stdc++.h>
using namespace std;

class Solution {
    // time complexity O(NLogN)
   public:
    long long findScore(vector<int>& nums) {
        int n = nums.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        long long score = 0;
        vector<bool> marked(n, false);
        for (int i = 0; i < n; i++) {
            pq.push({nums[i], i});
        }
        while (!pq.empty()) {
            int num = pq.top().first;
            int index = pq.top().second;
            pq.pop();
            if (marked[index]) continue;
            if (index == 0) {
                marked[index + 1] = true;
            } else if (index == n - 1) {
                marked[index - 1] = true;
            } else {
                marked[index + 1] = true;
                marked[index - 1] = true;
            }
            score += num;
        }
        return score;
    }
};

int main() {
    return 0;
}