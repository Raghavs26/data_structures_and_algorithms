#include <bits/stdc++.h>
using namespace std;

class Solution {
    int dp[1000][1001][4];

   private:
    int solve(int ind, int prevIndex, int count, vector<int>& rating) {
        if (count == 0) return 1;
        if (ind >= rating.size()) return 0;
        if (dp[ind][prevIndex + 1][count] != -1) return dp[ind][prevIndex + 1][count];

        int include = 0, exclude = 0;
        if (prevIndex == -1 || rating[ind] > rating[prevIndex]) include = solve(ind + 1, ind, count - 1, rating);
        int exclude = solve(ind + 1, prevIndex, count, rating);

        return dp[ind][prevIndex + 1][count] = include + exclude;
    }

   public:
    int numTeams(vector<int>& rating) {
        memset(dp, -1, sizeof(dp));
        int incre = solve(0, -1, 3, rating);
        reverse(rating.begin(), rating.end());
        memset(dp, -1, sizeof(dp));
        int decre = solve(0, -1, 3, rating);
        return (incre + decre);
    }
};
int main() {
    return 0;
}