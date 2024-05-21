#include <bits/stdc++.h>

#include <iostream>
using namespace std;

class Solution {
    vector<vector<double>> dp;

   private:
    double solve(vector<int>& nums, int k, int start, int partitions) {
        if (start == nums.size()) {
            if (partitions == k) {
                return 0.0;
            }
            return (double)INT_MIN;
        }
        if (partitions == k) {
            return (double)INT_MIN;
        }
        if (dp[start][partitions] != -1.0) {
            return dp[start][partitions];
        }
        double res = 0.0;
        double sum = 0.0;
        int count = 0;
        for (int i = start; i < nums.size(); i++) {
            sum += nums[i];
            count++;
            res = max(res, (double)sum / count + solve(nums, k, i + 1, partitions + 1));
        }
        return dp[start][partitions] = res;
    }

   public:
    double largestSumOfAverages(vector<int>& nums, int k) {
        dp.resize(nums.size() + 1, vector<double>(k + 1, -1.0));
        return solve(nums, k, 0, 0);
    }
};

int main() {
    return 0;
}