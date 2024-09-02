#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    long long maxPoints(vector<vector<int>>& points) {
        int m = points.size();
        int n = points[0].size();

        vector<vector<long long>> dp(m + 1, vector<long long>(n + 1, 0));

        for (int j = 0; j < n; j++) {
            dp[0][j] = points[0][j];
        }

        for (int i = 1; i < m; i++) {
            vector<long long> left(n, 0), right(n, 0);

            left[0] = dp[i - 1][0];
            for (int j = 1; j < n; j++) {
                left[j] = max(left[j - 1] - 1, dp[i - 1][j]);
            }

            right[n - 1] = dp[i - 1][n - 1];
            for (int j = n - 2; j >= 0; j--) {
                right[j] = max(right[j + 1] - 1, dp[i - 1][j]);
            }

            for (int j = 0; j < n; j++) {
                dp[i][j] = points[i][j] + max(left[j], right[j]);
            }
        }

        long long result = 0;
        for (int j = 0; j < n; j++) {
            result = max(result, dp[m - 1][j]);
        }

        return result;
    }
};
int main() {
    return 0;
}