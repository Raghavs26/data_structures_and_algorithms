#include <bits/stdc++.h>

#include <iostream>
using namespace std;

// top down approach
class Solution {
   private:
    vector<vector<int>> dp;

    int solve(vector<int> &a, int i, int prev) {
        if (i == a.size()) return 0;

        if (dp[i][prev + 1] != -1) return dp[i][prev + 1];

        int include = 0;
        if (prev == -1 || abs(a[i] - a[prev]) == 1) {
            include = 1 + solve(a, i + 1, i);
        }

        int exclude = solve(a, i + 1, prev);

        return dp[i][prev + 1] = max(include, exclude);
    }

   public:
    int longestSubseq(int n, vector<int> &a) {
        dp.resize(n, vector<int>(n + 1, -1));
        return solve(a, 0, -1);
    }
};

// bottom up approach
class Solution {
   public:
    int longestSubseq(int n, vector<int> &a) {
        vector<int> dp(n, 1);
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (abs(a[i] - a[j]) == 1) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};

int main() {
    return 0;
}
