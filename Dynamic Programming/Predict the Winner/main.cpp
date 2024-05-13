#include <bits/stdc++.h>

#include <iostream>
using namespace std;

class Solution {
    vector<vector<int>> dp;

   private:
    int solve(int left, int right, vector<int>& nums) {
        if (left > right) return 0;
        if (dp[left][right] != -1) return dp[left][right];
        int takeFromLeft = nums[left] + min(solve(left + 2, right, nums), solve(left + 1, right - 1, nums));
        int takeFromRight = nums[right] + min(solve(left + 1, right - 1, nums), solve(left, right - 2, nums));
        return dp[left][right] = max(takeFromLeft, takeFromRight);
    }

   public:
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        dp.resize(n + 1, vector<int>(n + 1, -1));
        int left = 0, right = n - 1;
        int totalScore = accumulate(nums.begin(), nums.end(), 0);
        int playerOneScore = solve(left, right, nums);
        int playerTwoScore = totalScore - playerOneScore;
        return playerOneScore >= playerTwoScore;
    }
};

// Alternate Approach

// class Solution {
//     vector<vector<int>> dp;

//    private:
//     int solve(int left, int right, vector<int>& nums) {
//         if (left > right) return 0;
//         if (dp[left][right] != -1) return dp[left][right];

//         int takeFromLeft = nums[left] - solve(left + 1, right, nums);
//         int takeFromRight = nums[right] - solve(left, right - 1, nums);

//         return dp[left][right] = max(takeFromLeft, takeFromRight);
//     }

//    public:
//     bool predictTheWinner(vector<int>& nums) {
//         int n = nums.size();
//         dp.resize(n + 1, vector<int>(n + 1, -1));
//         int left = 0, right = n - 1;
//         int totalScore = accumulate(nums.begin(), nums.end(), 0);
//         int playerOneScore = solve(left, right, nums);
//         int playerTwoScore = totalScore - playerOneScore;
//         return playerOneScore >= playerTwoScore;
//     }
// };

int main() {
    return 0;
}