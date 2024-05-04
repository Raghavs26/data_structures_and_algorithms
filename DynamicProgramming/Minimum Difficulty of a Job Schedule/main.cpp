#include <bits/stdc++.h>

#include <iostream>
using namespace std;

#include <bits/stdc++.h>


int subarrayMaximum(vector<int>& arr, int k) {
    int n = arr.size();
    if (n < k) return -1;
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));

    function<int(int, int)> solve = [&](int index, int day) {
        if (index == n) {
            if (day == 0) {
                return 0;
            }
            return (int)1e8;
        }
        if (day == 0) {
            return (int)1e8;
        }
        if (dp[index][day] != -1) return dp[index][day];

        int res = INT_MAX;
        int maxDifficulty = arr[index];
        for (int i = index; i < n - day + 1; i++) {
            maxDifficulty = (maxDifficulty, arr[index]);
            int tempAns = maxDifficulty + solve(i + 1, day - 1);
            res = min(res, tempAns);
            dp[index][day] = res;
        }
        return res;
    };
    return solve(0, k);
}

class Solution {
    vector<vector<int>> dp;

   private:
    int solve(int index, int n, vector<int>& jobDifficulty, int d) {
        if (d == 0 && index == n) {
            return 0;
        }
        if (d <= 0) {
            return 1e8;
        }

        if (dp[index][d] != -1) return dp[index][d];

        int maxDifficulty = jobDifficulty[index];
        int res = INT_MAX;
        for (int i = index; i < n - d + 1; i++) {
            maxDifficulty = max(jobDifficulty[i], maxDifficulty);
            int temp = maxDifficulty + solve(i + 1, n, jobDifficulty, d - 1);
            res = min(res, temp);
            dp[index][d] = res;
        }
        return res;
    }

   public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        dp.resize(n + 1, vector<int>(d + 1, -1));
        if (d > n) return -1;
        return solve(0, n, jobDifficulty, d);
    }
};

class Solution {
    unordered_map<string, int> dp;

   private:
    int solve(int index, int n, int currentMax, vector<int>& jobDifficulty, int d) {
        if (index == n) {
            if (d == 0) {
                return 0;
            }
            return 1e8;
        }
        if (d == 0) {
            return 1e8;
        }

        string key = to_string(index) + "_" + to_string(currentMax) + "_" + to_string(d);
        if (dp.find(key) != dp.end()) {
            return dp[key];
        }
        currentMax = max(currentMax, jobDifficulty[index]);
        int res = min(solve(index + 1, n, currentMax, jobDifficulty, d),                 // continue day
                      currentMax + solve(index + 1, n, INT_MIN, jobDifficulty, d - 1));  // end day
        return dp[key] = res;
    }

   public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        if (d > n) return -1;
        return solve(0, n, INT_MIN, jobDifficulty, d);
    }
};

int main() {
    return 0;
}