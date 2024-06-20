#include <bits/stdc++.h>

#include <iostream>
using namespace std;

class Solution {
    unordered_map<int, vector<int>> mp{
        {0, {0, 8}},
        {1, {1, 2, 4}},
        {2, {2, 1, 3, 5}},
        {3, {3, 2, 6}},
        {4, {4, 1, 5, 7}},
        {5, {5, 2, 6, 8, 4}},
        {6, {6, 3, 9, 5}},
        {7, {7, 4, 8}},
        {8, {8, 5, 9, 0, 7}},
        {9, {9, 6, 8}}};
    vector<vector<long long>> dp;

   private:
    long long solve(int length, int digit) {
        if (length == 1) return 1;
        if (dp[length][digit] != -1) return dp[length][digit];
        long long res = 0;
        for (auto neighbor : mp[digit]) {
            res += solve(length - 1, neighbor);
        }
        return dp[length][digit] = res;
    }

   public:
    long long getCount(int n) {
        if (n == 1) return 10;
        dp.resize(n + 1, vector<long long>(10, -1));
        long long res = 0;
        for (int i = 0; i < 10; i++) {
            res += solve(n, i);
        }
        return res;
    }
};

int main() {
    return 0;
}