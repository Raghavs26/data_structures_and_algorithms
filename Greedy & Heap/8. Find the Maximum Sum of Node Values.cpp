#include <bits/stdc++.h>

#include <iostream>
using namespace std;

class Solution {
   public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        long long res = 0;
        int count = 0;
        long long loss = LONG_MAX;
        for (int i = 0; i < nums.size(); i++) {
            res += max(nums[i] ^ k, nums[i]);
            if ((nums[i] ^ k) > nums[i]) count++;
            loss = min(loss, (long long)abs(nums[i] - (nums[i] ^ k)));
        }
        return res - (count % 2 == 0 ? 0 : loss);
    }
};

int main() {
    return 0;
}