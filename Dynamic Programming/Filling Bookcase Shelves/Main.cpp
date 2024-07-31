#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<int>> dp;

   private:
    int solve(int i, int currentWidth, int maxHeight, vector<vector<int>>& books, int shelfWidth) {
        if (i >= books.size()) return maxHeight;
        if (dp[i][currentWidth] != -1) return dp[i][currentWidth];

        int include = INT_MAX, exclude = INT_MAX;
        if (currentWidth >= books[i][0]) {
            include = solve(i + 1, currentWidth - books[i][0], max(maxHeight, books[i][1]), books, shelfWidth);
        }
        exclude = maxHeight + solve(i + 1, shelfWidth - books[i][0], books[i][1], books, shelfWidth);

        return dp[i][currentWidth] = min(include, exclude);
    }

   public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n = books.size();
        dp.resize(n + 1, vector<int>(shelfWidth + 1, -1));
        return solve(0, shelfWidth, 0, books, shelfWidth);
    }
};

int main() {
    return 0;
}