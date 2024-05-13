#include <bits/stdc++.h>

#include <iostream>
using namespace std;

class Solution {
   public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> candies(n, -1);

        function<int(int)> solve = [&](int index) {
            if (candies[index] != -1) return candies[index];

            bool check1 = (index - 1 >= 0 && ratings[index - 1] < ratings[index]);
            bool check2 = (index + 1 < n && ratings[index + 1] < ratings[index]);

            if (check1 && check2) {
                int temp1 = solve(index - 1);
                int temp2 = solve(index + 1);
                candies[index] = max(temp1, temp2) + 1;
            } else if (check1) {
                candies[index] = solve(index - 1) + 1;
            } else if (check2) {
                candies[index] = solve(index + 1) + 1;
            } else {
                candies[index] = 1;
            }

            return candies[index];
        };

        for (int i = 0; i < n; i++) {
            if (candies[i] == -1) {
                candies[i] = solve(i);
            }
        }

        return accumulate(candies.begin(), candies.end(), 0);
    }
};

int main() {
    return 0;
}