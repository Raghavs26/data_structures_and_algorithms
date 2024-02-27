#include <bits/stdc++.h>

#include <iostream>
using namespace std;

class Solution {
    vector<int> dp;

   private:
    int solve(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        if (dp[n] != -1) return dp[n];
        return dp[n] = max({n, maxSum(n / 2) + maxSum(n / 3) + maxSum(n / 4)});
    }

   public:
    int maxSum(int n) {
        dp.resize(n + 1, -1);
        return solve(n);
    }
};

int main() {
    string str = "ilike";
    vector<string> dictionary{"i", "like", "sam", "sung", "samsung", "mobile"};
    int n = dictionary.size();
    Solution* s;
    cout << s->wordBreak(n, str, dictionary);
    return 0;
}