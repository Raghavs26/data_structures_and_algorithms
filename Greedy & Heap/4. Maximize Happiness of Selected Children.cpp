#include <bits/stdc++.h>

#include <iostream>
using namespace std;

class Solution {
   public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        int n = happiness.size();
        sort(happiness.begin(), happiness.end());

        int childrenSelected = 0;
        long long totalHappiness = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (childrenSelected == k) break;
            totalHappiness += max(happiness[i] - childrenSelected, 0);
            childrenSelected++;
        }
        return totalHappiness;
    }
};

int main() {
    return 0;
}