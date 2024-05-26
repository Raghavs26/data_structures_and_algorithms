#include <bits/stdc++.h>

#include <iostream>
using namespace std;

class Solution {
    vector<vector<int>> dp;

   private:
    int longestPalindromeSubseq(string& str, string& s, int i, int j) {
        if (i == 0 || j == 0) {
            return 0;
        }
        if (dp[i][j] != -1) return dp[i][j];

        if (str[i - 1] == s[j - 1]) {
            dp[i][j] = 1 + longestPalindromeSubseq(str, s, i - 1, j - 1);
        } else {
            dp[i][j] = max(longestPalindromeSubseq(str, s, i - 1, j),
                           longestPalindromeSubseq(str, s, i, j - 1));
        }

        return dp[i][j];
    }

   public:
    int kPalindrome(string str, int n, int k) {
        string s = str;
        reverse(s.begin(), s.end());
        dp.resize(n + 1, vector<int>(n + 1, -1));
        int lpsLength = longestPalindromeSubseq(str, s, n, n);
        return (n - lpsLength) <= k;
    }
};

int main() {
    return 0;
}