#include <bits/stdc++.h>

#include <iostream>
using namespace std;

class Solution {
   public:
    int min_operations(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        // lis code
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j] && (i - j) <= (nums[i] - nums[j])) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }

        return n - *max_element(dp.begin(), dp.end());
    }
};

int main() {
    return 0;
}