#include <bits/stdc++.h>

#include <iostream>
using namespace std;

class Solution {
   private:
    vector<string> split(string& s, char delim) {
        vector<string> res;
        istringstream ss(s);
        string token;
        while (getline(ss, token, delim)) {
            res.push_back(token);
        }
        return res;
    }

   public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> mp;
        vector<string> words = split(s, ' ');
        if (pattern.size() != s.size()) return false;
        int n = s.size();

        for (int i = 0; i < n; i++) {
            if (mp.find(pattern[i]) != mp.end()) {
                if (mp[pattern[i]] != words[i]) return false;
            }
            mp[pattern[i]] = words[i];
        }
        return true;
    }
};

class Solution {
    vector<vector<int>> dp;

   private:
    int solve(int i, int j, int n, vector<vector<int>>& matrix) {
        if (i == n - 1) {
            return matrix[i][j];
        }
        if (dp[i][j] != INT_MIN) {
            return dp[i][j];
        }

        int currentCellValue = matrix[i][j];

        int straightDownSum = solve(i + 1, j, n, matrix);
        int downLeftSum = (j > 0) ? solve(i + 1, j - 1, n, matrix) : -1e8;
        int downRightSum = (j < n - 1) ? solve(i + 1, j + 1, n, matrix) : -1e8;

        int maxPathSum = currentCellValue + max({straightDownSum, downLeftSum, downRightSum});

        return dp[i][j] = maxPathSum;
    }

   public:
    int maximumPath(int n, vector<vector<int>> matrix) {
        dp.resize(n + 1, vector<int>(n + 1, INT_MIN));
        int res = INT_MIN;
        for (int i = 0; i < n; i++) {
            int tempAns = solve(0, i, n, matrix);
            res = max(res, tempAns);
        }
        return res;
    }
};

int main() {
    return 0;
}
